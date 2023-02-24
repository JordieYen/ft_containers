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
			reverse_iterator (const reverse_iterator<Iter>& other);
			~reverse_iterator(void);

			template< class U > reverse_iterator&	operator=( const reverse_iterator<U>& other );
			reference 								operator*(void) const;
			pointer									operator->(void) const;
			reference								operator[] (difference_type n) const;
			reverse_iterator						operator+ (difference_type n) const;
			reverse_iterator						operator++(void);
			reverse_iterator						operator++(int);
			reverse_iterator&						operator+= (difference_type n);
			reverse_iterator						operator- (difference_type n) const;
			reverse_iterator						operator--(void);
			reverse_iterator						operator--(int);
			reverse_iterator&						operator-= (difference_type n);
			iterator_type							base(void) const;

		private:
			iterator_type	_base;
	};

	template <class Iter>
	bool		operator<(reverse_iterator<Iter> current, reverse_iterator<Iter> other)
	{
		return (current.base() > other.base());
	}
	template <class Iter>
	bool		operator>(reverse_iterator<Iter> current, reverse_iterator<Iter> other)
	{
		return (current.base() < other.base());
	}
	template <class Iter>
	bool		operator<=(reverse_iterator<Iter> current, reverse_iterator<Iter> other)
	{
		return (current.base() >= other.base());
	}
	template <class Iter>
	bool		operator>=(reverse_iterator<Iter> current, reverse_iterator<Iter> other)
	{
		return (current.base() <= other.base());
	}
	template <class Iter>
	bool		operator==(reverse_iterator<Iter> current, reverse_iterator<Iter> other)
	{
		return (current.base() == other.base());
	}
	template <class Iter>
	bool		operator!=(reverse_iterator<Iter> current, reverse_iterator<Iter> other)
	{
		return (current.base() != other.base());
	}
	template <class Iter>
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it)
	{
		reverse_iterator<Iter> temp(*rev_it);

		temp + n;
		return (temp);
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		typename ft::reverse_iterator<Iterator>::difference_type	dist;

		dist = lhs.base().base - rhs.base().base;
		return (dist);
	}
}

#include "ft_reverse_iterator.tpp"

#endif