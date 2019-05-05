#include "ToolForm.h"
#include "MainForm.h"

#define IMG_SCALE 0.05f
namespace MiniPhotoshop
{
	Mat img;
	MiniPhotoshop::ToolForm::ToolForm()
	{
		InitializeComponent();
		//
		txtWidth->Text = MainForm::imgX.ToString();
		txtHeight->Text = MainForm::imgY.ToString();
		MainForm::setImageTmp(MainForm::getImage());
		//
	}

	//thay doi chieu rong theo trachbar
	Void ToolForm::trackBarWidth_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		int x = trackBarWidth->Value;
		if (x != 0 && MainForm::getImage().rows + (int)MainForm::getImage().rows * x * IMG_SCALE > 0)
		{
			cv::resize(MainForm::getImage(), img, cv::Size(MainForm::getImage().rows + (int)MainForm::getImage().rows * x * IMG_SCALE, MainForm::getImage().cols));
			MainForm::DisplayPictureBox(img);
			txtWidth->Text = MainForm::pictureBox->Width.ToString();
		}


	}

	//thay doi chieu dai theo trackbar
	Void ToolForm::trackBarHeight_Scroll(System::Object^ sender, System::EventArgs^ e)
	{
		int y = trackBarHeight->Value;
		if (y != 0 && (MainForm::getImage().cols + (int)MainForm::getImage().cols * y * IMG_SCALE > 0))
		{

			cv::resize(MainForm::getImage(), img, cv::Size(MainForm::getImage().rows, MainForm::getImage().cols + (int)MainForm::getImage().cols * y * IMG_SCALE));
			MainForm::DisplayPictureBox(img);
			txtHeight->Text = MainForm::pictureBox->Height.ToString();
		}
	}

	//reset
	Void ToolForm::BtnReset_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		MainForm::setImage(MainForm::getImageTmp());
		MainForm::DisplayPictureBox(MainForm::getImage());
		txtWidth->Text = MainForm::pictureBox->Width.ToString();
		txtHeight->Text = MainForm::pictureBox->Height.ToString();

	}

	//thay doi chieu rong theo textbox
	Void ToolForm::TxtWidth_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		try
		{
			int x = int::Parse(txtWidth->Text);
			int y = int::Parse(txtHeight->Text);
			if (x > 0 && y > 0)
			{
				cv::resize(MainForm::getImage(), img, cv::Size(x, y));

				MainForm::DisplayPictureBox(img);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->ToString());
		}
	}

	//thay doi chieu dai theo textBox
	Void ToolForm::TxtHeight_TextChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		try
		{
			int x = int::Parse(txtWidth->Text);
			int y = int::Parse(txtHeight->Text);
			if (x > 0 && y > 0)
			{
				cv::resize(MainForm::getImage(), img, cv::Size(x, y));

				MainForm::DisplayPictureBox(img);
			}

		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->ToString());
		}
	}
	//xoay anh
	Void ToolForm::BtnXoay_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		try
		{
			int theta = int::Parse(txtRotation->Text);
			if (theta != 0)
			{
				img = HandleImage::rotationImg(theta, MainForm::getImage());
				MainForm::DisplayPictureBox(img);
			}
		}
		catch (System::Exception ^ e)
		{
			MessageBox::Show(e->ToString());
		}
	}
	//cat anh
	Void ToolForm::BtnCrop_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (!MainForm::rec.IsEmpty)
		{
			img = HandleImage::CropImg(MainForm::getImage(), MainForm::rec.X, MainForm::rec.Y, MainForm::rec.Width, MainForm::rec.Height);
			MainForm::DisplayPictureBox(img);
		}
		else
		{
			MessageBox::Show("Select Area!");
		}
	}


	//xac nhan thay doi
	Void ToolForm::BtnOk_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		MainForm::setImage(img);
		MainForm::imgX = MainForm::pictureBox->Image->Width;
		MainForm::imgY = MainForm::pictureBox->Image->Height;
		this->Close();
	}
	Void ToolForm::BtnCancel_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		MainForm::setImage(MainForm::getImageTmp());
		MainForm::DisplayPictureBox(MainForm::getImage());
		MainForm::isOpenToolForm = false;
		this->Close();

	}

	Void ToolForm::tabControl_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		txtRotation->Text = "0";
		if (!img.empty())
		{
			MainForm::setImage(img);

		}
		else
		{
			img = MainForm::getImage();
		}
		switch (tabControl->SelectedIndex) {
		case 0:
		{
			//txtWidth->Text = MainForm::pictureBox->Width.ToString();
			//txtHeight->Text = MainForm::pictureBox->Height.ToString();
			break;
		}
		}
	}

}