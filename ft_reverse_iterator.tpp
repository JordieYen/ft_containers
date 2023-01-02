#include "ft_iterator.hpp"

namespace ft
{
	template< class Iter >
	reverse_iterator<Iter>::reverse_iterator(void)
	{
	}

	template< class Iter >
	explicit reverse_iterator<Iter>::reverse_iterator (iterator_type it)
	{
		this->base = it;
	}

	template <class Iter>
	reverse_iterator<Iter>::reverse_iterator (const reverse_iterator<Iter>& other)
	{
		this->base = other.base();
	}

	template <class Iter>
	reverse_iterator<Iter>::~reverse_iterator (void)
	{
	}

	template <class Iter>
	template< class U >
	reverse_iterator& reverse_iterator<Iter>::operator=( const reverse_iterator<U>& other )
	{
		this->base = other.base();
		return (*this);
	}

	template <class Iter>
	reference reverse_iterator<Iter>::operator*() const
	{
		return (*this->base.base);
	}

	template <class Iter>
	pointer reverse_iterator<Iter>::operator->() const
	{
		return (this->base.base);
	}

	template <class Iter>
	reference reverse_iterator<Iter>::operator[] (difference_type n) const
	{
		return (*(this->base - n));
	}

	template <class Iter>
	reverse_iterator reverse_iterator<Iter>::operator+ (difference_type n) const
	{
		this->base - n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator& reverse_iterator<Iter>::operator++()
	{
		reverse_iterator temp(*this);

		this->base--;
		return (temp);
	}

	template <class Iter>
	reverse_iterator reverse_iterator<Iter>::operator++(int)
	{
		this->base--;
		return (*this);
	}

	template <class Iter>
	reverse_iterator& reverse_iterator<Iter>::operator+= (difference_type n)
	{
		this->base -= n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator reverse_iterator<Iter>::operator- (difference_type n) const
	{
		this->base + n;
		return (*this);
	}

	template <class Iter>
	reverse_iterator& reverse_iterator<Iter>::operator--()
	{
		reverse_iterator temp(*this);

		this->base++;
		return (temp);
	}

	template <class Iter>
	reverse_iterator reverse_iterator<Iter>::operator--(int)
	{
		this->base++;
		return (*this);
	}

	template <class Iter>
	reverse_iterator& reverse_iterator<Iter>::operator-= (difference_type n)
	{
		this->base += n;
		return (*this);
	}

	template <class Iter>
	iterator_type reverse_iterator<Iter>::base(void) const
	{
		return (this->base);
	}
}