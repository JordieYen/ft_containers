#include "stack.hpp"

namespace ft
{
	template <class T, class Container>
	stack<T, Container>::stack(const container_type& ctnr) : c(ctnr)
	{
	}

	template <class T, class Container>
	stack<T, Container>::~stack(void)
	{
	}

	template <class T, class Container>
	stack<T, Container>::stack( const stack<T, Container>& other )
	{
		this->c = other.c;
	}

	template <class T, class Container>
	stack<T, Container>& stack<T, Container>::operator=( const stack<T, Container>& other )
	{
		this->c = other.c;
		return (*this);
	}

	template <class T, class Container>
	bool	stack<T, Container>::empty(void)
	{
		return (this->c.empty());
	}

	template <class T, class Container>
	size_t	stack<T, Container>::size(void)
	{
		return (this->c.size());
	}

	template <class T, class Container>
	T	stack<T, Container>::top(void)
	{
		return (this->c.back());
	}

	template <class T, class Container>
	void	stack<T, Container>::push(T val)
	{
		this->c.push_back(val);
	}
	
	template <class T, class Container>
	void	stack<T, Container>::pop(void)
	{
		this->c.pop_back();
	}

	template <class T, class Container>
	void	stack<T, Container>::swap(stack& other)
	{
		this->c.swap(other.c);
	}
}