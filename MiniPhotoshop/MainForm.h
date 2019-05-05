#pragma once
#include "HandleImage.h"
#include "ToolForm.h"
#include "HistogramForm.h"
#include <opencv2/opencv.hpp>

using namespace cv;
namespace MiniPhotoshop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
#define IMAGE_SCALE 1.1
		int maxWidthImg, maxHeightImg;
		System::Drawing::Point^ p1, ^ p2;
		bool isMouseDown = false;
	public: static bool isOpenToolForm = false;//co trang thai toolform
	public:static	 System::Drawing::Rectangle rec;
	public:
		MainForm(void)
		{
			InitializeComponent();
			maxWidthImg = 10 * pictureBox->Width;
			maxHeightImg = 10 * pictureBox->Height;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menu;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ menuFile;
	private: System::Windows::Forms::ToolStripMenuItem^ menuOpenFile;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSave;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSaveAs;
	private: System::Windows::Forms::Panel^ panel;
	public: static System::Windows::Forms::PictureBox^ pictureBox;
	private:

	private:

	private:

	private:

	private:

	private:

	private:

	private:


	private: System::Windows::Forms::Button^ btnScaleTool;
	public:static int imgX, imgY;
	private: System::Windows::Forms::Button^ btbHistorgam;
	public:

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
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
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->menuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuOpenFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSaveAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->btnScaleTool = (gcnew System::Windows::Forms::Button());
			this->btbHistorgam = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menu->SuspendLayout();
			this->panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuFile });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(1200, 28);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuStrip1";
			// 
			// menuFile
			// 
			this->menuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuOpenFile,
					this->menuSave, this->menuSaveAs
			});
			this->menuFile->Name = L"menuFile";
			this->menuFile->Size = System::Drawing::Size(44, 24);
			this->menuFile->Text = L"File";
			// 
			// menuOpenFile
			// 
			this->menuOpenFile->Name = L"menuOpenFile";
			this->menuOpenFile->Size = System::Drawing::Size(135, 26);
			this->menuOpenFile->Text = L"Open";
			this->menuOpenFile->Click += gcnew System::EventHandler(this, &MainForm::MenuOpenFile_Click);
			// 
			// menuSave
			// 
			this->menuSave->Name = L"menuSave";
			this->menuSave->Size = System::Drawing::Size(135, 26);
			this->menuSave->Text = L"Save";
			this->menuSave->Click += gcnew System::EventHandler(this, &MainForm::MenuSave_Click);
			// 
			// menuSaveAs
			// 
			this->menuSaveAs->Name = L"menuSaveAs";
			this->menuSaveAs->Size = System::Drawing::Size(135, 26);
			this->menuSaveAs->Text = L"Save As";
			this->menuSaveAs->Click += gcnew System::EventHandler(this, &MainForm::MenuSaveAs_Click);
			// 
			// panel
			// 
			this->panel->AutoScroll = true;
			this->panel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel->Controls->Add(this->pictureBox);
			this->panel->Location = System::Drawing::Point(12, 42);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(936, 573);
			this->panel->TabIndex = 1;
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox->Location = System::Drawing::Point(3, 3);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(930, 567);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PictureBox_MouseDown);
			this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PictureBox_MouseMove);
			this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::PictureBox_MouseUp);
			// 
			// btnScaleTool
			// 
			this->btnScaleTool->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnScaleTool->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnScaleTool->Location = System::Drawing::Point(1036, 45);
			this->btnScaleTool->Name = L"btnScaleTool";
			this->btnScaleTool->Size = System::Drawing::Size(81, 33);
			this->btnScaleTool->TabIndex = 2;
			this->btnScaleTool->Text = L"Tool";
			this->btnScaleTool->UseVisualStyleBackColor = true;
			this->btnScaleTool->Click += gcnew System::EventHandler(this, &MainForm::BtnScaleTool_Click);
			// 
			// btbHistorgam
			// 
			this->btbHistorgam->Location = System::Drawing::Point(1036, 116);
			this->btbHistorgam->Name = L"btbHistorgam";
			this->btbHistorgam->Size = System::Drawing::Size(81, 23);
			this->btbHistorgam->TabIndex = 3;
			this->btbHistorgam->Text = L"Histogram";
			this->btbHistorgam->UseVisualStyleBackColor = true;
			this->btbHistorgam->Click += gcnew System::EventHandler(this, &MainForm::BtbHistorgam_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1036, 187);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(81, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"btn";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1036, 265);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(81, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1036, 352);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btbHistorgam);
			this->Controls->Add(this->btnScaleTool);
			this->Controls->Add(this->panel);
			this->Controls->Add(this->menu);
			this->KeyPreview = true;
			this->MainMenuStrip = this->menu;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuOpenFile_Click(System::Object^ sender, System::EventArgs^ e) {

		MainForm::LoadImg();

	}


	private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		//phong to anh/thu nho anh
		if (e->Modifiers == Keys::Control)
		{
			int width = 0, height = 0;
			if (e->KeyCode == Keys::Oemplus)
			{
				width = (int)(pictureBox->Width * IMAGE_SCALE);
				height = (int)(pictureBox->Height * IMAGE_SCALE);
				if (width > maxWidthImg) width = maxWidthImg;
				if (height > maxHeightImg) height = maxHeightImg;
				pictureBox->Width = width;
				pictureBox->Height = height;
			}
			else if (e->KeyCode == Keys::OemMinus)
			{
				width = (int)(pictureBox->Width / IMAGE_SCALE);
				height = (int)(pictureBox->Height / IMAGE_SCALE);
				if (width <= 100) width = 100;
				if (height <= 100) height = 100;
				pictureBox->Width = width;
				pictureBox->Height = height;
			}
		}
	}

	private: System::Void BtnScaleTool_Click(System::Object ^ sender, System::EventArgs ^ e) {
		if (pictureBox->Image != nullptr)
		{
			if (isOpenToolForm == false)
			{
				MiniPhotoshop::ToolForm^ form = gcnew ToolForm();
				form->Show();
				isOpenToolForm = true;
			}
		}
		else MessageBox::Show("Vui long mo file truoc.");
	}

	public: void LoadImg();
	public:static void DisplayPictureBox(Mat mat);

	public: static Mat getImage();//lay Mat hinh anh opencv
	public: static void setImage(Mat mat);
	public: static Mat getImageTmp();//lay Mat hinh anh opencv
	public: static void setImageTmp(Mat mat);
	private: System::Void MenuSave_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void MenuSaveAs_Click(System::Object ^ sender, System::EventArgs ^ e);
	private: System::Void PictureBox_MouseDown(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e) {
		isMouseDown = true;
		p1 = e->Location;
		pictureBox->Invalidate();

	}
	private: System::Void PictureBox_MouseMove(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e) {
		if (isMouseDown == true)
		{
			p2 = e->Location;
		}
	}

	private: System::Void PictureBox_MouseUp(System::Object ^ sender, System::Windows::Forms::MouseEventArgs ^ e) {
		if (isMouseDown == true)
		{
			p2 = e->Location;
			DrawTangle();
			isMouseDown = false;
		}
	}
			 void DrawTangle()
			 {
				 if (isMouseDown == true)
				 {
					 rec.X = Math::Min(p1->X, p2->X);
					 rec.Y = Math::Min(p1->Y, p2->Y);
					 rec.Width = Math::Abs(p1->X - p2->X);
					 rec.Height = Math::Abs(p1->Y - p2->Y);
					 Graphics ^ graphics = pictureBox->CreateGraphics();
					 graphics->DrawRectangle(gcnew Pen(Color::Red), rec);
				 }
			 }
	private: System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
	}
	private: System::Void BtbHistorgam_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (pictureBox->Image != nullptr)
		{
			MiniPhotoshop::HistogramForm^ h = gcnew HistogramForm();
			h->HistogramGray();
			h->Show();
		}
		else MessageBox::Show("vui long mo file truoc.");
	}
	};

}

