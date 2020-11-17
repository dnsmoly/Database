#pragma once

#include "DataHandler.h"

namespace DataBases {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AddEntry
	/// </summary>
	public ref class AddEntry : public System::Windows::Forms::Form
	{
	public:
		AddEntry(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		AddEntry(String^ filename, DataHandler* handler)
		{
			InitializeComponent();
			this->handler = handler;
			this->filename = filename;
		}

	private: DataHandler* handler;
	private: String^ filename;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddEntry()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::CheckBox^ checkBox_payed;

	private: System::Windows::Forms::TextBox^ text_sum;

	private: System::Windows::Forms::TextBox^ text_lastname;

	private: System::Windows::Forms::TextBox^ text_name;
	private: System::Windows::Forms::TextBox^ text_id;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ Submit;
	private: System::Windows::Forms::Button^ Cancel;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_payed = (gcnew System::Windows::Forms::CheckBox());
			this->text_sum = (gcnew System::Windows::Forms::TextBox());
			this->text_lastname = (gcnew System::Windows::Forms::TextBox());
			this->text_name = (gcnew System::Windows::Forms::TextBox());
			this->text_id = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Submit = (gcnew System::Windows::Forms::Button());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox_payed);
			this->groupBox1->Controls->Add(this->text_sum);
			this->groupBox1->Controls->Add(this->text_lastname);
			this->groupBox1->Controls->Add(this->text_name);
			this->groupBox1->Controls->Add(this->text_id);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(234, 214);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Данные записи";
			// 
			// checkBox_payed
			// 
			this->checkBox_payed->AutoSize = true;
			this->checkBox_payed->Location = System::Drawing::Point(95, 171);
			this->checkBox_payed->Name = L"checkBox_payed";
			this->checkBox_payed->Size = System::Drawing::Size(15, 14);
			this->checkBox_payed->TabIndex = 2;
			this->checkBox_payed->UseVisualStyleBackColor = true;
			// 
			// text_sum
			// 
			this->text_sum->Location = System::Drawing::Point(95, 133);
			this->text_sum->Name = L"text_sum";
			this->text_sum->Size = System::Drawing::Size(127, 20);
			this->text_sum->TabIndex = 1;
			// 
			// text_lastname
			// 
			this->text_lastname->Location = System::Drawing::Point(95, 97);
			this->text_lastname->Name = L"text_lastname";
			this->text_lastname->Size = System::Drawing::Size(127, 20);
			this->text_lastname->TabIndex = 1;
			// 
			// text_name
			// 
			this->text_name->Location = System::Drawing::Point(95, 60);
			this->text_name->Name = L"text_name";
			this->text_name->Size = System::Drawing::Size(127, 20);
			this->text_name->TabIndex = 1;
			// 
			// text_id
			// 
			this->text_id->Location = System::Drawing::Point(95, 27);
			this->text_id->Name = L"text_id";
			this->text_id->Size = System::Drawing::Size(127, 20);
			this->text_id->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(6, 170);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 15);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Оплачено\?";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(6, 133);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 15);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Сумма заказа";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 15);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Фамилия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Имя";
			// 
			// Submit
			// 
			this->Submit->Location = System::Drawing::Point(176, 245);
			this->Submit->Name = L"Submit";
			this->Submit->Size = System::Drawing::Size(75, 23);
			this->Submit->TabIndex = 2;
			this->Submit->Text = L"Submit";
			this->Submit->UseVisualStyleBackColor = true;
			this->Submit->Click += gcnew System::EventHandler(this, &AddEntry::Submit_Click);
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(95, 245);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(75, 23);
			this->Cancel->TabIndex = 2;
			this->Cancel->Text = L"Cancel";
			this->Cancel->UseVisualStyleBackColor = true;
			this->Cancel->Click += gcnew System::EventHandler(this, &AddEntry::Cancel_Click);
			// 
			// AddEntry
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(263, 280);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->Submit);
			this->Controls->Add(this->groupBox1);
			this->Name = L"AddEntry";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddEntry";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Submit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
