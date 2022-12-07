#include "test.hpp"

namespace ft
{
	template <typename T, class Allocator>
	vector<T, Allocator>::vector(void)
	{
		this->_vector = this->allocator.allocate(5);
		this->_capacity = 1;
		this->_size = 0;
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::~vector(void)
	{
	}
}