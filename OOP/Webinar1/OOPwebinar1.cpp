/* 1.Создать класс Power, который содержит два вещественных числа. 
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел.
Еще создать два метода: один с именем set, который позволит присваивать значения переменным, второй — calculate,
который будет выводить результат возведения первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
оздать конструктор со списком инициализации членов, который позволит пользователю передавать 
значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.
3. Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
private-массив целых чисел длиной 10;
private целочисленное значение для отслеживания длины стека;
public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
public-метод с именем print(), который будет выводить все значения стека.*/

#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

class Power {
public:
	double m_firstNum;
	double m_secNum;
	Power() {
		m_firstNum = 2;
		m_secNum = 2;
	}
	void set() {
		cout << "Insert first number:\n";
		cin >> m_firstNum;
		cout << "Insert second number:\n";
		cin >> m_secNum;
	}
	void calculate() {
		cout << "Result:" << pow(m_firstNum, m_secNum)<<endl;
	}
};

class RGBA {
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
public:
	RGBA(uint8_t red=0, uint8_t green=0, uint8_t blue=0, uint8_t alpha=255)
		: m_red (red), m_green (green), m_blue(blue), m_alpha(alpha)
	{

	}
	void print() {
		cout << static_cast<int>(m_red) << ", " << static_cast<int>(m_green) << ", " << static_cast<int>(m_blue) << ", " << static_cast<int>(m_alpha)<<"." << endl;
	}
};

class Stack {
private:
	int m_array[10];
	int m_size;								//размер стека, он же индекс свободного элемента массива
public:
	void reset() {
		m_size = 0;							//скидываем размер на 0
		for (int i = 0; i < 10; i++) {		//зануляем значения элементов массива
			m_array[i] = 0;
		}
	}
	bool push(int value) {					
		if (m_size >= 10) {					//если больше(всякое бывает) или равно 10 значит переполнено
			return false;
		}
		m_array[m_size++] = value;			//заносим значение
		return true;
	}
	int pop()
	{
		if (m_size <= 0) {					//если размер меньше(всякое бывает) или равен нулю, то выводим ошибку
			cout << "ARRAY EMPTY!\n";
		};
		return m_array[--m_size];			//возвращаем значение элемента массива перед свободным
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_size; ++i) {
			std::cout << m_array[i] << ' ';
		}
		std::cout << ")\n";
	}
};

int main() {
	cout << "Task 1.\n"<<"=========================================================\n";
	Power task1;
	task1.set();
	task1.calculate();
	cout << "\nTask 2.\n" << "=========================================================\n";
	RGBA task2(1,2,3,4);
	task2.print();
	cout << "\nTask 3.\n" << "=========================================================\n";
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}