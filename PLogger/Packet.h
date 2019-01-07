#pragma once

namespace SnifferNameSpace {
	enum PacketType {
		ClientToServer = 1<<0,
		ServerToClient = 1<<1,
		TCP = 1<<2,
		UDP = 1<<3
	};

	struct Packet {
		byte Opcode1;
		byte Opcode2;
		short Length;
		unsigned char* Data;

		bool Encrypted;
		PacketType Type;
	};
}