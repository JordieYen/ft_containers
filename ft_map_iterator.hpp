#ifndef FTMAPITERATOR_HPP
# define FTMAPITERATOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>
# include "ft_iterator_traits.hpp"

namespace ft
{
	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		public:
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
	};
	
	template <typename T>
	struct mIterator
	{
		public:
			typedef	typename ft::iterator_traits<T*>::difference_type		difference_type;
			typedef	typename ft::iterator_traits<T*>::value_type			value_type;
			typedef	typename ft::iterator_traits<T*>::pointer				pointer;
			typedef	typename ft::iterator_traits<T*>::reference				reference;
			typedef	typename ft::iterator_traits<T*>::iterator_category		iterator_category;

			mIterator(void);
			mIterator(T *value);
			mIterator(const Iterator& clone);
			mIterator&	operator=(const Iterator& clone);
			~mIterator(void);

			mIterator	operator+(int n);
			mIterator	operator-(int n);
			mIterator	operator++();
			mIterator	operator++(int);
			mIterator	operator--();
			mIterator	operator--(int);
			void		operator+=(int n);
			void		operator-=(int n);
			T&			operator*();
			T			*operator->();
			T&			operator[](int i);

			T	*base;
	};

	template <typename T>
	bool		operator<(mIterator<T> current, mIterator<T> other);
	template <typename T>
	bool		operator>(mIterator<T> current, mIterator<T> other);
	template <typename T>
	bool		operator<=(mIterator<T> current, mIterator<T> other);
	template <typename T>
	bool		operator>=(mIterator<T> current, mIterator<T> other);
	template <typename T>
	bool		operator==(mIterator<T> current, mIterator<T> other);
	template <typename T>
	bool		operator!=(mIterator<T> current, mIterator<T> other);
}

#include "ft_map_iterator.tpp"

#endif