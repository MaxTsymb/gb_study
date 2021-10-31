﻿/*
1.Добавить в контейнерный класс, который был написан в этом уроке, методы:
+ для удаления последнего элемента массива (аналог функции pop_back() в векторах)
+ для удаления первого элемента массива (аналог pop_front() в векторах)
+ для сортировки массива
+ для вывода на экран элементов.
2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
3. Реализовать класс Hand, который представляет собой коллекцию карт. 
В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов должен быть - указатель на объекты класса Card). 
Также в классе Hand должно быть 3 метода:
- метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
- метод Clear, который очищает руку от карт
- метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/



#include <iostream>
#include <vector>
#include <algorithm>

#include "ArrayInt.h"

using namespace std;


int main() {
	cout << "TASK 1\n" << "=============================================================================\n";
    ArrayInt array(7);

    // Заполняем массив числами от 1 до 10
    for (int i = 0; i < 7; i++)
        array[i] = i + 1;
    array.print();
    //меняем размер массива
    array.resize(5);
    array.print();
    // Вставляем число 17 перед элементом с индексом 4
    array.insertBefore(17, 4);
    array.print();
    // Добавляем числа 33 в конец
    array.insertAtEnd(33);
    array.print();
    // Добавляем числа 22 в начало
    array.insertAtBeginning(22);
    array.print();
    array.sort();
    array.print();
    cout << "\nTASK 2\n" << "=============================================================================\n";
    vector<int> task2{ 2,4,2,5,34,5,2,3,5,8 };
    for (auto i : task2)
        cout << i << ' ';
    cout << endl;
    //сортируем элементы вектора
    sort(task2.begin(), task2.end());
    //удаляем дубликаты
    task2.erase(unique(task2.begin(), task2.end()), task2.end());
    for (auto i : task2)
       cout << i << ' ';
    cout << endl;
    cout << task2.size();
    return 0;
}