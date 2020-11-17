#include "Edit.h"

System::Void DataBases::Edit::Submit_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string oldid;
	ConvertTostring(OldID->Text->ToString(), oldid);
	std::vector<int> items = handler->find("ID", oldid);
	if (items.size() < 1) {
		MessageBox::Show("Данные не обнаружены", "Ошибка");
	}
	else {
		handler->remove(items);
	}


	if (NewID->Text->Length == 0 |
		NameText->Text->Length == 0 |
		LastName->Text->Length == 0 |
		Sum->Text->Length == 0) {
		MessageBox::Show("Неверно введены данные", "Ошибка");
	}
	else {
		std::string sid;
		std::string sname;
		std::string slastname;
		std::string ssum;
		ConvertTostring(NewID->Text->ToString(), sid);
		ConvertTostring(NameText->Text->ToString(), sname);
		ConvertTostring(LastName->Text->ToString(), slastname);
		ConvertTostring(Sum->Text->ToString(), ssum);
		if (handler->addEntry(sid, sname, slastname, ssum, Payed->Checked)) {
			MessageBox::Show("Запись заменена", "Ура!");
			this->Hide();
		}
	}
}

System::Void DataBases::Edit::Cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
}
