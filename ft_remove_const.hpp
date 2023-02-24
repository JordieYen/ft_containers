#ifndef FTREMOVECONST_HPP
# define FTREMOVECONST_HPP

namespace ft
{
	template< class T > struct remove_const                { typedef T type; };
	template< class T > struct remove_const<const T>       { typedef T type; };
}

#endif