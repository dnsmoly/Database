#pragma once

namespace DataBases {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FileExistst
	/// </summary>
	public ref class FileExistst : public System::Windows::Forms::Form
	{
	public:
		FileExistst(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		FileExistst(String^ s) {
			InitializeComponent();
			filename = s;
		}

	private: String^ filename;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FileExistst()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ Yes;
	private: System::Windows::Forms::Button^ No;

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
			this->Yes = (gcnew System::Windows::Forms::Button());
			this->No = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(269, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Файл с таким именем уже существует. \r\nВсе равно создать файл\?";
			// 
			// Yes
			// 
			this->Yes->Location = System::Drawing::Point(306, 93);
			this->Yes->Name = L"Yes";
			this->Yes->Size = System::Drawing::Size(75, 23);
			this->Yes->TabIndex = 1;
			this->Yes->Text = L"Да";
			this->Yes->UseVisualStyleBackColor = true;
			this->Yes->Click += gcnew System::EventHandler(this, &FileExistst::Yes_Click);
			// 
			// No
			// 
			this->No->Location = System::Drawing::Point(225, 93);
			this->No->Name = L"No";
			this->No->Size = System::Drawing::Size(75, 23);
			this->No->TabIndex = 1;
			this->No->Text = L"Нет";
			this->No->UseVisualStyleBackColor = true;
			this->No->Click += gcnew System::EventHandler(this, &FileExistst::No_Click);
			// 
			// FileExistst
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(393, 128);
			this->Controls->Add(this->No);
			this->Controls->Add(this->Yes);
			this->Controls->Add(this->label1);
			this->Name = L"FileExistst";
			this->Text = L"FileExistst";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Yes_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void No_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
