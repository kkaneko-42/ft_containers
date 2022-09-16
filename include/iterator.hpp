#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace ft
{
	template < class T >
	class random_access_iterator
	{
        public:
            typedef std::random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;

            typedef pointer iterator_type;

            random_access_iterator( void ): it_(iterator_type())
            { }
            explicit random_access_iterator( iterator_type x ): it_(x)
            { }
            template < class U >
            random_access_iterator( const random_access_iterator<U>& other )
            {
                *this = other;
            }

            template < class U >
            random_access_iterator& operator=( const random_access_iterator<U>& other )
            {
                if (this != &other)
                {
                    it_ = other.it_;
                }
                return (*this);
            }

            iterator_type base( void ) const
            {
                return (it_);
            }

            reference operator*( void ) const
            {
                return (*it_);
            }
            pointer operator->( void ) const
            {
                return (it_);
            }

            /* unspecified */
            reference operator[]( difference_type n ) const
            {
                return (*(it_ + n));
            }
            random_access_iterator& operator++( void )
            {
                ++it_;
                return (*this);
            }
            random_access_iterator& operator--( void )
            {
                --it_;
                return (*this);
            }
            random_access_iterator operator++( int )
            {
                random_access_iterator res = *this;
                ++it_;
                return (res);
            }
            random_access_iterator operator--( int )
            {
                random_access_iterator res = *this;
                --it_;
                return (res);
            }
            random_access_iterator operator+( difference_type n ) const
            {
                return (ft::random_access_iterator<iterator_type>(it_ + n));
            }
            random_access_iterator operator-( difference_type n ) const
            {
                return (ft::random_access_iterator<iterator_type>(it_ - n));
            }
            random_access_iterator& operator+=( difference_type n )
            {
                it_ += n;
                return (*this);
            }
            random_access_iterator& operator-=( difference_type n )
            {
                it_ -= n;
                return (*this);
            }

		private:
			iterator_type it_;
	};

    /*
	template < class Iter >
	class reverse_iterator
	: public std::iterator<
		std::iterator_traits<Iter>::iterator_category,
		std::iterator_traits<Iter>::value_type,
		std::iterator_traits<Iter>::difference_type,
		std::iterator_traits<Iter>::pointer,
		std::iterator_traits<Iter>::reference
	>
	{
		public:
			typedef Iter iterator_type;

			reverse_iterator( void ): it_(iterator_type())
			{ }
			explicit reverse_iterator( iterator_type x ): it_(x)
			{ }
			template < class U >
			reverse_iterator( const reverse_iterator<U>& other )
			{
				*this = other;
			}

			template < class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other )
			{
				if (this != &other)
				{
					it_ = other.it_;
				}
				return (*this);
			}

			iterator_type base( void ) const
			{
				return (it_);
			}

			reference operator*( void ) const
			{
				return (it_.operator*());
			}
			pointer operator->( void ) const
			{
				return (it_.operator->());
			}

			// unspecified
            reference operator[]( difference_type n ) const
            {
                return (*(it_ - n));
            }
			reverse_iterator& operator++( void )
			{
				--it_;
				return (*this);
			}
			reverse_iterator& operator--( void )
			{
				++it_;
				return (*this);
			}
			reverse_iterator operator++( int )
			{
				reverse_iterator res = *this;
				--it_;
				return (res);
			}
			reverse_iterator operator--( int )
			{
				reverse_iterator res = *this;
				++it_;
				return (res);
			}
			reverse_iterator operator+( difference_type n ) const
			{
				return (ft::reverse_iterator<iterator_type>(it_ - n));
			}
			reverse_iterator operator-( difference_type n ) const
			{
				return (ft::reverse_iterator<iterator_type>(it_ + n));
			}
			reverse_iterator& operator+=( difference_type n )
			{
				it_ -= n;
				return (*this);
			}
			reverse_iterator& operator-=( difference_type n )
			{
				it_ += n;
				return (*this);
			}

		private:
			iterator_type it_;
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
    */
}

#endif
