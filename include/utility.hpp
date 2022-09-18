#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
    template <class T>
    void swap(T& a, T& b)
    {
        T tmp;

        tmp = a;
        a = b;
        b = tmp;
    }
}

#endif
