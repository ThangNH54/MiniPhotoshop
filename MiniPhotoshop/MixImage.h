#pragma once

namespace MiniPhotoshop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MixImage
	/// </summary>
	public ref class MixImage : public System::Windows::Forms::Form
	{
	public:
		MixImage(void)
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
		~MixImage()
		{
			if (components)
			{
				delete components;
			}
		}
	public:static System::Windows::Forms::PictureBox^ pictureBoxInput;
	protected:
	public: System::Windows::Forms::PictureBox^ pictureBoxBg;
	public: System::Windows::Forms::PictureBox^ pictureBoxOut;

	protected:


	public:static System::Windows::Forms::Button^ btnOpenInput;
	public:static System::Windows::Forms::Button^ btnOpenBg;
	private: System::Windows::Forms::Button^ btnMix;

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
			this->pictureBoxInput = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxBg = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxOut = (gcnew System::Windows::Forms::PictureBox());
			this->btnOpenInput = (gcnew System::Windows::Forms::Button());
			this->btnOpenBg = (gcnew System::Windows::Forms::Button());
			this->btnMix = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOut))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBoxInput
			// 
			this->pictureBoxInput->Location = System::Drawing::Point(59, 12);
			this->pictureBoxInput->Name = L"pictureBoxInput";
			this->pictureBoxInput->Size = System::Drawing::Size(349, 263);
			this->pictureBoxInput->TabIndex = 0;
			this->pictureBoxInput->TabStop = false;
			// 
			// pictureBoxBg
			// 
			this->pictureBoxBg->Location = System::Drawing::Point(656, 12);
			this->pictureBoxBg->Name = L"pictureBoxBg";
			this->pictureBoxBg->Size = System::Drawing::Size(379, 263);
			this->pictureBoxBg->TabIndex = 1;
			this->pictureBoxBg->TabStop = false;
			// 
			// pictureBoxOut
			// 
			this->pictureBoxOut->Location = System::Drawing::Point(284, 339);
			this->pictureBoxOut->Name = L"pictureBoxOut";
			this->pictureBoxOut->Size = System::Drawing::Size(515, 338);
			this->pictureBoxOut->TabIndex = 2;
			this->pictureBoxOut->TabStop = false;
			// 
			// btnOpenInput
			// 
			this->btnOpenInput->Location = System::Drawing::Point(436, 128);
			this->btnOpenInput->Name = L"btnOpenInput";
			this->btnOpenInput->Size = System::Drawing::Size(75, 30);
			this->btnOpenInput->TabIndex = 3;
			this->btnOpenInput->Text = L"Image";
			this->btnOpenInput->UseVisualStyleBackColor = true;
			this->btnOpenInput->Click += gcnew System::EventHandler(this, &MixImage::BtnOpenInput_Click);
			// 
			// btnOpenBg
			// 
			this->btnOpenBg->Location = System::Drawing::Point(1041, 128);
			this->btnOpenBg->Name = L"btnOpenBg";
			this->btnOpenBg->Size = System::Drawing::Size(108, 30);
			this->btnOpenBg->TabIndex = 4;
			this->btnOpenBg->Text = L"BackGround";
			this->btnOpenBg->UseVisualStyleBackColor = true;
			this->btnOpenBg->Click += gcnew System::EventHandler(this, &MixImage::BtnOpenBg_Click);
			// 
			// btnMix
			// 
			this->btnMix->Location = System::Drawing::Point(885, 479);
			this->btnMix->Name = L"btnMix";
			this->btnMix->Size = System::Drawing::Size(75, 23);
			this->btnMix->TabIndex = 5;
			this->btnMix->Text = L"Mix";
			this->btnMix->UseVisualStyleBackColor = true;
			this->btnMix->Click += gcnew System::EventHandler(this, &MixImage::BtnMix_Click);
			// 
			// MixImage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1161, 689);
			this->Controls->Add(this->btnMix);
			this->Controls->Add(this->btnOpenBg);
			this->Controls->Add(this->btnOpenInput);
			this->Controls->Add(this->pictureBoxOut);
			this->Controls->Add(this->pictureBoxBg);
			this->Controls->Add(this->pictureBoxInput);
			this->Name = L"MixImage";
			this->Text = L"MixImage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOut))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BtnOpenInput_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnOpenBg_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void BtnMix_Click(System::Object^ sender, System::EventArgs^ e);
};
}
