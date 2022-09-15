#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a;

	auto it = a.begin();
	auto it_end = a.end();

	// std::cout << it << " / " << it_end << std::endl;
	std::cout << *it << std::endl;
	return (0);
}
