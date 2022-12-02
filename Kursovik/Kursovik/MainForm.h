#include <vector>
#include "Vishener.h"
#include "Resheto.h"
#include "Zabor.h"
#include "msclr\marshal_cppstd.h"
#include <vector>
#include <string.h>
#include <stdlib.h>

namespace Kursovik {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace msclr::interop;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button4;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(755, 9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(215, 70);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Открыть файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 48);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(700, 215);
			this->textBox1->TabIndex = 1;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(223, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(249, 36);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Исходный текст";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 321);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(700, 215);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(261, 282);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(165, 36);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Результат";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(740, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(240, 70);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Шифровать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(740, 161);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(240, 70);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Дешифровать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(755, 266);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(187, 44);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Железнодорожная\r\n       изгородь";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(755, 316);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(204, 44);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Поворачивающаяся \r\n          решётка ";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(755, 372);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(169, 24);
			this->radioButton3->TabIndex = 9;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Шифр Виженера";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton3_CheckedChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(779, 432);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(163, 23);
			this->textBox3->TabIndex = 10;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(750, 237);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 26);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Способы:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Yi Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(775, 409);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 20);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Ключ:";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(755, 471);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(215, 70);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Сохранить результат\r\n";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PaleTurquoise;
			this->ClientSize = System::Drawing::Size(982, 553);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"Шифратор/Дешифратор файлов";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ FileName = "";

		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			FileName = openFileDialog1->FileName;
		}

		try
		{
			StreamReader^ file = File::OpenText(FileName);
			textBox1->Text = file->ReadToEnd();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(this, "Не удалось открыть файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (radioButton1->Checked)
		{
			if (textBox3->Text == "" || textBox3->Text == "0")
			{
				MessageBox::Show(this, "Введите корректный ключ для данного метода", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				System::String^ keyname;
				keyname = textBox3->Text;
				string Key;
				Key = marshal_as<string>(keyname);
				System::String^ name;
				name = textBox1->Text;
				string result1;
				result1 = marshal_as<string>(name);
				result1 = EncryptZabor(result1, Key);
				System::String^ result2;
				result2 = marshal_as<String^>(result1);
				if (result2 == "Oshibka")
				{
					MessageBox::Show(this, "Введите ключ содержащий цифры больше нуля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					textBox2->Text = result2;
				}
			}
		}
		if (radioButton2->Checked)
		{
			{
				System::String^ name;
				name = textBox1->Text;
				string result1;
				result1 = marshal_as<string>(name);
				result1 = EncryptResheto(result1);
				String^ result2;
				result2 = marshal_as<String^>(result1);
				textBox2->Text = result2;
			}
		}
		if (radioButton3->Checked)
		{
			if(textBox3->Text == "")
			{
				MessageBox::Show(this, "Введите ключ для данного метода", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				System::String^ keyname;
				keyname = textBox3->Text;
				string Key;
				Key = marshal_as<string>(keyname);
				System::String^ name;
				name = textBox1->Text;
				string result1;
				result1 = marshal_as<string>(name);
				result1 = EncryptVishener(result1, Key);
				String^ result2;
				result2 = marshal_as<String^>(result1);
				if (result2 == "Oshibka")
				{
					MessageBox::Show(this, "Введите ключ содержащий буквы из русского алфавита", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else {
					textBox2->Text = result2;
				}
			}
		}
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton1->Checked)
	{
		System::String^ keyname;
		keyname = textBox3->Text;
		string Key;
		Key = marshal_as<string>(keyname);
		System::String^ name;
		name = textBox1->Text;
		string result1;
		result1 = marshal_as<string>(name);
		result1 = DecodeZabor(result1, Key);
		String^ result2;
		result2 = marshal_as<String^>(result1);
		if (result2 == "Oshibka")
		{
			MessageBox::Show(this, "Введите ключ содержащий цифры больше нуля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			textBox2->Text = result2;
		}
	}
	if (radioButton2->Checked)
	{
		{
			System::String^ name;
			name = textBox1->Text;
			string result1;
			result1 = marshal_as<string>(name);
			result1 = DecodeResheto(result1);
			String^ result2;
			result2 = marshal_as<String^>(result1);
			textBox2->Text = result2;
		}
	}
	   if (radioButton3->Checked)
	   {
		   if (textBox3->Text == "")
		   {
			   MessageBox::Show(this, "Введите ключ для данного метода", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
		   else
		   {
			   System::String^ keyname;
			   keyname = textBox3->Text;
			   string Key;
			   Key = marshal_as<string>(keyname);
			   System::String^ name;
			   name = textBox1->Text;
			   string result1;
			   result1 = marshal_as<string>(name);
			   result1 = DecodeVishener(result1, Key);
			   String^ result2;
			   result2 = marshal_as<String^>(result1);
			   if (result2 == "Oshibka")
			   {
				   MessageBox::Show(this, "Введите ключ содержащий буквы из русского алфавита", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   }
			   else {
				   textBox2->Text = result2;
			   }
		   }
	   }
	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	StreamWriter^ f = gcnew StreamWriter("D:\\1Рабочий стол\\2Учёба\\4_сем\\ТИ\\Kursovik\\Result.txt", true);
	f->Write(textBox2->Text);
	f->Close();
	MessageBox::Show(this, "Файл успешно сохранён", "Сообщение", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
