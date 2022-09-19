#include <iostream>
#include <vector>
#include <cstdlib>
#include "vector.hpp"
#include "Stopwatch.hpp"
#include "equal.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET_COLOR "\033[m"
#define MAX_LOSS 20 // milli seconds

static void printContents( const std::vector<int> vec )
{
    for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

static void printContents( const ft::vector<int> vec )
{
    for (ft::vector<int>::iterator it = vec.begin(); it < vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

template < class RetType = void >
static int testResult( const std::vector<int>& std_res, const ft::vector<int>& ft_res )
{
    int ret = 0;
    const char* color = GREEN;

    if (ft::equal<
    std::vector<int>::iterator,
    ft::vector<int>::iterator>(
        std_res.begin(), std_res.end(), ft_res.begin()))
    {
        ret = 1;
        color = RED;
    }

    std::cout << "std: ";
    printContents(std_res);
    std::cout << std::endl;

    std::cout << "ft: ";
    printContents(ft_res);
    std::cout << std::endl;
    
    std::cout << "result: " << color << (std_res == ft_res) ? RESET_COLOR << std::endl;
    return (ret);
}

int testDefaultConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;

    std::cout << "====== Default Constructor ======" << std::endl;
    std::vector<int> a;
    ft::vector<int> b;

    return (testResult(a, b));
}

int testInitConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;

    std::cout << "====== Initalization Constructor ======" << std::endl;
    w.start();
    std::vector<int> a(n, 0);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<int> b(n, 0);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testIterConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    std::vector<int> std_src(n, 0);
    ft::vector<int> ft_src(n, 0);
    double std_res;
    double ft_res;

    std::cout << "====== Initialize by input iterator Constructor ======" << std::endl;
    w.start();
    std::vector<int> a(std_src.begin(), std_src.end());
    std_res = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<int> b(ft_src.begin(), ft_src.end());
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testCopyConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    std::vector<int> std_src(n, 0);
    ft::vector<int> ft_src(n, 0);
    double std_res;
    double ft_res;

    std::cout << "====== Copy Constructor ======" << std::endl;
    w.start();
    std::vector<int> a(std_src);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<int> b(ft_src);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testDestructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;

    std::cout << "====== Destructor ======" << std::endl;
    {
        std::vector<std::vector<int>::iterator> a;
        w.start();
    }
    std_res = w.getElapsedMilliseconds();

    {
        ft::vector<std::vector<int>::iterator> b;
        w.restart();
    }
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testAssignationOperator( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    int ret = 0;

    std::cout << "====== Assignation operator ======" << std::endl;
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n + 1 may overflow
        std::vector<int> std_src(n + 1);
        ft::vector<int> ft_src(n + 1);
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a = std_src;
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b = ft_src;
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n - 1 may underflow
        std::vector<int> std_src(n - 1);
        ft::vector<int> ft_src(n - 1);
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a = std_src;
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b = ft_src;
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    return (ret);
}

int testAssign( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    int ret = 0;

    std::cout << "====== Assignation ======" << std::endl;
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n + 1 may overflow
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a.assign(n + 1, 0);
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b.assign(n + 1, 0);
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n - 1 may underflow
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a.assign(n - 1, 0);
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b.assign(n - 1, 0);
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    return (ret);
}

int testIterAssign( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    int ret = 0;

    std::cout << "====== Iterator Assignation ======" << std::endl;
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n + 1 may overflow
        std::vector<int> std_src(n + 1);
        ft::vector<int> ft_src(n + 1);
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a.assign<std::vector<int>::iterator>(std_src.begin(), std_src.end());
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    std::cout << "@lhs.capacity() > rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n - 1 may underflow
        std::vector<int> std_src(n);
        ft::vector<int> ft_src(n);
        std::vector<int> a(n + 1);
        ft::vector<int> b(n + 1);

        w.start();
        a.assign<std::vector<int>::iterator>(std_src.begin(), std_src.end());
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    return (ret);
}

int testReserve( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    int ret = 0;

    std::cout << "====== Reserve ======" << std::endl;
    std::cout << "@this->capacity() < count case" << std::endl;
    {
        // todo: apply stress_power
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a.reserve(n + 1);
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b.reserve(n + 1);
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }
    std::cout << "@this->capacity() > count case" << std::endl;
    {
        // todo: apply stress_power
        std::vector<int> a(n + 1);
        ft::vector<int> b(n + 1);

        w.start();
        a.reserve(n);
        std_res = w.getElapsedMilliseconds();

        w.restart();
        b.reserve(n);
        ft_res = w.getElapsedMilliseconds();

        ret += testResult(std_res, ft_res);
    }

    return (ret);
}

int testClear( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== Clear ======" << std::endl;

    w.start();
    a.clear();
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.clear();
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testInsert( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== Insert ======" << std::endl;
    // todo: apply stress_power
    w.start();
    a.insert(a.begin(), 0);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.insert(b.begin(), 0);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testRangeInsert( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== Range Insert ======" << std::endl;
    w.start();
    a.insert(a.begin(), stress_power, 0);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.insert(b.begin(), stress_power, 0);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testIterInsert( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int> src(stress_power);

    std::cout << "====== Iter Insert ======" << std::endl;
    w.start();
    a.insert(a.begin(), src.begin(), src.end());
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.insert(b.begin(), src.begin(), src.end());
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testErase( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== Erase ======" << std::endl;
    // todo: apply stress_power
    w.start();
    a.erase(a.begin());
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.erase(b.begin());
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testIterErase( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int> src(stress_power);

    std::cout << "====== Iter Erase ======" << std::endl;
    
    w.start();
    // todo: apply stress_power
    a.erase(a.begin(), a.begin() + (n / 2));
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.erase(b.begin(), b.begin() + (n / 2));
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testPushBack( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== PushBack ======" << std::endl;
    w.start();
    a.push_back(0);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.push_back(0);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testPopBack( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== PopBack ======" << std::endl;
    w.start();
    a.pop_back();
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.pop_back();
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testResize( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== PopBack ======" << std::endl;
    w.start();
    a.resize(stress_power, 0);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.resize(stress_power, 0);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

int testSwap( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_res;
    double ft_res;
    std::vector<int> a(n);
    std::vector<int> a_swap(n + stress_power);
    ft::vector<int> b(n);
    ft::vector<int> b_swap(n + stress_power);

    std::cout << "====== Swap ======" << std::endl;
    w.start();
    a.swap(a_swap);
    std_res = w.getElapsedMilliseconds();

    w.restart();
    b.swap(b_swap);
    ft_res = w.getElapsedMilliseconds();

    return (testResult(std_res, ft_res));
}

std::vector<int(*)(std::size_t, int)> getTestCases( void )
{
    const std::size_t nb_test = 19;
    int (*test[nb_test])(std::size_t, int)  = {
        testDefaultConstructor,
        testInitConstructor,
        testIterConstructor,
        testCopyConstructor,
        testDestructor,
        testAssignationOperator,
        testAssign,
        testIterAssign,
        testReserve,
        testClear,
        testInsert,
        testRangeInsert,
        testIterInsert,
        testErase,
        testIterErase,
        testPushBack,
        testPopBack,
        testResize,
        testSwap
    };
    std::vector<int(*)(std::size_t, int)> cases;

    for (std::size_t i = 0; i < nb_test; ++i)
    {
        cases.push_back(test[i]);
    }

    return (cases);
}
