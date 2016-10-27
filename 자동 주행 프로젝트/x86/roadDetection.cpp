
#include "LineDetection.h"

int main(){
	
	VideoCapture video("road.mp4");
	if (!video.isOpened()){
		printf("VIDEO OPEN ERROR\n");
	}
	
	video.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	video.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	
	Mat image, gray, result, edge;
	// namedWindow("RoadVideo");
	namedWindow("Threshold Video");
	namedWindow("Edge Video");
	int thresValue = 0;	// threshold value

	cvCreateTrackbar("Threshold", "Edge Video", &thresValue, 255);
	cvCreateTrackbar("Threshold", "Threshold Video", &thresValue, 255);
	while (1){
		video >> image;
		cvtColor(image, gray, CV_BGR2GRAY);

		// Threshold video test
		threshold(gray, result, thresValue, 255, CV_THRESH_BINARY);
		
		// Line Detection video test
		Dilation(gray, gray);
		Erosion(gray, gray);
		Morphology(gray, gray, 4);

		Canny(gray, edge, thresValue, 200);
		
		imshow("Threshold Video", result);
		imshow("Edge Video", edge);

		if (waitKey(30) >= 0) 
			break;
	}

	return 0;
}

