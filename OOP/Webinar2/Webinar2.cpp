/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса. 
Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов. 
В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
2.Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.
3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. 
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? 
Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы*/

#include <iostream>
#include <string>

using namespace std;

enum Gender {       //внутри класса не заработало, почему не понял
	male,
	female,
	creature        //для всех не традиционных
};

class Person {
protected:
    string m_name;
    int m_age;
    Gender m_gender;
    float m_weight;
public:
    Person(string name = "", int age = 0, Gender gender = male, float weight = 0)
        : m_name(name), m_age(age), m_gender(gender), m_weight(weight)
    {
    }

    void setName(string name)
    {
        if (name == "")
        {
            cout << "Enter your name: ";
            cin >> m_name;
        }
        else
            m_name = name;
    }

    void setAge(int age)
    {
        if (age == 0)
        {
            cout << "\nEnter your age: ";
            cin >> m_age;
        }
        else
            m_age = age;
    }

    void setWeight(float weight)
    {
        if (weight == 0)
        {
            cout << "\nEnter your weight: ";
            cin >> m_weight;
        }
        else
            m_weight = weight;
    }
};
    

class Student : public Person
{
private:
	int m_year;
public:
    static int count;          //счетчик студентов
	Student(string name, int age, Gender gender, float weight, int year=0)
		: Person(name, age, gender, weight), m_year(year)
    {
      count++;                //увеличим счетчик при создании студента
    }
   static void printCount()
    {
        cout << "\nStudents: " << count;
    }

    void setYear(int year)
    {
        if (year == 0)
        {
            cout << "\nEnter year of study: ";
            cin >> m_year;
        }
        else
            m_year = year;
    }
    void printInfo() {
        cout << "Name: " << m_name << endl;
        cout<< "Age: " << m_age << endl;
        if (m_gender == male) {
            cout << "Gender: male" << endl;
        }
        else if (m_gender == female) {
            cout << "Gender: female" << endl;
        }
        else {
            cout << "Gender: bastard" << endl;
        }
        cout<< "Weight: " << m_weight << endl;
        cout << "Year of study: " << m_year << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
    }

};

int Student::count=0;// при определении внутри класса выдает ошибку

class Fruit
{
private:
    std::string m_name;
    std::string m_color;
public:
    void setName(std::string name)
    {
        m_name = name;
    }

    void setColor(std::string color)
    {
        m_color = color;
    }

    const std::string& getName() const
    {
        return m_name;
    }

    const std::string& getColor() const
    {
        return m_color;
    }
};

class Apple : public Fruit
{
public:
    Apple(std::string color = "")
    {
        if (color == "")
            color = "green";

        setName("apple");
        setColor(color);
    }
};

class Banana : public Fruit
{
public:
    Banana(std::string color = "")
    {
        if (color == "")
            color = "yellow";

        setName("banana");
        setColor(color);
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
    {
        setName("Granny Smith " + Apple::getName());
    }
};

int main() {
    cout << "TASK 1\n" << "================================================\n";
    Student Max("Maksim", 31, male, 68.2, 2021);
    Student Kate("Katerina", 21, female, 48.2, 2021);
    Student Igor("Igor", 19, creature, 52.6, 2021);
    Max.printInfo();
    Kate.printInfo();
    Igor.printInfo();
    Student::printCount();
    cout << "\n\nTASK 2\n" << "================================================\n";
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

/*
Для игры в БэкДжек на понадобится 3 класса:
1. Класс Player. Собственно сам игрок, у него будут фишки чтобы делать ставки и две руки чтобы держать карты (при выпадении двух карт одного достоинства можно делать Split -
разделение карт на две руки с последующей игрой обеими).
2. Класс Dealer. Тот же игрок, только дополнительно тасует и раздает карты. Ставок не делает, но держит банк.
3. Класс Deck. Колода карт, состоящая собственно из карт. После того как диллер перетасует и раздаст карты, она хранит оставшиеся и проверяет, чтобы не выдавались повторы.
Из функций - это собственно само перемешивание карт.

Также нам понадобится структура Card состоящая из перечислений свойств карты: номинал и масть. Каждая карта, входящая в колоду будет элементом данной структуры.
*/
