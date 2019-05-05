#include "HistogramForm.h"
#include "MainForm.h"
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
			cv::line
			(hist_image
				, cv::Point(b, hist_height - height), cv::Point(b, hist_height)
				, cv::Scalar::all(255)
			);
		}
		HistogramForm::loadHistogram(hist_image);
	}

	Void HistogramForm::BtnDispay_Click(System::Object ^ sender, System::EventArgs ^ e)
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
	Mat HistogramForm::correctGamma(Mat & img, double gamma) {
		double inverse_gamma = 1.0 / gamma;

		Mat lut_matrix(1, 256, CV_8UC1);
		uchar* ptr = lut_matrix.ptr();
		for (int i = 0; i < 256; i++)
			ptr[i] = (int)(pow((double)i / 255.0, inverse_gamma) * 255.0);

		Mat result;
		LUT(img, lut_matrix, result);

		return result;
	}
	Void HistogramForm::BtnGamma_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		Mat img = MainForm::getImageTmp().clone();
		double valueGamma = (double)(trackContrast->Value) / 10;
		Mat result = HistogramForm::correctGamma(img, valueGamma);
		MainForm::DisplayPictureBox(result);
	}
}