#ifndef FTENABLEIF_HPP
# define FTENABLEIF_HPP

namespace ft
{
	// template<bool B, class T = void >
	// struct enable_if<true, T>
	// {
	// 	typedef T type;
	// };

	// template<>
	// struct enable_if<false, T>
	// { };

	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> 
	{ 
		typedef T type;
	};
}

#endif