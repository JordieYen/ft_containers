#ifndef FTVECTOR_HPP
# define FTVECTOR_HPP

# include <iostream>

namespace ft
{
	template <typename T>
	class vector
	{
		public:
			vector(void);
			vector(unsigned int i);
			vector(const vector& clone);
			vector&	operator=(const vector& clone);
			T&	operator[](int i);
			~vector();
			
			int		size(void);
			int		capacity(void);

		private:
			T		*_vector;
			int		_capacity;
			int		_size;
	};
}

#endif