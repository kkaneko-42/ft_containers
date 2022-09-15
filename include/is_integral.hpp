#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include "remove_cv.hpp"

namespace ft
{
	template < class T, T v >
	struct integral_constant
	{
		typedef T value_type;
		typedef integral_constant<T, v> type;

		static const T value = v;
	};

	template <>
	struct integral_constant<bool, true>
	{
		typedef bool value_type;
		typedef integral_constant<bool, true> type;
		typedef integral_constant<bool, true> true_type;

		static const bool value = true;
	};

	template <>
	struct integral_constant<bool, false>
	{
		typedef bool value_type;
		typedef integral_constant<bool, false> type;
		typedef integral_constant<bool, false> false_type;

		static const bool value = false;
	};

	template <class>
	struct is_integral_helper : public ft::integral_constant<bool, false>::false_type
	{ };

	template <>
	struct is_integral_helper<bool> : public ft::integral_constant<bool, true>::true_type
	{ };

	template <>
	struct is_integral_helper<char>
	: public ft::integral_constant<bool, true>::true_type
	{ };

	template <>
	struct is_integral_helper<wchar_t>
	: public ft::integral_constant<bool, true>::true_type
	{ };

	template <>
	struct is_integral_helper<short> 
	: public ft::integral_constant<bool, true>::true_type
	{ };

	template <>
	struct is_integral_helper<int>
	: public ft::integral_constant<bool, true>::true_type
	{ };

	template <>
	struct is_integral_helper<long>
	: public ft::integral_constant<bool, true>::true_type
	{ };

	template <>
	struct is_integral_helper<long long>
	: public ft::integral_constant<bool, true>::true_type
	{ };

	template < class T >
	struct is_integral
	: public ft::is_integral_helper< typename ft::remove_cv<T>::type >
	{ };
}

#endif
