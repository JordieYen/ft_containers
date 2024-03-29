#ifndef FTVECTOR_HPP
# define FTVECTOR_HPP

# include <iostream>
# include <limits>
# include <algorithm>
# include <memory>
# include "ft_iterator.hpp"
# include "ft_reverse_iterator.hpp"
# include "ft_equal.hpp"
# include "ft_lexicographical_compare.hpp"
# include "ft_enable_if.hpp"
# include "ft_is_integral.hpp"
# include "ft_remove_const.hpp"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector 
	{
		public:
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef value_type*													pointer;
			typedef const pointer												const_pointer;
			typedef typename ft::Iterator<T>									iterator;
			typedef typename ft::Iterator<const T>								const_iterator;
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef std::size_t													size_type;

			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			vector(const vector& clone);
			~vector(void);

			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type* = nullptr);
			template <class InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type first,
				InputIterator last, const allocator_type& alloc = allocator_type());

			Allocator			get_allocator(void);
			size_t				size(void) const;
			int					capacity(void) const;
			T					*data(void);

			size_t				max_size(void) const;
			T&					front(void) const;
			T&					back(void) const;
			bool				empty(void) const;
			void				swap(vector& other);

			void				clear(void);
			void				assign(size_t i, T value);
			template< class InputIt >
			void				assign( InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value>::type* = 0);
			T&					at(size_t index) const;
			void				reserve(size_t size);
			void				push_back(T value);
			void				pop_back(void);
			void				resize(size_t size);
			void				resize(size_t size, T value);

			vector<T>&			operator=(const vector& clone);
			T&					operator[](size_t i);

			Iterator<T>			insert(Iterator<T> pos, const value_type& val);
			void				insert(Iterator<T> pos, size_t n, const value_type& val);
			template< class InputIt >
			void				insert(Iterator<T> pos, InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value>::type* = 0);
			Iterator<T>			erase(Iterator<T> pos);
			Iterator<T>			erase(Iterator<T> first, Iterator<T> last);

			iterator			begin(void);
			iterator			end(void);
			const_iterator		begin(void) const;
			const_iterator		end(void) const;
			reverse_iterator	rbegin(void);
			reverse_iterator	rend(void);
			const_reverse_iterator	rbegin(void) const;
			const_reverse_iterator	rend(void) const;

		private:
			template< class InputIt >
			size_t	count_iterator(InputIt first, InputIt last);
			bool	validate_iterator(Iterator<T> pos);
			void	destroy_vector(void);
			T*		create_vector(size_t new_capacity);

			allocator_type	allocator;
			T				*_vector;
			int				_capacity;
			int				_size;
	};

	template <typename T, class Allocator>
	bool	operator==(const vector<T, Allocator>& current, const vector<T, Allocator>& other);
	template <typename T, class Allocator>
	bool	operator!=(const vector<T, Allocator>& current, const vector<T, Allocator>& other);
	template <typename T, class Allocator>
	bool	operator<(const vector<T, Allocator>& current, const vector<T, Allocator>& other);
	template <typename T, class Allocator>
	bool	operator<=(const vector<T, Allocator>& current, const vector<T, Allocator>& other);
	template <typename T, class Allocator>
	bool	operator>(const vector<T, Allocator>& current, const vector<T, Allocator>& other);
	template <typename T, class Allocator>
	bool	operator>=(const vector<T, Allocator>& current, const vector<T, Allocator>& other);
	template <typename T>
	void	swap(const vector<T>& current, const vector<T>& other);
}

#include "vector.tpp"

#endif