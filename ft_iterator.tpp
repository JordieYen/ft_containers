#include "ft_iterator.hpp"

namespace ft
{
	template<typename T>
	Iterator<T>::Iterator(void)
	{
		this->_pointer = nullptr;
	}

	template<typename T>
	Iterator<T>::Iterator(T *value)
	{
		this->_pointer = value;
	}

	template<typename T>
	Iterator<T>::Iterator(const Iterator& clone)
	{
		this->_pointer = clone._pointer;
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator=(const Iterator& clone)
	{
		this->_pointer = clone._pointer;
		return (*this);
	}

	template<typename T>
	Iterator<T>::~Iterator(void)
	{
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator++(int)
	{
		this->_pointer++;
		return (*this);
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator++()
	{
		Iterator	temp(this->_pointer);

		this->_pointer++;
		return (temp);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator--(int)
	{
		this->_pointer--;
		return (*this);
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator--()
	{
		Iterator	temp(this->_pointer);

		this->_pointer--;
		return (temp);
	}

	template<typename T>
	T&	Iterator<T>::operator*()
	{
		return (*this->_pointer);
	}

	template<typename T>
	T*	Iterator<T>::operator->()
	{
		return (this->_pointer);
	}

	template<typename T>
	T&	Iterator<T>::operator[](int i)
	{
		return (this->_pointer[i]);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator+(int n)
	{
		Iterator	temp(this->_pointer);

		for (int i = 0; i < n; i++)
			temp._pointer++;
		return (temp);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator-(int n)
	{
		Iterator	temp(this->_pointer);

		for (int i = 0; i < n; i++)
			temp._pointer--;
		return (temp);
	}

	template<typename T>
	bool		operator==(Iterator<T> current, Iterator<T> other)
	{
		if (current._pointer == other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator!=(Iterator<T> current, Iterator<T> other)
	{
		if (current._pointer != other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<(Iterator<T> current, Iterator<T> other)
	{
		if (current._pointer < other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>(Iterator<T> current, Iterator<T> other)
	{
		if (current._pointer > other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<=(Iterator<T> current, Iterator<T> other)
	{
		if (current._pointer == other._pointer)
			return (true);
		if (current._pointer < other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>=(Iterator<T> current, Iterator<T> other)
	{
		if (current._pointer == other._pointer)
			return (true);
		if (current._pointer > other._pointer)
			return (true);
		return (false);
	}

	template<typename T>
	void	Iterator<T>::operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			this->_pointer++;
	}

	template<typename T>
	void	Iterator<T>::operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			this->_pointer--;
	}
}