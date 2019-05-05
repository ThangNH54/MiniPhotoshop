#include "MainForm.h"

using namespace System;
Mat image;//hinh anh su dung trong chinh sua
Mat imageTmp;//hinh anh su dung de luu ban sao anh goc.
std::string currentPath = "";
[STAThreadAttribute]


int main()
{
	System::Windows::Forms::Application::Run(gcnew MiniPhotoshop::MainForm());

	return 0;
}

namespace MiniPhotoshop
{
	Mat MainForm::getImage()
	{
		return image.clone();
	}
	void MainForm::setImage(Mat mat)
	{
		image = mat.clone();

	}
	Mat MainForm::getImageTmp()
	{
		return imageTmp.clone();
	}
	void MainForm::setImageTmp(Mat mat)
	{
		imageTmp = mat.clone();

	}

	void MainForm::LoadImg()
	{

		OpenFileDialog^ open = gcnew OpenFileDialog;

		open->Filter = "Image Files(*.jpg; *.jpeg; *.gif; *.bmp)|*.jpg; *.jpeg; *.gif; *.bmp";
		if (open->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{

			pictureBox->SizeMode = PictureBoxSizeMode::Zoom;


			std::string fileName = HandleImage::toStdString(open->FileName->ToString());
			currentPath = fileName;

			image = imread(fileName, cv::IMREAD_COLOR);
			imageTmp = image.clone();
			DisplayPictureBox(image);

			imgX = pictureBox->Image->Width;
			imgY = pictureBox->Image->Height;

		}
	}
	void MainForm::DisplayPictureBox(Mat mat)
	{
		cv::Size s = mat.size();
		MainForm::pictureBox->Width = mat.cols;
		MainForm::pictureBox->Height = mat.rows;

		cvtColor(mat, mat, cv::COLOR_BGR2BGRA);
		HBITMAP hBit = CreateBitmap(mat.cols, mat.rows, 1, 32, mat.data);


		Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);

		MainForm::pictureBox->Image = bmp;
	}

	Void MainForm::MenuSave_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			HandleImage::SaveImg(currentPath, MainForm::getImage());
		}
		catch (const std::exception&)
		{

		}

	}
	Void MainForm::MenuSaveAs_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
			saveFileDialog->Title = "Save an Image File";
			saveFileDialog->ShowDialog();

			// If the file name is not an empty string open it for saving.  
			if (saveFileDialog->FileName != "")
			{
				HandleImage::SaveImg(HandleImage::toStdString(saveFileDialog->FileName->ToString()), MainForm::getImage());
			}
		}
		catch (const std::exception&)
		{

		}

	}
}