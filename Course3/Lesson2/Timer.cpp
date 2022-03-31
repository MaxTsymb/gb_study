#include "Timer.h"

[[nodiscard]] double Timer::Elapsed() const
{
	return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

void Timer::Start(std::string name) {
	m_name = std::move(name);
	m_beg = clock_t::now();
}

void Timer::Print() const {
	std::cout << m_name << ":\t" << Elapsed() * 1000 << " ms" << std::endl;
}
