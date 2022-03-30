#pragma once
#include <regex>
#include <iostream>
#include <string>
#include <optional>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>



struct Person {
    std::string last_name;
    std::string first_name;
    std::optional<std::string> middle_name;

    friend bool operator < (const Person& person1, const Person& person2);
    friend bool operator == (const Person& person1, const Person& person2);
    friend std::ostream& operator<< (std::ostream& out, const Person& person);
};


struct PhoneNumber{
    int countryNum;
    int cityNum;
    std::string phoneNum;
    std::optional<int> extenNum;

    friend std::ostream& operator<<(std::ostream& ostr, const PhoneNumber& phone_number);
    friend bool operator<(const PhoneNumber& num1, const PhoneNumber& num2);
};


class PhoneBook {
private:
    std::vector<std::pair<Person, PhoneNumber>> phoneBook;
  
public:
    PhoneBook(std::ifstream& ifs);

    friend std::ostream& operator << (std::ostream& out, const PhoneBook& book);
    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& lastName);

    void ChangePhoneNumber(const Person& person, const PhoneNumber& number);

};

