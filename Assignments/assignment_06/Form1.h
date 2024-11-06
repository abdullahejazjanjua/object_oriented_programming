#include <fstream>
#include <sstream>
#include <chrono>
#pragma once
#include <string>
#include <vcclr.h>
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		int number_of_poly, number_of_vars;
		int *buff;
		int *sum;
		String ^fileName;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button2;
	public:

	public:
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	public:
		Form1(void)
		{
			number_of_poly = 0;
			number_of_vars = 0;
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			delete[] buff;
			delete[] sum;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(446, 436);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(183, 233);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(655, 180);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->WordWrap = false;
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(183, 560);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(1000, 50);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			this->richTextBox2->WordWrap = false;
			this->richTextBox2->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(13, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Filename";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Number of polynomials";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(170, 22);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Number of variables";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 110);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Time taken";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(12, 226);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(149, 29);
			this->label5->TabIndex = 7;
			this->label5->Text = L"File Content:";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(92, 560);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 29);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Sum:";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(12, 143);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(224, 22);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Number of non zero values";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(12, 180);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(207, 22);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Data Structure: 1D Array";
			this->label8->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(403, 497);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(204, 45);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Generate OutputFIle";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1354, 664);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"File Reading";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		auto start = chrono::high_resolution_clock::now(); // starts the timer
		String^ path, ^user_choice;
		ifstream reader;
		user_choice = openFileDialog1->ShowDialog().ToString(); //gets user choice (OK or CANCEL)
		if (String::Compare(user_choice, "cancel", StringComparison::OrdinalIgnoreCase) == 0)
		{
			MessageBox::Show("File NOT selected\n"); // Message displayed if NO file selected
			return;
		}
		path = openFileDialog1->FileName;
		//Clears the text boxes of remenant texts 
		richTextBox1->Clear();
		richTextBox2->Clear();
		//converts system string to wchar and then to string
		pin_ptr<const wchar_t> wch = PtrToStringChars(path);
		int len = path->Length;
		wchar_t* wchPtr = const_cast<wchar_t*>(wch);
		wstring convertedString(wchPtr, len);
		// Convert wstring to string
		string nativepath(convertedString.begin(), convertedString.end());
		fileName = Path :: GetFileName(path);
		label1->Text = "Filename: " + fileName;
		reader.open(nativepath); // Open the file in text mode
		if (!reader.is_open())
		{
			MessageBox::Show("Error opening file");
			return;
		}
		int temp_poly = 0, temp_vars = 0;
		reader >> temp_poly;
		reader >> temp_vars;
		if (temp_vars <= 0 || temp_poly <= 0)
		{
			MessageBox::Show("Invalid vlaues");
			return;
		}
		number_of_poly = temp_poly;
		number_of_vars = temp_vars;
		
		label2->Text = "Number of polynomials: " + number_of_poly.ToString();
		label3->Text = "Number of variables: " + number_of_vars.ToString();

		richTextBox1->AppendText(number_of_poly.ToString() + "\n");
		richTextBox1->AppendText(number_of_vars.ToString() + "\n");
		// Allocate memory for buff and sum arrays
		buff = new int[number_of_vars];
		sum = new int[number_of_vars];
		for (int i = 0; i < number_of_vars; i++)
		{
			sum[i] = 0; // Initialize sum array elements to zero
		}

		string line;
		getline(reader, line); // Consume the remaining newline character after reading number_of_vars
		while (getline(reader, line))
		{
			istringstream iss(line); // picks values from line
			for (int j = 0; j < number_of_vars; j++)
			{
				int value;
				if (!(iss >> value))
				{
					MessageBox::Show("Error reading file");
					return;
				}
				buff[j] = value; // Store the read value in buff array
				sum[j] += buff[j]; // Update sum with the read value
				String^ intString = Convert::ToString(value); 
				richTextBox1->AppendText(intString + "       "); //displaying values 
			}
			richTextBox1->AppendText(Environment::NewLine); //Add new line
		}


		for (int i = 0; i < number_of_vars; i++)
		{
			richTextBox2->AppendText(sum[i].ToString() + "    "); // displaying values
		}

		reader.close(); // Close the file after reading
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		double seconds = duration.count() / 1000000.0;
		label4->Text = "Time taken: " + seconds.ToString() + " secs";

		int non_zero_values = 0;
		for (int i = 0; i < number_of_vars; i++)
		{
			if (sum[i] != 0)
				non_zero_values++;
		}


		label7->Text = "Number of non zero values: " + non_zero_values.ToString();
	

	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
{
	
}

private: System::Void richTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	ofstream writer;

	writer.open("result_addition.txt");
	if (!writer.is_open())
	{
		MessageBox::Show("Error creating file");
	}
	if (String::IsNullOrEmpty(fileName) || fileName->Trim() == "") //checks if fileName is empty
	{
		MessageBox::Show("File NOT Selected yet!\n");
		return;
	}
	// convert system string into wString and then into string
	pin_ptr<const wchar_t> wch = PtrToStringChars(fileName);
	int len = fileName->Length;
	wchar_t* wchPtr = const_cast<wchar_t*>(wch);
	wstring convertedString(wchPtr, len);
	// Convert wstring to string
	string nativeFileName(convertedString.begin(), convertedString.end());
	writer << "File name: " << nativeFileName << "\n" << "Result: "; // writing file
	for (int i = 0; i < number_of_vars; i++)
	{
		writer << sum[i] << " "; //writing to file
	}
	MessageBox::Show("File generated successfully in the working dict");
	writer.close();
}
};
}
