#include <vector>
#include <iostream>

class Sample
{
    public:
        Sample( void ): memory(NULL)
        {
            std::cout << "default constructor called" << std::endl;
            reallocArray(42, 0);
        }

        Sample( const Sample& src )
        {
            std::cout << "copy constructor called" << std::endl;
            reallocArray(42, 0);
        }

        Sample& operator=( const Sample& rhs )
        {
            std::cout << "Assigned" << std::endl;
            if (this != &rhs)
            {
                reallocArray(42, 0);
            }
            return (*this);
        }
        ~Sample()
        {
            std::cout << "Destructor called" << std::endl;
            delete[] memory;
        }

    private:
        void reallocArray( size_t count, int value = 0 )
        {
            delete[] memory;
            memory = new int[count];
            for (size_t i = 0; i < count; ++i)
            {
                memory[i] = value;
            }
        }

    private:
        int *memory;
};

int main()
{
	std::vector<Sample> a(5);
    Sample s;

    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    a.reserve(6);
    std::cout << "=====" << std::endl;
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    return (0);
}
