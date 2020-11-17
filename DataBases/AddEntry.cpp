#include "AddEntry.h"
#include "DataMenu.h"
#include "DataHandler.h"

System::Void DataBases::AddEntry::Cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

System::Void DataBases::AddEntry::Submit_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (text_id->Text->Length == 0 |
		text_name->Text->Length == 0 |
		text_lastname->Text->Length == 0 |
		text_sum->Text->Length == 0) {
		MessageBox::Show("Неверно введены данные", "Ошибка");
	}
	else {
		std::string sid;
		std::string sname;
		std::string slastname;
		std::string ssum;
		ConvertTostring(text_id->Text->ToString(), sid);
		ConvertTostring(text_name->Text->ToString(), sname);
		ConvertTostring(text_lastname->Text->ToString(), slastname);
		ConvertTostring(text_sum->Text->ToString(), ssum);
		unsigned int start_time = clock();
		if (handler->addEntry(sid, sname, slastname, ssum, checkBox_payed->Checked)) {
			unsigned int end_time = clock();
			unsigned int fin_time = end_time - start_time;
			MessageBox::Show(fin_time.ToString(), "time");
			MessageBox::Show("Запись добавлена", "Ура!");
			this->Hide();
		}
	}
	
}
