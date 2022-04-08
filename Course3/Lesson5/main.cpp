/*1. Создать шаблонную функцию, которая принимает итераторы на начало и конец
последовательности слов, и выводящую в консоль список уникальных слов (если слово
повторяется больше 1 раза, то вывести его надо один раз). Продемонстрировать работу
функции, передав итераторы различных типов.
2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные
введенные пользователем из стандартного потока ввода и разбивать их на предложения.
Далее программа должна вывести пользователю все предложения, а также количество слов в
них, отсортировав предложения по количеству слов.*/#include <iostream>
#include <random>
#include <chrono>
#include <set>
#include <iterator>
#include <list>
#include <regex>

const size_t LIST_SIZE = 10;

int getRandomNum(int min, int max) {
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int> dis(min, max);
    return dis(generator);
}

template<typename T>
void PrintAll(const T& begin, const T& end) {
    for (T p1 = begin; p1 != end; p1++) {
        std::cout << *p1 << '\n';
    }
    std::cout << std::endl << std::endl;
}

template<typename T>
void PrintUnique(const T& begin, const T& end) {
    for (T p1 = begin; p1 != end; p1++) {
        T p2;
        for (p2 = begin; p2 != p1; p2++) {
            if (*p1 == *p2)
                break;
        }
        if (p1 == p2)
            std::cout << *p1 << '\n';
    }
    std::cout << std::endl << std::endl;
}

std::string GenerateString() {
    int length = getRandomNum(3, 10);
    bool uppercase = getRandomNum(0, 1);
    std::string result;
    for (size_t i = 0; i < length; i++) {
        if (uppercase) {
            result += char(getRandomNum('A', 'Z'));
        }
        else {
            result += char(getRandomNum('a', 'z'));
        }
    }
    return result;
}

std::string trim(std::string src)
{
    src.erase(std::find_if_not(src.rbegin(), src.rend(), ::isspace).base(), src.end());
    src.erase(src.begin(), std::find_if_not(src.begin(), src.end(), ::isspace));
    return src;
}

auto cmp = [](const std::string& a, const std::string& b) { return a.length() > b.length(); };

std::set<std::string, decltype(cmp)> SplitString(std::string& str, char delimiter = '.') {
    std::set<std::string, decltype(cmp)> result;
    auto start = 0U;
    auto end = str.find(delimiter);
    while (end != std::string::npos) {
        result.insert(trim(str.substr(start, end - start)));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    if (start != end) {
        result.insert(trim(str.substr(start, end - start)));
    }
    return result;
}

void Task1() {
    {
        std::cout << "LIST \n";
        std::list<std::string> word_list;
        word_list.push_back(GenerateString());
        for (size_t i = 1; i < LIST_SIZE; i++) {
            bool repeat = getRandomNum(0, 1);
            if (repeat) {
                int repeat_index = getRandomNum(0, i - 1);
                auto word_iterator = word_list.begin();
                std::advance(word_iterator, repeat_index);
                std::string repeat_word = *word_iterator;
                word_list.push_back(repeat_word);
            }
            else {
                word_list.push_back(GenerateString());
            }
        }
        std::cout << "Print all words: \n";
        PrintAll(word_list.begin(), word_list.end());
        std::cout << "Print unique words: \n";
        PrintUnique(word_list.begin(), word_list.end());
    }

    {
        std::cout << "MULTISET\n";
        std::multiset<std::string> word_list;
        word_list.insert(GenerateString());
        for (size_t i = 1; i < LIST_SIZE; i++) {
            bool repeat = getRandomNum(0, 1);
            if (repeat) {
                int repeat_index = getRandomNum(0, i - 1);
                auto word_iterator = word_list.begin();
                std::advance(word_iterator, repeat_index);
                std::string repeat_word = *word_iterator;
                word_list.insert(repeat_word);
            }
            else {
                word_list.insert(GenerateString());
            }
        }
        std::cout << "Print all words: \n";
        PrintAll(word_list.begin(), word_list.end());
        std::cout << "Print unique words: \n";
        PrintUnique(word_list.begin(), word_list.end());
    }
}

void Task2() {
    std::string text;
    std::cout << "Enter some string (delimiter is '.'): ";
    std::getline(std::cin, text);
    std::cout << "You have entered: "<<text << std::endl;
    std::set<std::string, decltype(cmp)> container = SplitString(text);
    std::cout << "Sorted string: \n";
    copy(container.begin(), container.end(), std::ostream_iterator<std::string>(std::cout, " \n"));
}

int main() {
    std::cout << "Task 1" << std::endl;
    Task1();
    std::cout<<std::endl;
    std::cout << "Task 2" << std::endl;
    Task2();
    return 0;
}
