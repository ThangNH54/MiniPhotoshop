#include "MixImage.h"
#include "HandleImage.h"
namespace MiniPhotoshop
{
	void DisplayPictureBox(Mat, PictureBox^);
	Mat input, bg, output;
	Void MixImage::BtnOpenInput_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ open = gcnew OpenFileDialog;

		open->Filter = "Image Files(*.jpg; *.jpeg; *.gif; *.bmp)|*.jpg; *.jpeg; *.gif; *.bmp";
		if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			pictureBoxInput->SizeMode = PictureBoxSizeMode::Zoom;

			std::string fileName = HandleImage::toStdString(open->FileName->ToString());

			input = imread(fileName, cv::IMREAD_COLOR);
			DisplayPictureBox(input, pictureBoxInput);
		}
	}
	Void MixImage::BtnOpenBg_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ open = gcnew OpenFileDialog;

		open->Filter = "Image Files(*.jpg; *.jpeg; *.gif; *.bmp)|*.jpg; *.jpeg; *.gif; *.bmp";
		if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			pictureBoxBg->SizeMode = PictureBoxSizeMode::Zoom;

			std::string fileName = HandleImage::toStdString(open->FileName->ToString());

			bg = imread(fileName, cv::IMREAD_COLOR);
			DisplayPictureBox(bg, pictureBoxBg);

		}
	}
	Void MixImage::BtnMix_Click(System::Object^ sender, System::EventArgs^ e)
	{
		pictureBoxOut->SizeMode = PictureBoxSizeMode::Zoom;
		Mat srcMask = 255 * Mat::ones(input.rows, input.cols, input.depth());
		cv::Point center(bg.cols / 2, bg.rows / 2);
		cv::seamlessClone(input, bg, srcMask, center, output, MIXED_CLONE);
		DisplayPictureBox(output, pictureBoxOut);
	}
	void DisplayPictureBox(Mat mat, PictureBox^ pic)
	{
		cv::Size s = mat.size();
		cvtColor(mat, mat, cv::COLOR_BGR2BGRA);
		HBITMAP hBit = CreateBitmap(mat.cols, mat.rows, 1, 32, mat.data);

		Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);
		pic->Image = bmp;
	}
}

