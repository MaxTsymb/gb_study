#include <iostream>

using namespace std;

template <class T>
class Pair1
{
private:
	T m_a;
	T m_b;

public:
	Pair1(const T& a, const T& b)
		: m_a(a), m_b(b)
	{
	}

	T& first() { return m_a; }
	const T& first() const { return m_a; }
	T& second() { return m_b; }
	const T& second() const { return m_b; }
};

template <class T, class S>
class Pair
{
private:
	T m_a;
	S m_b;

public:
	Pair(const T& a, const S& b)
		: m_a(a), m_b(b)
	{
	}

	T& first() { return m_a; }
	const T& first() const { return m_a; }
	S& second() { return m_b; }
	const S& second() const { return m_b; }
};

template <class S>
class StringValuePair : public Pair<std::string, S>
{
public:
	StringValuePair(const std::string& key, const S& value)
		: Pair<std::string, S>(key, value)
	{
	}
};

int main()
{
	cout << "\n Task 1\n" << "=============================================================\n";
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	cout << "\n Task 2\n" << "=============================================================\n";
	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
	const Pair<double, int> p4(3.4, 5);
	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
	cout << "\n Task 3\n" << "=============================================================\n";
	StringValuePair<int> svp("Amazing", 7);
	cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}