#include "action.h"
#include <iostream>


void Action::FillVect(double minRad, double maxRad)
{
    //���� ������ ������� �� nullptr, ��
    //���� ������ ��������, ����� ������ ����
    //�.�. ����������� � ������������ ������ �������
    if (vect[0] != nullptr) 
    {
        Clear();
    }

    unsigned count = 0;

    int cnt = 0;
    while (count != vect.size()) //���� ���������� �������
    {
        size_t pos;
        //����� ������� ��� ����������
        pos = rand() % vect.size();
        while (vect[pos] != nullptr)
            pos = (pos + 1) % vect.size();

        int var = rand() % 2; //����� ���� ������: ���������� ��� ������
        ++cnt;
        switch (var) {
        case 0:
            vect[pos] = new Elipse(generate(1, 100),
                                    generate(1, 100),
                                    generate(minRad, maxRad), 
                                    generate(minRad, maxRad));
            break;
        case 1:
            vect[pos] = new Circle(generate(1, 100),
                                    generate(1, 100),
                                    generate(minRad, maxRad));
            break;
        }
        SumArea += vect[pos]->GetArea();        //���������� ����� �������
        ++count;
    }
}

void Action::CalcArea()
{
    //���������� ����� �������� ������
    if (vect[0] == nullptr)
        return;
    SumArea = 0;
    for (size_t pos = 0; pos < vect.size(); ++pos)
    {
        SumArea += vect[pos]->GetArea();
    }
}

void Action::Clear() //�������� ������
{
    if (vect[0] == nullptr)
        return;
    for (auto cur : vect)
        delete cur;
    int size = vect.size();
    vect.clear();
    vect.resize(size);
    SumArea = 0;
}

//������������� �����
double Action::generate(double min, double max)
{
    random_device dev;
    mt19937 ger(dev());
    uniform_real_distribution<> dist(min, max);
    return dist(ger);
}

Action::Action(size_t size) : vect(size), SumArea(0) {}

Action::~Action()
{
    if (vect[0] == nullptr)
        return;
    for (auto cur : vect)
    {
        delete cur;
    }
}

void Action::SortVector()
{
    if (vect[0] == nullptr)
        return;

    sort(vect.begin(), vect.end(), [](Circle* s1, Circle* s2) {
        return  s1->GetArea() < s2->GetArea();
        });
}

double Action::GetSumArea()
{
    return SumArea;
}

vector<Circle*> Action::GetVect()
{
    return vect;
}

void Action::SetSizeVector(size_t size) //�������� ������ �������
{
    Clear();

    vect.resize(size);
}

ostream& operator<<(ostream& os, const Action& act)
{
    if (act.vect.size() != 0 && act.vect[0] != nullptr)
    {
        for (size_t pos = 0; pos != act.vect.size(); ++pos)
        {
            os << "Figure area " << pos << ": " << act.vect[pos]->GetArea() << endl;
        }
    }
    return os;
}
