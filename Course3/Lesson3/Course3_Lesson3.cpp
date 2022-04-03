/*
1) Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.
2) Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы.
3) Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for-range-based.
*/
#include <iostream>
#include <list>
#include "Matrix.h"
#include "MyIterator.h"
#include "GetRand.h"

void AveragePushBack (std::list <double> &list) {
    std::list<double>::iterator listIter = list.begin();
    double sum = 0;
    size_t num_elem = 0;
    while (listIter != list.end()) {
        sum = sum + *listIter;
        ++num_elem;
        ++listIter;
    }
    list.push_back(sum / num_elem);
}

template<class T>
class SimpleArray {
    T* data;
    size_t size;
public:
    explicit SimpleArray(size_t size) : size(size) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = T(getRandomNum(0, 100));
        }
    };

    ~SimpleArray() {
        delete[] data;
    };

    Iterator<T> begin() {
        return Iterator<T> (data);
    };

    Iterator<T> end() {
        return Iterator<T> (data + size);
    };
};



int main()
{
    std::cout << "Task 1" << std::endl;
    std::list<double> list{ 2,2,3 };
    copy(list.begin(), list.end(), std::ostream_iterator<double>(std::cout, " | "));
    std::cout << std::endl;
    AveragePushBack(list);
    copy(list.begin(), list.end(), std::ostream_iterator<double>(std::cout, " | "));
    std::cout << std::endl<<std::endl;
    std::cout << "Task 2" << std::endl;
    Matrix<float> m(5);
    m.Print();
    std::cout << "Determinant:" << m.GaussDeterminant() << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "Task 3" << std::endl;
    SimpleArray<int> arr(13);
    for (auto item : arr) {
        std::cout << item << '\t';
    }
    std::cout << std::endl;

    return 0;
}