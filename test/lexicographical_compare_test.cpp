#include "lexicographical_compare.hpp"
#include <algorithm>
#include <string>
#include <iostream>

int main(int ac, char **av)
{
	std::string s1;
	std::string s2;

	if (ac < 3)
	{
		s1 = std::string("hogehoge");
		s2 = std::string("hogehogea");
	}
	else
	{
		s1 = std::string(av[1]);
		s2 = std::string(av[2]);
	}

	std::cout << "EXPECT: "
	<< std::lexicographical_compare<
		std::string::iterator, std::string::iterator>(
			s1.begin(), s1.end(), s2.begin(), s2.end()
		)
	<< std::endl;

	std::cout << "res: "
	<< ft::lexicographical_compare<
		std::string::iterator, std::string::iterator>(
			s1.begin(), s1.end(), s2.begin(), s2.end()
		)
	<< std::endl;
	return (0);
}
