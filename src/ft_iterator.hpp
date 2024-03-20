#ifndef FTITERATOR_HPP
# define FTITERATOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>
# include "ft_iterator_traits.hpp"
# include "ft_remove_const.hpp"

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
			Iterator(typename ft::remove_const<T>::type *value);
			Iterator(const Iterator<typename ft::remove_const<T>::type>& clone);
			template<typename U>
			Iterator<T>&	operator=(const Iterator<U>& clone);
			~Iterator(void);

			Iterator		operator+(int n) const;
			Iterator		operator-(int n) const;
			template<typename Iter>
			difference_type	operator-(Iter other) const;
			Iterator&		operator++();
			Iterator		operator++(int);
			Iterator&		operator--();
			Iterator		operator--(int);
			Iterator&		operator+=(int n);
			Iterator&		operator-=(int n);
			T&				operator*();
			T				*operator->();
			T&				operator[](int i);

			typename ft::remove_const<T>::type	*base;
	};

	template <typename T, typename U>
	bool		operator<(Iterator<T> current, Iterator<U> other);
	template <typename T, typename U>
	bool		operator>(Iterator<T> current, Iterator<U> other);
	template <typename T, typename U>
	bool		operator<=(Iterator<T> current, Iterator<U> other);
	template <typename T, typename U>
	bool		operator>=(Iterator<T> current, Iterator<U> other);
	template <typename T, typename U>
	bool		operator==(Iterator<T> current, Iterator<U> other);
	template <typename T, typename U>
	bool		operator!=(Iterator<T> current, Iterator<U> other);
	template <typename T>
	Iterator<T>		operator+(int n, Iterator<T> other)
	{
		Iterator<T>	temp(other);

		for (int i = 0; i < n; i++)
			temp.base++;
		return (temp);
	}
	template <typename T>
	Iterator<T>		operator-(int n, Iterator<T> other)
	{
		Iterator<T>	temp(other);

		for (int i = 0; i < n; i++)
			temp.base--;
		return (temp);
	}
	// template <typename T, typename U>
	// std::ptrdiff_t	operator-(T current, U other)
	// {
	// 	std::ptrdiff_t ret = current.base - other.base();

	// 	return (ret);
	// }
}

#include "ft_iterator.tpp"

#endif