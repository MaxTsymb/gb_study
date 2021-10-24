/*
1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
2. Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. 
Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.
4. Создать класс Card, описывающий карту в игре БлэкДжек. 
У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. 
Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.
*/
#include <iostream>

using namespace std;

class Figure
{
public:
	Figure() {};
	virtual double area() = 0;
};

class Parallelogram : public Figure
{
protected:
	double a, h;

public:
	Parallelogram(double inputA, double inputH)
		: a(inputA), h(inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Circle : public Figure
{
private:
	double r;
public:
	Circle(double inputR)
		: r(inputR) {};

	double area() override
	{
		return (3.14 * r * r / 2);
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

class Square : public Parallelogram
{
public:
	Square(double inputA)
		: Parallelogram(inputA, inputA) {};

	double area() override
	{
		return (a * a);
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double inputA, double inputH)
		: Parallelogram(inputA, inputH) {};

	double area() override
	{
		return (a * h);
	}
};

//Task 2 ======================================================================================================================

class Car
{
protected:
	string company, model;
public:
	Car() {}
	Car(string inputCompany, string inputModel)
		: company(inputCompany), model(inputModel)
	{
		cout << "\nBase car constructor";
	}

	virtual ~Car()
	{
		cout << "\nBase car destructor";
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar() {}
	PassengerCar(string inputCompany, string inputModel)
		: Car(inputCompany, inputModel)
	{
		cout << "\nPassenger car constructor";
		cout << "\n" << company << " " << model;
	}

	string getModel()
	{
		return model;
	}

	~PassengerCar()
	{
		cout << "\nPassenger car destructor";
	}
};

class Bus : virtual public Car
{
public:
	Bus() {}
	Bus(string inputCompany, string inputModel)
		: Car(inputCompany, inputModel)
	{
		cout << "\nBus constructor";
		cout << "\n" << company << " " << model;
	}

	~Bus()
	{
		cout << "\nBus destructor";
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(string inputCompany, string inputModel)
		: Car(inputCompany, inputModel)
	{
		cout << "\nMinivan constructor";
		cout << "\n" << company << " " << model;
	}

	~Minivan()
	{
		cout << "\nMinivan destructor";
	}
};

//Task 3 ======================================================================================================================

class Fraction
{
private:
	double numerator, denominator;
public:
	Fraction(double inputNumerator, double inputDenominator)
		: numerator(inputNumerator), denominator(inputDenominator)
	{
		if (denominator == 0) denominator = 0.00000001;
	}

	friend Fraction operator+(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1, const Fraction& d2);
	friend Fraction operator*(const Fraction& d1, const Fraction& d2);
	friend Fraction operator/(const Fraction& d1, const Fraction& d2);
	friend Fraction operator-(const Fraction& d1);
	friend ostream& operator<<(ostream& out, const Fraction& fraction);

	void setDenominator(double inputDenominator)
	{
		if (inputDenominator == 0) inputDenominator = 0.00000001;
		denominator = inputDenominator;
	}

	void setNumerator(double inputNumerator)
	{
		numerator = inputNumerator;
	}

	double getNumerator()
	{
		return numerator;
	}

	double getDenominator()
	{
		return denominator;
	}
};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator + d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator - d2.numerator * d1.denominator, d1.denominator * d2.denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.numerator, d1.denominator * d2.denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
	return Fraction(d1.numerator * d2.denominator, d1.denominator * d2.numerator);
}

Fraction operator-(const Fraction& d1)
{
	return Fraction(-d1.numerator, -d1.denominator);
}

bool operator==(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() == d2.getNumerator()) && (d1.getDenominator() == d2.getDenominator())) return true;
	else return false;
}

bool operator!=(Fraction& d1, Fraction& d2)
{
	if (d1 == d2) return false;
	else return true;
}

bool operator>(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) > (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator<=(Fraction& d1, Fraction& d2)
{
	if (!(d1 > d2)) return true;
	else return false;
}

bool operator<(Fraction& d1, Fraction& d2)
{
	if ((d1.getNumerator() / d1.getDenominator()) < (d2.getNumerator() / d2.getDenominator())) return true;
	else return false;
}

bool operator>=(Fraction& d1, Fraction& d2)
{
	if (!(d1 < d2)) return true;
	else return false;
}


ostream& operator<<(ostream& out, const Fraction& fraction)
{
	out << fraction.numerator << "/" << fraction.denominator;
	return out;
}

//Task 4 ======================================================================================================================
enum Suits {
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum Ranks {
	ACE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK=10,
	QUEEN=10,
	KING=10
};

class Card
{
private:
	Suits suit;
	Ranks rank;
	bool isFaceUp;
public:

	void Flip()
	{
		isFaceUp = !isFaceUp;
	}

	Ranks getValue()
	{
		return rank;
	}
};

int main()
{
	cout << "Task 1\n" << "==============================================================================\n";
	double parallelorgamHeight(3), parallelogramBase(5);
	Parallelogram parallelogram(parallelogramBase, parallelorgamHeight);
	cout << parallelogram.area() << "\n";

	double circleRadius(4);
	Circle circle(circleRadius);
	cout << circle.area() << "\n";

	double squareBase(5);
	Square square(squareBase);
	cout << square.area() << "\n";

	double rectangleBase(3), rectangleHeight(3);
	Rectangle rectangle(rectangleBase, rectangleHeight);
	cout << rectangle.area() << "\n";

	double rhombusBase(2), rhombusHeight(5);
	Rhombus rhombus(rhombusBase, rhombusHeight);
	cout << rhombus.area() << "\n";

	cout << "\nTask 2\n" << "==============================================================================\n";

	PassengerCar* passengerCar = new PassengerCar("Chevrolet", "Lanos");
	cout << "\n----------------------------------";
	Bus* bus = new Bus("Nissan", "Civilian");
	cout << "\n----------------------------------";
	Minivan* minivan = new Minivan("Volkswagen", "Caravelle");
	cout << "\n----------------------------------";
	delete minivan;
	cout << "\n----------------------------------";
	delete bus;
	cout << "\n----------------------------------";
	delete passengerCar;
	

	cout << "\nTask 3\n" << "==============================================================================\n";
	Fraction d1(3, 2);
	Fraction d2(8, 3);
	cout << "\n\n" << (d1 + d2);
	cout << "\n\n" << (d1 - d2);
	cout << "\n\n" << (d1 * d2);
	cout << "\n\n" << (d1 / d2);
	cout << "\n\n" << (-d1) << "\n";

	if (d1 == d2) cout << "\nFraction 1 == Fraction 2";
	if (d1 != d2) cout << "\nFraction 1 != Fraction 2";
	if (d1 > d2) cout << "\nFraction 1 > Fraction 2";
	if (d1 <= d2) cout << "\nFraction 1 <= Fraction 2";
	if (d1 < d2) cout << "\nFraction 1 < Fraction 2";
	if (d1 >= d2) cout << "\nFraction 1 >= Fraction 2";
}