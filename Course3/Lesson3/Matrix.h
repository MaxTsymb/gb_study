#pragma once
#include "GetRand.h"

template<class T>
class Matrix {
protected:
    T** data;
    size_t size;

    int col_max(int col) {
        T max = std::abs(data[col][col]);
        int maxPos = col;
        for (int i = col + 1; i < size; ++i) {
            T element = std::abs(data[i][col]);
            if (element > max) {
                max = element;
                maxPos = i;
            }
        }
        return maxPos;
    };

    unsigned int triangulation() {
        unsigned int swapCount = 0;
        for (int i = 0; i < size - 1; ++i) {
            unsigned int imax = col_max(i);
            if (i != imax) {
                std::swap(data[i], data[imax]);
                ++swapCount;
            }
            for (int j = i + 1; j < size; ++j) {
                T mul = -data[j][i] / data[i][i];
                for (int k = i; k < size; ++k) {
                    data[j][k] += data[i][k] * mul;
                }
            }
        }
        return swapCount;
    };
public:
    explicit Matrix(size_t size) : size(size) {
        data = new T * [size];
        for (int i = 0; i < size; i++) {
            data[i] = new T[size];
            for (int j = 0; j < size; j++) {
                data[i][j] = T(getRandomNum(0, 10));
            }
        }
    };

    ~Matrix() {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    };

    T GaussDeterminant() {
        unsigned int swapCount = triangulation();
        T determinant = 1;
        if (swapCount % 2 == 1)
            determinant = -1;
        for (int i = 0; i < size; ++i) {
            determinant *= data[i][i];
        }
        return determinant;
    };

    void Print() {
        for (int i = 0; i < size; ++i)
        {

            for (int j = 0; j < size; ++j) {
                std::cout << data[i][j] << '\t';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};
