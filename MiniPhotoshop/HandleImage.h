#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
#endif // 

#include <opencv2/opencv.hpp>
using namespace cv;
namespace MiniPhotoshop
{
	public class HandleImage
	{


	public: static std::string toStdString(System::String^ str);
	public:static Mat rotationImg(float theta, Mat img);
	public: static	void SaveImg(std::string str, Mat);
	public:static 	Mat CropImg(Mat mat, int x, int y, int width, int height);
	};
}