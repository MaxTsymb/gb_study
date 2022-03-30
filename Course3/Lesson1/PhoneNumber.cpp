#include "PhoneBook.h"

std::ostream& operator << (std::ostream& out, const PhoneNumber& phone_number) {
    out << '+' << phone_number.countryNum << " (" << phone_number.cityNum << ") " << phone_number.phoneNum;
    if (phone_number.extenNum) {
        out << " " << phone_number.extenNum.value();
    }
    return out;
}

bool operator < (const PhoneNumber& num1, const PhoneNumber& num2) {
    return std::tie(num1.countryNum, num1.cityNum, num1.phoneNum, num1.extenNum) <
        std::tie(num2.countryNum, num2.cityNum, num2.phoneNum, num2.extenNum);
}
