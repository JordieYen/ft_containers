#ifndef FTPAIR_HPP
# define FTPAIR_HPP

#include <iostream>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		pair(void);
		pair(const first_type& a, const second_type& b);
		template<class U, class V>	pair(const pair<U, V>& clone);
		pair& operator=(const pair& other);

		void swap (pair& pr);

		first_type	first;
		second_type	second;
	};

	template <class T1, class T2>
	bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	template <class T1, class T2>
	bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	template <class T1, class T2>
	bool	operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	template <class T1, class T2>
	bool	operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
	template <class T1, class T2>
	void	swap (pair<T1,T2>& x, pair<T1,T2>& y);
	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u );
	// template <size_t I, class T1, class T2> 
	// typename std::tuple_element< I, pair<T1,T2> >::type&	get(pair<T1,T2>&  pr);
	// template <size_t I, class T1, class T2>
	// const typename std::tuple_element< I, pair<T1,T2> >::type&	get (const pair<T1,T2>& pr);
}

#include "ft_pair.tpp"

#endif