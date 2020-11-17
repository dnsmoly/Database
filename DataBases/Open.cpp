#include <iostream>
#include <fstream>

#include "Open.h"
#include "MainForm.h"
#include "DataMenu.h"
#include "FileExistst.h"
#include "Func.h"

System::Void DataBases::Open::âåðóíòüñÿÂÃëàâíîåÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MainForm^ form = gcnew MainForm();
	this->Hide();
	form->Show();
}

System::Void DataBases::Open::âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DataBases::Open::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	MainForm^ form = gcnew MainForm();
	this->Hide();
	form->Show();
}

System::Void DataBases::Open::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string filename;
	ConvertTostring(FileName->Text->ToString(), filename);

	if (!std::ifstream(filename)) {
		MessageBox::Show("Òàêîãî ôàéëà íå ñóùåñòâóåò", "Îøèáêà");
	}
	else {
		DataMenu^ form = gcnew DataMenu(FileName->Text->ToString());
		//DataMenu^ form = gcnew DataMenu();
		this->Hide();
		form->Show();
	}
}
