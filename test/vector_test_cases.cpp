#include <iostream>
#include <vector>
#include <cstdlib>
#include "vector.hpp"
#include <algorithm>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET_COLOR "\033[m"
#define MAX_LOSS 20 // milli seconds

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
    std::cout << std::endl;
}

static void printTitle( const std::string& title )
{
    std::cout << "====== ";
    std::cout << title;
    std::cout << " ======" << std::endl;
}

static void printResult( bool ok )
{
    const char* color = (ok) ? GREEN : RED;
    const char* msg = (ok) ? "OK" : "KO";

    std::cout << color << msg << RESET_COLOR << std::endl;
}

// Assuming that operator[] works properly
static void assignRandomContents( std::vector<int>& std_dst, ft::vector<int>& ft_dst )
{
    int num;

    if (std_dst.size() != ft_dst.size())
        return;

    for (std::size_t i = 0; i < std_dst.size(); ++i)
    {
        num = rand();
        std_dst[i] = num;
        ft_dst[i] = num;
    }
}

template < class T >
static int testReturnValue( T ret1, T ret2 )
{
    if (ret1 == ret2)
    {
        printResult(true);
        return (0);
    }
    else
    {
        printResult(false);
        return (1);
    }
}

static int testResult( const std::vector<int>& std_res, const ft::vector<int>& ft_res,
    bool verbose = true )
{
    int ret = 1;

    if (std_res.size() == ft_res.size()
        && std::equal<
        std::vector<int>::const_iterator,
        ft::vector<int>::const_iterator>(
            std_res.begin(), std_res.end(), ft_res.begin()))
    {
        ret = 0;
    }
    
    // todo: put log(contents, size, capacity, etc...)
    std::cout << "std: ";
    printContents(std_res);
    std::cout << "ft_: ";
    printContents(ft_res);
    if (verbose)
    {
        printResult(ret == 0);
    }
    return (ret);
}

int testDefaultConstructor( std::size_t n )
{
    (void)n;

    printTitle("Default Constructor");
    std::vector<int> a;
    ft::vector<int> b;

    return (testResult(a, b));
}

int testInitConstructor( std::size_t n )
{
    printTitle("Init Constructor");
    std::vector<int> a(n, 42);
    ft::vector<int> b(n, 42);

    return (testResult(a, b));
}

int testIterConstructor( std::size_t n )
{
    std::vector<int> src(n, 42);

    printTitle("Iter Constructor");
    std::vector<int> a(src.begin(), src.end());
    ft::vector<int> b(src.begin(), src.end());

    return (testResult(a, b));
}

int testCopyConstructor( std::size_t n )
{
    std::vector<int> std_src(n, 42);
    ft::vector<int> ft_src(n, 42);

    printTitle("Copy Constructor");
    std::vector<int> a(std_src);
    ft::vector<int> b(ft_src);

    return (testResult(a, b));
}

int testAssignationOperator( std::size_t n )
{
    int ret = 0;

    printTitle("Assignation operator");
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        std::vector<int> std_src(n + 1, 42);
        ft::vector<int> ft_src(n + 1, 42);
        std::vector<int> a(n);
        ft::vector<int> b(n);

        assignRandomContents(std_src, ft_src);
        a = std_src;
        b = ft_src;
        ret += testResult(a, b);
    }
    std::cout << "@lhs.capacity() > rhs.capacity() case" << std::endl;
    {
        std::vector<int> std_src(n, 42);
        ft::vector<int> ft_src(n, 42);
        std::vector<int> a(n + 1);
        ft::vector<int> b(n + 1);

        assignRandomContents(std_src, ft_src);
        a = std_src;
        b = ft_src;
        ret += testResult(a, b);
    }
    std::cout << "@lhs.capacity() == rhs.capacity() case" << std::endl;
    {   
        std::vector<int> std_src(n, 42);
        ft::vector<int> ft_src(n, 42);
        std::vector<int> a(n + 1);
        ft::vector<int> b(n + 1);

        assignRandomContents(std_src, ft_src);
        a = std_src;
        b = ft_src;
        ret += testResult(a, b);
    }

    return (ret);
}

int testAssign( std::size_t n )
{
    int ret = 0;

    printTitle("Assign");
    std::cout << "@lhs.capacity() > rhs.capacity() case" << std::endl;
    {
        std::vector<int> a(n);
        ft::vector<int> b(n);

        a.assign(n + 1, 42);
        b.assign(n + 1, 42);
        ret += testResult(a, b);
    }
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        std::vector<int> a(n + 1);
        ft::vector<int> b(n + 1);

        a.assign(n, 42);
        b.assign(n, 42);
        ret += testResult(a, b);
    }
    std::cout << "@lhs.capacity() == rhs.capacity() case" << std::endl;
    {   
        std::vector<int> a(n);
        ft::vector<int> b(n);

        a.assign(n, 42);
        b.assign(n, 42);
        ret += testResult(a, b);
    }

    return (ret);
}

int testIterAssign( std::size_t n )
{
    int ret = 0;

    printTitle("Iter Assign");
    std::cout << "@lhs.capacity() < rhs.capacity() case" << std::endl;
    {
        std::vector<int> std_src(n + 1, 42);
        ft::vector<int> ft_src(n + 1, 42);
        std::vector<int> a(n);
        ft::vector<int> b(n);

        assignRandomContents(std_src, ft_src);
        a.assign<std::vector<int>::iterator>(std_src.begin(), std_src.end());
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ret += testResult(a, b);
    }
    std::cout << "@lhs.capacity() > rhs.capacity() case" << std::endl;
    {
        std::vector<int> std_src(n, 42);
        ft::vector<int> ft_src(n, 42);
        std::vector<int> a(n + 1);
        ft::vector<int> b(n + 1);

        assignRandomContents(std_src, ft_src);
        a.assign<std::vector<int>::iterator>(std_src.begin(), std_src.end());
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ret += testResult(a, b);
    }
    std::cout << "@lhs.capacity() == rhs.capacity() case" << std::endl;
    {   
        std::vector<int> std_src(n, 42);
        ft::vector<int> ft_src(n, 42);
        std::vector<int> a(n);
        ft::vector<int> b(n);

        assignRandomContents(std_src, ft_src);
        a.assign<std::vector<int>::iterator>(std_src.begin(), std_src.end());
        b.assign<ft::vector<int>::iterator>(ft_src.begin(), ft_src.end());
        ret += testResult(a, b);
    }

    return (ret);
}

int testAt( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    int ret = 0;
    assignRandomContents(a, b);

    printTitle("At");
    std::cout << "@pos is out of range case" << std::endl;
    {
        bool std_res;
        bool ft_res;

        try {
            a.at(n);
            std_res = false;
        } catch(const std::exception& e) {
            std_res = true;
        }

        try {
            b.at(n);
            ft_res = false;
        } catch(const std::exception& e) {
            ft_res = true;
        }
        ret += testReturnValue<bool>(std_res, ft_res);
    }

    std::cout << "@normal case" << std::endl;
    {
        for (std::size_t i = 0; i < a.size(); ++i)
        {
            if (a.at(i) != b.at(i))
            {
                ++ret;
            }
        }
        printResult(ret == 0);
    }
    return (ret);
}

int testSquareBracketOperator( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    int ret = 0;
    assignRandomContents(a, b);

    printTitle("Square Bracket Operator");
    for (std::size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            ++ret;
        }
    }
    printResult(ret == 0);
    return (ret);
}

int testFront( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("Front");
    return (testReturnValue<int>(a.front(), b.front()));
}

int testBack( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("Back");
    return (testReturnValue<int>(a.back(), b.back()));
}

int testData( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("Data");
    return (testReturnValue<int>(*(a.data()), *(b.data())));
}

int testBegin( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("Begin");
    std::vector<int>::iterator std_res = a.begin();
    ft::vector<int>::iterator ft_res = b.begin();

    while (std_res < a.end())
    {
        if (*std_res != *ft_res)
        {
            printResult(false);
            return (1);
        }
        ++std_res;
        ++ft_res;
    }
    printResult(true);
    return (0);
}

int testEnd( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("End");
    std::vector<int>::iterator std_res = a.end() - 1;
    ft::vector<int>::iterator ft_res = b.end() - 1;

    while (std_res >= a.begin())
    {
        if (*std_res != *ft_res)
        {
            printResult(false);
            return (1);
        }
        --std_res;
        --ft_res;
    }
    printResult(true);
    return (0);
}

int testRBegin( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("rBegin");
    std::vector<int>::reverse_iterator std_res = a.rbegin();
    ft::vector<int>::reverse_iterator ft_res = b.rbegin();

    while (std_res < a.rend())
    {
        if (*std_res != *ft_res)
        {
            printResult(false);
            return (1);
        }
        ++std_res;
        ++ft_res;
    }
    printResult(true);
    return (0);
}

int testREnd( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    assignRandomContents(a, b);

    printTitle("rEnd");
    std::vector<int>::reverse_iterator std_res = a.rend() - 1;
    ft::vector<int>::reverse_iterator ft_res = b.rend() - 1;

    while (std_res >= a.rbegin())
    {
        if (*std_res != *ft_res)
        {
            printResult(false);
            return (1);
        }
        --std_res;
        --ft_res;
    }
    printResult(true);
    return (0);
}

int testEmpty( std::size_t n )
{
    std::vector<int> no_empty_a(n);
    ft::vector<int> no_empty_b(n);
    std::vector<int> a(0);
    ft::vector<int> b(0);

    printTitle("Empty");
    return (testReturnValue<bool>(no_empty_a.empty(), no_empty_b.empty())
        + testReturnValue<bool>(a.empty(), b.empty()));
}

int testSize( std::size_t n )
{
    std::vector<int> zero_a(0);
    ft::vector<int> zero_b(0);
    std::vector<int> a(n);
    ft::vector<int> b(n);

    printTitle("Size");
    return (testReturnValue<std::size_t>(zero_a.size(), zero_b.size())
        + testReturnValue<std::size_t>(a.size(), b.size()));
}

int testMaxSize( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);

    printTitle("Max Size");
    return (testReturnValue<std::size_t>(a.max_size(), b.max_size()));
}

// also test capacity
int testReserve( std::size_t n )
{
    int ret = 0;

    printTitle("Reserve");
    std::cout << "@new_cap == max_size() case" << std::endl;
    {
        /* // causes valgrind or sanitizer error
        std::vector<int> a(n);
        ft::vector<int> b(n);
        bool std_res, ft_res;

        try {
            a.reserve(a.max_size());
            std_res = false;
        } catch(const std::exception& e) {
            std_res = true;
        }
        try {
            b.reserve(b.max_size());
            ft_res = true;
        } catch(const std::exception& e) {
            ft_res = true;
        }
        ret += testReturnValue<bool>(std_res, ft_res);
        */
    }
    std::cout << "@new_cap > capacity() case" << std::endl;
    {
        std::vector<int> a(n);
        ft::vector<int> b(n);

        a.reserve(a.capacity() + 10);
        b.reserve(b.capacity() + 10);
        std::cout << "contents: ";
        ret += testResult(a, b);
        std::cout << "capacity: ";
        ret += testReturnValue<std::size_t>(a.capacity(), b.capacity());
    }
    std::cout << "@new_cap <= capacity() case" << std::endl;
    {
        std::vector<int> a(n + 10);
        ft::vector<int> b(n + 10);

        a.reserve(n);
        b.reserve(n);
        std::cout << "contents: ";
        ret += testResult(a, b);
        std::cout << "capacity: ";
        ret += testReturnValue<std::size_t>(a.capacity(), b.capacity());
    }
    
    return (ret);
}

int testClear( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);

    printTitle("Clear");
    a.clear();
    b.clear();
    return (testResult(a, b) + testReturnValue<std::size_t>(a.size(), b.size()));
}

int testInsert( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int>::iterator std_ret;
    ft::vector<int>::iterator ft_ret;
    std::size_t pos = rand() & n;

    printTitle("Insert");
    std_ret = a.insert(a.begin() + pos, 42);
    ft_ret = b.insert(b.begin() + pos, 42);

    return (testResult(a, b)
        + testReturnValue<int>(*std_ret, *ft_ret));
}

int testRangeInsert( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::size_t pos = rand() % n, count = rand() % n;

    printTitle("Range Insert");
    a.insert(a.begin() + pos, count, 42);
    b.insert(b.begin() + pos, count, 42);
    return (testResult(a, b));
}

int testIterInsert( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int> std_src(rand() % n);
    ft::vector<int> ft_src(rand() % n);
    std::size_t pos = rand() % n;
    assignRandomContents(std_src, ft_src);

    printTitle("Iter Insert");
    a.insert(a.begin() + pos, std_src.begin(), std_src.end());
    b.insert(b.begin() + pos, ft_src.begin(), ft_src.end());
    
    return (testResult(a, b));
}

int testErase( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int>::iterator std_res;
    ft::vector<int>::iterator ft_res;
    std::size_t pos = rand() % n;

    printTitle("Erase");
    std_res = a.erase(a.begin() + pos);
    ft_res = b.erase(b.begin() + pos);
    return (testResult(a, b)
        + testReturnValue<int>(*std_res, *ft_res));
}

int testRangeErase( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int>::iterator std_res;
    ft::vector<int>::iterator ft_res;
    std::size_t pos = rand() % n, count = std::min(rand() % n, n - pos);

    printTitle("Range Erase");
    std_res = a.erase(a.begin() + pos, a.begin() + pos + count);
    ft_res = b.erase(b.begin() + pos, b.begin() + pos + count);
    return (testResult(a, b)
        + testReturnValue<int>(*std_res, *ft_res));
}

int testPushBack( std::size_t n )
{
    const std::size_t count = n * 2 + 1;
    std::vector<int> a(n);
    ft::vector<int> b(n);
    int ret = 0;

    printTitle("Push Back");
    for (std::size_t i = 0; i < count; ++i)
    {
        int value = rand();

        a.push_back(value);
        b.push_back(value);
        ret += testResult(a, b, false);
    }
    return (ret);
}

int testPopBack( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    int ret = 0;

    printTitle("Pop Back");
    for (std::size_t i = 0; i < n; ++i)
    {
        a.pop_back();
        b.pop_back();
        ret += testResult(a, b, false);
    }
    printResult(ret == 0);
    return (ret);
}

int testResize( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::size_t to_size = rand() % n;

    printTitle("Resize");
    a.resize(to_size, 42);
    b.resize(to_size, 42);

    return (testResult(a, b));
}

int testSwap( std::size_t n )
{
    std::vector<int> a(n);
    ft::vector<int> b(n);
    std::vector<int> std_src(n);
    ft::vector<int> ft_src(n);

    printTitle("Swap");
    a.swap(std_src);
    b.swap(ft_src);

    return (testResult(a, b));
}

std::vector<int(*)(std::size_t)> getTestCases( void )
{
    int (*test[])(std::size_t)  = {
        testDefaultConstructor,
        testInitConstructor,
        testIterConstructor,
        testCopyConstructor,
        testAssignationOperator,
        testAssign,
        testIterAssign,
        testAt,
        testSquareBracketOperator,
        testFront,
        testBack,
        testData,
        testBegin,
        testEnd,
        testRBegin,
        testREnd,
        testEmpty,
        testSize,
        testMaxSize,
        testReserve,
        testClear,
        testInsert,
        testRangeInsert,
        testIterInsert,
        testErase,
        testRangeErase,
        testPushBack,
        testPopBack,
        testResize,
        testSwap,
        NULL
    };
    std::vector<int(*)(std::size_t)> cases;

    for (std::size_t i = 0; test[i] != NULL; ++i)
    {
        cases.push_back(test[i]);
    }

    return (cases);
}
