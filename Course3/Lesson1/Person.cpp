#include "PhoneBook.h"


bool operator < (const Person& person1, const Person& person2)  {
    return (std::tie(person1.last_name, person1.first_name, person1.middle_name) < std::tie(person2.last_name, person2.first_name, person2.middle_name));
}

bool operator == (const Person& person1, const Person& person2)  {
    return (std::tie(person1.last_name, person1.first_name, person1.middle_name) == std::tie(person2.last_name, person2.first_name, person2.middle_name));
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
    out << std::setw(11) << person.last_name << " " << std::setw(10) << person.first_name << " ";

    if (person.middle_name)
        out << std::setw(14) << person.middle_name.value();
    return out;
}
