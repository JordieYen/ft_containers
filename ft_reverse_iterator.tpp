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
		this->_base = it;
	}

	template <class Iter>
	reverse_iterator<Iter>::reverse_iterator (const reverse_iterator<Iter>& other)
	{
		this->_base = other.base();
	}

	template <class Iter>
	reverse_iterator<Iter>::~reverse_iterator(void)
	{
	}

	template <class Iter>
	template< class U >
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator=( const reverse_iterator<U>& other )
	{
		this->_base = other.base();
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
		return (*(this->_base - n));
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator+ (difference_type n) const
	{
		this->_base - n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator++()
	{
		reverse_iterator temp(*this);

		this->_base--;
		return (temp);
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator++(int)
	{
		this->_base--;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator+= (difference_type n)
	{
		this->_base -= n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator- (difference_type n) const
	{
		this->_base + n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator<Iter>& reverse_iterator<Iter>::operator--()
	{
		reverse_iterator temp(*this);

		this->_base++;
		return (temp);
	}

	template <class Iter>
	reverse_iterator<Iter> reverse_iterator<Iter>::operator--(int)
	{
		this->_base++;
		return (*this);
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
		return (this->_base);
	}
}