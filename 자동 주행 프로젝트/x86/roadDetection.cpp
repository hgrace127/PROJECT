
#include "LineDetection.h"

void RoadDetection(Mat& gray, Mat& edge, int thresValue){
	
	Canny(gray, edge, thresValue, 200);

}