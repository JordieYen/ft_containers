#ifndef FTMAPITERATOR_HPP
# define FTMAPITERATOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>
# include "ft_iterator_traits.hpp"
# include "bst.hpp"
# include "ft_remove_const.hpp"

namespace ft
{

	template <typename T>
	struct mIterator
	{
		public:
			typedef	typename ft::iterator_traits<T*>::difference_type		difference_type;
			typedef	typename ft::iterator_traits<T*>::value_type			value_type;
			typedef	typename ft::iterator_traits<T*>::pointer				pointer;
			typedef	typename ft::iterator_traits<T*>::reference				reference;
			typedef	typename ft::iterator_traits<T*>::iterator_category		iterator_category;
			typedef ft::node<typename ft::remove_const<T>::type >*			node_ptr;

			mIterator(void);
			mIterator(node_ptr node);
			mIterator(const mIterator& clone);
			mIterator&	operator=(const mIterator<T>& clone);
			~mIterator(void);

			node_ptr			minimum(node_ptr x);
			node_ptr			maximum(node_ptr x);

			mIterator	operator+(int n);
			mIterator	operator-(int n);
			mIterator	operator++();
			mIterator	operator++(int);
			mIterator	operator--();
			mIterator	operator--(int);
			void		operator+=(int n);
			void		operator-=(int n);
			T&			operator*() const;
			T			*operator->();
			T			*operator->() const;

			T				*base;
			node_ptr		_node;

	};

	template <typename T, typename U>
	bool		operator<(mIterator<T> current, mIterator<U> other);
	template <typename T, typename U>
	bool		operator>(mIterator<T> current, mIterator<U> other);
	template <typename T, typename U>
	bool		operator<=(mIterator<T> current, mIterator<U> other);
	template <typename T, typename U>
	bool		operator>=(mIterator<T> current, mIterator<U> other);
	template <typename T, typename U>
	bool		operator==(mIterator<T> current, mIterator<U> other);
	template <typename T, typename U>
	bool		operator!=(mIterator<T> current, mIterator<U> other);
}

#include "ft_map_iterator.tpp"

#endif