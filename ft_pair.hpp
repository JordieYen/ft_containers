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
		// pair& operator=(const pair& other);

		void swap (pair& pr);

		const first_type	first;
		second_type			second;
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
	ft::pair<T1, T2> make_pair(const T1& t, const T2 u );

	template< class T1, class T2 >
	std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& pr)
	{
		os << "(key [" << pr.first << "] value [" << pr.second << "])";
		return os;
	}
}

#include "ft_pair.tpp"

#endif