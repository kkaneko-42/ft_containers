#include "equal.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	std::vector<int> a(42, 0);
	std::vector<int> b(42, 0);

	std::cout << std::equal<
		std::vector<int>::iterator,
		std::vector<int>::iterator>(a.begin(), a.end(), b.begin());
	std::cout << std::endl;
	std::cout << ft::equal<
		std::vector<int>::iterator,
		std::vector<int>::iterator>(a.begin(), a.end(), b.begin());
	std::cout << std::endl;

	a.insert(a.begin() + 3, 42);

	std::cout << std::equal<
		std::vector<int>::iterator,
		std::vector<int>::iterator>(a.begin(), a.end(), b.begin());
	std::cout << std::endl;
	std::cout << ft::equal<
		std::vector<int>::iterator,
		std::vector<int>::iterator>(a.begin(), a.end(), b.begin());
	std::cout << std::endl;
	return (0);
}
