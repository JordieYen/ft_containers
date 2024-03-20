#include "ft_iterator.hpp"

namespace ft
{
	template< class Iter >
	reverse_iterator<Iter>::reverse_iterator(void)
	{
	}

	template< class Iter >
	reverse_iterator<Iter>::reverse_iterator (iterator_type it)
	{
		this->_base = it - 1;
	}

	template <class Iter>
	template <typename U>
	reverse_iterator<Iter>::reverse_iterator (const reverse_iterator<U>& other)
	{
		this->_base = other._base;
	}

	template <class Iter>
	reverse_iterator<Iter>::~reverse_iterator(void)
	{
	}

	template <class Iter>
	template< class U >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=( const reverse_iterator<U>& other )
	{
		this->_base = other._base;
		return (*this);
	}

	template <class Iter>
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator*() const
	{
		return (*(this->_base.base));
	}

	template <class Iter>
	typename reverse_iterator<Iter>::pointer reverse_iterator<Iter>::operator->() const
	{
		return (this->_base.base);
	}

	template <class Iter>
	typename reverse_iterator<Iter>::reference reverse_iterator<Iter>::operator[] (difference_type n) const
	{
		return (*(this->_base.base - n));
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator+ (difference_type n) const
	{
		reverse_iterator<Iter>	temp(*this);

		for (int i = 0; i < n; i++)
			temp._base--;
		return (temp);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
	{
		--this->_base;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
	{
		reverse_iterator temp(*this);

		(this->_base)--;
		return (temp);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
	{
		(this->_base)++;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
	{
		reverse_iterator temp(*this);

		(this->_base)++;
		return (temp);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator+= (difference_type n)
	{
		this->_base -= n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator-(difference_type n) const
	{
		reverse_iterator<Iter>	temp(*this);

		for (int i = 0; i < n; i++)
			temp._base++;
		return (temp);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator-= (difference_type n)
	{
		this->_base += n;
		return (*this);
	}

	template <class Iter>
	typename reverse_iterator<Iter>::iterator_type reverse_iterator<Iter>::base(void) const
	{
		return (this->_base + 1);
	}
}