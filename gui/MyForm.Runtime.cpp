#include "MyForm.h"
#include "Theme.h"
namespace gui {
MyForm::MyForm(bool startWorkers)
{
			InitializeComponent();
            Theme::Apply(this);
			comboBox2->SelectedIndex = 0;
			comboBox4->SelectedIndex = 0;
			radioButton4->Checked = true;
			PopulateSkinLists();
			if (!startWorkers) return;
			Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MyForm::UpdateGameStatusWorker));
			t->IsBackground = true;
            t->Start();
			backgroundWorker1->RunWorkerAsync();

		}

int MyForm::getKey(int index)
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

void MyForm::AttachToGame()
{
			Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MyForm::AttachToGameWorker));
			t->IsBackground = true;
            t->Start();

		}

void MyForm::AttachToGameWorker()
{
			while (!memory.Attach(L"Counter-Strike: Global Offensive", PROCESS_ALL_ACCESS)) {
				Sleep(1000); //"Counter-Strike: Global Offensive"
			}
			scanOffsets();
		}

void MyForm::UpdateGameStatusWorker()
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

void MyForm::PopulateSkinLists()
{
			//Skins
			for (int i = 0; i < _countof(skin_obj); i++)
			{
				listBox2->Items->Add(gcnew String(skin_obj[i].skin));
			}
			//Knife Skins
			for (int i = 0; i < _countof(knives_obj); i++)
			{
				listBox3->Items->Add(gcnew String(knives_obj[i].skin));
			}
		}

void MyForm::setText(System::String^ text)
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

MyForm::~MyForm()
{
			if (components)
			{
				delete components;
			}
		}
}
