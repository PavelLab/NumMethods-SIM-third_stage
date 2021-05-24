#pragma once
#include <math.h>
#include "SI_Method_class.h"

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		SI_Method* pTask3;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^ textBox_n_x;











	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_m_y;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox_MaxIters;
	private: System::Windows::Forms::TextBox^ textBox_epsInitial;



	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ Label_result;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;











	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_n_x = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_m_y = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_MaxIters = (gcnew System::Windows::Forms::TextBox());
			this->textBox_epsInitial = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->Label_result = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(338, 367);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 36);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Solve";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(72, 41);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"a=1";
			// 
			// textBox_n_x
			// 
			this->textBox_n_x->Location = System::Drawing::Point(376, 182);
			this->textBox_n_x->Name = L"textBox_n_x";
			this->textBox_n_x->Size = System::Drawing::Size(105, 22);
			this->textBox_n_x->TabIndex = 13;
			this->textBox_n_x->Text = L"8";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(153, 41);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 25);
			this->label6->TabIndex = 14;
			this->label6->Text = L"b=2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(223, 41);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 25);
			this->label7->TabIndex = 15;
			this->label7->Text = L"c=2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(298, 41);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(46, 25);
			this->label8->TabIndex = 16;
			this->label8->Text = L"d=3";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(371, 41);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(62, 25);
			this->label9->TabIndex = 17;
			this->label9->Text = L"e=1.5";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(455, 41);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(56, 25);
			this->label10->TabIndex = 18;
			this->label10->Text = L"f=2.5";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(33, 178);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(281, 25);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Число разбиений n (по оси х)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(33, 218);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(286, 25);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Число разбиений m (по оси y)";
			// 
			// textBox_m_y
			// 
			this->textBox_m_y->Location = System::Drawing::Point(376, 222);
			this->textBox_m_y->Name = L"textBox_m_y";
			this->textBox_m_y->Size = System::Drawing::Size(105, 22);
			this->textBox_m_y->TabIndex = 21;
			this->textBox_m_y->Text = L"8";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(33, 260);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(305, 25);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Максимальное число итераций";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(33, 302);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(208, 25);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Требуемая точность";
			// 
			// textBox_MaxIters
			// 
			this->textBox_MaxIters->Location = System::Drawing::Point(376, 263);
			this->textBox_MaxIters->Name = L"textBox_MaxIters";
			this->textBox_MaxIters->Size = System::Drawing::Size(105, 22);
			this->textBox_MaxIters->TabIndex = 24;
			this->textBox_MaxIters->Text = L"1000";
			// 
			// textBox_epsInitial
			// 
			this->textBox_epsInitial->Location = System::Drawing::Point(376, 306);
			this->textBox_epsInitial->Name = L"textBox_epsInitial";
			this->textBox_epsInitial->Size = System::Drawing::Size(105, 22);
			this->textBox_epsInitial->TabIndex = 25;
			this->textBox_epsInitial->Text = L"0,00000001";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(72, 99);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(214, 29);
			this->label11->TabIndex = 26;
			this->label11->Text = L"u(test)=sin(π*x*y)";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(13, 9);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(231, 25);
			this->label12->TabIndex = 27;
			this->label12->Text = L"Вариант 4. Область 1\r\n";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(574, 31);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 30;
			this->dataGridView1->Size = System::Drawing::Size(782, 418);
			this->dataGridView1->TabIndex = 2;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(33, 424);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(74, 25);
			this->label13->TabIndex = 28;
			this->label13->Text = L"Итоги:";
			// 
			// Label_result
			// 
			this->Label_result->AutoSize = true;
			this->Label_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Label_result->Location = System::Drawing::Point(33, 463);
			this->Label_result->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Label_result->Name = L"Label_result";
			this->Label_result->Size = System::Drawing::Size(0, 24);
			this->Label_result->TabIndex = 29;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(648, 487);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(66, 21);
			this->radioButton1->TabIndex = 30;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"V^s_ij";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(648, 528);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(53, 21);
			this->radioButton2->TabIndex = 31;
			this->radioButton2->Text = L"U_ij";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(648, 570);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(95, 21);
			this->radioButton3->TabIndex = 32;
			this->radioButton3->Text = L"V^s_ij-U_ij";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1402, 793);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->Label_result);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox_epsInitial);
			this->Controls->Add(this->textBox_MaxIters);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox_m_y);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox_n_x);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		// Данные
		int n_x = Convert::ToInt32(textBox_n_x->Text);
		int m_y = Convert::ToInt32(textBox_m_y->Text);
		int MaxIters = Convert::ToInt32(textBox_MaxIters->Text);
		double eps_initial = Convert::ToDouble(textBox_epsInitial->Text);

		if (pTask3) {
			delete pTask3;
		}
		pTask3 = new SI_Method(n_x, m_y, MaxIters, eps_initial);
		pTask3->Solve_SI_Method();
		
		
		
		// Список точек
		dataGridView1->Columns->Clear();
		dataGridView1->Rows->Clear();
		//i - разбиения по оси х, j - по оси y, graph_offset - смещение на графике
		int graph_offset = 3;
		
		//создание строк и столбцов
		for (int i = 0; i <= n_x + graph_offset; i++) {
			dataGridView1->Columns->Add("", "      ");
		}
		for (int j = 0; j <= m_y + graph_offset; j++){
			dataGridView1->Rows->Add();
		}
		
		//вывод шага, i и j
		for (int j = 0; j <= m_y + graph_offset; j++)
			 for (int i = 0; i <= n_x + graph_offset; i++){
				 if ((j == 0) && (i >= graph_offset))
					 dataGridView1->Rows[j]->Cells[i]->Value = i - graph_offset;
				 else if ((j == 1) && (i >= graph_offset))
					 dataGridView1->Rows[j]->Cells[i]->Value = ((2. - 1.) / n_x) * (i - graph_offset);
				 else if ((i == 0) && (j <= m_y))
					 //m_y + graph_offset-j так как идем снизу вверх
					 dataGridView1->Rows[m_y + graph_offset-j]->Cells[i]->Value = j;
				 else if ((i == 1) && (j <= m_y))
					 dataGridView1->Rows[m_y + graph_offset - j]->Cells[i]->Value = ((3. - 2.) / m_y) * j;
			}
		dataGridView1->Rows[0]->Cells[2]->Value = "i";
		dataGridView1->Rows[1]->Cells[2]->Value = "h";
		dataGridView1->Rows[2]->Cells[0]->Value = "j";
		dataGridView1->Rows[2]->Cells[1]->Value = "k";

		
		//Печать в таблицу значений
		if (radioButton1->Checked) {
			for (int j = graph_offset; j <= m_y + graph_offset; j++)
				for (int i = graph_offset; i <= n_x + graph_offset; i++)
				{
					double a = pTask3->V_new[i - graph_offset][m_y - (j - graph_offset)];
					a = (int)(a * 1000 + Math::Sign(a) * 0.5) / 1000.;
					dataGridView1->Rows[j]->Cells[i]->Value = a;
				}
		}
		if (radioButton2->Checked) {
			for (int j = graph_offset; j <= m_y + graph_offset; j++)
				for (int i = graph_offset; i <= n_x + graph_offset; i++)
				{
					pTask3->Fill_exact_solution();
					double a = pTask3->U_exact[i - graph_offset][m_y - (j - graph_offset)];
					a = (int)(a * 1000 + Math::Sign(a) * 0.5) / 1000.;
					dataGridView1->Rows[j]->Cells[i]->Value = a;
				}
		}
		if (radioButton3->Checked) {
			for (int j = graph_offset; j <= m_y + graph_offset; j++)
				for (int i = graph_offset; i <= n_x + graph_offset; i++)
				{
					pTask3->Fill_exact_solution();
					double a = pTask3->V_new[i - graph_offset][m_y - (j - graph_offset)]- pTask3->U_exact[i - graph_offset][m_y - (j - graph_offset)];
					dataGridView1->Rows[j]->Cells[i]->Value = a;
				}
		}




		Label_result->Text = "Метод простых итераций";
		Label_result->Text += "\nОптимальный параметр: " + pTask3->Сalculate_tau();
		Label_result->Text += "\nРазмерность сетки: (" + pTask3->n + ", " + pTask3->m + ")";
		Label_result->Text += "\nОбласть определения X: [" + pTask3->a + "; " + pTask3->b + "] " + "Область определения Y: [" + pTask3->c + "; " + pTask3->d + "]";
		Label_result->Text += "\nШаг сетки по оси Ox: h = " + (pTask3->b - pTask3->a) / pTask3->n;
		Label_result->Text += "\nШаг сетки по оси Oy: k = " + (pTask3->d - pTask3->c) / pTask3->m;
		Label_result->Text += "\nЗаданная точность: " + eps_initial;
		Label_result->Text += "\nНевязка решения(евклидова норма): " + pTask3->DiscrepancyOfSolution();
		Label_result->Text += "\nПроведено итераций: " + pTask3->iters;
		Label_result->Text += "\nДостигнутая точность метода:\nmax|v^s_ij-v^(s-1)_ij|: " + pTask3->epsMax_achieved;
		Label_result->Text += "\nПогрешность решения:\nmax|v^s_ij-u_ij|: " + pTask3->CheckNumSolution();
	}



private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
