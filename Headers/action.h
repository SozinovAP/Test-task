#pragma once

#include "circle.h"
#include "elipse.h"
#include <vector>
#include <random>
#include <ctime>


using namespace std;

//����� ���������� ��������
class Action
{
protected:
    vector<Circle*> vect;                       //������ ������
    double SumArea;                            //����� ��������
    double generate(double min, double max);    //����� ��������� �������

public:
    Action(size_t size = 0);
    ~Action();
    
    void SortVector();                                      //���������� ������� �� ���������� ��������
    void FillVect(double minRad = 1, double maxRad = 100);  //��������� ������
    void CalcArea();                                       //��������� ����� �������
    void Clear();                                           //�������� ������

    double GetSumArea();                                   //�������� ����� ��������
    vector<Circle*> GetVect();                             //�������� ������
    void SetSizeVector(size_t size);                        //�������� ������ �������

    friend ostream& operator<< (ostream& os, const Action& act);
};

ostream& operator<< (ostream& os, const Action& act);
