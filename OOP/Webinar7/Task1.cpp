#include "Date.h"

void task1()
{
	_ptr<Date> today(new Date(9, 11, 2021));

	std::cout << "Day: " << today->getDay() << std::endl;
	std::cout << "Month: " << today->getMonth() << std::endl;
	std::cout << "Year: " << today->getYear() << std::endl;
	std::cout << "today: " << *today << std::endl;

	_ptr<Date> date;

	std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
	std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

	date = today;

	std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
	std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

	std::cout << "date: " << *date << std::endl;
}