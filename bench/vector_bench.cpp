#include <iostream>
#include <vector>
#include <cstdlib>
#include "vector.hpp"
#include "Stopwatch.hpp"
#define USAGE "./vector <number of elements> <stress power>"
#define BENCH_FUNC int(*)(std::size_t, int)

std::vector<BENCH_FUNC> getBenchCases( void );

static bool validateArgs( int ac, char** av )
{
    if (ac != 3 || atoi(av[1]) < 0 || atoi(av[2]) < 0)
    {
        std::cerr << USAGE << std::endl;
        return (true);
    }
    return (false);
}

int main(int ac, char** av)
{
    int nb_elements;
    int stress_power;
    int total_ko = 0;
    std::vector<int (*)(std::size_t, int)> cases = getBenchCases();

    if (validateArgs(ac, av))
    {
        return (1);
    }

    nb_elements = atoi(av[1]);
    stress_power = atoi(av[2]);
    for (typename std::vector<int(*)(std::size_t, int)>::iterator it = cases.begin(); it < cases.end(); ++it)
    {
        total_ko += (*it)(nb_elements, stress_power);
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
