#include <iostream>
#include "enable_if.hpp"

template < class T >
typename std::enable_if< std::is_integral<T>::value >::type test( void )
{
	std::cout << "T is an integer" << std::endl;
}

template < class T >
typename std::enable_if< !std::is_integral<T>::value >::type test( void )
{
	std::cout << "T is not an integer" << std::endl;
}

template < class T >
typename ft::enable_if< std::is_integral<T>::value >::type ft_test( void )
{
	std::cout << "T is an integer" << std::endl;
}

template < class T >
typename ft::enable_if< !std::is_integral<T>::value >::type ft_test( void )
{
	std::cout << "T is not an integer" << std::endl;
}

int main()
{
	test<int>();
	ft_test<int>();
	test<std::string>();
	ft_test<std::string>();
	return (0);
}
