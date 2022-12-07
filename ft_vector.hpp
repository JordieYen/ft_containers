#ifndef FTVECTOR_HPP
# define FTVECTOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef typename std::allocator_traits<Allocator>::pointer			pointer;
			typedef typename std::allocator_traits<Allocator>::const_pointer	const_pointer;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;

			vector(void);
			vector(int i);
			vector(const vector& clone);
			vector&	operator=(const vector& clone);
			T&	operator[](int i);
			~vector();
			
			T&		at(int index);
			T&		front(void);
			T&		back(void);
			T		*data(void);
			bool	empty(void);
			int		size(void);
			// int		max_size(void);
			void	reserve(int size);
			int		capacity(void);
			void	shrink_to_fit(void);
			void	clear(void);
			void	push_back(T value);
			void	pop_back(void);
			void	resize(int size);
			void	resize(int size, T value);
			void	swap(vector& other);

		private:
			void	update_capacity(void);
			void	reallocate(T *new_vector);

			allocator_type	allocator;
			T				*_vector;
			int				_capacity;
			int				_size;
	};
}

#endif