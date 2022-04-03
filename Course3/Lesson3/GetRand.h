#pragma once
#include <random>
#include <chrono>

int getRandomNum(int min, int max) {
	const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	static std::mt19937_64 generator(seed);
	std::uniform_int_distribution<int> dis(min, max);
	return dis(generator);
}

