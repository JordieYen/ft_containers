#ifndef FTITERATOR_HPP
# define FTITERATOR_HPP

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
	struct Iterator
	{
		public:
			typedef	typename ft::iterator_traits<T*>::difference_type		difference_type;
			typedef	typename ft::iterator_traits<T*>::value_type			value_type;
			typedef	typename ft::iterator_traits<T*>::pointer				pointer;
			typedef	typename ft::iterator_traits<T*>::reference				reference;
			typedef	typename ft::iterator_traits<T*>::iterator_category		iterator_category;

			Iterator(void);
			Iterator(T *value);
			Iterator(const Iterator& clone);
			Iterator&	operator=(const Iterator& clone);
			~Iterator(void);

			Iterator		operator+(int n) const;
			Iterator		operator-(int n) const;
			difference_type	operator-(Iterator other) const;
			Iterator&		operator++();
			Iterator		operator++(int);
			Iterator&		operator--();
			Iterator		operator--(int);
			void			operator+=(int n);
			void			operator-=(int n);
			T&				operator*();
			T				*operator->();
			T&				operator[](int i);

			T	*base;
	};

	template <typename T>
	bool		operator<(Iterator<T> current, Iterator<T> other);
	template <typename T>
	bool		operator>(Iterator<T> current, Iterator<T> other);
	template <typename T>
	bool		operator<=(Iterator<T> current, Iterator<T> other);
	template <typename T>
	bool		operator>=(Iterator<T> current, Iterator<T> other);
	template <typename T>
	bool		operator==(Iterator<T> current, Iterator<T> other);
	template <typename T>
	bool		operator!=(Iterator<T> current, Iterator<T> other);
}

#include "ft_iterator.tpp"

#endif