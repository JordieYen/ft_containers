#ifndef FTSTACK_HPP
# define FTSTACK_HPP

# include <iostream>
# include "ft_vector.hpp"

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
				return (current._stack == other._stack);
			}

			friend bool	operator<(const stack<T, Container>& current, const stack<T, Container>& other)
			{
				return (current._stack < other._stack);
			}

		protected:
			container_type	_stack;
	};

	template <class T, class Container>
	bool	operator!=(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (!(current == other));
	}
	template <class T, class Container>
	bool	operator<=(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (!(other < current));
	}
	template <class T, class Container>
	bool	operator>(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (other < current);
	}
	template <class T, class Container>
	bool	operator>=(const stack<T, Container>& current, const stack<T, Container>& other)
	{
		return (!(current < other));
	}
}

#include "ft_stack.tpp"

#endif