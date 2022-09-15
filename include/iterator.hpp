#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace ft
{
	template < class Iter >
	class reverse_iterator : std::iterator<
		typename std::iterator_traits<Iter>::iterator_category,
		typename std::iterator_traits<Iter>::value_type,
		typename std::iterator_traits<Iter>::difference_type,
		typename std::iterator_traits<Iter>::pointer,
		typename std::iterator_traits<Iter>::reference
	>
	{
		public:
			typedef Iter iterator_type;

			reverse_iterator( void );
			explicit reverse_iterator( iterator_type x );
			template < class U >
			reverse_iterator( const reverse_iterator<U>& other );

			template < class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other )
			{
				if (this != &other)
				{
					
				}
				return (*this);
			}
			
			iterator_type base( void ) const;

			reference operator*( void ) const;
			pointer operator->( void ) const;

			/* unspecified */ reference operator[]( difference_type n ) const;
			reverse_iterator& operator++( void );
			reverse_iterator& operator--( void );
			reverse_iterator operator++( int );
			reverse_iterator operator--( int );
			reverse_iterator operator+( difference_type n ) const;
			reverse_iterator operator-( difference_type n ) const;
			reverse_iterator& operator+=( difference_type n );
			reverse_iterator& operator-=( difference_type n );
	};

	template < class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() == rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() != rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() > rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() >= rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() < rhs.base());
	}

	template < class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{
		return (lhs.base() <= rhs.base());
	}


	template < class Iter >
	reverse_iterator<Iter>
	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it );

	template < class Iterator >
	typename reverse_iterator<Iterator>::difference_type
	operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs );


}

#endif
