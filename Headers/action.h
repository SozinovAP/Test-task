#pragma once

#include "circle.h"
#include "elipse.h"
#include <vector>
#include <random>
#include <ctime>


using namespace std;

//класс выполнения действий
class Action
{
protected:
    vector<Circle*> vect;                       //вектор кривых
    double SumArea;                            //сумма площадей
    double generate(double min, double max);    //метод генерации радиуса

public:
    Action(size_t size = 0);
    ~Action();
    
    void SortVector();                                      //сортировка вектора по увеличению площадей
    void FillVect(double minRad = 1, double maxRad = 100);  //заполнить вектор
    void CalcArea();                                       //вычислить сумму плоадей
    void Clear();                                           //очистить вектор

    double GetSumArea();                                   //полуичть сумма площадей
    vector<Circle*> GetVect();                             //получить вектор
    void SetSizeVector(size_t size);                        //изменить размер вектора

    friend ostream& operator<< (ostream& os, const Action& act);
};

ostream& operator<< (ostream& os, const Action& act);
