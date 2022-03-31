#pragma once
#include <chrono>
#include <iostream>
#include <utility>

class Timer
{
protected:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::string m_name;
	std::chrono::time_point<clock_t> m_beg;
	[[nodiscard]] double Elapsed() const;

public:
	Timer() : m_beg(clock_t::now()) { }
	explicit Timer(std::string name) : m_name(std::move(name)), m_beg(clock_t::now()) { }

	void Start(std::string name);
	void Print() const;
};
