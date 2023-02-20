#include "ft_map_iterator.hpp"
#include "bst.hpp"

namespace ft
{
	template<typename T>
	mIterator<T>::mIterator(void)
	{
		this->base = nullptr;
		this->_node = nullptr;
	}

	template<typename T>
	mIterator<T>::mIterator(ft::node<T> *node)
	{
		this->base = node->key;
		this->_node = node;
	}

	template<typename T>
	mIterator<T>::mIterator(const mIterator& clone)
	{
		this->base = clone.base;
		this->_node = clone._node;
	}

	template<typename T>
	mIterator<T>&	mIterator<T>::operator=(const mIterator& clone)
	{
		this->base = clone.base;
		this->_node = clone._node;
		return (*this);
	}

	template<typename T>
	mIterator<T>::~mIterator(void)
	{
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator++(int)
	{
		if (this->_node->is_nil == true)
			this->_node = this->_node->left_child;
		else if (this->_node->right_child->is_nil == true)
		{
			if (this->_node->parent->right_child == this->_node)
			{
				while (this->_node->parent->left_child != this->_node && this->_node->parent->is_nil == false)
					this->_node = this->_node->parent;
			}
			this->_node = this->_node->parent;
		}
		else
			this->_node = this->minimum(this->_node->right_child);
		this->base = this->_node->key;
		return (*this);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator++()
	{
		mIterator	temp(this->_node);

		(*this)++;
		return (temp);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator--(int)
	{
		if (this->_node->is_nil == true)
			this->_node = this->_node->right_child;
		else if (this->_node->left_child->is_nil == true)
		{
			if (this->_node->parent->left_child == this->_node)
			{
				while (this->_node->parent->right_child != this->_node && this->_node->parent->is_nil == false)
					this->_node = this->_node->parent;
			}
			this->_node = this->_node->parent;
		}
		else
			this->_node = this->maximum(this->_node->left_child);
		this->base = this->_node->key;
		return (*this);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator--()
	{
		mIterator	temp(this->_node);

		(*this)--;
		return (temp);
	}

	template<typename T>
	T&	mIterator<T>::operator*()
	{
		return (*this->base);
	}

	template<typename T>
	T*	mIterator<T>::operator->()
	{
		return (this->base);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator+(int n)
	{
		mIterator<T>	temp(this->_node);

		for (int i = 0; i < n; i++)
			temp++;
		return (temp);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator-(int n)
	{
		mIterator	temp(this->_node);

		for (int i = 0; i < n; i++)
			temp--;
		return (temp);
	}

	template<typename T>
	bool		operator==(mIterator<T> current, mIterator<T> other)
	{
		if (current._node == other._node)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator!=(mIterator<T> current, mIterator<T> other)
	{
		if (current._node != other._node)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<(mIterator<T> current, mIterator<T> other)
	{
		if (current._node->key->first < other._node->key->first)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>(mIterator<T> current, mIterator<T> other)
	{
		if (current._node->key->first > other._node->key->first)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<=(mIterator<T> current, mIterator<T> other)
	{
		if (current._node->key->first == other._node->key->first)
			return (true);
		if (current._node->key->first < other._node->key->first)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>=(mIterator<T> current, mIterator<T> other)
	{
		if (current._node->key->first == other._node->key->first)
			return (true);
		if (current._node->key->first > other._node->key->first)
			return (true);
		return (false);
	}

	template<typename T>
	void	mIterator<T>::operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			(*this)++;
	}

	template<typename T>
	void	mIterator<T>::operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			(*this)--;
	}

	template < typename T>
	ft::node<T>*		mIterator<T>::minimum(ft::node<T> *x)
	{
		ft::node<T> *y = x;

		while (y->left_child->is_nil != true)
			y = y->left_child;
		return (y);
	}

	template<typename T>
	ft::node<T>*	mIterator<T>::maximum(ft::node<T> *x)
	{
		ft::node<T> *y = x;

		while (y->right_child->is_nil != true)
			y = y->right_child;
		return (y);
	}
}