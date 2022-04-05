/*1. Имеется отсортированный массив целых чисел. Необходимо разработать функцию
insert_sorted, которая принимает вектор и новое число и вставляет новое число в
определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась.
Реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать с любым
контейнером, содержащим любой тип значения.
2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой
значения аналогового сигнала. На основе этого массива чисел создайте другой вектор целых
чисел b, представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой
сигнал по сравнению с аналоговым по формуле
Постарайтесь воспользоваться алгоритмическими функциями, не используя циклы*/

#include <iostream>
#include <random>
#include <chrono>
#include <numeric>

const size_t VECTOR_SIZE = 5;
const size_t SIGNAL_SIZE = 10;

int getRandomNum(int min, int max) {
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int> dis(min, max);
    return dis(generator);
}

template<typename T>
void insert_sorted(std::vector<T>& v, T num) {
    auto low = lower_bound(v.begin(), v.end(), num);
    v.insert(low, num);
}

void Task1() {
    std::vector<int> v(VECTOR_SIZE);
    std::generate(v.begin(), v.end(), []() { return getRandomNum(1, 100); });
    std::sort(v.begin(), v.end());
    for (auto n : v) {
        std::cout << n << '\t';
    }
    std::cout << std::endl;
    insert_sorted(v, getRandomNum(1, 100));
    insert_sorted(v, getRandomNum(1, 100));
    insert_sorted(v, getRandomNum(1, 100));
    insert_sorted(v, getRandomNum(1, 100));
    insert_sorted(v, getRandomNum(1, 100));
    insert_sorted(v, getRandomNum(1, 100));
    for (auto n : v) {
        std::cout << n << '\t';
    }
    std::cout << std::endl;
}

void Task2() {
    std::vector<float> analog(SIGNAL_SIZE);
    std::generate(analog.begin(), analog.end(), []() { return float(getRandomNum(1, 100)) + (float(getRandomNum(1, 100)) / 100); });
    for (auto n : analog) {
        std::cout << n << '\t';
    }
    std::cout << std::endl;
    std::vector<int> digital;
    digital.reserve(SIGNAL_SIZE);
    std::transform(analog.begin(), analog.end(), std::back_inserter(digital), [](float f) {return int(f); });
    for (auto n : digital) {
        std::cout << n << '\t';
    }
    std::cout << std::endl;
    std::cout << "Digital infelicity: " << std::inner_product(digital.begin(), digital.end(), analog.begin(), 0.f, std::plus<>(), [](float a, float d) {
        return (a - d) * (a - d);
        });
}

int main() {
    std::cout << "TASK 1" << std::endl;
    Task1();
    std::cout << std::endl;
    std::cout << "TASK 1" << std::endl;
    Task2();
    return 0;
}
