#include "ft_iterator.hpp"

namespace ft
{
	template<typename T>
	Iterator<T>::Iterator(void)
	{
		// this->base = nullptr;
		this->base = NULL;
	}

	template<typename T>
	Iterator<T>::Iterator(typename ft::remove_const<T>::type *value)
	{
		this->base = value;
	}

	template<typename T>
	Iterator<T>::Iterator(const Iterator<typename ft::remove_const<T>::type>& clone)
	{
		this->base = clone.base;
	}

	template<typename T>
	template<typename U>
	Iterator<T>&	Iterator<T>::operator=(const Iterator<U>& clone)
	{
		this->base = clone.base;
		return (*this);
	}

	template<typename T>
	Iterator<T>::~Iterator(void)
	{
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator++()
	{
		this->base++;
		return (*this);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator++(int)
	{
		Iterator	temp(this->base);

		++(*this);
		return (temp);
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator--()
	{
		this->base--;
		return (*this);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator--(int)
	{
		Iterator	temp(this->base);

		--(*this);
		return (temp);
	}

	template<typename T>
	T&	Iterator<T>::operator*()
	{
		return (*this->base);
	}

	template<typename T>
	T*	Iterator<T>::operator->()
	{
		return (this->base);
	}

	template<typename T>
	T&	Iterator<T>::operator[](int i)
	{
		return (this->base[i]);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator+(int n) const
	{
		Iterator	temp(this->base);

		for (int i = 0; i < n; i++)
			temp.base++;
		return (temp);
	}

	template<typename T>
	Iterator<T>	Iterator<T>::operator-(int n) const
	{
		Iterator	temp(this->base);

		for (int i = 0; i < n; i++)
			temp.base--;
		return (temp);
	}

	template<typename T>
	template<typename Iter>
	typename Iterator<T>::difference_type	Iterator<T>::operator-(Iter other) const
	{
		difference_type ret = this->base - other.base;

		return (ret);
	}

	template <typename T, typename U>
	bool		operator==(Iterator<T> current, Iterator<U> other)
	{
		if (current.base == other.base)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator!=(Iterator<T> current, Iterator<U> other)
	{
		if (current.base != other.base)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator<(Iterator<T> current, Iterator<U> other)
	{
		if (current.base < other.base)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator>(Iterator<T> current, Iterator<U> other)
	{
		if (current.base > other.base)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator<=(Iterator<T> current, Iterator<U> other)
	{
		if (current.base == other.base)
			return (true);
		if (current.base < other.base)
			return (true);
		return (false);
	}

	template <typename T, typename U>
	bool		operator>=(Iterator<T> current, Iterator<U> other)
	{
		if (current.base == other.base)
			return (true);
		if (current.base > other.base)
			return (true);
		return (false);
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			this->base++;
		return(*this);
	}

	template<typename T>
	Iterator<T>&	Iterator<T>::operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			this->base--;
		return(*this);
	}
}