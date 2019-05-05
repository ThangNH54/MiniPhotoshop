#pragma once
namespace MiniPhotoshop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ToolForm
	/// </summary>
	public ref class ToolForm : public System::Windows::Forms::Form
	{
	public:
		ToolForm();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblWidth;
	protected:
	private: System::Windows::Forms::Label^ lblHeight;
	private: System::Windows::Forms::TextBox^ txtWidth;
	private: System::Windows::Forms::TextBox^ txtHeight;
	private: System::Windows::Forms::TrackBar^ trackBarWidth;
	private: System::Windows::Forms::TrackBar^ trackBarHeight;
	private: System::Windows::Forms::Button^ btnReset;
	private: System::Windows::Forms::Button^ btnOk;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtRotation;
	private: System::Windows::Forms::Button^ btnXoay;

	private: System::Windows::Forms::TabControl^ tabControl;

	private: System::Windows::Forms::TabPage^ tabSize;
	private: System::Windows::Forms::TabPage^ tabRotation;
	private: System::Windows::Forms::TabPage^ tabCroo;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnCrop;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblWidth = (gcnew System::Windows::Forms::Label());
			this->lblHeight = (gcnew System::Windows::Forms::Label());
			this->txtWidth = (gcnew System::Windows::Forms::TextBox());
			this->txtHeight = (gcnew System::Windows::Forms::TextBox());
			this->trackBarWidth = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarHeight = (gcnew System::Windows::Forms::TrackBar());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtRotation = (gcnew System::Windows::Forms::TextBox());
			this->btnXoay = (gcnew System::Windows::Forms::Button());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabSize = (gcnew System::Windows::Forms::TabPage());
			this->tabRotation = (gcnew System::Windows::Forms::TabPage());
			this->tabCroo = (gcnew System::Windows::Forms::TabPage());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnCrop = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarWidth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarHeight))->BeginInit();
			this->tabControl->SuspendLayout();
			this->tabSize->SuspendLayout();
			this->tabRotation->SuspendLayout();
			this->tabCroo->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblWidth
			// 
			this->lblWidth->AutoSize = true;
			this->lblWidth->Location = System::Drawing::Point(18, 29);
			this->lblWidth->Name = L"lblWidth";
			this->lblWidth->Size = System::Drawing::Size(44, 17);
			this->lblWidth->TabIndex = 0;
			this->lblWidth->Text = L"Width";
			// 
			// lblHeight
			// 
			this->lblHeight->AutoSize = true;
			this->lblHeight->Location = System::Drawing::Point(18, 123);
			this->lblHeight->Name = L"lblHeight";
			this->lblHeight->Size = System::Drawing::Size(49, 17);
			this->lblHeight->TabIndex = 1;
			this->lblHeight->Text = L"Height";
			// 
			// txtWidth
			// 
			this->txtWidth->Location = System::Drawing::Point(93, 29);
			this->txtWidth->Name = L"txtWidth";
			this->txtWidth->Size = System::Drawing::Size(76, 22);
			this->txtWidth->TabIndex = 2;
			this->txtWidth->Text = L"0";
			this->txtWidth->TextChanged += gcnew System::EventHandler(this, &ToolForm::TxtWidth_TextChanged);
			// 
			// txtHeight
			// 
			this->txtHeight->Location = System::Drawing::Point(93, 120);
			this->txtHeight->Name = L"txtHeight";
			this->txtHeight->Size = System::Drawing::Size(76, 22);
			this->txtHeight->TabIndex = 3;
			this->txtHeight->Text = L"0";
			this->txtHeight->TextChanged += gcnew System::EventHandler(this, &ToolForm::TxtHeight_TextChanged);
			// 
			// trackBarWidth
			// 
			this->trackBarWidth->Location = System::Drawing::Point(206, 16);
			this->trackBarWidth->Maximum = 50;
			this->trackBarWidth->Minimum = -50;
			this->trackBarWidth->Name = L"trackBarWidth";
			this->trackBarWidth->Size = System::Drawing::Size(398, 56);
			this->trackBarWidth->TabIndex = 4;
			this->trackBarWidth->Scroll += gcnew System::EventHandler(this, &ToolForm::trackBarWidth_Scroll);
			// 
			// trackBarHeight
			// 
			this->trackBarHeight->Location = System::Drawing::Point(206, 102);
			this->trackBarHeight->Maximum = 50;
			this->trackBarHeight->Minimum = -50;
			this->trackBarHeight->Name = L"trackBarHeight";
			this->trackBarHeight->Size = System::Drawing::Size(398, 56);
			this->trackBarHeight->TabIndex = 5;
			this->trackBarHeight->Scroll += gcnew System::EventHandler(this, &ToolForm::trackBarHeight_Scroll);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(125, 335);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 23);
			this->btnReset->TabIndex = 6;
			this->btnReset->Text = L"Reset";
			this->btnReset->UseVisualStyleBackColor = true;
			this->btnReset->Click += gcnew System::EventHandler(this, &ToolForm::BtnReset_Click);
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(304, 335);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(75, 23);
			this->btnOk->TabIndex = 7;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &ToolForm::BtnOk_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Rotation";
			// 
			// txtRotation
			// 
			this->txtRotation->Location = System::Drawing::Point(170, 48);
			this->txtRotation->Name = L"txtRotation";
			this->txtRotation->Size = System::Drawing::Size(76, 22);
			this->txtRotation->TabIndex = 9;
			this->txtRotation->Text = L"0";
			// 
			// btnXoay
			// 
			this->btnXoay->Location = System::Drawing::Point(342, 48);
			this->btnXoay->Name = L"btnXoay";
			this->btnXoay->Size = System::Drawing::Size(75, 27);
			this->btnXoay->TabIndex = 10;
			this->btnXoay->Text = L"Xoay";
			this->btnXoay->UseVisualStyleBackColor = true;
			this->btnXoay->Click += gcnew System::EventHandler(this, &ToolForm::BtnXoay_Click);
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabSize);
			this->tabControl->Controls->Add(this->tabRotation);
			this->tabControl->Controls->Add(this->tabCroo);
			this->tabControl->Location = System::Drawing::Point(27, 12);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(637, 264);
			this->tabControl->TabIndex = 12;
			this->tabControl->SelectedIndexChanged += gcnew System::EventHandler(this, &ToolForm::tabControl_SelectedIndexChanged);
			// 
			// tabSize
			// 
			this->tabSize->Controls->Add(this->lblWidth);
			this->tabSize->Controls->Add(this->txtWidth);
			this->tabSize->Controls->Add(this->lblHeight);
			this->tabSize->Controls->Add(this->txtHeight);
			this->tabSize->Controls->Add(this->trackBarWidth);
			this->tabSize->Controls->Add(this->trackBarHeight);
			this->tabSize->Location = System::Drawing::Point(4, 25);
			this->tabSize->Name = L"tabSize";
			this->tabSize->Padding = System::Windows::Forms::Padding(3);
			this->tabSize->Size = System::Drawing::Size(629, 235);
			this->tabSize->TabIndex = 0;
			this->tabSize->Text = L"Size";
			this->tabSize->UseVisualStyleBackColor = true;
			// 
			// tabRotation
			// 
			this->tabRotation->Controls->Add(this->btnXoay);
			this->tabRotation->Controls->Add(this->label1);
			this->tabRotation->Controls->Add(this->txtRotation);
			this->tabRotation->Location = System::Drawing::Point(4, 25);
			this->tabRotation->Name = L"tabRotation";
			this->tabRotation->Padding = System::Windows::Forms::Padding(3);
			this->tabRotation->Size = System::Drawing::Size(629, 235);
			this->tabRotation->TabIndex = 1;
			this->tabRotation->Text = L"Rotation";
			this->tabRotation->UseVisualStyleBackColor = true;
			// 
			// tabCroo
			// 
			this->tabCroo->Controls->Add(this->btnCrop);
			this->tabCroo->Location = System::Drawing::Point(4, 25);
			this->tabCroo->Name = L"tabCroo";
			this->tabCroo->Size = System::Drawing::Size(629, 235);
			this->tabCroo->TabIndex = 2;
			this->tabCroo->Text = L"Crop";
			this->tabCroo->UseVisualStyleBackColor = true;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(490, 335);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 13;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &ToolForm::BtnCancel_Click);
			// 
			// btnCrop
			// 
			this->btnCrop->Location = System::Drawing::Point(273, 82);
			this->btnCrop->Name = L"btnCrop";
			this->btnCrop->Size = System::Drawing::Size(75, 23);
			this->btnCrop->TabIndex = 0;
			this->btnCrop->Text = L"Crop";
			this->btnCrop->UseVisualStyleBackColor = true;
			this->btnCrop->Click += gcnew System::EventHandler(this, &ToolForm::BtnCrop_Click);
			// 
			// ToolForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 381);
			this->ControlBox = false;
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->btnReset);
			this->Name = L"ToolForm";
			this->Text = L"ToolForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarWidth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarHeight))->EndInit();
			this->tabControl->ResumeLayout(false);
			this->tabSize->ResumeLayout(false);
			this->tabSize->PerformLayout();
			this->tabRotation->ResumeLayout(false);
			this->tabRotation->PerformLayout();
			this->tabCroo->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void trackBarWidth_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void trackBarHeight_Scroll(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnReset_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TxtWidth_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TxtHeight_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnOk_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnXoay_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void tabControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnCancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnCrop_Click(System::Object^ sender, System::EventArgs^ e);
	};
}