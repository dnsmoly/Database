#include <fstream>
#include <string>

#include "ShowResults.h"
#include "Func.h"


System::Void DataBases::ShowResults::ShowResults_Shown(System::Object^ sender, System::EventArgs^ e)
{
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();

	Header();

	dataGridView1->RowCount = handler->rowCount + 1;
	dataGridView1->ColumnCount = 5;

	Show();

	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView1->AutoResizeColumns();

	return System::Void();
}

System::Void DataBases::ShowResults::ok_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
}

void DataBases::ShowResults::Header()
{
	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Name = "ID";
	c1->HeaderText = "ID";
	c1->Width = 150;
	dataGridView1->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Name = "Name";
	c2->HeaderText = "Имя";
	c2->Width = 150;
	dataGridView1->Columns->Add(c2);

	DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
	c3->Name = "Lastname";
	c3->HeaderText = "Фамилия";
	c3->Width = 150;
	dataGridView1->Columns->Add(c3);

	DataGridViewTextBoxColumn^ c4 = gcnew DataGridViewTextBoxColumn();
	c4->Name = "Sum";
	c4->HeaderText = "Сумма заказа";
	c4->Width = 150;
	dataGridView1->Columns->Add(c4);

	DataGridViewTextBoxColumn^ c5 = gcnew DataGridViewTextBoxColumn();
	c5->Name = "Payed";
	c5->HeaderText = "Оплачено";
	c5->Width = 150;
	dataGridView1->Columns->Add(c5);

	dataGridView1->TopLeftHeaderCell->Value = "Данные";
	dataGridView1->AutoResizeColumns();
}

void DataBases::ShowResults::Show()
{
	std::fstream filestream;
	filestream.open("tmp.txt");
	std::string buff;

	for (int i = 0; i < dataGridView1->RowCount - 1; i++) {
		dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);

		getline(filestream, buff);
		dataGridView1->Rows[i]->Cells[0]->Value = ConvertToString(buff);
		getline(filestream, buff);
		dataGridView1->Rows[i]->Cells[1]->Value = ConvertToString(buff);
		getline(filestream, buff);
		dataGridView1->Rows[i]->Cells[2]->Value = ConvertToString(buff);
		getline(filestream, buff);
		dataGridView1->Rows[i]->Cells[3]->Value = ConvertToString(buff);
		getline(filestream, buff);
		if (buff == "1") dataGridView1->Rows[i]->Cells[4]->Value = "Да";
		else dataGridView1->Rows[i]->Cells[4]->Value = "Нет";
	}
}
