#ifndef FTNAMESPACE_HPP
# define FTNAMESPACE_HPP

namespace ft
{
	template <typename T>
	class vector
	{
		public:
			Array(void);
			Array(unsigned int i);
			Array(const Array& clone);
			Array&	operator=(const Array& clone);
			T&	operator[](int i);
			~Array();
			
			int		size(void);

		private:
			T		*_vector;
			int		_size;
	};
}

#endif