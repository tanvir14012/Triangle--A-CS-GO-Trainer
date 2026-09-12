#include "MyForm.h"
namespace gui {
void MyForm::BuildMiscPage()
{
 auto resources = gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);
			//
			// tabPage4
			//
			this->tabPage4->Controls->Add(this->groupBox9);
			this->tabPage4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(572, 373);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"OTHERS";
			this->tabPage4->UseVisualStyleBackColor = true;
			//
			// groupBox9
			//
			this->groupBox9->Controls->Add(this->label29);
			this->groupBox9->Controls->Add(this->label6);
			this->groupBox9->Controls->Add(this->trackBar5);
			this->groupBox9->Controls->Add(this->button8);
			this->groupBox9->Controls->Add(this->pictureBox2);
			this->groupBox9->Controls->Add(this->textBox7);
			this->groupBox9->Controls->Add(this->label5);
			this->groupBox9->Controls->Add(this->checkBox4);
			this->groupBox9->Controls->Add(this->checkBox26);
			this->groupBox9->Controls->Add(this->checkBox24);
			this->groupBox9->Controls->Add(this->checkBox23);
			this->groupBox9->Controls->Add(this->checkBox22);
			this->groupBox9->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox9->Location = System::Drawing::Point(18, 22);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(518, 344);
			this->groupBox9->TabIndex = 0;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Miscellaneous";
			//
			// label29
			//
			this->label29->AutoSize = true;
			this->label29->ForeColor = System::Drawing::Color::Gainsboro;
			this->label29->Location = System::Drawing::Point(142, 267);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(14, 13);
			this->label29->TabIndex = 18;
			this->label29->Text = L"1";
			//
			// label6
			//
			this->label6->ForeColor = System::Drawing::Color::Gainsboro;
			this->label6->Location = System::Drawing::Point(27, 235);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(64, 29);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Delay(s)";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// trackBar5
			//
			this->trackBar5->Location = System::Drawing::Point(97, 235);
			this->trackBar5->Maximum = 25;
			this->trackBar5->Minimum = 1;
			this->trackBar5->Name = L"trackBar5";
			this->trackBar5->Size = System::Drawing::Size(113, 45);
			this->trackBar5->TabIndex = 16;
			this->trackBar5->Value = 1;
			this->trackBar5->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar5_Scroll);
			//
			// button8
			//
			this->button8->Location = System::Drawing::Point(283, 315);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(122, 23);
			this->button8->TabIndex = 15;
			this->button8->Text = L"Attatch\r\n";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			//
			// pictureBox2
			//
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(284, 80);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(216, 184);
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			//
			// textBox7
			//
			this->textBox7->ForeColor = System::Drawing::Color::Gainsboro;
			this->textBox7->Location = System::Drawing::Point(284, 282);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(216, 20);
			this->textBox7->TabIndex = 13;
			//
			// label5
			//
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(279, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 25);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Status";
			//
			// checkBox4
			//
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(17, 285);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(49, 17);
			this->checkBox4->TabIndex = 11;
			this->checkBox4->Text = L"AFK";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox4_CheckedChanged);
			//
			// checkBox26
			//
			this->checkBox26->AutoSize = true;
			this->checkBox26->Location = System::Drawing::Point(17, 209);
			this->checkBox26->Name = L"checkBox26";
			this->checkBox26->Size = System::Drawing::Size(79, 17);
			this->checkBox26->TabIndex = 10;
			this->checkBox26->Text = L"Fake Lag";
			this->checkBox26->UseVisualStyleBackColor = true;
			this->checkBox26->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox26_CheckedChanged);
			//
			// checkBox24
			//
			this->checkBox24->AutoSize = true;
			this->checkBox24->Location = System::Drawing::Point(20, 158);
			this->checkBox24->Name = L"checkBox24";
			this->checkBox24->Size = System::Drawing::Size(76, 17);
			this->checkBox24->TabIndex = 8;
			this->checkBox24->Text = L"No Flash";
			this->checkBox24->UseVisualStyleBackColor = true;
			this->checkBox24->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox24_CheckedChanged);
			//
			// checkBox23
			//
			this->checkBox23->AutoSize = true;
			this->checkBox23->Location = System::Drawing::Point(21, 102);
			this->checkBox23->Name = L"checkBox23";
			this->checkBox23->Size = System::Drawing::Size(135, 17);
			this->checkBox23->TabIndex = 7;
			this->checkBox23->Text = L"Auto Accept Match";
			this->checkBox23->UseVisualStyleBackColor = true;
			this->checkBox23->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox23_CheckedChanged);
			//
			// checkBox22
			//
			this->checkBox22->AutoSize = true;
			this->checkBox22->Location = System::Drawing::Point(21, 46);
			this->checkBox22->Name = L"checkBox22";
			this->checkBox22->Size = System::Drawing::Size(82, 17);
			this->checkBox22->TabIndex = 6;
			this->checkBox22->Text = L"Bunnyhop";
			this->checkBox22->UseVisualStyleBackColor = true;
			this->checkBox22->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox22_CheckedChanged);
			//
			// backgroundWorker1
			//
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
}
}
