#ifndef SMOOTHFUNCTION_H
#define SMOOTHFUNCTION_H

#include <cassert>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void Gauss(Mat input, Mat output, int n, int size_g, double sigmaX, int size_k, int iteration_e, int iteration_d)//�������� �� ������ + ���������� �� ����
{
    assert(!input.empty());

    for (int i = 0; i < n; i++)
    {
        GaussianBlur(input, output, Size(size_g, size_g), sigmaX);
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(size_k, size_k));
        erode(input, input, kernel, Point(-1, -1), iteration_e);//�������
        dilate(input, input, Mat(), Point(-1, -1), iteration_d);//����������
    }

    assert(!output.empty());
}

#endif
