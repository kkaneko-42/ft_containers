#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft
{
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1,
		InputIt2 first2 )
	{
		InputIt1 it1 = first1;
		InputIt2 it2 = first2;

		while (it1 != last1)
		{
			if (!static_cast<bool>(*it1 == *it2))
				return (false);
			++it1;
			++it2;
		}
		return (true);
	}

	template<
		class InputIt1,
		class InputIt2,
		class BinaryPredicate >
	bool equal(
		InputIt1 first1, InputIt1 last1,
		InputIt2 first2, BinaryPredicate p
	)
	{
		InputIt1 it1 = first1;
		InputIt2 it2 = first2;

		while (it1 != last1)
		{
			if (!static_cast<bool>(p(*it1, *it2)))
				return (false);
			++it1;
			++it2;
		}
		return (true);
	}
}

#endif
