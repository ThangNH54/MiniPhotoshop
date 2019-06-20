#include "HistogramForm.h"
#include "MainForm.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <stdio.h>
#include <string.h>

///
using namespace cv;
namespace MiniPhotoshop
{

	MiniPhotoshop::HistogramForm::HistogramForm()
	{
		InitializeComponent();
	}


	Void HistogramForm::loadHistogram(Mat img)
	{
		Mat imgHistogram = img;
		cvtColor(imgHistogram, imgHistogram, cv::COLOR_BGR2BGRA);

		HBITMAP hBit = CreateBitmap(imgHistogram.cols, imgHistogram.rows, 1, 32, imgHistogram.data);

		Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);
		HistogramForm::pictureHitogram->Image = bmp;
	}
	Void HistogramForm::loadHistogramCanny(Mat img)
	{
		Mat imgHistogram = img;
		cvtColor(imgHistogram, imgHistogram, cv::COLOR_BGR2BGRA);

		HBITMAP hBit = CreateBitmap(imgHistogram.cols, imgHistogram.rows, 1, 32, imgHistogram.data);

		Bitmap^ bmp = Bitmap::FromHbitmap((IntPtr)hBit);
		HistogramForm::pictureHistogramCanny->Image = bmp;
	}

	void HistogramForm::HistogramGray()
	{
		Mat image1_gray;
		cvtColor(MainForm::getImageTmp(), image1_gray, cv::COLOR_BGR2GRAY);
		Mat* img = &image1_gray;
		int bins = 256;
		int histSize[] = { bins };
		// Set ranges for histogram bins
		float lranges[] = { 0, 256 };
		const float* ranges[] = { lranges };
		// create matrix for histogram
		cv::Mat hist;
		int channels[] = { 0 };

		// create matrix for histogram visualization
		int const hist_height = 400;
		cv::Mat3b hist_image = cv::Mat3b::zeros(hist_height, bins);

		cv::calcHist(img, 1, channels, cv::Mat(), hist, 1, histSize, ranges, true, false);

		double max_val = 0;
		minMaxLoc(hist, 0, &max_val);

		// visualize each bin
		for (int b = 0; b < bins; b++) {
			float const binVal = hist.at<float>(b);
			int   const height = cvRound(binVal * hist_height / max_val);
			cv::line(hist_image,
				cv::Point(b, hist_height - height),
				cv::Point(b, hist_height),
				cv::Scalar::all(255));
		}
		HistogramForm::loadHistogram(hist_image);
		HistogramForm::loadHistogramCanny(hist_image);
	}

	Void HistogramForm::BtnDispay_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//g(x) = Contrast f(x) + Bright
		int b = trackBright->Value;
		double c = (double)(trackContrast->Value) / 10;
		Mat src = MainForm::getImageTmp().clone();
		Mat new_image = Mat::zeros(src.size(), src.type());
		for (int y = 0; y < src.rows; y++) {
			for (int x = 0; x < src.cols; x++) {
				for (int c = 0; c < 3; c++) {
					new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(c * (src.at<Vec3b>(y, x)[c]) + b);
				}
			}
		}
		MainForm::DisplayPictureBox(new_image);
	}
	Mat HistogramForm::correctGamma(Mat& img, double gamma) {
		double inverse_gamma = 1.0 / gamma;

		Mat lut_matrix(1, 256, CV_8UC1);
		uchar* ptr = lut_matrix.ptr();
		for (int i = 0; i < 256; i++)
			ptr[i] = (int)(pow((double)i / 255.0, inverse_gamma) * 255.0);

		Mat result;
		LUT(img, lut_matrix, result);

		return result;
	}

	Void HistogramForm::BtnGamma_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Mat img = MainForm::getImageTmp().clone();
		double valueGamma = (double)(trackContrast->Value) / 10;
		Mat result = HistogramForm::correctGamma(img, valueGamma);
		MainForm::DisplayPictureBox(result);
	}

	Mat	HistogramForm::HistogramRGB(char* imgColor)
	{
		Mat imageSrc = MainForm::getImageTmp().clone();

		std::vector<Mat> imageRGB;
		// Khởi tạo các biến lưu trữ 3 bênh màu
		Mat imageRed, imageGreen, imageBlue;

		int width = 256, height = 400;
		int sizeHistogram = 255;
		float range[] = { 0, 255 };
		const float* histogramRange = { range };

		// Hàm này có tác dụng tách imageSrc thành 3 kênh màu.
		split(imageSrc, imageRGB);

		// Tính toán cho từng kênh màu và vẽ biểu đồ Histogram
		calcHist(&imageRGB[0], 1, 0, Mat(), imageRed, 1, &sizeHistogram, &histogramRange, true, false);
		calcHist(&imageRGB[1], 1, 0, Mat(), imageGreen, 1, &sizeHistogram, &histogramRange, true, false);
		calcHist(&imageRGB[2], 1, 0, Mat(), imageBlue, 1, &sizeHistogram, &histogramRange, true, false);

		int bin = cvRound((double)width / sizeHistogram);

		Mat dispRed(width, height, CV_8UC3, Scalar(255, 255, 255));
		Mat dispGreen = dispRed.clone();
		Mat dispBlue = dispRed.clone();

		normalize(imageBlue, imageBlue, 0, dispBlue.rows, NORM_MINMAX, -1, Mat());
		normalize(imageGreen, imageGreen, 0, dispGreen.rows, NORM_MINMAX, -1, Mat());
		normalize(imageRed, imageRed, 0, dispRed.rows, NORM_MINMAX, -1, Mat());

		for (int i = 0; i < 255; i++)
		{
			line(dispRed, cv::Point(bin * (i), height), cv::Point(bin * (i), height - cvRound(imageRed.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
			line(dispGreen, cv::Point(bin * (i), height), cv::Point(bin * (i), height - cvRound(imageGreen.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
			line(dispBlue, cv::Point(bin * (i), height), cv::Point(bin * (i), height - cvRound(imageBlue.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
		}
		if (strcmp(imgColor, "RED") == 0)
			return dispRed;
		if (strcmp(imgColor, "GREEN") == 0)
			return dispGreen;
		if (strcmp(imgColor, "BLUE") == 0)
			return dispBlue;
	}

	Mat HistogramForm::CannyEdgeDetection(Mat img)
	{
		Mat imgBinary, imgGauss, imgCanny;
		cvtColor(img.clone(), imgBinary, ::COLOR_BGR2GRAY);
		GaussianBlur(imgBinary, imgGauss, cv::Size(5, 5), 0);
		Canny(imgGauss, imgCanny, (double)(tbNguongT->Value), (double)(tbNguongH->Value), 5);
		return imgCanny;
	}

	Void HistogramForm::BtnHGray_Click(System::Object^ sender, System::EventArgs^ e)
	{
		HistogramGray();
	}
	Void HistogramForm::BtnHGreen_Click(System::Object^ sender, System::EventArgs^ e)
	{
		HistogramForm::loadHistogram(HistogramForm::HistogramRGB("GREEN"));
	}
	Void HistogramForm::BtnHRed_Click(System::Object^ sender, System::EventArgs^ e)
	{
		HistogramForm::loadHistogram(HistogramForm::HistogramRGB("RED"));
	}
	Void HistogramForm::BntHBlue_Click(System::Object^ sender, System::EventArgs^ e)
	{
		HistogramForm::loadHistogram(HistogramForm::HistogramRGB("BLUE"));
	}
	Void HistogramForm::BtnCannyvcl_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Mat imgSrc = MainForm::getImage().clone();
		Mat result = HistogramForm::CannyEdgeDetection(imgSrc);
		namedWindow("Canny_Edge_Detection");
		imshow("Canny_Edge_Detection", result);
		waitKey(0);
	}
}
