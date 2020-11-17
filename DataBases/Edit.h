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
	/// Сводка для Edit
	/// </summary>
	public ref class Edit : public System::Windows::Forms::Form
	{
	public:
		Edit(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Edit(String^ filename, DataHandler* handler)
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
		~Edit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^ OldID;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::CheckBox^ Payed;
	private: System::Windows::Forms::TextBox^ Sum;
	private: System::Windows::Forms::TextBox^ LastName;
	private: System::Windows::Forms::TextBox^ NameText;

	private: System::Windows::Forms::TextBox^ NewID;
	private: System::Windows::Forms::Label^ label6;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->OldID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Payed = (gcnew System::Windows::Forms::CheckBox());
			this->Sum = (gcnew System::Windows::Forms::TextBox());
			this->LastName = (gcnew System::Windows::Forms::TextBox());
			this->NameText = (gcnew System::Windows::Forms::TextBox());
			this->NewID = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Submit = (gcnew System::Windows::Forms::Button());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->OldID);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(304, 63);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Редактировать поле";
			// 
			// OldID
			// 
			this->OldID->Location = System::Drawing::Point(98, 27);
			this->OldID->Name = L"OldID";
			this->OldID->Size = System::Drawing::Size(100, 20);
			this->OldID->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ведите ID";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Payed);
			this->groupBox2->Controls->Add(this->Sum);
			this->groupBox2->Controls->Add(this->LastName);
			this->groupBox2->Controls->Add(this->NameText);
			this->groupBox2->Controls->Add(this->NewID);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(13, 82);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(303, 193);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Введите новые данные";
			// 
			// Payed
			// 
			this->Payed->AutoSize = true;
			this->Payed->Location = System::Drawing::Point(97, 158);
			this->Payed->Name = L"Payed";
			this->Payed->Size = System::Drawing::Size(15, 14);
			this->Payed->TabIndex = 2;
			this->Payed->UseVisualStyleBackColor = true;
			// 
			// Sum
			// 
			this->Sum->Location = System::Drawing::Point(97, 128);
			this->Sum->Name = L"Sum";
			this->Sum->Size = System::Drawing::Size(100, 20);
			this->Sum->TabIndex = 1;
			// 
			// LastName
			// 
			this->LastName->Location = System::Drawing::Point(97, 97);
			this->LastName->Name = L"LastName";
			this->LastName->Size = System::Drawing::Size(100, 20);
			this->LastName->TabIndex = 1;
			// 
			// NameText
			// 
			this->NameText->Location = System::Drawing::Point(97, 67);
			this->NameText->Name = L"NameText";
			this->NameText->Size = System::Drawing::Size(100, 20);
			this->NameText->TabIndex = 1;
			// 
			// NewID
			// 
			this->NewID->Location = System::Drawing::Point(97, 37);
			this->NewID->Name = L"NewID";
			this->NewID->Size = System::Drawing::Size(100, 20);
			this->NewID->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 158);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Оплачено";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Сумма";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 97);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Фамилия";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Имя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"ID";
			// 
			// Submit
			// 
			this->Submit->Location = System::Drawing::Point(241, 281);
			this->Submit->Name = L"Submit";
			this->Submit->Size = System::Drawing::Size(75, 23);
			this->Submit->TabIndex = 2;
			this->Submit->Text = L"Submit";
			this->Submit->UseVisualStyleBackColor = true;
			this->Submit->Click += gcnew System::EventHandler(this, &Edit::Submit_Click);
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(160, 281);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(75, 23);
			this->Cancel->TabIndex = 2;
			this->Cancel->Text = L"Cancel";
			this->Cancel->UseVisualStyleBackColor = true;
			this->Cancel->Click += gcnew System::EventHandler(this, &Edit::Cancel_Click);
			// 
			// Edit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(322, 312);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->Submit);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Edit";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Edit";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Submit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e);
};
}
