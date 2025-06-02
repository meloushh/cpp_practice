#pragma once

#define PrintVar(v) std::cout << #v << ": " << v << std::endl

#define PrintVec(v) std::cout << #v << ": " << std::endl;\
for (auto i : v) {\
	std::cout << i << std::endl;\
}\
std::cout << std::endl

#define PrintMap(v) std::cout << #v << ": " << std::endl;\
for (auto i : v) {\
	std::cout << i.first << ", " << i.second << std::endl;\
}\
std::cout << std::endl
