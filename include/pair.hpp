#ifndef PAIR_HPP
#define PAIR_HPP

#include <utility>

namespace ft
{
	template < class T1, class T2 >
	struct pair
	{
		/* Member types */
		typedef T1 first_type;
		typedef T2 second_type;

		/* Member funcs */
		pair( void ): first(T1()), second(T2())
		{ }

		pair( const T1& x, const T2& y )
		: first(T1(x)), second(T2(y))
		{ }

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p )
		: first(T1(p.first)), second(T2(p.second))
		{ } // T1 != U1 ?????

		pair& operator=( const pair& other )
		{
			if (this != &other)
			{
				first = other.first;
				second = other.second;
			}
			return (*this);
		}

		/* Attributes(public) */
		T1 first;
		T2 second;
	};

	template < class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return (ft::pair<T1, T2>(t, u));
	}

	template < class T1, class T2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}

	template < class T1, class T2 >
	bool operator==( const std::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}

	template < class T1, class T2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}
}

#endif
