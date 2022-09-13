#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/* type definitions */
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			// TODO: implement iterator (also reverse one)
			typedef iterator;
			typedef const_iterator;
			typedef reverse_iterator;
			typedef const_reverse_iterator;

			/* Constructers */
			vector( void );
			explicit vector( const Allocator& alloc );
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() );
			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
			vector( const vector& other );

			/* Destructer */
			~vector();

			/* Assignations */
			vector& operator=( const vector& other );

			void assign( size_type count, const T& value );
			template < class InputIt >
			void assign( InputIt first, InputIt last );

			allocator_type get_allocator( void ) const;

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
			iterator begin( void );
			const_iterator begin( void ) const;

			iterator end( void );
			const_iterator end( void ) const;

			reverse_iterator rbegin( void );
			const_reverse_iterator rbegin( void ) const;

			reverse_iterator rend( void );
			const_reverse_iterator rend( void ) const;

			/* Capacity */
			bool empty( void ) const;
			size_type size( void ) const;
			size_type max_size( void ) const;
			void reserve( size_type new_cap );
			size_type capacity( void ) const;

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

	};

	/* Non-member functions */
	template < class T, class Alloc >
	bool operator==( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

	template < class T, class Alloc >
	bool operator!=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

	template < class T, class Alloc >
	bool operator<( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

	template < class T, class Alloc >
	bool operator<=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

	template < class T, class Alloc >
	bool operator>( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

	template < class T, class Alloc >
	bool operator>=( const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs );

	template < class T, class Alloc >
	void swap( ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs );
}

#endif
