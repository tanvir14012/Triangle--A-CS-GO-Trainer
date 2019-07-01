#include "MyForm.h"
#include <Windows.h>
using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	gui::MyForm^ myForm = gcnew gui::MyForm();
	myForm->attatch();
	Application::Run(myForm);
	Application::Exit();
	Environment::Exit(Environment::ExitCode);
	return 0;
}

