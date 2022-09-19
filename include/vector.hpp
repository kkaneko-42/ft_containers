#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <limits>
#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"
#include "utility.hpp"

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
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

			/* Constructers */
			vector( void ): allocator_(allocator_type())
			{
                try
                {
                    first_ = allocator_.allocate(0);
                }
                catch(const std::exception& e)
                {
                    // Throw exception thrown by the allocation.
                    throw;
                }
                last_ = first_;
                capacity_last_ = last_;
            }

			explicit vector( const Allocator& alloc ): allocator_(alloc)
			{
                try
                {
                    first_ = allocator_.allocate(0);
                }
                catch(const std::exception& e)
                {
                    // Throw exception thrown by the allocation.
                    throw;
                }
                last_ = first_;
                capacity_last_ = last_;
            }

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() )
            : allocator_(alloc)
			{
                try
                {
                    first_ = allocator_.allocate(count);
                }
                catch(const std::exception& e)
                {
                    // Throw exception thrown by the allocation.
                    throw;
                }
                last_ = first_ + count;
                capacity_last_ = last_;

                // Initialize contents
				for (pointer p = first_; p < last_; ++p)
				{
					allocator_.construct(p, value);
				}
			}

            // InputIt is not an integer(SFINAE)
			template < class InputIt >
			vector( typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first,
                InputIt last, const Allocator& alloc = Allocator() )
            : allocator_(alloc)
			{
				InputIt it = first;

                try
                {
                    first_ = allocator_.allocate(last - first);
                }
                catch(const std::exception& e)
                {
                    // Throw exception thrown by the allocation.
                    throw;
                }
                last_ = first_ + (last - first);
                capacity_last_ = last_;
                
                // Initialize contents
				for (pointer p = first_; p < last_; ++p, ++it)
				{
					allocator_.construct(p, *it);
				}
			}

			vector( const vector& other )
			{
                // default construction
                try
                {
                    first_ = allocator_.allocate(0);
                }
                catch(const std::exception& e)
                {
                    // Throw exception thrown by the allocation.
                    throw;
                }
                last_ = first_;
                capacity_last_ = last_;

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
				if (this != &other)
				{
					assign<const_iterator>(other.begin(), other.end());
				}
				return (*this);
			}

			void assign( size_type count, const T& value )
            {
                const size_type current_size = size();
                pointer new_first;

                if (count > capacity())
                {
                    try
                    {
                        new_first = allocator_.allocate(count);
                    }
                    catch(const std::exception& e)
                    {
                        throw;
                    }

                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(new_first + i, value);
                    }

                    for (pointer p = first_; p < last_; ++p)
                    {
                        allocator_.destroy(p);
                    }
                    allocator_.deallocate(first_, capacity());
                    first_ = new_first;
                    last_ = new_first + count;
                    capacity_last_ = new_first + count;
                }
                else
                {
                    size_type i = 0;
                    while (i < current_size)
                    {
                        *(first_ + i) = value;
                        ++i;
                    }
                    while (i < count)
                    {
                        allocator_.construct(first_ + i, value);
                        ++i;
                    }
                }
            }

            // InputIt is not integer(SFINAE)
			template < class InputIt >
			void assign( typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last )
            {
                const size_type count = static_cast<size_type>(last - first);
                const size_type current_size = size();
                pointer new_first;

                if (count > capacity())
                {
                    try
                    {
                        new_first = allocator_.allocate(count);
                    }
                    catch(const std::exception& e)
                    {
                        throw;
                    }

                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(new_first + i, *(first + i));
                    }

                    for (pointer p = first_; p < last_; ++p)
                    {
                        allocator_.destroy(p);
                    }
                    allocator_.deallocate(first_, capacity());
                    first_ = new_first;
                    last_ = new_first + count;
                    capacity_last_ = new_first + count;
                }
                else
                {
                    size_type i = 0;
                    while (i < current_size && i < count)
                    {
                        *(first_ + i) = *(first + i);
                        ++i;
                    }
                    
                    while (i < count)
                    {
                        allocator_.construct(first_ + i, *(first + i));
                        ++i;
                    }
                }
            }

			allocator_type get_allocator( void ) const { return allocator_; }

			/* Element access */
			reference at( size_type pos )
            {
                if (!(pos < size()))
                    throw std::out_of_range("ft::vector: invalid pos of \"at\"");
                return (*(first_ + pos));
            }
			const_reference at( size_type pos ) const
            {
                if (!(pos < size()))
                    throw std::out_of_range("ft::vector: invalid pos of \"at\"");
                return (*(first_ + pos));
            }

			reference operator[]( size_type pos )
            {
                return (*(first_ + pos));
            }
			const_reference operator[]( size_type pos ) const
            {
                return (*(first_ + pos));
            }

			reference front( void )
            {
                return (*first_);
            }
			const_reference front( void ) const
            {
                return (*first_);
            }

			reference back( void )
            {
                return (*(last_ - 1));
            }
			const_reference back( void ) const
            {
                return (*(last_ - 1));
            }

			T* data( void )
            {
                return (first_);
            }
			const T* data( void ) const
            {
                return (first_);
            }

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
                return (const_iterator(last_));
            }

			reverse_iterator rbegin( void )
            {
                return (reverse_iterator(iterator(last_ - 1)));
            }
			const_reverse_iterator rbegin( void ) const
            {
                return (const_reverse_iterator(iterator(last_ - 1)));
            }

			reverse_iterator rend( void )
            {
                return (reverse_iterator(iterator(first_ - 1)));
            }
			const_reverse_iterator rend( void ) const
            {
                return (const_reverse_iterator(iterator(first_ - 1)));
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
                return (std::min<size_type>(
                    std::numeric_limits<difference_type>::max(),
                    allocator_.max_size())
                );
            }
			void reserve( size_type new_cap )
            {
                const size_type current_size = size();
                const size_type current_capacity = capacity();
                pointer new_first;

                // validate new_cap
                if (new_cap > max_size())
                    throw std::length_error("ft::vector: reserved by invalid size");
                else if (new_cap <= capacity())
                    return;
            
                // allocate new one
                try
                {
                    new_first = allocator_.allocate(new_cap);
                }
                catch(const std::exception& e)
                {
                    // Throw exception thrown by the allocation.
                    throw;
                }

                // copy old contents
                for (size_type i = 0; i < current_size; ++i)
                {
                    allocator_.construct(new_first + i, *(first_ + i));
                }

                // replace
                for (pointer p = first_; p < last_; ++p)
                {
                    allocator_.destroy(p);
                }
                allocator_.deallocate(first_, current_capacity);
                first_ = new_first;
                last_ = new_first + current_size;
                capacity_last_ = new_first + new_cap;
            }

			size_type capacity( void ) const
            {
                return (capacity_last_ - first_);
            }

			/* Modifiers */
			void clear( void )
            {
                while (last_ != first_)
                {
                    allocator_.destroy(last_ - 1);
                    --last_;
                }
                // first_ == last_, means size() == 0
            }

			iterator insert( iterator pos, const T& value )
            {
                const size_type pos_idx = static_cast<size_type>(pos - begin());
                insert(pos, 1, value);
                return (begin() + pos_idx);
            }

			void insert( iterator pos, size_type count, const T& value )
            {
                const size_type pos_idx = static_cast<size_type>(pos - begin());

                // if capacity is enough, do nothing
                reserve(count + size());

                // pos == end()
                if (pos_idx == size())
                {
                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(last_ + i, value);
                    }
                    last_ += count;
                }
                else
                {
                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(last_ + i, *(last_ - count + i));
                    }
                    for (size_type i = size() - 1; i > pos_idx + count; --i)
                    {
                        *(first_ + i) = *(first_ + i - count);
                    }
                    for (size_type i = 0; i < count; ++i)
                    {
                        *(first_ + pos_idx + i) = value;
                    }
                    last_ += count;
                }
            }

			template < class InputIt >
			void insert( iterator pos, InputIt first,
                typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type last )
            {
                const size_type count = static_cast<size_type>(last - first);
                const size_type pos_idx = static_cast<size_type>(pos - begin());
                const size_type current_size = size();

                // if capacity is enough, do nothing
                reserve(count + size());

                if (begin() + pos_idx == end())
                {
                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(last_ + i, *(first + i));
                    }
                    last_ += count;
                }
                else
                {
                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(last_, *(last_ - count));
                        ++last_;
                    }
                    for (size_type i = current_size - 1; i > pos_idx + count; --i)
                    {
                        *(first_ + i) = *(first_ + i - count);
                    }
                    for (size_type i = 0; i < count; ++i)
                    {
                        *(first_ + pos_idx + i) = *(first + i);
                    }
                    last_ += count;
                }
            }

			iterator erase( iterator pos )
            {
                return (erase(pos, pos + 1));
            }

			iterator erase( iterator first, iterator last )
            {
                const size_type pos_idx = static_cast<size_type>(first - begin());
                const size_type count = static_cast<size_type>(last - first);

                for (size_type i = pos_idx; i < pos_idx + count; ++i)
                {
                    *(first_ + i) = *(first_ + i + count);
                }
                for (size_type i = 0; i < count; ++i)
                {
                    allocator_.destroy(last_ - 1);
                    --last_;
                }
                return (begin() + pos_idx + count);
            }

			void push_back( const T& value )
            {
                if (last_ == capacity_last_)
                {
                    reserve(size() * 2);
                }
                allocator_.construct(last_, value);
                ++last_;
            }

			void pop_back( void )
            {
                allocator_.destroy(last_ - 1);
                --last_;
            }

			void resize( size_type count, T value = T() )
            {
                if (count > capacity() * 2)
                {
                    reserve(count);
                }
                else if (count > capacity())
                {
                    reserve(capacity() * 2);
                }

                if (count < size())
                {
                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.destroy(last_ - 1);
                        --last_;
                    }
                }
                else
                {
                    for (size_type i = 0; i < count; ++i)
                    {
                        allocator_.construct(last_, value);
                        ++last_;
                    }
                }
            }

			void swap( vector& other )
            {
                ft::swap<pointer>(first_, other.first_);
                ft::swap<pointer>(last_, other.last_);
                ft::swap<pointer>(capacity_last_, other.capacity_last_);
                ft::swap<allocator_type>(allocator_, other.allocator_);
            }
		
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
        return (!(lhs > rhs) && !(lhs < rhs));
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
        return (rhs < lhs);
    }

	template < class T, class Alloc >
	bool operator>=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs )
    {
        return (!(lhs < rhs));
    }

	template < class T, class Alloc >
	void swap( ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs )
    {
        lhs.swap(rhs);
    }
}

#endif
