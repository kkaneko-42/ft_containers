#ifndef REMOVE_CV_HPP
#define REMOVE_CV_HPP

namespace ft
{
	template<typename T>
    struct remove_const
    { typedef T type; };

	template<typename T>
    struct remove_const<T const>
    { typedef T type; };

	template<typename T>
    struct remove_volatile
    { typedef T type; };

	template<typename T>
    struct remove_volatile<T volatile>
    { typedef T type; };

	template<typename T>
    struct remove_cv
    {
		typedef typename remove_const<typename remove_volatile<T>::type>::type type;
    };
}

#endif
