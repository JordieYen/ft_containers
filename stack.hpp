#ifndef FTSTACK_HPP
# define FTSTACK_HPP

# include <iostream>
# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

			explicit stack(const container_type& ctnr = container_type());
			stack(const stack& other);
			~stack(void);
			stack&		operator=( const stack& other);

			bool		empty(void); //
			size_t		size(void); //
			T			top(void); //
			void		push(T val); //
			void		pop(void); //
			void		swap(stack& other);

			friend bool	operator==(const stack<T, Container>& current, const stack<T, Container>& other)
			{
				return (current.c == other.c);
			}

			friend bool	operator<(const stack<T, Container>& current, const stack<T, Container>& other)
			{
				return (current.c < other.c);
			}

		// protected:
			container_type	c;
	};

	template <class T, class Container>
	bool	operator!=(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (!(current.c == other.c));
	}
	template <class T, class Container>
	bool	operator<=(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (!(other.c < current.c));
	}
	template <class T, class Container>
	bool	operator>(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (other.c < current.c);
	}
	template <class T, class Container>
	bool	operator>=(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (!(current.c < other.c));
	}
}

#include "stack.tpp"

#endif