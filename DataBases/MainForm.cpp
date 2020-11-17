#include "MainForm.h"
#include "Create.h"
#include "Open.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DataBases::MainForm form;
	Application::Run(% form);
}

System::Void DataBases::MainForm::âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DataBases::MainForm::ñîçäàòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Create^ form = gcnew Create();
	this->Hide();
	form->Show();
}

System::Void DataBases::MainForm::îòêğûòüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Open^ form = gcnew Open();
	this->Hide();
	form->Show();
}


System::Void DataBases::MainForm::aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Ïğèëîæåíèå áàçà äàííûõ", "About");
}
