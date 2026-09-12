#pragma once
#include "Header.h"
#include "Offsets.h"
#include "SkinId.h"
#include "Trainer.h"
#include "UiSettings.h"
namespace gui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
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
			 MyForm(bool startWorkers);
		int getKey(int index);

		void AttachToGame();
		void AttachToGameWorker();
		void UpdateGameStatusWorker();
		void PopulateSkinLists();
	private:
		delegate void StringArgReturningVoidDelegate(System::String^ text);
		void setText(System::String^ text);
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  button8;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::Label^  label5;
			 // Form controls

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm();
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
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void);
void BuildAimPage();
void BuildVisualPage();
void BuildSkinsPage();
void BuildMiscPage();
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e);

private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e);

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e);
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
private: System::Void checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

private: System::Void groupBox5_Enter(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void comboBox4_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
private: System::Void checkBox12_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox13_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button1_BackColorChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox14_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button2_BackColorChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox15_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button3_BackColorChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox16_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button4_BackColorChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox17_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox18_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox19_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox20_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox22_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox23_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox24_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox26_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void checkBox21_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e);
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void groupBox6_Enter(System::Object^  sender, System::EventArgs^  e);
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e);
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
};

}
