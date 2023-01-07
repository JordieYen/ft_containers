#include "ft_stack.hpp"

namespace ft
{
	template <class T, class Container>
	stack<T, Container>::stack(const container_type& ctnr)
	{
	}

	template <class T, class Container>
	stack<T, Container>::~stack(void)
	{
	}

	template <class T, class Container>
	bool	stack<T, Container>::empty(void)
	{
		return (this->_stack.empty());
	}

	template <class T, class Container>
	size_t	stack<T, Container>::size(void)
	{
		return (this->_stack.size());
	}

	template <class T, class Container>
	T	stack<T, Container>::top(void)
	{
		return (this->_stack[this->size() - 1]);
	}

	template <class T, class Container>
	void	stack<T, Container>::push(T val)
	{
		this->_stack.push_back(val);
	}
	
	template <class T, class Container>
	void	stack<T, Container>::pop(void)
	{
		this->_stack.pop_back();
	}

	template <class T, class Container>
	void	stack<T, Container>::swap(stack& other)
	{
		this->_stack.swap(other._stack);
	}
}