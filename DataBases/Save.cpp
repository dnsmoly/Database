#include "Save.h"
#include "MainForm.h"
#include "DataMenu.h"


System::Void DataBases::Save::���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MainForm^ form = gcnew MainForm();
	this->Hide();
	form->Show();
}

System::Void DataBases::Save::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
}

System::Void DataBases::Save::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void DataBases::Save::Submit_Click(System::Object^ sender, System::EventArgs^ e)
{

	std::string name;
	std::string old;
	ConvertTostring(textBox1->Text->ToString(), name);
	ConvertTostring(filename, old);
	if (std::ifstream(name)) {
		if (old == name) {
			handler->fixFile();
			handler->fillTables();
			MessageBox::Show("���� ��������", "���");
			this->Hide();
		}
		else {
			MessageBox::Show("���� � ����� ������ ��� ����������", "������");
		}
	}
	else {
		handler->fixFile();
		handler->fillTables();
		if (name != old) std::rename(old.c_str(), name.c_str());
		handler->changeFileName(name);
		MessageBox::Show("���� ��������", "���");
		this->Hide();
	}

}
