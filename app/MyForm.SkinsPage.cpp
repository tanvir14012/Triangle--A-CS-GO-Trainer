#include "MyForm.h"
namespace gui {
void MyForm::BuildSkinsPage()
{
 auto resources = gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);
			//
			// tabPage3
			//
			this->tabPage3->Controls->Add(this->groupBox8);
			this->tabPage3->Controls->Add(this->groupBox7);
			this->tabPage3->Controls->Add(this->groupBox6);
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(572, 373);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"SKIN CHANGER";
			this->tabPage3->UseVisualStyleBackColor = true;
			//
			// groupBox8
			//
			this->groupBox8->Controls->Add(this->label27);
			this->groupBox8->Controls->Add(this->textBox5);
			this->groupBox8->Controls->Add(this->label28);
			this->groupBox8->Controls->Add(this->textBox6);
			this->groupBox8->Controls->Add(this->checkBox11);
			this->groupBox8->Controls->Add(this->button7);
			this->groupBox8->Controls->Add(this->label21);
			this->groupBox8->Controls->Add(this->listBox5);
			this->groupBox8->Controls->Add(this->label22);
			this->groupBox8->Controls->Add(this->listBox6);
			this->groupBox8->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox8->Location = System::Drawing::Point(393, 27);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(162, 343);
			this->groupBox8->TabIndex = 2;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Gloves";
			//
			// label27
			//
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(83, 257);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(37, 13);
			this->label27->TabIndex = 19;
			this->label27->Text = L"Wear";
			//
			// textBox5
			//
			this->textBox5->Location = System::Drawing::Point(84, 273);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(64, 20);
			this->textBox5->TabIndex = 18;
			//
			// label28
			//
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(12, 257);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(65, 13);
			this->label28->TabIndex = 17;
			this->label28->Text = L"Name Tag";
			//
			// textBox6
			//
			this->textBox6->Location = System::Drawing::Point(13, 273);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(64, 20);
			this->textBox6->TabIndex = 16;
			//
			// checkBox11
			//
			this->checkBox11->AutoSize = true;
			this->checkBox11->Location = System::Drawing::Point(15, 237);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(82, 17);
			this->checkBox11->TabIndex = 15;
			this->checkBox11->Text = L"StatTrack";
			this->checkBox11->UseVisualStyleBackColor = true;
			//
			// button7
			//
			this->button7->Location = System::Drawing::Point(41, 303);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 34);
			this->button7->TabIndex = 14;
			this->button7->Text = L"Apply";
			this->button7->UseVisualStyleBackColor = true;
			//
			// label21
			//
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(12, 117);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(78, 13);
			this->label21->TabIndex = 13;
			this->label21->Text = L"Choose Skin";
			//
			// listBox5
			//
			this->listBox5->ForeColor = System::Drawing::Color::Gainsboro;
			this->listBox5->FormattingEnabled = true;
			this->listBox5->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"UPS-S", L"AK-47", L"M4A4", L"AWP" });
			this->listBox5->Location = System::Drawing::Point(15, 133);
			this->listBox5->Name = L"listBox5";
			this->listBox5->Size = System::Drawing::Size(135, 95);
			this->listBox5->TabIndex = 12;
			//
			// label22
			//
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(12, 16);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(35, 13);
			this->label22->TabIndex = 11;
			this->label22->Text = L"Type";
			//
			// listBox6
			//
			this->listBox6->ForeColor = System::Drawing::Color::Gainsboro;
			this->listBox6->FormattingEnabled = true;
			this->listBox6->Items->AddRange(gcnew cli::array< System::Object^  >(20) {
				L"UPS-S", L"AK-47", L"M4A4", L"AWP", L"UPS-S", L"AK-47",
					L"M4A4", L"AWP", L"UPS-S", L"AK-47", L"M4A4", L"AWP", L"UPS-S", L"AK-47", L"M4A4", L"AWP", L"UPS-S", L"AK-47", L"M4A4", L"AWP"
			});
			this->listBox6->Location = System::Drawing::Point(15, 32);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(135, 82);
			this->listBox6->TabIndex = 10;
			//
			// groupBox7
			//
			this->groupBox7->Controls->Add(this->label25);
			this->groupBox7->Controls->Add(this->textBox3);
			this->groupBox7->Controls->Add(this->label26);
			this->groupBox7->Controls->Add(this->textBox4);
			this->groupBox7->Controls->Add(this->checkBox10);
			this->groupBox7->Controls->Add(this->button6);
			this->groupBox7->Controls->Add(this->label19);
			this->groupBox7->Controls->Add(this->listBox3);
			this->groupBox7->Controls->Add(this->label20);
			this->groupBox7->Controls->Add(this->listBox4);
			this->groupBox7->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox7->Location = System::Drawing::Point(206, 27);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(167, 343);
			this->groupBox7->TabIndex = 1;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Knife";
			//
			// label25
			//
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(85, 257);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(37, 13);
			this->label25->TabIndex = 14;
			this->label25->Text = L"Wear";
			//
			// textBox3
			//
			this->textBox3->Location = System::Drawing::Point(86, 273);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(64, 20);
			this->textBox3->TabIndex = 13;
			//
			// label26
			//
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(14, 257);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(65, 13);
			this->label26->TabIndex = 12;
			this->label26->Text = L"Name Tag";
			//
			// textBox4
			//
			this->textBox4->Location = System::Drawing::Point(15, 273);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(64, 20);
			this->textBox4->TabIndex = 11;
			//
			// checkBox10
			//
			this->checkBox10->AutoSize = true;
			this->checkBox10->Location = System::Drawing::Point(17, 237);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(82, 17);
			this->checkBox10->TabIndex = 10;
			this->checkBox10->Text = L"StatTrack";
			this->checkBox10->UseVisualStyleBackColor = true;
			//
			// button6
			//
			this->button6->Location = System::Drawing::Point(43, 303);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 34);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Apply";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			//
			// label19
			//
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(14, 117);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(78, 13);
			this->label19->TabIndex = 8;
			this->label19->Text = L"Choose Skin";
			//
			// listBox3
			//
			this->listBox3->ForeColor = System::Drawing::Color::Gainsboro;
			this->listBox3->FormattingEnabled = true;
			this->listBox3->Location = System::Drawing::Point(17, 133);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(135, 95);
			this->listBox3->TabIndex = 7;
			//
			// label20
			//
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(14, 16);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(35, 13);
			this->label20->TabIndex = 6;
			this->label20->Text = L"Type";
			//
			// listBox4
			//
			this->listBox4->ForeColor = System::Drawing::Color::Gainsboro;
			this->listBox4->FormattingEnabled = true;
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"Bayonet", L"Flip", L"Gut", L"Karambit", L"M9 Bayonet",
					L"Huntsman", L"Falchion", L"Bowie", L"Butterfly", L"Push", L"Ursus", L"Gypsy Jackknife", L"Stiletto", L"Widowmaker"
			});
			this->listBox4->Location = System::Drawing::Point(17, 32);
			this->listBox4->Name = L"listBox4";
			this->listBox4->Size = System::Drawing::Size(135, 82);
			this->listBox4->TabIndex = 5;
			//
			// groupBox6
			//
			this->groupBox6->Controls->Add(this->label24);
			this->groupBox6->Controls->Add(this->textBox2);
			this->groupBox6->Controls->Add(this->label23);
			this->groupBox6->Controls->Add(this->textBox1);
			this->groupBox6->Controls->Add(this->button5);
			this->groupBox6->Controls->Add(this->label18);
			this->groupBox6->Controls->Add(this->listBox2);
			this->groupBox6->Controls->Add(this->label17);
			this->groupBox6->Controls->Add(this->listBox1);
			this->groupBox6->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox6->Location = System::Drawing::Point(18, 23);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(170, 343);
			this->groupBox6->TabIndex = 0;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Weapon";
			this->groupBox6->Enter += gcnew System::EventHandler(this, &MyForm::groupBox6_Enter);
			//
			// label24
			//
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(19, 222);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(76, 13);
			this->label24->TabIndex = 9;
			this->label24->Text = L"Search Skin";
			//
			// textBox2
			//
			this->textBox2->ForeColor = System::Drawing::Color::Gainsboro;
			this->textBox2->Location = System::Drawing::Point(20, 241);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(133, 20);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			//
			// label23
			//
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(17, 261);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(65, 13);
			this->label23->TabIndex = 7;
			this->label23->Text = L"Name Tag";
			//
			// textBox1
			//
			this->textBox1->Location = System::Drawing::Point(20, 277);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(135, 20);
			this->textBox1->TabIndex = 6;
			//
			// button5
			//
			this->button5->Location = System::Drawing::Point(44, 303);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 34);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Apply";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			//
			// label18
			//
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(17, 108);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(78, 13);
			this->label18->TabIndex = 3;
			this->label18->Text = L"Choose Skin";
			//
			// listBox2
			//
			this->listBox2->ForeColor = System::Drawing::Color::Gainsboro;
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(20, 124);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(135, 95);
			this->listBox2->TabIndex = 2;
			//
			// label17
			//
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(15, 20);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(35, 13);
			this->label17->TabIndex = 1;
			this->label17->Text = L"Type";
			//
			// listBox1
			//
			this->listBox1->ForeColor = System::Drawing::Color::Gainsboro;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(34) {
				L"Ak-47", L"AWP", L"SSG 08", L"M4A4", L"M4A1-S",
					L"FAMAS ", L"Galil AR", L"AUG ", L"SG 553", L"SCAR-20", L"G3SG1", L"Desert Eagle", L"USP-S", L"Glock-18 ", L"P2000", L"P250",
					L"Five-SeveN ", L"Tec-9 ", L"CZ75-Auto", L"Dual Berettas", L"R8 Revolver", L"MP9 ", L"MAC-10", L"PP-Bizon", L"MP7", L"UMP-45",
					L"P90", L"MP5-SD ", L"XM1014", L"Nova", L"MAG-7 ", L"Sawed-Off ", L"M249", L"Negev"
			});
			this->listBox1->Location = System::Drawing::Point(18, 36);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(135, 69);
			this->listBox1->TabIndex = 0;
}
}
