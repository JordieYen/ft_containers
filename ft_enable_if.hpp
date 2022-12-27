#ifndef FTENABLEIF_HPP
# define FTENABLEIF_HPP

namespace ft
{
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif