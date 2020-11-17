#include "DeleteForm.h"


System::Void DataBases::DeleteForm::Cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
}

System::Void DataBases::DeleteForm::Submit_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string item;
	std::string field;
	ConvertTostring(text->Text->ToString(), item);
	ConvertTostring(combo->Text->ToString(), field);

	unsigned int start_time = clock();

	std::vector<int> items = handler->find(field, item);
	if (items.size() < 1) {
		MessageBox::Show("Данные не обнаружены", "Ошибка");
	}
	else {
		handler->remove(items);
		unsigned int end_time = clock();
		unsigned int fin_time = end_time - start_time;
		MessageBox::Show(fin_time.ToString(), "time");
		MessageBox::Show("Элементы(ы) удален(ы)", "Ура");
		this->Hide();
	}
}
