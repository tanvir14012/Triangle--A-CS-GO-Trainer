#include "MyForm.h"
#include <Windows.h>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	bool smokeTest = Array::IndexOf(Environment::GetCommandLineArgs(), "--smoke-test") >= 0;
	gui::MyForm^ myForm = gcnew gui::MyForm(!smokeTest);
	if (smokeTest) {
		myForm->Show();
		Application::DoEvents();
		auto tabs = safe_cast<TabControl^>(myForm->Controls->Find("tabControl1", true)[0]);
		for (int i = 0; i < tabs->TabCount; ++i) {
			tabs->SelectedIndex = i;
			Application::DoEvents();
			auto bitmap = gcnew System::Drawing::Bitmap(myForm->Width, myForm->Height);
			myForm->DrawToBitmap(bitmap, System::Drawing::Rectangle(0, 0, bitmap->Width, bitmap->Height));
			bitmap->Save(System::IO::Path::Combine(Application::StartupPath, "smoke-" + i + ".png"));
			delete bitmap;
		}
		delete myForm;
		return 0;
	}
	myForm->AttachToGame();
	Application::Run(myForm);
	Application::Exit();
	Environment::Exit(Environment::ExitCode);
	return 0;
}

