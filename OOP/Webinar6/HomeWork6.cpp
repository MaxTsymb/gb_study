/*
1.Создать программу, которая считывает целое число типа int. 
И поставить «защиту от дурака»: если пользователь вводит что - то кроме одного целочисленного значения, 
нужно вывести сообщение об ошибке и предложить ввести число еще раз.
Пример неправильных введенных строк :
rbtrb
nj34njkn
1n
2.Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.
*/

#include <iostream>
#include <string>

template<class T>
T input_user(const char* promt)
{
    T a;
    std::cout << promt;
    std::cin >> a;

    while (std::cin.fail() || (std::cin.get() != '\n'))
    {
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        std::cin.sync();
        std::cout << "Error!\n\n" << promt;
        std::cin >> a;
    }
    return a;
}

class doubleEndl
{
public:
    friend std::ostream& operator<< (std::ostream& out, const doubleEndl& manip);
};
std::ostream& operator<< (std::ostream& out, const doubleEndl& manip)
{
    out << std::endl << std::endl;
    return out;
}

int main()
{
    std::cout << "-----TASK 1-----\n";
    while (true)
    {
        char var;
        std::cout << input_user<int>("Integer: ")
            << "\n\n";
        std::cout << "Continue? (y/n):";
        std::cin >> var;
        if (var != 'y') {
            break;
        }
    }
    std::cout<<"\n==========================================================\n" << "-----TASK 2-----\n";
    doubleEndl dendl;
    std::cout << "Hello " << dendl << "world";
    return 0;
}