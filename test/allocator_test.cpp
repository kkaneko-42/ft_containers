#include <vector>
#include <iostream>

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

int main()
{
    std::vector<Sample> a(5);
    Sample s;
    std::vector<Sample>::allocator_type alloc = a.get_allocator();

    alloc.construct(a.data(), s);
    return (0);
}
