#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
	    public:
			/* Type definitions */
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::random_access_iterator<value_type> iterator;
			typedef const ft::random_access_iterator<value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			/* Constructers */
			vector( void ):
				allocator_(allocator_type()), first_(allocator_.allocate(0)),
				last_(first_), capacity_last_(last_)
			{}

			explicit vector( const Allocator& alloc ):
				allocator_(alloc), first_(allocator_.allocate(0)),
				last_(first_), capacity_last_(last_)
			{}

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() ):
				allocator_(alloc), first_(allocator_.allocate(count)),
				last_(first_ + count), capacity_last(last_)
			{
				for (pointer p = first_; p < last_; ++p)
				{
					allocator_.construct(p, value);
				}
			}

			template < class InputIt, class enable = !ft::enable_if< ft::is_integral<InputIt> >::type >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ):
				allocator_(alloc), first_(allocator_.allocate(last - first)),
				last_(first_ + (last - first)), capacity_last_(last_)
			{
				InputIt it = first;

				for (pointer p = first_; p < last_; ++p)
				{
					allocator_.construct(p, *it);
					++it;
				}
			}

			vector( const vector& other )
			{
				*this = other;
			}

			/* Destructer */
			virtual ~vector( void )
			{
				for (pointer p = first_; p < last_; ++p)
				{
					allocator_.destroy(p);
				}
				allocator_.deallocate(first_, capacity_last_ - first_);
			}

			/* Assignations */
			vector& operator=( const vector& other )
			{
				if (this != &rhs)
				{
					// reallocate this->data_memory
					// deepcopy other's contents
					// set private var
				}
				return (*this);
			}

			void assign( size_type count, const T& value ) {};
			template < class InputIt >
			void assign( InputIt first, InputIt last ) {};

			allocator_type get_allocator( void ) const { return allocator_; }

			/* Element access */
			reference at( size_type pos );
			const_reference at( size_type pos ) const;

			reference operator[]( size_type pos );
			const_reference operator[]( size_type pos ) const;

			reference front( void );
			const_reference front( void ) const;

			reference back( void );
			const_reference back( void ) const;

			T* data( void );
			const T* data( void ) const;

			/* Iterators */
			iterator begin( void )
			{
				return (iterator(first_));
			}
			const_iterator begin( void ) const
            {
                return (const_iterator(first_));
            }

			iterator end( void )
            {
                return (iterator(last_));
            }
			const_iterator end( void ) const
            {
                return (const_iterator(end_));
            }

			reverse_iterator rbegin( void )
            {
                return (reverse_iterator(end() - 1));
            }
			const_reverse_iterator rbegin( void ) const
            {
                return (reverse_iterator(end() - 1));
            }

			reverse_iterator rend( void )
            {
                return (reverse_iterator(start() - 1));
            }
			const_reverse_iterator rend( void ) const
            {
                return (reverse_iterator(start() - 1));
            }

			/* Capacity */
			bool empty( void ) const
            {
                return (size() == 0);
            }
			size_type size( void ) const
            {
                return (last_ - first_);
            }
			size_type max_size( void ) const
            {
                std::numeric_limits<difference_type>::max();
            }
			void reserve( size_type new_cap )
            {
                if (new_cap <= capacity())
                    return;
                for (pointer p = first_; p < last_; ++p)
				{
					allocator_.destroy(p);
				}
				allocator_.deallocate(first_, capacity_last_ - first_);
                first_ = allocator_.allocate(new_cap);
            }
			size_type capacity( void ) const
            {
                return (capacity_last_ - first_);
            }

			/* Modifiers */
			void clear( void );

			iterator insert( iterator pos, const T& value );
			void insert( iterator pos, size_type count, const T& value );
			template < class InputIt >
			void insert( iterator pos, InputIt first, InputIt last );

			iterator erase( iterator pos );
			iterator erase( iterator first, iterator last );

			void push_back( const T& value );
			void pop_back( void );
			void resize( size_type count, T value = T() );
			void swap( vector& other );
		
		private:
			pointer first_;
			pointer last_;
			pointer capacity_last_;
			allocator_type allocator_;
	}; // namespace ft

	/* Non-member functions */
	template < class T, class Alloc >
	bool operator==( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        if (lhs.size() != rhs.size())
            return (false);
        return (
            ft::equal<
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator>(
                lhs.begin(), lhs.end(), rhs.begin()
            )
        );
    }

	template < class T, class Alloc >
	bool operator!=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        return (!(lhs == rhs));
    }

	template < class T, class Alloc >
	bool operator<( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        return (
            ft::lexicographical_compare<
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator>(
                lhs.begin(), lhs.end(),
                rhs.begin(), rhs.end()
            )
        );
    }

	template < class T, class Alloc >
	bool operator<=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        return (!(lhs > rhs));
    }

	template < class T, class Alloc >
	bool operator>( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        return (
            ft::lexicographical_compare<
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator,
            typename ft::vector<T>::iterator>(
                rhs.begin(), rhs.end(),
                lhs.begin(), lhs.end()
            )
        );
    }

	template < class T, class Alloc >
	bool operator>=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        return (!(lhs < rhs));
    }

	template < class T, class Alloc >
	void swap( ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs );
}

#endif
