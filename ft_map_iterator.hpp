#ifndef FTMAPITERATOR_HPP
# define FTMAPITERATOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>
# include "ft_iterator_traits.hpp"
# include "bst.hpp"

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

			mIterator(void);
			mIterator(ft::node<T> *node);
			mIterator(const mIterator& clone);
			mIterator&	operator=(const mIterator& clone);
			~mIterator(void);

			ft::node<T>*			minimum(ft::node<T> *x);
			ft::node<T>*			maximum(ft::node<T> *x);

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
			T			*operator->() const;

			T				*base;
			ft::node<T>		*_node;

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