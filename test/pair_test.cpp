#include <utility>
#include <iostream>
#include <string>
#include <cstdlib>
#include "pair.hpp"

static int constructersTest( bool verbose );
static int assignTest( bool verbose );
static int make_pairTest( bool verbose );
static int compareTest( bool verbose );

// T should support operators: <<, ==
template < class T1, class T2 >
static int expect( const std::string& test_case, T1 expect, T2 res, bool verbose )
{
	if (verbose)
	{
		std::cout << "@Case >> " << test_case << std::endl;
		std::cout << "EXPECT: " << expect << std::endl;
		std::cout << "res: " << res << std::endl;
	}
	if (!(expect == res))
	{
		if (verbose)
			std::cout << "\033[31mKO\033[m" << std::endl;
		return (1);
	}
	if (verbose)
		std::cout << "\033[32mOK\033[m" << std::endl;
	return (0);
}

template <class T1, class T2 >
std::ostream &operator<<( std::ostream& os, ft::pair<T1, T2>& p )
{
	os << "(" << p.first << ", " << p.second << ")";
	return (os);
}

template <class T1, class T2 >
std::ostream &operator<<( std::ostream& os, std::pair<T1, T2>& p )
{
	os << "(" << p.first << ", " << p.second << ")";
	return (os);
}

int main(int ac, char **av)
{
	bool verbose = (ac > 1) ? true : false;
	int nb_err = 0;

	(void)av;
	srand(time(NULL));
	nb_err += constructersTest(verbose);
	nb_err += assignTest(verbose);
	nb_err += make_pairTest(verbose);
	nb_err += compareTest(verbose);

	if (nb_err == 0)
		std::cout << "\033[32mAll OK\033[m" << std::endl;
	else
		std::cout << "\033[31mKO: " << nb_err << "\033[m" << std::endl;
	return (0);
}

static int constructersTest( bool verbose )
{
	int nb_err = 0;
	std::pair<std::string, int> a("hoge", 42);
	ft::pair<std::string, int> b("hoge", 42);
	std::pair<std::string, int> a_cpy(a);
	ft::pair<std::string, int> b_cpy(b);
	std::pair<std::string, int> a_assign;
	ft::pair<std::string, int> b_assign;

	// string : int
	nb_err += expect< std::pair<std::string, int>, ft::pair<std::string, int> >(
		"Default construct",
		std::pair<std::string, int>(),
		ft::pair<std::string, int>(),
		verbose
	);

	nb_err += expect< std::pair<std::string, int>, ft::pair<std::string, int> >(
		"Value-initialize construct",
		a, b,
		verbose
	);

	nb_err += expect< std::pair<std::string, int>, ft::pair<std::string, int> >(
		"Copy construct",
		a_cpy, b_cpy,
		verbose
	);

	return (nb_err);
}

static int assignTest( bool verbose )
{
	int nb_err = 0;
	std::pair<std::string, int> a("hoge", 42);
	ft::pair<std::string, int> b("hoge", 42);
	std::pair<std::string, int> a_assign;
	ft::pair<std::string, int> b_assign;

	nb_err += expect< std::pair<std::string, int>, ft::pair<std::string, int> >(
		"Assignation operator",
		a_assign = a, b_assign = b,
		verbose
	);

	return (nb_err);
}

static int make_pairTest( bool verbose )
{
	int nb_err = 0;

	nb_err += expect< std::pair<std::string, int>, ft::pair<std::string, int> >(
		"make_pair",
		std::make_pair<std::string, int>("fuga", -42),
		ft::make_pair<std::string, int>("fuga", -42),
		verbose
	);

	return (nb_err);
}

static int compareTest( bool verbose )
{
	int nb_err = 0;
	std::pair<std::string, int> a("hoge", 42);
	ft::pair<std::string, int> b("hoge", 42);
	std::pair<std::string, int> a_cpy(a);
	ft::pair<std::string, int> b_cpy(b);

	nb_err += expect<bool, bool>(
		"Compare",
		a == a_cpy, b == b_cpy,
		verbose
	);

	return (nb_err);
}
