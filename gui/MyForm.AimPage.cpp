#include "MyForm.h"
namespace gui {
void MyForm::BuildAimPage()
{
 auto resources = gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid);
			//
			// tabPage1
			//
			this->tabPage1->Controls->Add(this->checkBox21);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(572, 373);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"AIM";
			this->tabPage1->UseVisualStyleBackColor = true;
			//
			// checkBox21
			//
			this->checkBox21->AutoSize = true;
			this->checkBox21->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox21->Location = System::Drawing::Point(294, 338);
			this->checkBox21->Name = L"checkBox21";
			this->checkBox21->Size = System::Drawing::Size(82, 17);
			this->checkBox21->TabIndex = 3;
			this->checkBox21->Text = L"No Recoil";
			this->checkBox21->UseVisualStyleBackColor = true;
			this->checkBox21->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox21_CheckedChanged);
			//
			// groupBox2
			//
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Controls->Add(this->checkBox2);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox2->Location = System::Drawing::Point(294, 17);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 294);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Triggerbot";
			//
			// label15
			//
			this->label15->ForeColor = System::Drawing::Color::Gainsboro;
			this->label15->Location = System::Drawing::Point(-14, 106);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(100, 25);
			this->label15->TabIndex = 23;
			this->label15->Text = L"Fire On Key";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// comboBox2
			//
			this->comboBox2->ForeColor = System::Drawing::Color::Gainsboro;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Mouse Right Click", L"Mouse Left Click", L"Middle Mouse Click",
					L"Control", L"Alter", L"Up", L"Down", L"Left", L"Right"
			});
			this->comboBox2->Location = System::Drawing::Point(6, 134);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 10;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			//
			// label9
			//
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::Gainsboro;
			this->label9->Location = System::Drawing::Point(157, 225);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(14, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"0";
			//
			// label7
			//
			this->label7->ForeColor = System::Drawing::Color::Gainsboro;
			this->label7->Location = System::Drawing::Point(6, 193);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(64, 29);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Delay(ms)";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// trackBar1
			//
			this->trackBar1->Location = System::Drawing::Point(93, 193);
			this->trackBar1->Maximum = 500;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(149, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			//
			// checkBox2
			//
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox2->Location = System::Drawing::Point(8, 76);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(77, 17);
			this->checkBox2->TabIndex = 4;
			this->checkBox2->Text = L"Auto Fire";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			//
			// checkBox1
			//
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox1->Location = System::Drawing::Point(8, 30);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(62, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Active";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			//
			// groupBox1
			//
			this->groupBox1->Controls->Add(this->groupBox5);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->trackBar3);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->trackBar2);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->checkBox9);
			this->groupBox1->Controls->Add(this->comboBox4);
			this->groupBox1->Controls->Add(this->checkBox6);
			this->groupBox1->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox1->Location = System::Drawing::Point(18, 17);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(256, 349);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Aimbot";
			//
			// groupBox5
			//
			this->groupBox5->Controls->Add(this->radioButton4);
			this->groupBox5->Controls->Add(this->radioButton3);
			this->groupBox5->Controls->Add(this->radioButton2);
			this->groupBox5->Controls->Add(this->radioButton1);
			this->groupBox5->ForeColor = System::Drawing::Color::Gainsboro;
			this->groupBox5->Location = System::Drawing::Point(9, 273);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(216, 70);
			this->groupBox5->TabIndex = 23;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Aim Lock";
			this->groupBox5->Enter += gcnew System::EventHandler(this, &MyForm::groupBox5_Enter);
			//
			// radioButton4
			//
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(103, 53);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(71, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Random";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			//
			// radioButton3
			//
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(103, 26);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(74, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Stomach";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			//
			// radioButton2
			//
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(30, 48);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(57, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Chest";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			//
			// radioButton1
			//
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(30, 25);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(55, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Head";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			//
			// label14
			//
			this->label14->ForeColor = System::Drawing::Color::Gainsboro;
			this->label14->Location = System::Drawing::Point(-3, 106);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(100, 25);
			this->label14->TabIndex = 22;
			this->label14->Text = L"Fire On Key";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// label12
			//
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::Gainsboro;
			this->label12->Location = System::Drawing::Point(135, 252);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(14, 13);
			this->label12->TabIndex = 20;
			this->label12->Text = L"1";
			//
			// trackBar3
			//
			this->trackBar3->Location = System::Drawing::Point(76, 225);
			this->trackBar3->Maximum = 50;
			this->trackBar3->Minimum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(149, 45);
			this->trackBar3->TabIndex = 17;
			this->trackBar3->Value = 1;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar3_Scroll);
			//
			// label11
			//
			this->label11->ForeColor = System::Drawing::Color::Gainsboro;
			this->label11->Location = System::Drawing::Point(6, 236);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(64, 29);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Smooth";
			//
			// label10
			//
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::Gainsboro;
			this->label10->Location = System::Drawing::Point(135, 209);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"1";
			//
			// trackBar2
			//
			this->trackBar2->Location = System::Drawing::Point(76, 174);
			this->trackBar2->Maximum = 360;
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(149, 45);
			this->trackBar2->TabIndex = 14;
			this->trackBar2->Value = 1;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			//
			// label8
			//
			this->label8->ForeColor = System::Drawing::Color::Gainsboro;
			this->label8->Location = System::Drawing::Point(6, 177);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 29);
			this->label8->TabIndex = 13;
			this->label8->Text = L"FOV";
			//
			// checkBox9
			//
			this->checkBox9->AutoSize = true;
			this->checkBox9->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox9->Location = System::Drawing::Point(15, 76);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(77, 17);
			this->checkBox9->TabIndex = 12;
			this->checkBox9->Text = L"Auto Fire";
			this->checkBox9->UseVisualStyleBackColor = true;
			this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox9_CheckedChanged);
			//
			// comboBox4
			//
			this->comboBox4->ForeColor = System::Drawing::Color::Gainsboro;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"Mouse Right Click", L"Mouse Left Click", L"Middle Mouse Click",
					L"Control", L"Alter", L"Up", L"Down", L"Left", L"Right"
			});
			this->comboBox4->Location = System::Drawing::Point(15, 134);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 21);
			this->comboBox4->TabIndex = 11;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox4_SelectedIndexChanged_1);
			//
			// checkBox6
			//
			this->checkBox6->AutoSize = true;
			this->checkBox6->ForeColor = System::Drawing::Color::Gainsboro;
			this->checkBox6->Location = System::Drawing::Point(15, 30);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(62, 17);
			this->checkBox6->TabIndex = 3;
			this->checkBox6->Text = L"Active";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
}
}
