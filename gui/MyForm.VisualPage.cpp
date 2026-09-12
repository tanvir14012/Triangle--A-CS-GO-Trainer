#include "MyForm.h"
namespace gui {
void MyForm::BuildVisualPage()
{
 auto resources = gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);
			//
			// tabPage2
			//
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(572, 373);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"VISUALS";
			this->tabPage2->UseVisualStyleBackColor = true;
			//
			// groupBox4
			//
			this->groupBox4->Controls->Add(this->checkBox7);
			this->groupBox4->Controls->Add(this->checkBox3);
			this->groupBox4->Controls->Add(this->checkBox5);
			this->groupBox4->Controls->Add(this->checkBox20);
			this->groupBox4->Controls->Add(this->checkBox19);
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->checkBox18);
			this->groupBox4->Controls->Add(this->checkBox16);
			this->groupBox4->Controls->Add(this->checkBox17);
			this->groupBox4->Location = System::Drawing::Point(317, 22);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(248, 341);
			this->groupBox4->TabIndex = 22;
			this->groupBox4->TabStop = false;
			//
			// checkBox7
			//
			this->checkBox7->AutoSize = true;
			this->checkBox7->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox7->Location = System::Drawing::Point(128, 19);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(63, 17);
			this->checkBox7->TabIndex = 31;
			this->checkBox7->Text = L"Enemy";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox7_CheckedChanged);
			//
			// checkBox3
			//
			this->checkBox3->AutoSize = true;
			this->checkBox3->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox3->Location = System::Drawing::Point(20, 296);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(94, 17);
			this->checkBox3->TabIndex = 25;
			this->checkBox3->Text = L"Radar Hack";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox3_CheckedChanged);
			//
			// checkBox5
			//
			this->checkBox5->AutoSize = true;
			this->checkBox5->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox5->Location = System::Drawing::Point(23, 19);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(70, 17);
			this->checkBox5->TabIndex = 30;
			this->checkBox5->Text = L"Friendly";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox5_CheckedChanged);
			//
			// checkBox20
			//
			this->checkBox20->AutoSize = true;
			this->checkBox20->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox20->Location = System::Drawing::Point(20, 254);
			this->checkBox20->Name = L"checkBox20";
			this->checkBox20->Size = System::Drawing::Size(78, 17);
			this->checkBox20->TabIndex = 24;
			this->checkBox20->Text = L"Line ESP";
			this->checkBox20->UseVisualStyleBackColor = true;
			this->checkBox20->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox20_CheckedChanged);
			//
			// checkBox19
			//
			this->checkBox19->AutoSize = true;
			this->checkBox19->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox19->Location = System::Drawing::Point(20, 216);
			this->checkBox19->Name = L"checkBox19";
			this->checkBox19->Size = System::Drawing::Size(101, 17);
			this->checkBox19->TabIndex = 23;
			this->checkBox19->Text = L"Weapon ESP";
			this->checkBox19->UseVisualStyleBackColor = true;
			this->checkBox19->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox19_CheckedChanged);
			//
			// button4
			//
			this->button4->BackColor = System::Drawing::Color::Gainsboro;
			this->button4->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button4->Location = System::Drawing::Point(37, 97);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(61, 23);
			this->button4->TabIndex = 27;
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->BackColorChanged += gcnew System::EventHandler(this, &MyForm::button4_BackColorChanged);
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			//
			// checkBox18
			//
			this->checkBox18->AutoSize = true;
			this->checkBox18->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox18->Location = System::Drawing::Point(22, 180);
			this->checkBox18->Name = L"checkBox18";
			this->checkBox18->Size = System::Drawing::Size(130, 17);
			this->checkBox18->TabIndex = 22;
			this->checkBox18->Text = L"Player Health ESP";
			this->checkBox18->UseVisualStyleBackColor = true;
			this->checkBox18->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox18_CheckedChanged);
			//
			// checkBox16
			//
			this->checkBox16->AutoSize = true;
			this->checkBox16->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox16->Location = System::Drawing::Point(23, 59);
			this->checkBox16->Name = L"checkBox16";
			this->checkBox16->Size = System::Drawing::Size(75, 17);
			this->checkBox16->TabIndex = 26;
			this->checkBox16->Text = L"Box ESP";
			this->checkBox16->UseVisualStyleBackColor = true;
			this->checkBox16->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox16_CheckedChanged);
			//
			// checkBox17
			//
			this->checkBox17->AutoSize = true;
			this->checkBox17->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox17->Location = System::Drawing::Point(22, 141);
			this->checkBox17->Name = L"checkBox17";
			this->checkBox17->Size = System::Drawing::Size(129, 17);
			this->checkBox17->TabIndex = 21;
			this->checkBox17->Text = L"Player Name  ESP";
			this->checkBox17->UseVisualStyleBackColor = true;
			this->checkBox17->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox17_CheckedChanged);
			//
			// groupBox3
			//
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->checkBox15);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->trackBar4);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Controls->Add(this->pictureBox1);
			this->groupBox3->Controls->Add(this->checkBox14);
			this->groupBox3->Controls->Add(this->checkBox13);
			this->groupBox3->Controls->Add(this->checkBox12);
			this->groupBox3->Location = System::Drawing::Point(18, 22);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(267, 344);
			this->groupBox3->TabIndex = 21;
			this->groupBox3->TabStop = false;
			//
			// label16
			//
			this->label16->AutoSize = true;
			this->label16->ForeColor = System::Drawing::Color::Gainsboro;
			this->label16->Location = System::Drawing::Point(184, 316);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(14, 13);
			this->label16->TabIndex = 28;
			this->label16->Text = L"1";
			//
			// button3
			//
			this->button3->BackColor = System::Drawing::Color::DarkOrange;
			this->button3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button3->Location = System::Drawing::Point(161, 229);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(61, 23);
			this->button3->TabIndex = 25;
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->BackColorChanged += gcnew System::EventHandler(this, &MyForm::button3_BackColorChanged);
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			//
			// checkBox15
			//
			this->checkBox15->AutoSize = true;
			this->checkBox15->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox15->Location = System::Drawing::Point(86, 206);
			this->checkBox15->Name = L"checkBox15";
			this->checkBox15->Size = System::Drawing::Size(112, 17);
			this->checkBox15->TabIndex = 24;
			this->checkBox15->Text = L"Visibility Check";
			this->checkBox15->UseVisualStyleBackColor = true;
			this->checkBox15->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox15_CheckedChanged);
			//
			// label13
			//
			this->label13->ForeColor = System::Drawing::Color::Gainsboro;
			this->label13->Location = System::Drawing::Point(83, 268);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 30);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Opacity";
			//
			// trackBar4
			//
			this->trackBar4->Location = System::Drawing::Point(161, 268);
			this->trackBar4->Maximum = 100;
			this->trackBar4->Minimum = 1;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(61, 45);
			this->trackBar4->TabIndex = 22;
			this->trackBar4->Value = 1;
			this->trackBar4->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar4_Scroll);
			//
			// button2
			//
			this->button2->BackColor = System::Drawing::Color::Red;
			this->button2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button2->Location = System::Drawing::Point(161, 163);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(61, 23);
			this->button2->TabIndex = 21;
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->BackColorChanged += gcnew System::EventHandler(this, &MyForm::button2_BackColorChanged);
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			//
			// button1
			//
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(162, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 23);
			this->button1->TabIndex = 20;
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->BackColorChanged += gcnew System::EventHandler(this, &MyForm::button1_BackColorChanged);
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			//
			// pictureBox1
			//
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(149, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(91, 86);
			this->pictureBox1->TabIndex = 29;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			//
			// checkBox14
			//
			this->checkBox14->AutoSize = true;
			this->checkBox14->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox14->Location = System::Drawing::Point(86, 163);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(63, 17);
			this->checkBox14->TabIndex = 18;
			this->checkBox14->Text = L"Enemy";
			this->checkBox14->UseVisualStyleBackColor = true;
			this->checkBox14->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox14_CheckedChanged);
			//
			// checkBox13
			//
			this->checkBox13->AutoSize = true;
			this->checkBox13->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox13->Location = System::Drawing::Point(86, 122);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(70, 17);
			this->checkBox13->TabIndex = 17;
			this->checkBox13->Text = L"Friendly";
			this->checkBox13->UseVisualStyleBackColor = true;
			this->checkBox13->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox13_CheckedChanged);
			//
			// checkBox12
			//
			this->checkBox12->AutoSize = true;
			this->checkBox12->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox12->Location = System::Drawing::Point(44, 88);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(82, 17);
			this->checkBox12->TabIndex = 16;
			this->checkBox12->Text = L"Glow ESP";
			this->checkBox12->UseVisualStyleBackColor = true;
			this->checkBox12->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox12_CheckedChanged);
}
}
