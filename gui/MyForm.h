#pragma once
#include "Header.h"
#include "Offsets.h"
#include "SkinId.h"
#include "cheat.h"
namespace gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	/// Summary for MyForm
	struct aimUi
	{
		bool on = false;
		bool autoFire = false;
		int aimKeyIndex = 0;
		int fov = 1;
		int smooth = 1;
		int aimlock = 3;
		bool rcs = false;
	}aim_ui;
	struct triggerUI
	{
		bool on = false;
		bool autoFire = false;
		int aimKeyIndex = 0;
		int delay = 0;
	}trigger_ui;
	
	struct visualUI
	{
		bool glow_on = false;
		bool glow_friendly = false;
		myColor friendly_glow_color = { 0, 1, 0 };
		bool glow_enemy = false;
		myColor enemy_glow_color = { 1, 0, 0 };
		bool visibility_check = false;
		myColor visibility_check_color = { 1, 0.27, 0 };
		float alpha = 0.5;
		bool box_esp = false;
		myColor box_esp_color = { 0, 255, 255 };
		bool box_esp_friendly = false;
		bool box_esp_enemy = false;
		bool line_esp = false;
		bool item_esp = false;
		bool name_esp = false;
		bool radar_hack = false;
		bool health_esp = false;
	}visual_ui;

	struct misc
	{
		bool bunnyhop = false;
		bool autoAccept = false;
		bool noFlash = false;
		bool afk = false;
		bool fakeLag = false;
		int fakeLagDelay = 1;
	}misc_ui;
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Color currentColor = System::Drawing::Color::Blue;
	private: System::Windows::Forms::CheckBox^  checkBox21;
	public:
		Thread^ bunnyhopThread, ^autoAcceptThread, ^fakeLagThread;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TrackBar^  trackBar5;
	public:
			 MyForm(void)
		{
			InitializeComponent();
			comboBox2->SelectedIndex = 0;
			comboBox4->SelectedIndex = 0;
			radioButton4->Checked = true;
			listBoxAddSkins();
			Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MyForm::gameStatusThread));
			t->Start();
			backgroundWorker1->RunWorkerAsync();
			
		}
		int getKey(int index)
		{
			switch(index)
			{
				case 0: return VK_RBUTTON;
				case 1: return VK_LBUTTON;
				case 2: return VK_MBUTTON;
				case 3: return VK_CONTROL;
				case 4: return VK_MENU;
				case 5: return VK_UP;
				case 6: return VK_DOWN;
				case 7: return VK_LEFT;
				case 8: return VK_RIGHT;
				default: return VK_LBUTTON;
					
			}
		}
		 
		void attatch()
		{
			Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MyForm::attatchThread));
			t->Start();

		}
		void attatchThread()
		{
			while (!memory.Attach(L"Counter-Strike: Global Offensive", PROCESS_ALL_ACCESS)) {
				Sleep(1000); //"Counter-Strike: Global Offensive"
			}
			scanOffsets();
		}
		void gameStatusThread()
		{
			HWND hWnd;
			while (true)
			{
				hWnd = FindWindow(NULL, L"Counter-Strike: Global Offensive");
				if (hWnd != NULL)
				{
					this->setText("CS:GO is running");
				}
				else
				{
					this->setText("CS:GO is not running");
				}
				Sleep(5000);
			}
		}
		void listBoxAddSkins()
		{
			//Skins
			for (int i = 0; i < 651; i++)
			{
				listBox2->Items->Add(gcnew String(skin_obj[i].skin));
			}
			//Knife Skins
			for (int i = 0; i < 51; i++)
			{
				listBox3->Items->Add(gcnew String(knives_obj[i].skin));
			}
		}
	private:
		delegate void StringArgReturningVoidDelegate(System::String^ text);
		void setText(System::String^ text)
		{
			try {
				if (this->textBox7->InvokeRequired)
				{
					StringArgReturningVoidDelegate^ d = gcnew StringArgReturningVoidDelegate(this, &MyForm::setText);
					this->Invoke(d, gcnew array<System::Object^>{text});
				}
				else
				{
					textBox7->Text = text;
				}
			}
			catch (Exception^ e)
			{

			}
		}
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button8;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::Label^  label5;
			 //User definde
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::CheckBox^  checkBox1;

	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::CheckBox^  checkBox2;

	private: System::Windows::Forms::Label^  label9;



	private: System::Windows::Forms::ComboBox^  comboBox2;

	private: System::Windows::Forms::Label^  label12;


	private: System::Windows::Forms::TrackBar^  trackBar3;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckBox^  checkBox9;
	private: System::Windows::Forms::ComboBox^  comboBox4;


	private: System::Windows::Forms::CheckBox^  checkBox6;


	private: System::Windows::Forms::Label^  label15;

	private: System::Windows::Forms::Label^  label14;

	private: System::Windows::Forms::GroupBox^  groupBox4;

	private: System::Windows::Forms::CheckBox^  checkBox20;
	private: System::Windows::Forms::CheckBox^  checkBox19;
	private: System::Windows::Forms::CheckBox^  checkBox18;
	private: System::Windows::Forms::CheckBox^  checkBox17;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::CheckBox^  checkBox16;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckBox^  checkBox15;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TrackBar^  trackBar4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::CheckBox^  checkBox14;
	private: System::Windows::Forms::CheckBox^  checkBox13;
	private: System::Windows::Forms::CheckBox^  checkBox12;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::GroupBox^  groupBox5;
private: System::Windows::Forms::RadioButton^  radioButton4;
private: System::Windows::Forms::RadioButton^  radioButton3;
private: System::Windows::Forms::RadioButton^  radioButton2;
private: System::Windows::Forms::RadioButton^  radioButton1;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::ListBox^  listBox1;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::CheckBox^  checkBox11;
private: System::Windows::Forms::Button^  button7;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::ListBox^  listBox5;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::ListBox^  listBox6;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::TextBox^  textBox3;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::CheckBox^  checkBox10;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::ListBox^  listBox3;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::ListBox^  listBox4;


private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::TextBox^  textBox1;

private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::Label^  label17;

private: System::Windows::Forms::GroupBox^  groupBox9;



private: System::Windows::Forms::CheckBox^  checkBox26;

private: System::Windows::Forms::CheckBox^  checkBox24;
private: System::Windows::Forms::CheckBox^  checkBox23;
private: System::Windows::Forms::CheckBox^  checkBox22;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::CheckBox^  checkBox4;











	protected:

	protected:





	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox21 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox20 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar5 = (gcnew System::Windows::Forms::TrackBar());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox26 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox24 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox23 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox22 = (gcnew System::Windows::Forms::CheckBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(22, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 38);
			this->label1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(160, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 38);
			this->label2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(306, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 38);
			this->label3->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label4.Image")));
			this->label4->Location = System::Drawing::Point(449, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 38);
			this->label4->TabIndex = 3;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(3, 41);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->Padding = System::Drawing::Point(45, 3);
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(580, 399);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->checkBox21);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->checkBox21->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->groupBox2->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->groupBox2->Location = System::Drawing::Point(294, 17);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 294);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Triggerbot";
			// 
			// label15
			// 
			this->label15->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label15->Location = System::Drawing::Point(-14, 106);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(100, 25);
			this->label15->TabIndex = 23;
			this->label15->Text = L"Fire On Key";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox2
			// 
			this->comboBox2->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label9->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label9->Location = System::Drawing::Point(157, 225);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(14, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"0";
			// 
			// label7
			// 
			this->label7->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox2->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox1->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->groupBox1->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->groupBox5->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label14->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label12->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label11->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label11->Location = System::Drawing::Point(6, 236);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(64, 29);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Smooth";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label8->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label8->Location = System::Drawing::Point(6, 177);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 29);
			this->label8->TabIndex = 13;
			this->label8->Text = L"FOV";
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->comboBox4->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox6->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->checkBox6->Location = System::Drawing::Point(15, 30);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(62, 17);
			this->checkBox6->TabIndex = 3;
			this->checkBox6->Text = L"Active";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox6_CheckedChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->checkBox7->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox3->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox5->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox20->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox19->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->button4->BackColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox18->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox16->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox17->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label16->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox15->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label13->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox14->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox13->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->checkBox12->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->checkBox12->Location = System::Drawing::Point(44, 88);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(82, 17);
			this->checkBox12->TabIndex = 16;
			this->checkBox12->Text = L"Glow ESP";
			this->checkBox12->UseVisualStyleBackColor = true;
			this->checkBox12->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox12_CheckedChanged);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox8);
			this->tabPage3->Controls->Add(this->groupBox7);
			this->tabPage3->Controls->Add(this->groupBox6);
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->groupBox8->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->listBox5->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->listBox6->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->groupBox7->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->listBox3->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->listBox4->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->groupBox6->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->textBox2->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->listBox2->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->listBox1->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->groupBox9);
			this->tabPage4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->groupBox9->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->label29->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->label29->Location = System::Drawing::Point(142, 267);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(14, 13);
			this->label29->TabIndex = 18;
			this->label29->Text = L"1";
			// 
			// label6
			// 
			this->label6->ForeColor = System::Drawing::Color::LightSeaGreen;
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
			this->textBox7->ForeColor = System::Drawing::Color::LightSeaGreen;
			this->textBox7->Location = System::Drawing::Point(284, 282);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(216, 20);
			this->textBox7->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 441);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Triangle : A Trainer for CS:GO";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	label10->Text = System::Convert::ToString(trackBar2->Value);
	aim_ui.fov = System::Convert::ToInt32(trackBar2->Value);
}
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {
	label12->Text = System::Convert::ToString(trackBar3->Value);
	aim_ui.smooth = System::Convert::ToInt32(trackBar3->Value);
}
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
	label9->Text = System::Convert::ToString(trackBar1->Value);
	trigger_ui.delay = System::Convert::ToInt32(trackBar1->Value);
}
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e) {
	label16->Text = System::Convert::ToString(trackBar4->Value);
	visual_ui.alpha = (System::Convert::ToDouble(trackBar4->Value)) / 100;
}

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	button1->BackColor = currentColor;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	button2->BackColor = currentColor;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	button3->BackColor = currentColor;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	button4->BackColor = currentColor;
}
private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.on = checkBox6->Checked;
}
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	memory.Attach(L"Counter-Strike: Global Offensive", PROCESS_ALL_ACCESS);
	scanOffsets();
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	Aimbot aimbot;
	virtualesp glowEsp;
	DrawingESP drawingESP;
	while (true)
	{
		aimbot.startAimbot(aim_ui.on, aim_ui.autoFire, getKey(aim_ui.aimKeyIndex), aim_ui.fov, aim_ui.smooth, aim_ui.aimlock);
		aimbot.rcs(aim_ui.rcs);
		triggerbot(trigger_ui.on, trigger_ui.autoFire, getKey(trigger_ui.aimKeyIndex), trigger_ui.delay);
		glowEsp.esp_thread(visual_ui.glow_on, visual_ui.glow_friendly, visual_ui.friendly_glow_color, visual_ui.glow_enemy, visual_ui.enemy_glow_color, visual_ui.visibility_check, visual_ui.visibility_check_color, visual_ui.alpha);
		drawingESP.drawBox(visual_ui.box_esp, visual_ui.box_esp_friendly, visual_ui.box_esp_enemy, visual_ui.box_esp_color, visual_ui.line_esp, visual_ui.name_esp, visual_ui.health_esp, visual_ui.item_esp);
		radarHack(visual_ui.radar_hack);
		noFlash(misc_ui.noFlash);
		afk(misc_ui.afk);
		changeWeaponSkin();
		changeKnife();
		Sleep(1);
	}
}
private: System::Void checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.autoFire = checkBox9->Checked;
}

private: System::Void groupBox5_Enter(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.aimlock = (radioButton4->Enabled) ? 3 : aim_ui.aimlock;
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.aimlock = (radioButton1->Enabled) ? 0 : aim_ui.aimlock;
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.aimlock = (radioButton2->Enabled) ? 1 : aim_ui.aimlock;
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.aimlock = (radioButton3->Enabled) ? 2 : aim_ui.aimlock;
}
private: System::Void comboBox4_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.aimKeyIndex = comboBox4->SelectedIndex;
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	trigger_ui.on = checkBox1->Checked;
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	trigger_ui.autoFire = checkBox2->Checked;
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	trigger_ui.aimKeyIndex = comboBox2->SelectedIndex;
}

private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	System::Drawing::Bitmap^ btm = gcnew System::Drawing::Bitmap(pictureBox1->Image);
	currentColor = btm->GetPixel(e->X, e->Y);
	
}
private: System::Void checkBox12_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.glow_on = checkBox12->Checked;
}
private: System::Void checkBox13_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.glow_friendly = checkBox13->Checked;
}
private: System::Void button1_BackColorChanged(System::Object^  sender, System::EventArgs^  e) {
	myColor c = { System::Convert::ToDouble((button1->BackColor).R), System::Convert::ToDouble((button1->BackColor).G), System::Convert::ToDouble((button1->BackColor).B) };
	visual_ui.friendly_glow_color = { c.r / 255, c.g / 255, c.b / 255 };

}
private: System::Void checkBox14_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.glow_enemy = checkBox14->Checked;
}
private: System::Void button2_BackColorChanged(System::Object^  sender, System::EventArgs^  e) {
	myColor c = { System::Convert::ToDouble((button2->BackColor).R), System::Convert::ToDouble((button2->BackColor).G), System::Convert::ToDouble((button2->BackColor).B) };
	visual_ui.enemy_glow_color = { c.r / 255, c.g / 255, c.b / 255 };
}
private: System::Void checkBox15_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.visibility_check = checkBox15->Checked;
}
private: System::Void button3_BackColorChanged(System::Object^  sender, System::EventArgs^  e) {
	myColor c = { System::Convert::ToDouble((button3->BackColor).R), System::Convert::ToDouble((button3->BackColor).G), System::Convert::ToDouble((button3->BackColor).B) };
	visual_ui.visibility_check_color = { c.r / 255, c.g / 255, c.b / 255 };
}
private: System::Void checkBox16_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.box_esp = checkBox16->Checked;
}
private: System::Void button4_BackColorChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.box_esp_color = { System::Convert::ToDouble((button4->BackColor).R), System::Convert::ToDouble((button4->BackColor).G), System::Convert::ToDouble((button4->BackColor).B) };
}
private: System::Void checkBox17_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.name_esp = checkBox17->Checked;
}
private: System::Void checkBox18_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.health_esp = checkBox18->Checked;
}
private: System::Void checkBox19_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.item_esp = checkBox19->Checked;
}
private: System::Void checkBox20_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.line_esp = checkBox20->Checked;
}
private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.box_esp_friendly = checkBox5->Checked;
}
private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.box_esp_enemy = checkBox7->Checked;
}
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	visual_ui.radar_hack = checkBox3->Checked;
}
private: System::Void checkBox22_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	misc_ui.bunnyhop = checkBox22->Checked;
	if (misc_ui.bunnyhop)
	{
		bunnyhopThread = gcnew Thread(gcnew ThreadStart(&bunnyHop));
		bunnyhopThread->Start();
	}
	else
	{
		if (bunnyhopThread->IsAlive)
		{
			bunnyhopThread->Abort();
		}
	}
}
private: System::Void checkBox23_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	misc_ui.autoAccept = checkBox23->Checked;
	if (misc_ui.autoAccept)
	{
		autoAcceptThread = gcnew Thread(gcnew ThreadStart(&autoAcceptMatch));
		autoAcceptThread->Start();
	}
	else
	{
		if (autoAcceptThread->IsAlive)
		{
			autoAcceptThread->Abort();
		}
	}
}
private: System::Void checkBox24_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	misc_ui.noFlash = checkBox24->Checked;
}
private: System::Void checkBox26_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	misc_ui.fakeLag = checkBox26->Checked;
	if (misc_ui.fakeLag)
	{
		fakeLagThread = gcnew Thread( gcnew ParameterizedThreadStart( &fakeLag));
		fakeLagThread->Start(misc_ui.fakeLagDelay);
	}
	else
	{
		if (fakeLagThread->IsAlive)
		{
			fakeLagThread->Abort();
		}
	}
}
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	misc_ui.afk = checkBox4->Checked;
}
private: System::Void checkBox21_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	aim_ui.rcs = checkBox21->Checked;
}
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e) {
	label29->Text = System::Convert::ToString(trackBar5->Value);
	misc_ui.fakeLagDelay = trackBar5->Value;
	checkBox26->Checked = false;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (listBox1->SelectedIndex == -1 || listBox2->SelectedIndex == -1)
	{
		return;
	}
	switch (listBox1->SelectedIndex)
	{
	case 0:weapon_skin.Ak47 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 1:weapon_skin.AWP = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 2:weapon_skin.SSG08 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 3:weapon_skin.M4A4 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 4:weapon_skin.M4A1_S = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 5:weapon_skin.FAMAS = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 6:weapon_skin.GalilAR = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 7:weapon_skin.AUG = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 8:weapon_skin.SG553 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 9:weapon_skin.SCAR20 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 10:weapon_skin.G3SG1 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 11:weapon_skin.DesertEagle = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 12:weapon_skin.USP_S = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 13:weapon_skin.Glock18 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 14:weapon_skin.P2000 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 15:weapon_skin.P250 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 16:weapon_skin.FiveSeveN = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 17:weapon_skin.Tec9 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 18:weapon_skin.CZ75Auto = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 19:weapon_skin.DualBerettas = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 20:weapon_skin.R8Revolver = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 21:weapon_skin.MP9 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 22:weapon_skin.MAC10 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 23:weapon_skin.PPBizon = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 24:weapon_skin.MP7 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 25:weapon_skin.UMP45 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 26:weapon_skin.P90 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 27:weapon_skin.MP5SD = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 28:weapon_skin.XM1014 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 29:weapon_skin.Nova = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 30:weapon_skin.MAG7 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 31:weapon_skin.SawedOff = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 32:weapon_skin.M249 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 33:weapon_skin.Negev = skin_obj[listBox2->SelectedIndex].id;
		break;
	}
	changeWeaponSkin();
	memory.Write<int>(memory.Read<int>(getEnginedll(L"engine.dll") + dwClientState) + 0x174, -1);
}
private: System::Void groupBox6_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	String^ str = gcnew String("");
	for (int i = 0; i < listBox2->Items->Count; i++)
	{
		str = Convert::ToString(listBox2->Items[i]);
		if (str->Equals(textBox2->Text, StringComparison::CurrentCultureIgnoreCase))
		{
			listBox2->SelectedIndex = i;
			break;
		}
		else if (str->StartsWith(textBox2->Text, StringComparison::CurrentCultureIgnoreCase))
		{
			listBox2->SelectedIndex = i;
			break;
		}
	}
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	if (listBox4->SelectedIndex == -1 || listBox3->SelectedIndex == -1)
	{
		return;
	}
	switch (listBox4->SelectedIndex)
	{
	case 0: knife_info.knifeType = WEAPON_KNIFE_BAYONET;
		break;
	case 1: knife_info.knifeType = WEAPON_KNIFE_FLIP;
		break;
	case 2: knife_info.knifeType = WEAPON_KNIFE_GUT;
		break;
	case 3: knife_info.knifeType = WEAPON_KNIFE_KARAMBIT;
		break;
	case 4: knife_info.knifeType = WEAPON_KNIFE_M9_BAYONET;
		break;
	case 5: knife_info.knifeType = WEAPON_KNIFE_TACTICAL;
		break;
	case 6: knife_info.knifeType = WEAPON_KNIFE_FALCHION;
		break;
	case 7: knife_info.knifeType = WEAPON_KNIFE_SURVIVAL_BOWIE;
		break;
	case 8: knife_info.knifeType = WEAPON_KNIFE_BUTTERFLY;
		break;
	case 9: knife_info.knifeType = WEAPON_KNIFE_PUSH;
		break;
	case 10: knife_info.knifeType = WEAPON_KNIFE_URSUS;
		break;
	case 11: knife_info.knifeType = WEAPON_KNIFE_GYPSY_JACKKNIFE;
		break;
	case 12: knife_info.knifeType = WEAPON_KNIFE_STILETTO;
		break;
	case 13: knife_info.knifeType = WEAPON_KNIFE_WIDOWMAKER;
		break;
	}
	knife_info.knifeSkin = listBox3->SelectedIndex;
	changeKnife();
	memory.Write<int>(memory.Read<int>(getEnginedll(L"engine.dll") + dwClientState) + 0x174, -1);
}
};


}
