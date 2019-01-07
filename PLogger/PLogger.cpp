// This is the main DLL file.
#include "stdafx.h"
#include "Sniffer.h"
#include "PLogger.h"

using namespace SnifferNameSpace;

DWORD WINAPI LoopFunction(LPVOID lpParam);

void onTCPDecryptPacket();
int patchTCPDecryptPacket();
void onTCPEncryptPacket();
void patchTCPEncryptPacket();
void patchUDPEncryptPacket();
BOOL ApplyPatch(BYTE eType, DWORD dwAddress, const void* pTarget);
void PlaceJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen);

DWORD tcpEncryptPatchDoneAddr = 0x00C44376;
DWORD udpEncryptPatchDoneAddr = 0x00C4505E;

ref struct Globals {
	static SnifferNameSpace::Sniffer^ globalForm;
};

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{
	if (dwAttached == DLL_PROCESS_ATTACH) {
		/*AllocConsole();
		freopen("CONOUT$", "w", stdout);*/
		std::cout << "Initializing Logger." << std::endl;
		CreateThread(NULL, 0, &LoopFunction, NULL, 0, NULL);
		std::cout << "Initializing finished." << std::endl;
		std::cout << std::endl;
	}
	return 1;
}
//00C44370
DWORD WINAPI LoopFunction(LPVOID lpParam) {
	PlaceJMP((BYTE *)0x00C44370, (DWORD)patchTCPEncryptPacket, 6);
	PlaceJMP((BYTE *)0x00C44542, (DWORD)patchTCPDecryptPacket, 7);
	PlaceJMP((BYTE *)0x00C45059, (DWORD)patchUDPEncryptPacket, 5);

	SnifferNameSpace::Application::EnableVisualStyles();
	SnifferNameSpace::Application::SetCompatibleTextRenderingDefault(false);
	Globals::globalForm = gcnew SnifferNameSpace::Sniffer;
	Globals::globalForm->Show();
	SnifferNameSpace::Application::Run();
	return 0;
}

void hexdump(Packet packet) {
	int buflen = packet.Length;
	unsigned char *buf = packet.Data;
	Globals::globalForm->WritePacket(packet);

	return;
	int i, j;
	for (i = 0; i < buflen; i += 16) {
		printf("%06x: ", i);
		for (j = 0; j < 16; j++)
			if (i + j < buflen)
				printf("%02x ", buf[i + j]);
			else
				printf("   ");
		printf("        ");
		for (j = 0; j < 16; j++)
			if (i + j < buflen)
				printf("%c", isprint(buf[i + j]) ? buf[i + j] : '.');
		printf("\n");
	}
}


BYTE *udpEncData;
void onUDPEncryptPacket() {
	Packet packet;
	memcpy(&packet.Opcode1, udpEncData + 12, 1);
	memcpy(&packet.Opcode2, udpEncData + 16, 1);
	memcpy(&packet.Length, (udpEncData + 24), 2);
	packet.Data = (udpEncData + 36);
	packet.Encrypted = true;
	packet.Type = (PacketType)(PacketType::ClientToServer | PacketType::UDP);
	std::cout << "[C -> S]" << "[" << packet.Length << " bytes] [UDP]" << std::endl;
	hexdump(packet);
	std::cout << std::endl;
}

void onTCPDecryptPacket() {
	BYTE *data;
	__asm {
		mov data, edi
	}

	Packet packet;
	memcpy(&packet.Length, data, 2);
	memcpy(&packet.Opcode1, data + 5, 1);
	memcpy(&packet.Opcode2, data + 6, 1);
	packet.Length = packet.Length - 5;
	packet.Data = (data + 7);
	packet.Encrypted = true;
	packet.Type = (PacketType)(PacketType::ServerToClient | PacketType::TCP);
	std::cout << "[S -> C]" << "[" << packet.Length << " bytes] [TCP]" << std::endl;
	hexdump(packet);
	std::cout << std::endl;
}

void onTCPEncryptPacket() {
	BYTE *data;
	__asm {
		mov data, ecx
	}

	Packet packet;
	memcpy(&packet.Length, data, 2);
	memcpy(&packet.Opcode1, data + 2, 1);
	memcpy(&packet.Opcode2, data + 3, 1);
	packet.Length = packet.Length - 4;
	packet.Data = (data + 4);
	packet.Encrypted = true;
	packet.Type = (PacketType)(PacketType::ClientToServer | PacketType::TCP);
	std::cout << "[C -> S]" << "[" << packet.Length << " bytes] [TCP]" << std::endl;
	hexdump(packet);
	std::cout << std::endl;
}

void __declspec(naked) patchUDPEncryptPacket() {
	__asm {
		PUSHAD
		PUSHFD


		cmp ebp, 2h
		jz normal_routine
		mov udpEncData, ebp
		call onUDPEncryptPacket

		normal_routine :

		POPFD
		POPAD

		push ebp
		push esi
		movzx esi, bl
		jmp udpEncryptPatchDoneAddr
	}
}

int __declspec(naked) patchTCPDecryptPacket() {
	__asm {
		PUSHAD
		PUSHFD

		call onTCPDecryptPacket

		POPFD
		POPAD

		pop ebx
		add esp, 8
		retn 8
	}
}

void __declspec(naked) patchTCPEncryptPacket() {
	__asm {
		PUSHAD
		PUSHFD

		call onTCPEncryptPacket

		POPFD
		POPAD
		push ecx
		mov edx, eax
		push ebx
		mov ebx, eax
		jmp tcpEncryptPatchDoneAddr
	}
}

BOOL ApplyPatch(BYTE eType, DWORD dwAddress, const void* pTarget)
{
	//DWORD dwOldValue, dwTemp;
	//patch_t pWrite =
	//{
	//	eType,
	//	(DWORD)pTarget - (dwAddress + sizeof(DWORD) + sizeof(BYTE))
	//};

	//VirtualProtect((LPVOID)dwAddress, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &dwOldValue);
	//BOOL bSuccess = WriteProcessMemory(GetCurrentProcess(), (LPVOID)dwAddress, &pWrite, sizeof(pWrite), NULL);
	//VirtualProtect((LPVOID)dwAddress, sizeof(DWORD), dwOldValue, &dwTemp);
	//return bSuccess;
	return true;
}

void PlaceJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen) {
	DWORD dwOldProtect, dwBkup, dwRelAddr;

	VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	dwRelAddr = (DWORD)(dwJumpTo - (DWORD)pAddress) - 5;

	*pAddress = 0xE9;
	*((DWORD *)(pAddress + 0x1)) = dwRelAddr;
	for (DWORD x = 0x5; x < dwLen; x++)
		*(pAddress + x) = 0x90;

	VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
}