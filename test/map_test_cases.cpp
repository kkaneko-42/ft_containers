#include "map.hpp"
#include <map>

std::vector<int(*)(std::size_t)> getTestCases( void )
{
    int (*test[])(std::size_t) = {
        NULL
    }
    std::vector<int(*)(std::size_t)> cases;

    for (std::size_t i = 0; test[i] != NULL; ++i)
    {
        cases.push_back(test[i]);
    }

    return (cases);
}
