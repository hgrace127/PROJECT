#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

/* Line Detection */
void Dilation(const Mat& image, Mat& result, int type = 0, int size = 3);
void Erosion(const Mat& image, Mat& result, int type = 0, int size = 3);
void Morphology(const Mat& image, Mat& result, int op, int type = 0, int size = 3);
