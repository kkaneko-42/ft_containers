#include "iterator.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template < class T >
static int expect( const std::string& test_case, T expect, T res, bool verbose )
{
	if (verbose)
	{
		std::cout << "@Case >> " << test_case << std::endl;
		std::cout << "EXPECT: " << expect << std::endl;
		std::cout << "res: " << res << std::endl;
	}
	if (expect != res)
	{
		if (verbose)
			std::cout << "\033[31mKO\033[m" << std::endl;
		return (1);
	}
	if (verbose)
		std::cout << "\033[32mOK\033[m" << std::endl;
	return (0);
}

static int* generateRandomArray(std::size_t len)
{
    int *array = new int[len];
    
    srand(time(NULL));
    for (std::size_t i = 0; i < len; ++i)
    {
        array[i] = rand();
    }
    return (array);
}

int main(int ac, char **av)
{
    const std::size_t len = 100;
    bool verbose = (ac > 1) ? true : false;
    int *array = generateRandomArray(len);
    ft::random_access_iterator<int> it(array);
    int nb_err = 0;
    (void)av;

    for (std::size_t i = 0; i < len; ++i, ++it)
    {
        nb_err += expect<int>("Access test", array[i], *it, verbose);
    }
    it = ft::random_access_iterator<int>(array + len - 1);
    for (std::size_t i = len - 1; ; --i, --it)
    {
        nb_err += expect<int>("Access test", array[i], *it, verbose);
        if (i == 0)
            break;
    }

    ft::reverse_iterator< ft::random_access_iterator<int> > r_it(it);
    for (std::size_t i = 0; i < len; ++i, --r_it)
    {
        nb_err += expect<int>("Access test", array[i], *r_it, verbose);
    }
    ++r_it;
    for (std::size_t i = len - 1; ; --i, ++r_it)
    {
        nb_err += expect<int>("Access test", array[i], *r_it, verbose);
        if (i == 0)
            break;
    }

    if (nb_err == 0)
		std::cout << "\033[32mAll OK\033[m" << std::endl;
	else
		std::cout << "\033[31mKO: " << nb_err << "\033[m" << std::endl;
    delete[] array;
    return (0);
}
