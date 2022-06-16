#ifndef _XS_RANDOM_
#define _XS_RANDOM_
#include <stdlib.h>
#include <vector>

struct {
	using uint = unsigned int;
	template <typename T = int> T rand() { return (T)std::rand(); };
	template <typename T = int> T rand(int max) { return T(std::rand() % max); };
	template <> inline bool rand<bool>() { return randBool(); };
	template <> inline char rand<char>() { return randChar(); };
	template <> inline int rand<int>(int max) { return randInt(max); };
	template <> inline int rand<int>() { return randInt(); };
	template <> inline float rand<float>() { return randFloat(); };
	template <> inline float rand<float>(int max) { return (float)randInt(max) + randFloat(); };
	template <> inline double rand<double>() { return (double)std::rand() / (double)RAND_MAX; };
	template <> inline double rand<double>(int max) { return (double)randInt(max) + ((double)std::rand() / (double)RAND_MAX); };
	int randInt(int begin, int end) { return (std::rand() % ((end > begin) ? (end - begin) : (begin - end))) + (end > begin) ? begin : end; };
	int randInt(int end) { return std::rand() % end; };
	int randInt() { return std::rand() % RAND_MAX; };
	bool randBool() { return std::rand() % 2 == 0; };
	char randChar() { return char(std::rand() % 256 - 128); };
	char randLetter() { return char(randBool() ? randInt(65, 91) : randInt(97, 123)); };
	char randSymbol() { return char(randBool() ? randInt(33, 48) : randBool() ? randInt(58, 65) : randBool() ? randInt(91, 97) : randInt(123, 127)); };
	float randFloat() { return (float)std::rand() / (float)RAND_MAX; };
	template <typename T>
	auto randRange(uint limit, T max) {
		std::vector<T> l;
		for (uint i = 0; i < limit; i++)
			l.push_back(rand<T>(max));
		return l;
	};
	template <typename T> inline auto choice(const std::initializer_list<T>& v) { return *(v.begin() + (std::rand() % v.size())); };
	inline auto choice(const auto& v) { return *(v.begin() + (std::rand() % v.size())); };
} random;
#endif