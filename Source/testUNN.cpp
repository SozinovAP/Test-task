#include <iostream>
#include "action.h"
#include <string>
int main()
{
    int vectSize;
    int minRange = 1, maxRange = 100;
    do
    {
        std::cout << "Input vector size (> 0): ";
        std::cin >> vectSize;
    } while (vectSize <= 0);

    Action act(vectSize);

    string choice;
    std::cout << "Standart radius range [1:100]" << endl;
    std::cout << "Do you want to change the radius range?" << endl;
    do
    {
        std::cout << "1 - yes" << endl << "2 - no" << endl;
        std::cin >> choice;
    } while (choice != "1" && choice != "2");

    if (choice == "1")
    {
        std::cout << "Input radius range" << endl;
        do
        {
            std::cout << "minimum (> 0): ";
            std::cin >> minRange;
        } while (minRange <= 0);
        
        do
        {
            std::cout << "maximum (> 0): ";
            std::cin >> maxRange;
        } while (maxRange <= 0);
    }

    //Первоначальное заполнение вектора
    act.FillVect(min(minRange, maxRange), max(minRange, maxRange));
    cout << "Output areas before sorting: " << endl;
    cout << act << endl;
    act.SortVector();   //сортировка элементов в векторе
    cout << "Output areas after sorting: " << endl;
    cout << act << endl;
    act.CalcArea();     //подсчет суммы площадей
    cout << "Summa areas: " << act.GetSumArea() << endl;

    //Заново заполняем вектор другими фигурами
    cout << "Filling vector new figures" << endl;
    act.FillVect(min(minRange, maxRange), max(minRange, maxRange));
    cout << "Output areas before sorting: " << endl;
    cout << act << endl;
    act.SortVector();   //сортировка элементов в векторе
    cout << "Output areas after sorting: " << endl;
    cout << act << endl;
    //Вывод новой суммы площадей фигур (сумма считается при заполнении вектора)
    cout << "Summa areas: " << act.GetSumArea() << endl;

    //Заполняем вектор новыми элементами, используя пределы радиуса по умолчанию
    cout << "Filling vector new figures. Default radius limits are used" << endl;
    act.FillVect();
    cout << "Output areas before sorting: " << endl;
    cout << act << endl;
    act.SortVector();   //сортировка элементов в векторе
    cout << "Output areas after sorting: " << endl;
    cout << act << endl;
    //Вывод новой суммы площадей фигур
    cout << "Summa areas: " << act.GetSumArea() << endl;

    do
    {
        std::cout << "Input new vector size (> 0): ";
        std::cin >> vectSize;
    } while (vectSize <= 0);

    //Изменяем размер вектора
    cout << "Resize vector figures" << endl;
    act.SetSizeVector(vectSize);

    //Заполнение нового вектора
    act.FillVect(min(minRange, maxRange), max(minRange, maxRange));
    cout << "Output areas before sorting: " << endl;
    cout << act << endl;
    act.SortVector();   //сортировка элементов в векторе
    cout << "Output areas after sorting: " << endl;
    cout << act << endl;
    //Вывод суммы площадей фигур в новом векторе
    cout << "Summa areas: " << act.GetSumArea() << endl;
    return 0;

}
