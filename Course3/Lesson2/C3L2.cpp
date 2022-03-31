/*
1. Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает
местами значения, на которые указывают эти указатели (нужно обменивать именно сами
указатели, переменные должны оставаться в тех же адресах памяти).
2. Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и
сортирует указатели по значениям, на которые они указывают.
3. Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4
способа:
○ count_if и find
○ count_if и цикл for
○ цикл for и find
○ 2 цикла for
Замерьте время каждого способа подсчета и сделайте выводы.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

#include "Timer.h"

const size_t VECTOR_SIZE = 5;

int getRandomNum(int min, int max) {
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int> dis(min, max);
    return dis(generator);
}

template<typename T>
void Swap(T* p1, T* p2) {
    int* temp = std::move(*p1);
    *p1 = std::move(*p2);
    *p2 = temp;
}

template<typename T>
void SortPointers(std::vector<T*>& vector) {
    std::sort(vector.begin(), vector.end(),
        [](const T* left, const T* right) {
            return *left < *right;
        });
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T*> vector) {
    for (const auto& iter : vector) {
        out << *iter << ' ';
    }
    return out;
}

void CountVowels(std::ifstream& file, const std::string& vowels,
    void (*function)(std::ifstream& file, const std::string& vowels, size_t& count)) {
    if (!file.is_open()) {
        std::cerr << "Could not read the file!" << std::endl;
        return;
    }

    Timer t;
    t.Start(" ");

    size_t count = 0;
    function(file, vowels, count);

    t.Print();

    file.close();
    std::cout << "Number of vowels: " << count << std::endl;
}

void CountVowelsIfFind(std::ifstream& file, const std::string& vowels, size_t& count) {
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        count += std::count_if(line.begin(), line.end(),
            [=](char symbol) {
                return (symbol != ' ' && vowels.find(symbol) != std::string::npos);
            });
    }
}

void CountVowelsIfFor(std::ifstream& file, const std::string& vowels, size_t& count) {
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        count += std::count_if(line.begin(), line.end(),
            [=](char symbol) {
                if (symbol == ' ') {
                    return false;
                }
                for (char vowel : vowels) {
                    if (vowel == symbol) return true;
                }
                return false;
            });
    }
}

void CountVowelsForFind(std::ifstream& file, const std::string& vowels, size_t& count) {
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        for (char symbol : line) {
            count += ((symbol != ' ' && vowels.find(symbol) != std::string::npos) ? 1 : 0);
        }
    }
}

void CountVowelsForFor(std::ifstream& file, const std::string& vowels, size_t& count) {
    while (!file.eof()) {
        std::string line;
        std::getline(file, line);
        for (char symbol : line) {
            if (symbol == ' ') {
                continue;
            }
            for (char vowel : vowels) {
                count += (vowel == symbol ? 1 : 0);
            }
        }
    }
}

void Task1() {
    int i1 = 12;
    int* p1 = &i1;
    int i2 = 24;
    int* p2 = &i2;
    std::cout << "Value1:" << i1 << "\tPointer1 value:" << *p1 << std::endl;
    std::cout << "Value2:" << i2 << "\tPointer2 value:" << *p2 << std::endl;
    Swap(&p1, &p2);
    std::cout << "After swap Value1:" << i1 << "\tPointer1 value:" << *p1 << std::endl;
    std::cout << "After swap Value2:" << i2 << "\tPointer2 value:" << *p2 << std::endl;
}

void Task2() {
    std::vector<int*> vectorPtr;
    vectorPtr.reserve(VECTOR_SIZE);
    int* rPtr = new int[VECTOR_SIZE];
    for (size_t i = 0; i < VECTOR_SIZE; i++) {
        int r = getRandomNum(1, 512);
        *(rPtr + i) = r;
        vectorPtr.push_back(rPtr + i);
    }
    std::cout << vectorPtr << std::endl;
    SortPointers(vectorPtr);
    std::cout << vectorPtr << std::endl;
    delete[] rPtr;
}

int Task3() {
    std::ifstream vowels_file("alphabet.txt");
    if (!vowels_file.is_open()) {
        std::cerr << "Could not read the vowels file!" << std::endl;
        return 2;
    }
    std::string vowels;
    std::getline(vowels_file, vowels);
    vowels_file.close();
    std::ifstream file("WaP.txt");
    std::cout << "(Count_if + find) finished in";
    CountVowels(file, vowels, CountVowelsIfFind);
    file.open("WaP.txt");
    std::cout << "(Count_if + for) finished in";
    CountVowels(file, vowels, CountVowelsIfFor);
    file.open("WaP.txt");
    std::cout << "(For + find) finished in";
    CountVowels(file, vowels, CountVowelsForFind);
    file.open("WaP.txt");
    std::cout << "(For + for) finished in";
    CountVowels(file, vowels, CountVowelsForFor);
    return 0;
}

int main() {
    std::cout << "TASK 1" << std::endl;
    Task1();
    std::cout << "TASK 2" << std::endl;
    Task2();
    std::cout << "TASK 3" << std::endl;
    return Task3();
}
