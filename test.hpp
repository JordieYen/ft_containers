#ifndef TEST_HPP
# define TEST_HPP

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

		private:
			allocator_type	allocator;
			T				*_vector;
			int				_capacity;
			int				_size;
	};
}

#endif