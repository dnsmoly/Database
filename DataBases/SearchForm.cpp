#include "SearchForm.h"
#include "DataMenu.h"
#include "Func.h"
#include "ShowResults.h"

System::Void DataBases::SearchForm::Cancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
}

System::Void DataBases::SearchForm::Submit_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string item;
	std::string field;
	ConvertTostring(text->Text->ToString(), item);
	ConvertTostring(combo->Text->ToString(), field);
	unsigned int start_time = clock();
	
	std::vector<int> items = handler->find(field, item);
	unsigned int end_time = clock();
	unsigned int fin_time = end_time - start_time;
	MessageBox::Show(fin_time.ToString(), "time");
	if (items.size() < 1) {
		MessageBox::Show("Данные не обнаружены", "Ошибка");
	}
	else {
		handler->rowCount = items.size();
		handler->writeTmp(items);
		ShowResults^ form = gcnew ShowResults(handler);
		form->Show();
	}
	
}
