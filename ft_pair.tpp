#include "ft_pair.hpp"

namespace ft
{
	template <class T1, class T2>
	pair<T1, T2>::pair(void) : first(T1())
	{
		// this->first = T1();
		this->second = T2();
	}

	template <class T1, class T2>
	pair<T1, T2>::pair(const first_type& a, const second_type& b) : first(a)
	{
		// this->first = a;
		this->second = b;
	}

	template <class T1, class T2>
	template<class U, class V>
	pair<T1, T2>::pair(const pair<U, V>& clone) : first(clone.first)
	{
		// this->first = clone.first;
		this->second = clone.second;
	}

	// template <class T1, class T2>
	// pair<T1, T2>&	pair<T1, T2>::operator=(const pair& other)
	// {
	// 	pair<>
	// 	// this->first = other.first;
	// 	this->second = other.second;

	// 	return (*this);
	// }

	template <class T1, class T2>
	void	pair<T1, T2>::swap(pair& other)
	{
		first_type	this_a;
		second_type	this_b;

		this_a = this->a;
		this_b = this->b;
		this->first = other.a;
		this->second = other.b;
		other.a = this_a;
		other.b = this_b;
	}

	template <class T1, class T2>
	bool	operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first==rhs.first && lhs.second==rhs.second);
	}

	template <class T1, class T2>
	bool	operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs==rhs));
	}

	template <class T1, class T2>
	bool	operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second));
	}

	template <class T1, class T2>
	bool	operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(rhs<lhs));
	}

	template <class T1, class T2>
	bool	operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs<lhs);
	}

	template <class T1, class T2>
	bool	operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs<rhs));
	}

	template <class T1, class T2>
	void	swap(pair<T1,T2>& x, pair<T1,T2>& y)
	{
		x.swap(y);
	}

	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair(const T1& t, const T2 u )
	{
		ft::pair<T1, T2>	ret(t, u);

		return (ret);
	}

	// template <size_t I, class T1, class T2> 
	// typename std::tuple_element< I, pair<T1,T2> >::type&	get(pair<T1,T2>&  pr)
	// {
	// 	if (I == 0)
	// 		return (pr.first);
	// 	else if (I == 1)
	// 		return (pr.second);
	// }

	// template <size_t I, class T1, class T2>
	// const typename std::tuple_element< I, pair<T1,T2> >::type&	get (const pair<T1,T2>& pr)
	// {
	// 	if (I == 0)
	// 		return (pr.first);
	// 	else if (I == 1)
	// 		return (pr.second);
	// }
}