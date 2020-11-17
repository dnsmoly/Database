#include <iostream>
#include <fstream>

#include "Create.h"
#include "DataMenu.h"
#include "FileExistst.h"
#include "MainForm.h"
#include "Func.h"



System::Void DataBases::Create::âåðíóòüñÿÂÃëàâíîåÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MainForm^ form = gcnew MainForm();
	this->Hide();
	form->Show();
}

System::Void DataBases::Create::âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DataBases::Create::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	MainForm^ form = gcnew MainForm();
	this->Hide();
	form->Show();
}

System::Void DataBases::Create::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string filename;
	ConvertTostring(FileName->Text->ToString(), filename);

	if (std::ifstream(filename)) {
		FileExistst^ form = gcnew FileExistst(FileName->Text->ToString());
		//FileExistst^ form = gcnew FileExistst();
		this->Hide();
		form->Show();
	}
	else {
		std::ofstream of;
		of.open(filename);
		of.close();
		DataMenu^ form = gcnew DataMenu(FileName->Text->ToString());
		//DataMenu^ form = gcnew DataMenu();
		this->Hide();
		form->Show();
	}
	
}
