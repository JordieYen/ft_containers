#ifndef FTITERATOR_HPP
# define FTITERATOR_HPP

# include <iostream>
# include <limits>
# include <iterator>
# include <memory>

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
	struct Iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:
			Iterator(void);
			Iterator(T *value);
			Iterator(const Iterator& clone);
			Iterator&	operator=(const Iterator& clone);
			~Iterator(void);

			Iterator	operator+(int n);
			Iterator	operator-(int n);
			Iterator&	operator++();
			Iterator	operator++(int);
			Iterator&	operator--();
			Iterator	operator--(int);
			void		operator+=(int n);
			void		operator-=(int n);
			T&			operator*();
			T			*operator->();
			T&			operator[](int i);

			T	*_pointer;
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

#endif