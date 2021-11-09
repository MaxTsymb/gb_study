#include "Date.h"

const _ptr<Date>& compares_dates(const _ptr<Date>& a, const _ptr<Date>& b)
{
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else
	{
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else
				return b;
		}
	}
}

void swap_dates(_ptr<Date>& a, _ptr<Date>& b)
{
	_ptr<Date> temp(a);
	a = b;
	b = temp;
}

void task2()
{
	_ptr<Date> date1(new Date(9, 11, 2021));
	_ptr<Date> date2(new Date(10, 11, 2021));
	
	std::cout << *compares_dates(date1, date2) << std::endl;
	swap_dates(date1, date2);
}