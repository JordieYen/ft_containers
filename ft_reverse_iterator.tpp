#include "ft_iterator.hpp"

namespace ft
{
	template<typename T>
	reverseIterator<T>::reverseIterator(void)
	{
		this->_pointer = nullptr;
	}

	template<typename T>
	reverseIterator<T>::reverseIterator(T *value)
	{
		this->_pointer = value;
	}

	template<typename T>
	reverseIterator<T>::reverseIterator(const reverseIterator& clone)
	{
		this->_pointer = clone._pointer;
	}

	template<typename T>
	reverseIterator<T>&	reverseIterator<T>::operator=(const reverseIterator& clone)
	{
		this->_pointer = clone._pointer;
		return (*this);
	}

	template<typename T>
	reverseIterator<T>::~reverseIterator(void)
	{
	}

	template<typename T>
	reverseIterator<T>	reverseIterator<T>::operator++(int)
	{
		this->_pointer--;
		return (*this);
	}

	template<typename T>
	reverseIterator<T>	reverseIterator<T>::operator++()
	{
		reverseIterator	temp(this->_pointer);

		this->_pointer--;
		return (temp);
	}

	template<typename T>
	reverseIterator<T>	reverseIterator<T>::operator--(int)
	{
		this->_pointer++;
		return (*this);
	}

	template<typename T>
	reverseIterator<T>	reverseIterator<T>::operator--()
	{
		reverseIterator	temp(this->_pointer);

		this->_pointer++;
		return (temp);
	}

	template<typename T>
	T&	reverseIterator<T>::operator*()
	{
		return (*this->_pointer);
	}

	template<typename T>
	T*	reverseIterator<T>::operator->()
	{
		return (this->_pointer);
	}

	template<typename T>
	T&	reverseIterator<T>::operator[](int i)
	{
		return (this->_pointer[i]);
	}

	template<typename T>
	reverseIterator<T>	reverseIterator<T>::operator+(int n)
	{
		reverseIterator	temp(this->_pointer);

		for (int i = 0; i < n; i++)
			temp._pointer--;
		return (temp);
	}

	template<typename T>
	reverseIterator<T>	reverseIterator<T>::operator-(int n)
	{
		reverseIterator	temp(this->_pointer);

		for (int i = 0; i < n; i++)
			temp._pointer++;
		return (temp);
	}

	template<typename T>
	bool		operator==(reverseIterator<T> current, reverseIterator<T> other)
	{
		if (current._pointer == other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator!=(reverseIterator<T> current, reverseIterator<T> other)
	{
		if (current._pointer != other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<(reverseIterator<T> current, reverseIterator<T> other)
	{
		if (current._pointer < other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>(reverseIterator<T> current, reverseIterator<T> other)
	{
		if (current._pointer > other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<=(reverseIterator<T> current, reverseIterator<T> other)
	{
		if (current._pointer == other._pointer)
			return (true);
		if (current._pointer < other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>=(reverseIterator<T> current, reverseIterator<T> other)
	{
		if (current._pointer == other._pointer)
			return (true);
		if (current._pointer > other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	void	reverseIterator<T>::operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			this->_pointer++;
	}

	template<typename T>
	void	reverseIterator<T>::operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			this->_pointer--;
	}
}