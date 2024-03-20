#include "ft_map_iterator.hpp"
#include "bst.hpp"

namespace ft
{
	template<typename T>
	mIterator<T>::mIterator(void)
	{
		// this->base = nullptr;
		// this->_node = nullptr;
	}

	template<typename T>
	mIterator<T>::mIterator(node_ptr node)
	{
		this->base = node->key;
		this->_node = node;
	}

	template<typename T>
	mIterator<T>::mIterator(const mIterator<typename ft::remove_const<T>::type>& clone) : _node(clone._node)
	{
		this->base = this->_node->key;
	}

	template<typename T>
	mIterator<T>&	mIterator<T>::operator=(const mIterator<T>& clone)
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
	mIterator<T>&	mIterator<T>::operator++()
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
	mIterator<T>	mIterator<T>::operator++(int)
	{
		mIterator	temp(this->_node);

		++(*this);
		return (temp);
	}

	template<typename T>
	mIterator<T>&	mIterator<T>::operator--()
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
	mIterator<T>	mIterator<T>::operator--(int)
	{
		mIterator	temp(this->_node);

		(--(*this));
		return (temp);
	}

	template<typename T>
	T&	mIterator<T>::operator*() const
	{
		return (*this->base);
	}

	template<typename T>
	T*	mIterator<T>::operator->()
	{
		return (this->base);
	}

	template<typename T>
	T*	mIterator<T>::operator->() const
	{
		return (this->base);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator+(int n) const
	{
		mIterator<T>	temp(this->_node);

		for (int i = 0; i < n; i++)
			temp++;
		return (temp);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator-(int n) const
	{
		mIterator	temp(this->_node);

		for (int i = 0; i < n; i++)
			temp--;
		return (temp);
	}

	template <typename T, typename U>
	bool		operator==(mIterator<T> current, mIterator<U> other)
	{
		if (current._node == other._node)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator!=(mIterator<T> current, mIterator<U> other)
	{
		if (current._node != other._node)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator<(mIterator<T> current, mIterator<U> other)
	{
		if (current._node->key->first < other._node->key->first)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator>(mIterator<T> current, mIterator<U> other)
	{
		if (current._node->key->first > other._node->key->first)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator<=(mIterator<T> current, mIterator<U> other)
	{
		if (current._node->key->first == other._node->key->first)
			return (true);
		if (current._node->key->first < other._node->key->first)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator>=(mIterator<T> current, mIterator<U> other)
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
	typename mIterator<T>::node_ptr		mIterator<T>::minimum(node_ptr x)
	{
		typename mIterator<T>::node_ptr	y = x;

		while (y->left_child->is_nil != true)
			y = y->left_child;
		return (y);
	}

	template<typename T>
	typename mIterator<T>::node_ptr	mIterator<T>::maximum(node_ptr x)
	{
		typename mIterator<T>::node_ptr	y = x;

		while (y->right_child->is_nil != true)
			y = y->right_child;
		return (y);
	}
}