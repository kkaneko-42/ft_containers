#include <iostream>
#include <vector>
#include <cstdlib>
#include "vector.hpp"
#include <algorithm>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET_COLOR "\033[m"
#define MAX_LOSS 20 // milli seconds
/*
static void printContents( const std::vector<int>& vec )
{
    for (std::vector<int>::const_iterator it = vec.begin(); it < vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static void printContents( const ft::vector<int>& vec )
{
    for (ft::vector<int>::const_iterator it = vec.begin(); it < vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
}
*/

template < class RetType = void >
static int testResult( const std::vector<int>& std_res, const ft::vector<int>& ft_res )
{
    int ret = 1;
    const char* color = RED;
    const char* result = "KO";

    if (std::equal<
    std::vector<int>::const_iterator,
    ft::vector<int>::const_iterator>(
        std_res.begin(), std_res.end(), ft_res.begin()))
    {
        ret = 0;
        color = GREEN;
        result = "OK";
    }
    
    // todo: put log(contents, size, capacity, etc...)
    std::cout << "result: " << color << result << RESET_COLOR << std::endl;

    return (ret);
}

int testDefaultConstructor( std::size_t n )
{
    (void)n;

    std::cout << "====== Default Constructor ======" << std::endl;
    std::vector<int> a;
    ft::vector<int> b;

    return (testResult(a, b));
}

int testInitConstructor( std::size_t n )
{
    std::cout << "====== Initalization Constructor ======" << std::endl;
    std::vector<int> a(n, 42);
    ft::vector<int> b(n, 42);

    return (testResult(a, b));
}

int testIterConstructor( std::size_t n )
{
    std::vector<int> src(n, 42);

    std::cout << "====== Initalization Constructor ======" << std::endl;
    std::vector<int> a(src.begin(), src.end());
    ft::vector<int> b(src.begin(), src.end());

    return (testResult(a, b));
}
/*
int testCopyConstructor( std::size_t n )
{
    std::vector<int> std_src(n, 42);
    ft::vector<int> ft_src(n, 42);

    std::cout << "====== Initalization Constructor ======" << std::endl;
    std::vector<int> a(std_src);
    ft::vector<int> b(ft_src);

    return (testResult(a, b));
}
*/

std::vector<int(*)(std::size_t)> getTestCases( void )
{
    const std::size_t nb_test = 3;
    int (*test[nb_test])(std::size_t)  = {
        testDefaultConstructor,
        testInitConstructor,
        testIterConstructor
    };
    std::vector<int(*)(std::size_t)> cases;

    for (std::size_t i = 0; i < nb_test; ++i)
    {
        cases.push_back(test[i]);
    }

    return (cases);
}
