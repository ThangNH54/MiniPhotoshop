#pragma once
#include <opencv2/opencv.hpp>

namespace MiniPhotoshop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HistogramForm
	/// </summary>
	public ref class HistogramForm : public System::Windows::Forms::Form
	{
	public:
		HistogramForm();
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HistogramForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureHitogram;
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnDispay;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ trackContrast;

	private: System::Windows::Forms::TrackBar^ trackBright;
	private: System::Windows::Forms::Button^ btnGamma;



	protected:

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
			this->pictureHitogram = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnDispay = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackContrast = (gcnew System::Windows::Forms::TrackBar());
			this->trackBright = (gcnew System::Windows::Forms::TrackBar());
			this->btnGamma = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureHitogram))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackContrast))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBright))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureHitogram
			// 
			this->pictureHitogram->Location = System::Drawing::Point(25, 12);
			this->pictureHitogram->Name = L"pictureHitogram";
			this->pictureHitogram->Size = System::Drawing::Size(401, 309);
			this->pictureHitogram->TabIndex = 0;
			this->pictureHitogram->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(484, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Bright";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(484, 186);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Contrast";
			// 
			// btnDispay
			// 
			this->btnDispay->Location = System::Drawing::Point(464, 284);
			this->btnDispay->Name = L"btnDispay";
			this->btnDispay->Size = System::Drawing::Size(90, 37);
			this->btnDispay->TabIndex = 5;
			this->btnDispay->Text = L"Display";
			this->btnDispay->UseVisualStyleBackColor = true;
			this->btnDispay->Click += gcnew System::EventHandler(this, &HistogramForm::BtnDispay_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(115, 336);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Histogram image";
			// 
			// trackContrast
			// 
			this->trackContrast->Location = System::Drawing::Point(579, 186);
			this->trackContrast->Maximum = 30;
			this->trackContrast->Minimum = 1;
			this->trackContrast->Name = L"trackContrast";
			this->trackContrast->Size = System::Drawing::Size(161, 69);
			this->trackContrast->TabIndex = 7;
			this->trackContrast->Value = 10;
			// 
			// trackBright
			// 
			this->trackBright->Location = System::Drawing::Point(579, 102);
			this->trackBright->Maximum = 200;
			this->trackBright->Name = L"trackBright";
			this->trackBright->Size = System::Drawing::Size(161, 69);
			this->trackBright->TabIndex = 8;
			// 
			// btnGamma
			// 
			this->btnGamma->Location = System::Drawing::Point(596, 284);
			this->btnGamma->Name = L"btnGamma";
			this->btnGamma->Size = System::Drawing::Size(99, 37);
			this->btnGamma->TabIndex = 9;
			this->btnGamma->Text = L"Gamma";
			this->btnGamma->UseVisualStyleBackColor = true;
			this->btnGamma->Click += gcnew System::EventHandler(this, &HistogramForm::BtnGamma_Click);
			// 
			// HistogramForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(752, 376);
			this->Controls->Add(this->btnGamma);
			this->Controls->Add(this->trackBright);
			this->Controls->Add(this->trackContrast);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnDispay);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureHitogram);
			this->Name = L"HistogramForm";
			this->Text = L"HistogramForm";
			this->Load += gcnew System::EventHandler(this, &HistogramForm::HistogramForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureHitogram))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackContrast))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBright))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: void loadHistogram(cv::Mat img);
	public: void HistogramGray();
	public: cv::Mat correctGamma(cv::Mat& img, double gamma);
	private: System::Void HistogramForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void BtnDispay_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnGamma_Click(System::Object^ sender, System::EventArgs^ e);
	};
}