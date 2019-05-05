#include "HandleImage.h"
# define M_PI 3.14159265358979323846  //pi
namespace MiniPhotoshop
{
	std::string HandleImage::toStdString(System::String^ str)
	{
		std::string stdString = marshal_as<std::string>(str);
		return stdString;
	}
	//save file
	void HandleImage::SaveImg(std::string str, Mat img)
	{
		imwrite(str, img);
	}

	//xoay anh
	Mat HandleImage::rotationImg(float theta, Mat img)
	{
		Mat src, frame, frameRotated;
		src = img;


		int diagonal = (int)sqrt(src.cols * src.cols + src.rows * src.rows);
		int newWidth = diagonal;
		int newHeight = diagonal;

		int offsetX = (newWidth - src.cols) / 2;
		int offsetY = (newHeight - src.rows) / 2;
		Mat targetMat(newWidth, newHeight, src.type());
		Point2f src_center(targetMat.cols / 2.0F, targetMat.rows / 2.0F);

		src.copyTo(frame);
		double radians = theta * M_PI / 180.0;
		double sin = abs(std::sin(radians));
		double cos = abs(std::cos(radians));

		frame.copyTo(targetMat.rowRange(offsetY, offsetY + frame.rows).colRange(offsetX, offsetX + frame.cols));
		Mat rot_mat = getRotationMatrix2D(src_center, theta, 1.0);
		warpAffine(targetMat, frameRotated, rot_mat, targetMat.size());
		//Calculate bounding rect and for exact image
		Rect bound_Rect(frame.cols, frame.rows, 0, 0);

		int x1 = offsetX;
		int x2 = offsetX + frame.cols;
		int x3 = offsetX;
		int x4 = offsetX + frame.cols;

		int y1 = offsetY;
		int y2 = offsetY;
		int y3 = offsetY + frame.rows;
		int y4 = offsetY + frame.rows;

		Mat co_Ordinate = (Mat_<double>(3, 4) << x1, x2, x3, x4,
			y1, y2, y3, y4,
			1, 1, 1, 1);
		Mat RotCo_Ordinate = rot_mat * co_Ordinate;

		for (int i = 0; i < 4; i++) {
			if (RotCo_Ordinate.at<double>(0, i) < bound_Rect.x)
				bound_Rect.x = (int)RotCo_Ordinate.at<double>(0, i); //access smallest 
			if (RotCo_Ordinate.at<double>(1, i) < bound_Rect.y)
				bound_Rect.y = RotCo_Ordinate.at<double>(1, i); //access smallest y
		}

		for (int i = 0; i < 4; i++) {
			if (RotCo_Ordinate.at<double>(0, i) > bound_Rect.width)
				bound_Rect.width = (int)RotCo_Ordinate.at<double>(0, i); //access largest x
			if (RotCo_Ordinate.at<double>(1, i) > bound_Rect.height)
				bound_Rect.height = RotCo_Ordinate.at<double>(1, i); //access largest y
		}

		bound_Rect.width = bound_Rect.width - bound_Rect.x;
		bound_Rect.height = bound_Rect.height - bound_Rect.y;

		Mat cropedResult;
		Mat ROI = frameRotated(bound_Rect);
		ROI.copyTo(cropedResult);

		return cropedResult;
	}

	Mat HandleImage::CropImg(Mat mat, int x, int y, int width, int height)
	{
		cv::Rect myRoi(x, y, width, height);
		Mat cropImg = mat(myRoi);
		return cropImg;
	}
}