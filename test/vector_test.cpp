#include <vector>
#include <iostream>
#include "vector.hpp"

class Sample
{
    public:
        Sample( void )
        {
            std::cout << "default constructor called" << std::endl;
        }

        Sample( const Sample& src )
        {
            std::cout << "copy constructor called" << std::endl;
        }

        Sample& operator=( const Sample& rhs )
        {
            std::cout << "Assigned" << std::endl;
            return (*this);
        }
        ~Sample()
        {
            std::cout << "Destructor called" << std::endl;
        }
};

template < class T >
static void printAll(const std::vector<T>& vec)
{
    for (typename std::vector<T>::const_iterator it = vec.begin(); it < vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
	std::vector<Sample> a(5);
    std::vector<Sample> b(8);
    std::vector<int> integers(5, 42);
    std::vector<int> src(100);
    Sample s;

    std::cout << "capa: " << integers.capacity() << std::endl;
    std::cout << "size: " << integers.size() << std::endl;
    std::cout << "=======" << std::endl;

    integers.insert(integers.end(), src.begin(), src.begin() + 20);
    std::cout << "capa: " << integers.capacity() << std::endl;
    std::cout << "size: " << integers.size() << std::endl;
    printAll<int>(integers);

    return (0);
}
