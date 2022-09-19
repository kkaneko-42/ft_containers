#include <vector>
#include <cstdlib>
#include <iostream>

std::vector<int (*)(std::size_t)> getTestCases( void );

static bool validateArgs( int ac, char** av )
{
    if (ac != 2 || atoi(av[1]) < 0)
    {
        return (true);
    }
    return (false);
}

int main()
{
    int nb_elements;
	int total_ko = 0;
    std::vector<int (*)(std::size_t)> cases = getTestCases();

    if (validateArgs(ac, av))
    {
        std::cerr << USAGE << std::endl;
        return (1);
    }

    nb_elements = atoi(av[1]);
    for (std::vector<int(*)(std::size_t)>::iterator it = cases.begin(); it < cases.end(); ++it)
    {
        total_ko += (*it)(nb_elements);
    }

    if (total_ko != 0)
    {
        std::cout << "\033[31mKO: " << total_ko << "\033[m" << std::endl;
    }
    else
    {
        std::cout << "\033[32mAll OK" << "\033[m" << std::endl;
    }

    return (0);
}
