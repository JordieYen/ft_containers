#include "ft_map_iterator.hpp"

namespace ft
{
	template<typename T>
	mIterator<T>::mIterator(void)
	{
		this->base = nullptr;
	}

	template<typename T>
	mIterator<T>::mIterator(T *value)
	{
		this->base = value;
	}

	template<typename T>
	mIterator<T>::mIterator(const mIterator& clone)
	{
		this->base = clone.base;
	}

	template<typename T>
	mIterator<T>&	mIterator<T>::operator=(const mIterator& clone)
	{
		this->base = clone.base;
		return (*this);
	}

	template<typename T>
	mIterator<T>::~mIterator(void)
	{
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator++(int)
	{
		this->base++;
		return (*this);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator++()
	{
		mIterator	temp(this->base);

		this->base++;
		return (temp);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator--(int)
	{
		this->base--;
		return (*this);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator--()
	{
		mIterator	temp(this->base);

		this->base--;
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
	T&	mIterator<T>::operator[](int i)
	{
		return (this->base[i]);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator+(int n)
	{
		mIterator	temp(this->base);

		for (int i = 0; i < n; i++)
			temp.base++;
		return (temp);
	}

	template<typename T>
	mIterator<T>	mIterator<T>::operator-(int n)
	{
		mIterator	temp(this->base);

		for (int i = 0; i < n; i++)
			temp.base--;
		return (temp);
	}

	template<typename T>
	bool		operator==(mIterator<T> current, mIterator<T> other)
	{
		if (current.base == other.base)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator!=(mIterator<T> current, mIterator<T> other)
	{
		if (current.base != other.base)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<(mIterator<T> current, mIterator<T> other)
	{
		if (current.base < other.base)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>(mIterator<T> current, mIterator<T> other)
	{
		if (current.base > other.base)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator<=(mIterator<T> current, mIterator<T> other)
	{
		if (current.base == other.base)
			return (true);
		if (current.base < other.base)
			return (true);
		return (false);
	}

	template<typename T>
	bool		operator>=(mIterator<T> current, mIterator<T> other)
	{
		if (current.base == other.base)
			return (true);
		if (current.base > other.base)
			return (true);
		return (false);
	}

	template<typename T>
	void	mIterator<T>::operator+=(int n)
	{
		for (int i = 0; i < n; i++)
			this->base++;
	}

	template<typename T>
	void	mIterator<T>::operator-=(int n)
	{
		for (int i = 0; i < n; i++)
			this->base--;
	}
}