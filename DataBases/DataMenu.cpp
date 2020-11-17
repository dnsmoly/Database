#include "DataMenu.h"
#include "Create.h"
#include "Open.h"
#include "Save.h"
#include "AddEntry.h"
#include "SearchForm.h"
#include "DeleteForm.h"
#include"Edit.h"
#include "MainForm.h"

System::Void DataBases::DataMenu::�������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	Open^ form = gcnew Open();
	this->Hide();
	form->Show();
}

System::Void DataBases::DataMenu::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Create^ form = gcnew Create();
	this->Hide();
	form->Show();
}

System::Void DataBases::DataMenu::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Save^ form = gcnew Save(filename, handler);
	form->Show();
}

System::Void DataBases::DataMenu::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddEntry^ form = gcnew AddEntry(filename, handler);
	form->Show();
}

System::Void DataBases::DataMenu::Change_Click(System::Object^ sender, System::EventArgs^ e)
{
	Edit^ form = gcnew Edit(filename, handler);
	form->Show();
}

System::Void DataBases::DataMenu::Search_Click(System::Object^ sender, System::EventArgs^ e)
{
	SearchForm^ form = gcnew SearchForm(filename, handler);
	form->Show();
}

System::Void DataBases::DataMenu::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	DeleteForm^ form = gcnew DeleteForm(filename, handler);
	form->Show();
}

System::Void DataBases::DataMenu::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DataBases::DataMenu::��������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	handler->clear();
	MessageBox::Show("�� �������", "���");
}

System::Void DataBases::DataMenu::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::remove(handler->getFilename().c_str());
	MessageBox::Show("���� ������", "���");
	MainForm^ form = gcnew MainForm();
	this->Hide();
	form->Show();
}
