#ifndef FTREVERSEITERATOR_HPP
# define FTREVERSEITERATOR_HPP

# include "ft_iterator_traits.hpp"

namespace ft
{
	template< class Iter >
	class reverse_iterator
	{
		public:
			typedef	Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;

			reverse_iterator(void);
			explicit reverse_iterator (iterator_type it);
			template <typename U>
			reverse_iterator (const reverse_iterator<U>& other);
			~reverse_iterator(void);

			template< class U > reverse_iterator&	operator=( const reverse_iterator<U>& other );
			reference 								operator*(void) const;
			pointer									operator->(void) const;
			reference								operator[] (difference_type n) const;
			reverse_iterator						operator+ (difference_type n) const;
			reverse_iterator&						operator++(void);
			reverse_iterator						operator++(int);
			reverse_iterator&						operator+= (difference_type n);
			reverse_iterator						operator- (difference_type n) const;
			reverse_iterator&						operator--(void);
			reverse_iterator						operator--(int);
			reverse_iterator&						operator-= (difference_type n);
			iterator_type							base(void) const;

		// private:
			iterator_type	_base;
	};

	template <class Iter, class U>
	bool		operator<(reverse_iterator<Iter> current, reverse_iterator<U> other)
	{
		return (current.base() > other.base());
	}
	template <class Iter, class U>
	bool		operator>(reverse_iterator<Iter> current, reverse_iterator<U> other)
	{
		return (current.base() < other.base());
	}
	template <class Iter, class U>
	bool		operator<=(reverse_iterator<Iter> current, reverse_iterator<U> other)
	{
		return (current.base() >= other.base());
	}
	template <class Iter, class U>
	bool		operator>=(reverse_iterator<Iter> current, reverse_iterator<U> other)
	{
		return (current.base() <= other.base());
	}
	template <class Iter, class U>
	bool		operator==(reverse_iterator<Iter> current, reverse_iterator<U> other)
	{
		return (current.base() == other.base());
	}
	template <class Iter, class U>
	bool		operator!=(reverse_iterator<Iter> current, reverse_iterator<U> other)
	{
		return (current.base() != other.base());
	}
	template <class Iter, class U>
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<U>& rev_it)
	{
		reverse_iterator<Iter> temp(*rev_it);

		temp + n;
		return (temp);
	}
	template <class T, class U>
	typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs)
	{
		typename ft::reverse_iterator<T>::difference_type	dist;

		// dist = lhs.base().base - rhs.base().base;
		dist = rhs.base().base - lhs.base().base;
		return (dist);
	}
	template <typename Iter>
	reverse_iterator<Iter>		operator+(int n, reverse_iterator<Iter> other)
	{
		reverse_iterator<Iter>	temp(other);

		for (int i = 0; i < n; i++)
			temp++;
		return (temp);
	}
	template <typename Iter>
	reverse_iterator<Iter>		operator-(int n, reverse_iterator<Iter> other)
	{
		reverse_iterator<Iter>	temp(other);

		for (int i = 0; i < n; i++)
			temp--;
		return (temp);
	}
}

#include "ft_reverse_iterator.tpp"

#endif