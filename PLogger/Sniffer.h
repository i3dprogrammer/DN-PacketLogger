#include "PLogger.h"

namespace SnifferNameSpace {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sniffer
	/// </summary>
	public ref class Sniffer : public System::Windows::Forms::Form
	{
	public:
		Sniffer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Sniffer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  rtb_packets;
	protected:

	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  btn_hideRemove;

	private: System::Windows::Forms::Button^  btn_hideAdd;

	private: System::Windows::Forms::TextBox^  txtBox_hideOpcode;
	private: System::Windows::Forms::ListBox^  list_hidden;
	private: System::Windows::Forms::ListBox^  list_shown;




	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  btn_showRemove;

	private: System::Windows::Forms::Button^  btn_showAdd;

	private: System::Windows::Forms::TextBox^  txtBox_showOpcode;
	private: System::Windows::Forms::CheckBox^  chkbox_udp;


	private: System::Windows::Forms::CheckBox^  chkBox_tcp;


	private: System::Windows::Forms::CheckBox^  chkBox_CS;

	private: System::Windows::Forms::CheckBox^  chkBox_SC;
	private: System::Windows::Forms::CheckBox^  chkBox_autoScroll;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->rtb_packets = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_hideRemove = (gcnew System::Windows::Forms::Button());
			this->btn_hideAdd = (gcnew System::Windows::Forms::Button());
			this->txtBox_hideOpcode = (gcnew System::Windows::Forms::TextBox());
			this->list_hidden = (gcnew System::Windows::Forms::ListBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btn_showRemove = (gcnew System::Windows::Forms::Button());
			this->btn_showAdd = (gcnew System::Windows::Forms::Button());
			this->txtBox_showOpcode = (gcnew System::Windows::Forms::TextBox());
			this->list_shown = (gcnew System::Windows::Forms::ListBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->chkBox_autoScroll = (gcnew System::Windows::Forms::CheckBox());
			this->chkbox_udp = (gcnew System::Windows::Forms::CheckBox());
			this->chkBox_tcp = (gcnew System::Windows::Forms::CheckBox());
			this->chkBox_CS = (gcnew System::Windows::Forms::CheckBox());
			this->chkBox_SC = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// rtb_packets
			// 
			this->rtb_packets->Dock = System::Windows::Forms::DockStyle::Left;
			this->rtb_packets->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rtb_packets->Location = System::Drawing::Point(0, 0);
			this->rtb_packets->Name = L"rtb_packets";
			this->rtb_packets->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedVertical;
			this->rtb_packets->Size = System::Drawing::Size(731, 626);
			this->rtb_packets->TabIndex = 0;
			this->rtb_packets->Text = L"";
			this->rtb_packets->WordWrap = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->btn_hideRemove);
			this->groupBox1->Controls->Add(this->btn_hideAdd);
			this->groupBox1->Controls->Add(this->txtBox_hideOpcode);
			this->groupBox1->Controls->Add(this->list_hidden);
			this->groupBox1->Location = System::Drawing::Point(737, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(218, 235);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Hide Opcodes";
			// 
			// btn_hideRemove
			// 
			this->btn_hideRemove->Location = System::Drawing::Point(108, 52);
			this->btn_hideRemove->Name = L"btn_hideRemove";
			this->btn_hideRemove->Size = System::Drawing::Size(97, 27);
			this->btn_hideRemove->TabIndex = 3;
			this->btn_hideRemove->Text = L"Remove";
			this->btn_hideRemove->UseVisualStyleBackColor = true;
			this->btn_hideRemove->Click += gcnew System::EventHandler(this, &Sniffer::btn_hideRemove_Click);
			// 
			// btn_hideAdd
			// 
			this->btn_hideAdd->Location = System::Drawing::Point(9, 52);
			this->btn_hideAdd->Name = L"btn_hideAdd";
			this->btn_hideAdd->Size = System::Drawing::Size(97, 27);
			this->btn_hideAdd->TabIndex = 2;
			this->btn_hideAdd->Text = L"Add";
			this->btn_hideAdd->UseVisualStyleBackColor = true;
			this->btn_hideAdd->Click += gcnew System::EventHandler(this, &Sniffer::btn_hideAdd_Click);
			// 
			// txtBox_hideOpcode
			// 
			this->txtBox_hideOpcode->Location = System::Drawing::Point(7, 22);
			this->txtBox_hideOpcode->Name = L"txtBox_hideOpcode";
			this->txtBox_hideOpcode->Size = System::Drawing::Size(201, 23);
			this->txtBox_hideOpcode->TabIndex = 1;
			// 
			// list_hidden
			// 
			this->list_hidden->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->list_hidden->FormattingEnabled = true;
			this->list_hidden->ItemHeight = 15;
			this->list_hidden->Location = System::Drawing::Point(3, 93);
			this->list_hidden->Name = L"list_hidden";
			this->list_hidden->Size = System::Drawing::Size(212, 139);
			this->list_hidden->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Controls->Add(this->btn_showRemove);
			this->groupBox2->Controls->Add(this->btn_showAdd);
			this->groupBox2->Controls->Add(this->txtBox_showOpcode);
			this->groupBox2->Controls->Add(this->list_shown);
			this->groupBox2->Location = System::Drawing::Point(737, 241);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(218, 235);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Show Opcodes";
			// 
			// btn_showRemove
			// 
			this->btn_showRemove->Location = System::Drawing::Point(108, 52);
			this->btn_showRemove->Name = L"btn_showRemove";
			this->btn_showRemove->Size = System::Drawing::Size(97, 27);
			this->btn_showRemove->TabIndex = 6;
			this->btn_showRemove->Text = L"Remove";
			this->btn_showRemove->UseVisualStyleBackColor = true;
			this->btn_showRemove->Click += gcnew System::EventHandler(this, &Sniffer::btn_showRemove_Click);
			// 
			// btn_showAdd
			// 
			this->btn_showAdd->Location = System::Drawing::Point(9, 52);
			this->btn_showAdd->Name = L"btn_showAdd";
			this->btn_showAdd->Size = System::Drawing::Size(97, 27);
			this->btn_showAdd->TabIndex = 5;
			this->btn_showAdd->Text = L"Add";
			this->btn_showAdd->UseVisualStyleBackColor = true;
			this->btn_showAdd->Click += gcnew System::EventHandler(this, &Sniffer::btn_showAdd_Click);
			// 
			// txtBox_showOpcode
			// 
			this->txtBox_showOpcode->Location = System::Drawing::Point(7, 22);
			this->txtBox_showOpcode->Name = L"txtBox_showOpcode";
			this->txtBox_showOpcode->Size = System::Drawing::Size(201, 23);
			this->txtBox_showOpcode->TabIndex = 4;
			// 
			// list_shown
			// 
			this->list_shown->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->list_shown->FormattingEnabled = true;
			this->list_shown->ItemHeight = 15;
			this->list_shown->Location = System::Drawing::Point(3, 93);
			this->list_shown->Name = L"list_shown";
			this->list_shown->Size = System::Drawing::Size(212, 139);
			this->list_shown->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->chkBox_autoScroll);
			this->groupBox3->Controls->Add(this->chkbox_udp);
			this->groupBox3->Controls->Add(this->chkBox_tcp);
			this->groupBox3->Controls->Add(this->chkBox_CS);
			this->groupBox3->Controls->Add(this->chkBox_SC);
			this->groupBox3->Location = System::Drawing::Point(737, 485);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(218, 138);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Settings";
			// 
			// chkBox_autoScroll
			// 
			this->chkBox_autoScroll->AutoSize = true;
			this->chkBox_autoScroll->Checked = true;
			this->chkBox_autoScroll->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkBox_autoScroll->Location = System::Drawing::Point(13, 100);
			this->chkBox_autoScroll->Name = L"chkBox_autoScroll";
			this->chkBox_autoScroll->Size = System::Drawing::Size(103, 19);
			this->chkBox_autoScroll->TabIndex = 4;
			this->chkBox_autoScroll->Text = L"Auto Scroll";
			this->chkBox_autoScroll->UseVisualStyleBackColor = true;
			// 
			// chkbox_udp
			// 
			this->chkbox_udp->AutoSize = true;
			this->chkbox_udp->Checked = true;
			this->chkbox_udp->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkbox_udp->Location = System::Drawing::Point(104, 75);
			this->chkbox_udp->Name = L"chkbox_udp";
			this->chkbox_udp->Size = System::Drawing::Size(47, 19);
			this->chkbox_udp->TabIndex = 3;
			this->chkbox_udp->Text = L"UDP";
			this->chkbox_udp->UseVisualStyleBackColor = true;
			// 
			// chkBox_tcp
			// 
			this->chkBox_tcp->AutoSize = true;
			this->chkBox_tcp->Checked = true;
			this->chkBox_tcp->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkBox_tcp->Location = System::Drawing::Point(13, 75);
			this->chkBox_tcp->Name = L"chkBox_tcp";
			this->chkBox_tcp->Size = System::Drawing::Size(47, 19);
			this->chkBox_tcp->TabIndex = 2;
			this->chkBox_tcp->Text = L"TCP";
			this->chkBox_tcp->UseVisualStyleBackColor = true;
			// 
			// chkBox_CS
			// 
			this->chkBox_CS->AutoSize = true;
			this->chkBox_CS->Checked = true;
			this->chkBox_CS->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkBox_CS->Location = System::Drawing::Point(13, 48);
			this->chkBox_CS->Name = L"chkBox_CS";
			this->chkBox_CS->Size = System::Drawing::Size(166, 19);
			this->chkBox_CS->TabIndex = 1;
			this->chkBox_CS->Text = L"Show Client > Server";
			this->chkBox_CS->UseVisualStyleBackColor = true;
			// 
			// chkBox_SC
			// 
			this->chkBox_SC->AutoSize = true;
			this->chkBox_SC->Checked = true;
			this->chkBox_SC->CheckState = System::Windows::Forms::CheckState::Checked;
			this->chkBox_SC->Location = System::Drawing::Point(13, 22);
			this->chkBox_SC->Name = L"chkBox_SC";
			this->chkBox_SC->Size = System::Drawing::Size(166, 19);
			this->chkBox_SC->TabIndex = 0;
			this->chkBox_SC->Text = L"Show Server > Client";
			this->chkBox_SC->UseVisualStyleBackColor = true;
			// 
			// Sniffer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 626);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->rtb_packets);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Sniffer";
			this->Text = L"Packet Parser";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Sniffer::Sniffer_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Sniffer::Sniffer_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Sniffer_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: int checkItemExists(System::Windows::Forms::ListBox^ list, String^ item) {
		int index = -1;
		for (int i = 0; i < list->Items->Count; i++) {
			if (list->Items[i]->ToString() == item) {
				index = i;
			}
		}

		return index;
	}

	private: System::Void btn_hideAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->txtBox_hideOpcode->TextLength > 0) {
			if (checkItemExists(this->list_hidden, this->txtBox_hideOpcode->Text->ToUpper()) == -1) {
				this->list_hidden->Items->Add(this->txtBox_hideOpcode->Text->ToUpper());
			}
			this->txtBox_hideOpcode->Text = "";
		}
	}

	private: System::Void btn_hideRemove_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->txtBox_hideOpcode->TextLength > 0) {
			int itemIndex = checkItemExists(this->list_hidden, this->txtBox_hideOpcode->Text->ToUpper());
			if (itemIndex != -1) {
				std::cout << itemIndex << std::endl;
				this->list_hidden->Items->RemoveAt(itemIndex);
			}
			this->txtBox_hideOpcode->Text = "";
		} else if(this->list_hidden->SelectedItem) {
			this->list_hidden->Items->Remove(this->list_hidden->SelectedItem);
		}
	}
	private: System::Void btn_showAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->txtBox_showOpcode->TextLength > 0) {
			if (checkItemExists(this->list_shown, this->txtBox_showOpcode->Text->ToUpper()) == -1) {
				this->list_shown->Items->Add(this->txtBox_showOpcode->Text->ToUpper());
			}
			this->txtBox_showOpcode->Text = "";
		}
	}
	private: System::Void btn_showRemove_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->txtBox_showOpcode->TextLength > 0) {
			int itemIndex = checkItemExists(this->list_shown, this->txtBox_showOpcode->Text->ToUpper());
			if (itemIndex != -1) {
				this->list_shown->Items->RemoveAt(itemIndex);
			}
			this->txtBox_showOpcode->Text = "";
		} else if (this->list_shown->SelectedItem) {
			this->list_shown->Items->Remove(this->list_shown->SelectedItem);
		}
	}

	public: System::Void WritePacket(Packet packet) {
		if (this->list_shown->Items->Count > 0)
			if (!this->list_shown->Items->Contains(packet.Opcode1.ToString("X2") + "-" + packet.Opcode2.ToString("X2")))
				return;
		if (this->list_hidden->Items->Count > 0)
			if (this->list_hidden->Items->Contains(packet.Opcode1.ToString("X2") + "-" + packet.Opcode2.ToString("X2")))
				return;
		if (this->chkbox_udp->Checked == false && this->chkBox_tcp->Checked == false)
			return;
		if (this->chkbox_udp->Checked && !this->chkBox_tcp->Checked && (packet.Type & PacketType::TCP))
			return;
		if (!this->chkbox_udp->Checked && this->chkBox_tcp->Checked && (packet.Type & PacketType::UDP))
			return;

		if (this->chkBox_CS->Checked == false && this->chkBox_SC->Checked == false)
			return;
		if ((packet.Type & PacketType::ServerToClient) && this->chkBox_CS->Checked == true && this->chkBox_SC->Checked == false)
			return;
		if ((packet.Type & PacketType::ClientToServer) && this->chkBox_CS->Checked == false && this->chkBox_SC->Checked == true)
			return;
		//[C -> S] [AB] [CD] [10 bytes]
		if (packet.Type & PacketType::ClientToServer)
			this->rtb_packets->AppendText("[C -> S] " + 
				"[" + gcnew String(LoggerClass::string_format("%02X", packet.Opcode1).c_str()) + "-" + gcnew String(LoggerClass::string_format("%02X", packet.Opcode2).c_str()) + "] " +
				"[" + packet.Length.ToString() + " bytes]\n");
		else
			this->rtb_packets->AppendText("[S -> C] " + 
				"[" + gcnew String(LoggerClass::string_format("%02X", packet.Opcode1).c_str()) + "-" + gcnew String(LoggerClass::string_format("%02X", packet.Opcode2).c_str()) + "] " +
				"[" + packet.Length.ToString() + " bytes]\n");

		std::string printedText = "";

		int i, j;
		for (i = 0; i < packet.Length; i += 16) {
			printedText += SnifferNameSpace::LoggerClass::string_format("%06x: ", i);
			for (j = 0; j < 16; j++)
				if (i + j < packet.Length) {
					printedText += SnifferNameSpace::LoggerClass::string_format("%02x ", packet.Data[i + j]);
				}
				else {
					printedText += SnifferNameSpace::LoggerClass::string_format("   ");
				}
			printedText += SnifferNameSpace::LoggerClass::string_format("        ");

			for (j = 0; j < 16; j++)
				if (i + j < packet.Length) {
					printedText += SnifferNameSpace::LoggerClass::string_format("%c", isprint(packet.Data[i + j]) ? packet.Data[i + j] : '.');
				}
			printedText += SnifferNameSpace::LoggerClass::string_format("\n");
		}

		printedText += "\n";

		this->rtb_packets->AppendText(gcnew String(printedText.c_str()));

		if (this->chkBox_autoScroll->Checked) {
			this->rtb_packets->SelectionStart = this->rtb_packets->Text->Length;
			this->rtb_packets->ScrollToCaret();
		}
	}
	private: System::Void Sniffer_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		e->Cancel = true;
		this->WindowState = FormWindowState::Minimized;
	}
};
}
