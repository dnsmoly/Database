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
	/// Сводка для SearchForm
	/// </summary>
	public ref class SearchForm : public System::Windows::Forms::Form
	{
	public:
		SearchForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		SearchForm(String^ filename, DataHandler* handler)
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
		~SearchForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ combo;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ text;

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
			this->text = (gcnew System::Windows::Forms::TextBox());
			this->combo = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Submit = (gcnew System::Windows::Forms::Button());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->text);
			this->groupBox1->Controls->Add(this->combo);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(361, 125);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Найти запись";
			// 
			// text
			// 
			this->text->Location = System::Drawing::Point(171, 78);
			this->text->Name = L"text";
			this->text->Size = System::Drawing::Size(121, 20);
			this->text->TabIndex = 2;
			// 
			// combo
			// 
			this->combo->FormattingEnabled = true;
			this->combo->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"ID", L"Имя", L"Фамилия", L"Сумма заказа", L"Оплачено" });
			this->combo->Location = System::Drawing::Point(171, 35);
			this->combo->Name = L"combo";
			this->combo->Size = System::Drawing::Size(121, 21);
			this->combo->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(21, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Введите значение";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(21, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите поле";
			// 
			// Submit
			// 
			this->Submit->Location = System::Drawing::Point(298, 146);
			this->Submit->Name = L"Submit";
			this->Submit->Size = System::Drawing::Size(75, 23);
			this->Submit->TabIndex = 1;
			this->Submit->Text = L"Submit";
			this->Submit->UseVisualStyleBackColor = true;
			this->Submit->Click += gcnew System::EventHandler(this, &SearchForm::Submit_Click);
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(217, 146);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(75, 23);
			this->Cancel->TabIndex = 1;
			this->Cancel->Text = L"Cancel";
			this->Cancel->UseVisualStyleBackColor = true;
			this->Cancel->Click += gcnew System::EventHandler(this, &SearchForm::Cancel_Click);
			// 
			// SearchForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 181);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->Submit);
			this->Controls->Add(this->groupBox1);
			this->Name = L"SearchForm";
			this->Text = L"SearchForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Cancel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Submit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
