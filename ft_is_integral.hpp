#ifndef FTISINTEGRAL_HPP
# define FTISINTEGRAL_HPP

namespace ft
{
	template< class T >
	struct is_integral
	{
		bool	operator()(T t)
		{
			T* p;
			
			this->value = true;

			reinterpret_cast<T>(t);
			f(0);
    		p + t;
		}

		bool	value;
	};
}

#endif