#include "is_integral.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

// T should support operators: <<, !=
template < class T >
static int expect( const std::string& test_case, T expect, T res, bool verbose )
{
	if (verbose)
	{
		std::cout << "@Case >> " << test_case << std::endl;
		std::cout << "EXPECT: " << expect << std::endl;
		std::cout << "res: " << res << std::endl;
	}
	if (expect != res)
	{
		if (verbose)
			std::cout << "\033[31mKO\033[m" << std::endl;
		return (1);
	}
	if (verbose)
		std::cout << "\033[32mOK\033[m" << std::endl;
	return (0);
}

template < class T >
int is_integral_test( bool verbose )
{
	const std::string type = typeid(T).name();
	int nb_err = 0;

	if (verbose)
		std::cout << "============== is_integral test of typename " + type + " ===============" << std::endl;

	nb_err += expect<bool>(
		"is_integral<" + type + ">::value",
		std::is_integral<T>::value,
		ft::is_integral<T>::value,
		verbose
	);

	return (nb_err);
}

int main(int ac, char **av)
{
	bool verbose = (ac > 1) ? true : false;
	int nb_err = 0;
	(void)av;

	nb_err += is_integral_test<bool>(verbose);
	nb_err += is_integral_test<const bool>(verbose);
	nb_err += is_integral_test<bool const>(verbose);
	nb_err += is_integral_test<volatile bool>(verbose);
	nb_err += is_integral_test<bool volatile>(verbose);
	nb_err += is_integral_test<const volatile bool>(verbose);
	nb_err += is_integral_test<volatile const bool>(verbose);

	nb_err += is_integral_test<char>(verbose);
	nb_err += is_integral_test<const char>(verbose);
	nb_err += is_integral_test<char const>(verbose);
	nb_err += is_integral_test<volatile char>(verbose);
	nb_err += is_integral_test<char volatile>(verbose);
	nb_err += is_integral_test<const volatile char>(verbose);
	nb_err += is_integral_test<volatile const char>(verbose);

	nb_err += is_integral_test<wchar_t>(verbose);
	nb_err += is_integral_test<const wchar_t>(verbose);
	nb_err += is_integral_test<wchar_t const>(verbose);
	nb_err += is_integral_test<volatile wchar_t>(verbose);
	nb_err += is_integral_test<wchar_t volatile>(verbose);
	nb_err += is_integral_test<const volatile wchar_t>(verbose);
	nb_err += is_integral_test<volatile const wchar_t>(verbose);

	nb_err += is_integral_test<short>(verbose);
	nb_err += is_integral_test<const short>(verbose);
	nb_err += is_integral_test<short const>(verbose);
	nb_err += is_integral_test<volatile short>(verbose);
	nb_err += is_integral_test<short volatile>(verbose);
	nb_err += is_integral_test<const volatile short>(verbose);
	nb_err += is_integral_test<volatile const short>(verbose);

	nb_err += is_integral_test<int>(verbose);
	nb_err += is_integral_test<const int>(verbose);
	nb_err += is_integral_test<int const>(verbose);
	nb_err += is_integral_test<volatile int>(verbose);
	nb_err += is_integral_test<int volatile>(verbose);
	nb_err += is_integral_test<const volatile int>(verbose);
	nb_err += is_integral_test<volatile const int>(verbose);

	nb_err += is_integral_test<long>(verbose);
	nb_err += is_integral_test<const long>(verbose);
	nb_err += is_integral_test<long const>(verbose);
	nb_err += is_integral_test<volatile long>(verbose);
	nb_err += is_integral_test<long volatile>(verbose);
	nb_err += is_integral_test<const volatile long>(verbose);
	nb_err += is_integral_test<volatile const long>(verbose);

	nb_err += is_integral_test<long long>(verbose);
	nb_err += is_integral_test<const long long>(verbose);
	nb_err += is_integral_test<long long const>(verbose);
	nb_err += is_integral_test<volatile long long>(verbose);
	nb_err += is_integral_test<long long volatile>(verbose);
	nb_err += is_integral_test<const volatile long long>(verbose);
	nb_err += is_integral_test<volatile const long long>(verbose);

	nb_err += is_integral_test<std::string>(verbose);
	nb_err += is_integral_test<const std::string>(verbose);
	nb_err += is_integral_test<std::string const>(verbose);
	nb_err += is_integral_test<volatile std::string>(verbose);
	nb_err += is_integral_test<std::string volatile>(verbose);
	nb_err += is_integral_test<const volatile std::string>(verbose);
	nb_err += is_integral_test<volatile const std::string>(verbose);


	if (nb_err == 0)
		std::cout << "\033[32mAll OK\033[m" << std::endl;
	else
		std::cout << "\033[31mKO: " << nb_err << "\033[m" << std::endl;
	return (0);
}
