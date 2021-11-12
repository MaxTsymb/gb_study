﻿/*
1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров 
и запускать исключение DivisionByZero, если второй параметр равен 0. 
В функции main выводить результат вызова функции div в консоль, а также ловить исключения. 

2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
инициализирующий x значением параметра. Написать класс Bar, хранящий вещественное число y 
(конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a. 
Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. 
В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.

3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, 
означающий задание переместиться на соседнюю позицию. Эти методы должны запускать классы-исключения OffTheField, 
если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). 
Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main,
пользующуюся этим классом и перехватывающую все исключения от его методов, а также выводящую подробную информацию о всех возникающих ошибках.
*/

#include <iostream>
#include <string>
using namespace std;

double div(double numenator, double denominator) {
	if (denominator == 0) {
		throw "DivisionByZero";
	}
	return numenator / denominator;
}

class Ex
{
public:
    double x;
    Ex(const double& x_) :x(x_) {}
    ~Ex() {}
};

class Bar
{
private:
    double y;

public:
    Bar() { y = 0; }
    ~Bar() {}
    void set(const double& a)
    {
        if (y + a <= 100)
        {
            y = a;

        }
        else throw Ex(y * a);
    }

};

class OffTheField
{
	int cur_pos_x;
	int cur_pos_y;
	int new_pos_x;
	int new_pos_y;
	string m_message;
public:
	OffTheField(int c_x, int c_y, int n_x, int n_y) :
		cur_pos_x(c_x), cur_pos_y(c_y), new_pos_x(n_x), new_pos_y(n_y), m_message("")
	{
		if (new_pos_x > 10 || new_pos_x < 1)
		{
			m_message += "Ошибка координаты X! Робот выходит за границу поля!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}
		if (new_pos_y > 10 || new_pos_y < 1)
		{
			m_message += "Ошибка координаты Y! Робот выходит за границу поля!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}
	}

	const string& getInfo() const
	{
		return m_message;
	}
};

class IllegalCommand
{
private:
	int cur_pos_x;
	int cur_pos_y;
	int new_pos_x;
	int new_pos_y;
	string m_message;
public:
	IllegalCommand(int c_x, int c_y, int n_x, int n_y) :
		cur_pos_x(c_x), cur_pos_y(c_y), new_pos_x(n_x), new_pos_y(n_y), m_message("")
	{
		if (abs(cur_pos_x - new_pos_x) > 1)
		{
			m_message += "Ошибка координаты X! Шаг слишком велик!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}

		if (abs(cur_pos_y - new_pos_y) > 1)
		{
			m_message += "Ошибка координаты Y! Шаг слишком велик!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + std::to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}

		if (cur_pos_x == new_pos_x && cur_pos_y == new_pos_y)
		{
			m_message += "Ошибка координаты X и Y! Нельзя шагнуть на текущее место!\n";
			m_message += '[' + to_string(cur_pos_x) + ';' + to_string(cur_pos_y) + "] => [" +
				to_string(new_pos_x) + ';' + to_string(new_pos_y) + "]\n";
		}
	}

	const string& getInfo() const
	{
		return m_message;
	}
};

class Robot
{
private:
	int pos_x;
	int pos_y;
public:
	Robot(int x = 5, int y = 5) : pos_x(x), pos_y(y)
	{
		cout << "Начальная позиция робота: [" << pos_x << ';' << pos_y << ']' << endl;
	}

	void move(int x, int y)
	{
		if (abs(pos_x - x) > 1 || abs(pos_y - y) > 1 || (pos_x == x && pos_y == y))
			throw IllegalCommand(pos_x, pos_y, x, y);
		if (x > 10 || x < 1 || y > 10 || y < 1)
			throw OffTheField(pos_x, pos_y, x, y);

		cout << "Робот шагнул [" << pos_x << ';' << pos_y << "] => [" << x << ';' << y << ']' <<endl;

		pos_x = x;
		pos_y = y;
	}
};

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "TASK 1" << endl;
    
    double num, den;
    cout << "Введите первое делимое: ";
    cin >> num;
    cout << "Введите делитель: ";
    cin >> den;

    try
    {
        double res = div(num,den);
        cout << res << endl;
    }
    catch (const char* exception)
    {
        cerr << "Ошибка: " << exception << endl;
    }

    cout << "==================================================\n" << "TASK 2" << endl;
    Bar b;
    int n{};
    while (cin >> n && n != 0) {

        try
        {
            b.set(n);
        }
        catch (Ex& err)
        {
            cerr << "Ошибка: " << err.x << endl;
        }
    }
    cout << "\n==================================================\n" << "TASK 3" << endl;
	int x = 0, y = 0;
	Robot rob;

	while (true)
	{
		cout << "Введите новую координату Х: " << endl;
		cin >> x;
		cout << "Введите новую координату Y: " << endl;
		cin >> y;

		if (x == 0 && y == 0)
			break;

		try
		{
			rob.move(x, y);
		}
		catch (const IllegalCommand& e)
		{
			cerr << e.getInfo() << endl;
		}
		catch (const OffTheField& e)
		{
			cerr << e.getInfo() << endl;
		}
	}

    return 0;
}
