#include <stdio.h>
#include <iostream>
#include <vector>

#include <opencv.hpp>
#include <imgproc\types_c.h>
#include <imgcodecs.hpp>
#include <core.hpp>
#include <imgproc.hpp>
#include <highgui.hpp>
#include <objdetect.hpp>
//#include <highgui\highgui_winrt.hpp>

int main()
{
	/* ????????????? */
	cv::CascadeClassifier face_cascade;
	cv::Mat image = cv::imread("group1.jpg");
	cv::Mat groupFaces = cv::Mat(image.rows, image.cols, CV_8UC4);
	cv::cvtColor(image, groupFaces, cv::COLOR_BGR2BGRA);
	//cv::winrt_initContainer(cvContainer);
	cv::imshow(std::string("Window 1"), groupFaces);

	if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
		std::cout << "Couldn't load face detector" << std::endl;
	}

	/* ??????????? */
	if (!groupFaces.empty()) {
		std::vector<cv::Rect> facesColl;
		cv::Mat frame_gray;

		cvtColor(groupFaces, frame_gray, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(frame_gray, frame_gray);

		// Detect faces
		face_cascade.detectMultiScale(frame_gray,
			facesColl,
			1.1, 2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(1, 1));
		for (unsigned int i = 0; i < facesColl.size(); i++)
		{
			auto face = facesColl[i];
			cv::rectangle(groupFaces, face, cv::Scalar(0, 255, 255), 5);
		}

		cv::imshow(std::string("Window 2"), groupFaces);
	}
	else {
		std::cout << "Initialize image before processing" << std::endl;
	}

	cv::waitKey();
	system("Pause");
	return 0;
}