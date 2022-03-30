#include <iostream>
#include "PhoneBook.h"


int main()
{
    std::ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
    if (file) {
        PhoneBook phone_book(file);
        std::cout << phone_book;
        system("pause");

        std::cout << "------SortByPhone-------" << std::endl;
        phone_book.SortByPhone();
        std::cout << phone_book;
        system("pause");

        std::cout << "------SortByName--------" << std::endl;
        phone_book.SortByName();
        std::cout << phone_book;
        system("pause");

        std::cout << "-----GetPhoneNumber-----" << std::endl;

        auto print_phone_number = [&phone_book](const std::string& surname) {
            std::cout << surname << "\t";
            auto answer = phone_book.GetPhoneNumber(surname);
            if (get<0>(answer).empty())
                std::cout << get<1>(answer);
            else
                std::cout << get<0>(answer);
            std::cout << std::endl;
        };

        print_phone_number("Ivanov");
        print_phone_number("Petrov");
        system("pause");

        std::cout << "----ChangePhoneNumber----" << std::endl;
        phone_book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", std::nullopt });
        phone_book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });

        std::cout << phone_book;
    }
    else { std::cout << "File Not Open"; }
    return 0;

}
