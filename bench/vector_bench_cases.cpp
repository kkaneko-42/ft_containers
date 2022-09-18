#include <iostream>
#include <vector>
#include <cstdlib>
#include "vector.hpp"
#include "Stopwatch.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET_COLOR "\033[m"
#define MAX_LOSS 20 // milli seconds
#define BENCH_FUNC int(*)(std::size_t, int)

static int benchResult( double std_score, double ft_score )
{
    const double diff = ft_score - std_score;
    int ret = 0;
    const char* color = GREEN;

    if (diff > MAX_LOSS)
    {
        ret = 1;
        color = RED;
    }

    std::cout << "std: " << std_score << "[ms]" << std::endl;
    std::cout << "ft: " << ft_score << "[ms]" << std::endl;
    std::cout << "diff: " << color << diff << "[ms]" << RESET_COLOR << std::endl;
    return (ret);
}

int benchDefaultConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;

    std::cout << "====== Default Constructor ======" << std::endl;
    w.start();
    std::vector<int> a;
    std_score = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<int> b;
    ft_score = w.getElapsedMilliseconds();

    return (benchResult(std_score, ft_score));
}

int benchInitConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;

    std::cout << "====== Initalization Constructor ======" << std::endl;
    w.start();
    std::vector<int> a(n, 0);
    std_score = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<int> b(n, 0);
    ft_score = w.getElapsedMilliseconds();

    return (benchResult(std_score, ft_score));
}

int benchIterConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    std::vector<int> std_src(n, 0);
    ft::vector<int> ft_src(n, 0);
    double std_score;
    double ft_score;

    std::cout << "====== Initialize by input iterator Constructor ======" << std::endl;
    w.start();
    std::vector<std::vector<int>::iterator> a(std_src.begin(), std_src.end());
    std_score = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<ft::vector<int>::iterator> b(ft_src.begin(), ft_src.end());
    ft_score = w.getElapsedMilliseconds();

    return (benchResult(std_score, ft_score));
}

int benchCopyConstructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    std::vector<int> std_src(n, 0);
    ft::vector<int> ft_src(n, 0);
    double std_score;
    double ft_score;

    std::cout << "====== Copy Constructor ======" << std::endl;
    w.start();
    std::vector<int> a(std_src);
    std_score = w.getElapsedMilliseconds();

    w.restart();
    ft::vector<int> b(ft_src);
    ft_score = w.getElapsedMilliseconds();

    return (benchResult(std_score, ft_score));
}

int benchDestructor( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;

    std::cout << "====== Destructor ======" << std::endl;
    {
        std::vector<std::vector<int>::iterator> a;
        w.start();
    }
    std_score = w.getElapsedMilliseconds();

    {
        ft::vector<std::vector<int>::iterator> b;
        w.restart();
    }
    ft_score = w.getElapsedMilliseconds();

    return (benchResult(std_score, ft_score));
}

int benchAssignationOperator( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;
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
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b = ft_src;
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
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
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b = ft_src;
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
    }
    return (ret);
}

int benchAssign( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;
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
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b.assign(n + 1, 0);
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
    }
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        // todo: randamize
        // note: n - 1 may underflow
        std::vector<int> a(n);
        ft::vector<int> b(n);

        w.start();
        a.assign(n - 1, 0);
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b.assign(n - 1, 0);
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
    }
    return (ret);
}

int benchIterAssign( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;
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
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
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
        a.assign<std::vector<int>::iterator>(std_src.begin(), std_src.end());
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
    }
    return (ret);
}

int benchReserve( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;
    int ret = 0;

    std::cout << "====== Reserve ======" << std::endl;
    std::cout << "@this->capacity() < count case" << std::endl;
    {
        // todo: apply stress_power
        std::vector<int> a(n - 10);
        ft::vector<int> b(n - 10);

        w.start();
        a.reserve(n);
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b.reserve(n);
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
    }
    std::cout << "@this->capacity() > count case" << std::endl;
    {
        // todo: apply stress_power
        std::vector<int> a(n + 10);
        ft::vector<int> b(n + 10);

        w.start();
        a.reserve(n);
        std_score = w.getElapsedMilliseconds();

        w.restart();
        b.reserve(n);
        ft_score = w.getElapsedMilliseconds();

        ret += benchResult(std_score, ft_score);
    }

    return (ret);
}

int benchClear( std::size_t n, int stress_power )
{
    Stopwatch w;
    double std_score;
    double ft_score;
    std::vector<int> a(n);
    ft::vector<int> b(n);

    std::cout << "====== Clear ======" << std::endl;

    w.start();
    a.clear();
    std_score = w.getElapsedMilliseconds();

    w.restart();
    b.clear();
    ft_score = w.getElapsedMilliseconds();

    return (benchResult(std_score, ft_score));
}

/*
benchInsert,
benchRangeInsert,
benchIterInsert,
benchErase,
benchIterErase,
benchPushBack,
benchPopBack,
benchResize,
benchSwap
*/

std::vector<int(*)(std::size_t, int)> getBenchCases( void )
{
    const std::size_t nb_bench = 10;
    int (*bench[nb_bench])(std::size_t, int)  = {
        benchDefaultConstructor,
        benchInitConstructor,
        benchIterConstructor,
        benchCopyConstructor,
        benchDestructor,
        benchAssignationOperator,
        benchAssign,
        benchIterAssign,
        benchReserve,
        benchClear
    };
    std::vector<int(*)(std::size_t, int)> cases;

    for (std::size_t i = 0; i < nb_bench; ++i)
    {
        cases.push_back(bench[i]);
    }

    return (cases);
}
