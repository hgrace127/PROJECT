#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

void Dilation(const Mat& image, Mat& result, int type, int size){
	// allcation if necessary
	result.create(image.size(), image.type());

	int dilation_type;
	if (type == 0)
		dilation_type = MORPH_RECT;
	else if (type == 1)
		dilation_type = MORPH_CROSS;
	else if (type == 2)
		dilation_type = MORPH_ELLIPSE;

	Mat element = getStructuringElement(dilation_type, Size(size, size)); 
	
	// Apply the dilation operation
	dilate(image, result, element);
}

void Erosion(const Mat &image, Mat& result, int type, int size){
	result.create(image.size(), image.type());

	int erosion_type;
	if (type == 0)
		erosion_type = MORPH_RECT;
	else if (type == 1)
		erosion_type = MORPH_CROSS;
	else if (type == 2)
		erosion_type = MORPH_ELLIPSE;
	
	Mat element = getStructuringElement(erosion_type, Size(size, size));

	erode(image, result, element);
}

void Morphology(const Mat& image, Mat& result, int op, int type, int size){
	result.create(image.size(), image.type());

	int operation;
	switch (op){
	case 0:
		operation = MORPH_OPEN;
		break;
	case 1:
		operation = MORPH_CLOSE;
		break;
	case 2:
		operation = MORPH_GRADIENT;
		break;
	case 3:
		operation = MORPH_TOPHAT;
		break;
	case 4:
		operation = MORPH_BLACKHAT;
		break;
	}

	int mor_type;
	if (type == 0){
		mor_type = MORPH_RECT;
	}
	else if (type == 1){
		mor_type = MORPH_CROSS;
	}
	else if (type == 2){
		mor_type = MORPH_ELLIPSE;
	}

	Mat element = getStructuringElement(mor_type, Size(size, size));
	morphologyEx(image, result, op, element);
}