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
	private: System::Windows::Forms::TabPage^ tabPage2;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ tbNguongH;

	private: System::Windows::Forms::TrackBar^ tbNguongT;

	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Button^ btnDispay;
	private: System::Windows::Forms::Button^ btnHGray;
	private: System::Windows::Forms::Button^ btnGamma;
	private: System::Windows::Forms::Button^ btnHGreen;
	private: System::Windows::Forms::TrackBar^ trackBright;
	private: System::Windows::Forms::Button^ bntHBlue;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnHRed;
	private: System::Windows::Forms::TrackBar^ trackContrast;
	private: System::Windows::Forms::PictureBox^ pictureHitogram;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TabControl^ pictrue;

	private: System::Windows::Forms::Button^ btnCannyvcl;
	private: System::Windows::Forms::PictureBox^ pictureHistogramCanny;






	protected:























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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->btnCannyvcl = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbNguongH = (gcnew System::Windows::Forms::TrackBar());
			this->tbNguongT = (gcnew System::Windows::Forms::TrackBar());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnDispay = (gcnew System::Windows::Forms::Button());
			this->btnHGray = (gcnew System::Windows::Forms::Button());
			this->btnGamma = (gcnew System::Windows::Forms::Button());
			this->btnHGreen = (gcnew System::Windows::Forms::Button());
			this->trackBright = (gcnew System::Windows::Forms::TrackBar());
			this->bntHBlue = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnHRed = (gcnew System::Windows::Forms::Button());
			this->trackContrast = (gcnew System::Windows::Forms::TrackBar());
			this->pictureHitogram = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictrue = (gcnew System::Windows::Forms::TabControl());
			this->pictureHistogramCanny = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbNguongH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbNguongT))->BeginInit();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBright))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackContrast))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureHitogram))->BeginInit();
			this->pictrue->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureHistogramCanny))->BeginInit();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->pictureHistogramCanny);
			this->tabPage2->Controls->Add(this->btnCannyvcl);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->tbNguongH);
			this->tabPage2->Controls->Add(this->tbNguongT);
			this->tabPage2->Location = System::Drawing::Point(4, 29);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1005, 340);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Canny";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &HistogramForm::TabPage2_Click);
			// 
			// btnCannyvcl
			// 
			this->btnCannyvcl->Location = System::Drawing::Point(874, 125);
			this->btnCannyvcl->Name = L"btnCannyvcl";
			this->btnCannyvcl->Size = System::Drawing::Size(125, 72);
			this->btnCannyvcl->TabIndex = 4;
			this->btnCannyvcl->Text = L"Canny";
			this->btnCannyvcl->UseVisualStyleBackColor = true;
			this->btnCannyvcl->Click += gcnew System::EventHandler(this, &HistogramForm::BtnCannyvcl_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(432, 236);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Ngưỡng H";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(432, 77);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Ngưỡng L";
			// 
			// tbNguongH
			// 
			this->tbNguongH->Location = System::Drawing::Point(536, 199);
			this->tbNguongH->Maximum = 255;
			this->tbNguongH->Name = L"tbNguongH";
			this->tbNguongH->Size = System::Drawing::Size(299, 69);
			this->tbNguongH->TabIndex = 1;
			// 
			// tbNguongT
			// 
			this->tbNguongT->Location = System::Drawing::Point(536, 52);
			this->tbNguongT->Maximum = 255;
			this->tbNguongT->Name = L"tbNguongT";
			this->tbNguongT->Size = System::Drawing::Size(299, 69);
			this->tbNguongT->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->btnDispay);
			this->tabPage1->Controls->Add(this->btnHGray);
			this->tabPage1->Controls->Add(this->btnGamma);
			this->tabPage1->Controls->Add(this->btnHGreen);
			this->tabPage1->Controls->Add(this->trackBright);
			this->tabPage1->Controls->Add(this->bntHBlue);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->btnHRed);
			this->tabPage1->Controls->Add(this->trackContrast);
			this->tabPage1->Controls->Add(this->pictureHitogram);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1005, 340);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Histogram";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// btnDispay
			// 
			this->btnDispay->Location = System::Drawing::Point(757, 266);
			this->btnDispay->Name = L"btnDispay";
			this->btnDispay->Size = System::Drawing::Size(90, 37);
			this->btnDispay->TabIndex = 5;
			this->btnDispay->Text = L"Display";
			this->btnDispay->UseVisualStyleBackColor = true;
			this->btnDispay->Click += gcnew System::EventHandler(this, &HistogramForm::BtnDispay_Click);
			// 
			// btnHGray
			// 
			this->btnHGray->Location = System::Drawing::Point(449, 41);
			this->btnHGray->Name = L"btnHGray";
			this->btnHGray->Size = System::Drawing::Size(133, 32);
			this->btnHGray->TabIndex = 13;
			this->btnHGray->Text = L"HistogramGray";
			this->btnHGray->UseVisualStyleBackColor = true;
			this->btnHGray->Click += gcnew System::EventHandler(this, &HistogramForm::BtnHGray_Click);
			// 
			// btnGamma
			// 
			this->btnGamma->Location = System::Drawing::Point(900, 266);
			this->btnGamma->Name = L"btnGamma";
			this->btnGamma->Size = System::Drawing::Size(99, 37);
			this->btnGamma->TabIndex = 9;
			this->btnGamma->Text = L"Gamma";
			this->btnGamma->UseVisualStyleBackColor = true;
			this->btnGamma->Click += gcnew System::EventHandler(this, &HistogramForm::BtnGamma_Click);
			// 
			// btnHGreen
			// 
			this->btnHGreen->Location = System::Drawing::Point(447, 254);
			this->btnHGreen->Name = L"btnHGreen";
			this->btnHGreen->Size = System::Drawing::Size(145, 32);
			this->btnHGreen->TabIndex = 12;
			this->btnHGreen->Text = L"HistogramGreen";
			this->btnHGreen->UseVisualStyleBackColor = true;
			this->btnHGreen->Click += gcnew System::EventHandler(this, &HistogramForm::BtnHGreen_Click);
			// 
			// trackBright
			// 
			this->trackBright->Location = System::Drawing::Point(826, 41);
			this->trackBright->Maximum = 200;
			this->trackBright->Name = L"trackBright";
			this->trackBright->Size = System::Drawing::Size(161, 69);
			this->trackBright->TabIndex = 8;
			// 
			// bntHBlue
			// 
			this->bntHBlue->Location = System::Drawing::Point(447, 183);
			this->bntHBlue->Name = L"bntHBlue";
			this->bntHBlue->Size = System::Drawing::Size(135, 32);
			this->bntHBlue->TabIndex = 11;
			this->bntHBlue->Text = L"HistogramBlue";
			this->bntHBlue->UseVisualStyleBackColor = true;
			this->bntHBlue->Click += gcnew System::EventHandler(this, &HistogramForm::BntHBlue_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(739, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Bright";
			this->label1->Click += gcnew System::EventHandler(this, &HistogramForm::Label1_Click);
			// 
			// btnHRed
			// 
			this->btnHRed->Location = System::Drawing::Point(449, 112);
			this->btnHRed->Name = L"btnHRed";
			this->btnHRed->Size = System::Drawing::Size(133, 32);
			this->btnHRed->TabIndex = 10;
			this->btnHRed->Text = L"HistogramRed";
			this->btnHRed->UseVisualStyleBackColor = true;
			this->btnHRed->Click += gcnew System::EventHandler(this, &HistogramForm::BtnHRed_Click);
			// 
			// trackContrast
			// 
			this->trackContrast->Location = System::Drawing::Point(826, 156);
			this->trackContrast->Maximum = 30;
			this->trackContrast->Minimum = 1;
			this->trackContrast->Name = L"trackContrast";
			this->trackContrast->Size = System::Drawing::Size(161, 69);
			this->trackContrast->TabIndex = 7;
			this->trackContrast->Value = 10;
			// 
			// pictureHitogram
			// 
			this->pictureHitogram->Location = System::Drawing::Point(6, 23);
			this->pictureHitogram->Name = L"pictureHitogram";
			this->pictureHitogram->Size = System::Drawing::Size(401, 309);
			this->pictureHitogram->TabIndex = 0;
			this->pictureHitogram->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(739, 183);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Contrast";
			// 
			// pictrue
			// 
			this->pictrue->Controls->Add(this->tabPage1);
			this->pictrue->Controls->Add(this->tabPage2);
			this->pictrue->Location = System::Drawing::Point(12, 3);
			this->pictrue->Name = L"pictrue";
			this->pictrue->SelectedIndex = 0;
			this->pictrue->Size = System::Drawing::Size(1013, 373);
			this->pictrue->TabIndex = 14;
			// 
			// pictureHistogramCanny
			// 
			this->pictureHistogramCanny->Location = System::Drawing::Point(6, 20);
			this->pictureHistogramCanny->Name = L"pictureHistogramCanny";
			this->pictureHistogramCanny->Size = System::Drawing::Size(403, 312);
			this->pictureHistogramCanny->TabIndex = 5;
			this->pictureHistogramCanny->TabStop = false;
			// 
			// HistogramForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1037, 376);
			this->Controls->Add(this->pictrue);
			this->Name = L"HistogramForm";
			this->Text = L"HistogramForm";
			this->Load += gcnew System::EventHandler(this, &HistogramForm::HistogramForm_Load);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbNguongH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbNguongT))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBright))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackContrast))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureHitogram))->EndInit();
			this->pictrue->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureHistogramCanny))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: void loadHistogram(cv::Mat img);
	public: void loadHistogramCanny(cv::Mat img);
	public: void HistogramGray();
	public:cv::Mat HistogramRGB(char* imgColor);
		   /*
		   public: Mat GetRed();
		   public: Mat GetBlue();
		   public: Mat GetGreen();
		   public: void SetRed(Mat img);
		   public: void SetGreen(Mat img);
		   public: void SetBlue(Mat img);
		   */
	public: cv::Mat correctGamma(cv::Mat& img, double gamma);
	public: cv::Mat CannyEdgeDetection(cv::Mat img);
	private: System::Void HistogramForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void BtnDispay_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnGamma_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnHRed_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BntHBlue_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnHGreen_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnHGray_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnCanny_Click(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void TabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BtnCannyvcl_Click(System::Object^ sender, System::EventArgs^ e);
};
}
