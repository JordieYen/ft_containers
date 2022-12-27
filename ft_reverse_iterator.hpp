#ifndef FTREVERSEITERATOR_HPP
# define FTREVERSEITERATOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>
# include "ft_iterator_traits.hpp"

namespace ft
{	
	template <typename T>
	struct reverseIterator : public ft::iterator_traits<T*>
	{
		public:
			reverseIterator(void);
			reverseIterator(T *value);
			reverseIterator(const reverseIterator& clone);
			reverseIterator&	operator=(const reverseIterator& clone);
			~reverseIterator(void);

			reverseIterator	operator+(int n);
			reverseIterator	operator-(int n);
			reverseIterator	operator++();
			reverseIterator	operator++(int);
			reverseIterator	operator--();
			reverseIterator	operator--(int);
			void			operator+=(int n);
			void			operator-=(int n);
			T&				operator*();
			T				*operator->();
			T&				operator[](int i);

			T	*_pointer;
	};

	template <typename T>
	bool		operator<(reverseIterator<T> current, reverseIterator<T> other);
	template <typename T>
	bool		operator>(reverseIterator<T> current, reverseIterator<T> other);
	template <typename T>
	bool		operator<=(reverseIterator<T> current, reverseIterator<T> other);
	template <typename T>
	bool		operator>=(reverseIterator<T> current, reverseIterator<T> other);
	template <typename T>
	bool		operator==(reverseIterator<T> current, reverseIterator<T> other);
	template <typename T>
	bool		operator!=(reverseIterator<T> current, reverseIterator<T> other);
}

#include "ft_reverse_iterator.tpp"

#endif