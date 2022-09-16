#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

#include <cstdlib>

namespace ft
{
	template < class InputIt1, class InputIt2 >
	bool lexicographical_compare(
		InputIt1 first1, InputIt1 last1,
		InputIt2 first2, InputIt2 last2 )
	{
		InputIt1 it1 = first1;
		InputIt2 it2 = first2;
		bool ret = false;

		while (it1 != last1 && it2 != last2)
		{
			if (*it1 != *it2)
			{
				ret = static_cast<bool>(*it1 < *it2);
				break;
			}
			++it1;
			++it2;
		}
		return (ret || (it1 == last1 && it2 != last2));
	}
}

#endif
