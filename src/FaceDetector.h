#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <opencv2/opencv.hpp>
#include <QDir>
#include <QDebug>
#include <QApplication>

using namespace std;
using namespace cv;

//������������ "��������" ����

CascadeClassifier faceCascadeClassifiler; //��������� ������������ ��� ����������� ��������

void RemoveFaces(Mat input, Mat output)//�������� ����
{
    String faceClassifilerFilName =  qApp->applicationDirPath().toStdString() + "/res/haarcascade_frontalface_alt.xml";
    assert(!input.empty());
    assert(faceCascadeClassifiler.load(faceClassifilerFilName));

    vector<Rect> faces;//������ ���������������

    Mat frameGray;
    cvtColor(input, frameGray, COLOR_RGB2GRAY);//������� ����������� � ����� ����
    equalizeHist(frameGray, frameGray);//������������ ����������� �����������

    faceCascadeClassifiler.load(faceClassifilerFilName);//��������� �������������
    faceCascadeClassifiler.detectMultiScale(frameGray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(120, 120));//����� ���

    //����������� ����
    for (unsigned i = 0; i < faces.size(); i++)
        rectangle(output, Point(faces[i].x, faces[i].y-55), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height+70), Scalar(0, 0, 0), -1);
};

#endif
