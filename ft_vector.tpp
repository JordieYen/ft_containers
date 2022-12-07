#include "ft_vector.hpp"

namespace ft
{
	template <typename T, class Allocator>
	vector<T, Allocator>::vector(void)
	{
		this->_vector = new T[0];
		// this->_vector = this->allocator.allocate(0);
		this->_capacity = 1;
		this->_size = 0;
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::vector(int i)
	{
		if (i < 0)
			throw std::length_error("ft_vector");
		this->_capacity = 1;
		this->_size = i;
		while (this->_capacity < this->_size)
			this->_capacity *= 2;
		// this->_vector = this->allocator.allocate(this->_capacity);
		this->_vector = new T[this->_capacity];
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::vector(const vector& clone)
	{
		this->_capacity = clone._capacity;
		// this->_vector = this->allocator.allocate(clone._capacity);
		this->_vector = new T[clone._capacity];
		for (int i = 0; i < clone._size; i++)
			this->_vector[i] = clone._vector[i];
		this->_size = clone._size;
	}

	template <typename T, class Allocator>
	vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector& clone)
	{
		this->_capacity = clone._capacity;
		this->_vector = new T[clone._capacity];
		for (int i = 0; i < clone._size; i++)
			this->_vector[i] = clone._vector[i];
		this->_size = clone._size;

		return (*this);
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::~vector()
	{
		delete[] this->_vector;
	}

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::operator[](int i)
	{
		if (i < 0 || i > this->_size - 1)
			throw std::out_of_range("out of raaange");
		else
			return (this->_vector[i]);
	}

	// template <typename T, class Allocator>
	// void	vector<T, Allocator>::append(T input)
	// {
	// 	this->_vector.append(input);
	// 	this->_size++;
	// }

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::at(int index)
	{
		if (index >= this->_size)
			throw std::out_of_range("my vector");
		return (this->_vector[index]);
	}

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::front(void)
	{
		return (this->_vector[0]);
	}

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::back(void)
	{
		return (this->_vector[this->_size - 1]);
	}

	template <typename T, class Allocator>
	T	*vector<T, Allocator>::data(void)
	{
		return (this->_vector);
	}

	template <typename T, class Allocator>
	bool	vector<T, Allocator>::empty(void)
	{
		if (this->_size == 0)
			return (true);
		return (false);
	}

	template <typename T, class Allocator>
	int	vector<T, Allocator>::size(void)
	{
		return (this->_size);
	}

	// template <typename T, class Allocator>
	// int	vector<T, Allocator>::max_size(void)
	// {
	// 	return (std::numeric_limits<difference_type>::max());
	// }

	template <typename T, class Allocator>
	void	vector<T, Allocator>::reserve(int size)
	{
		T	*new_vector;

		if (size > this->_capacity)
		{
			this->_capacity = size;
			this->reallocate(new_vector);
		}
	}

	template <typename T, class Allocator>
	int	vector<T, Allocator>::capacity(void)
	{
		return (this->_capacity);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::shrink_to_fit(void)
	{
		T	*new_vector;

		if (this->_size != this->_capacity)
		{
			this->_capacity = this->_size;
			this->reallocate(new_vector);
		}
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::clear(void)
	{
		this->_size = 0;
	}


	template <typename T, class Allocator>
	void	vector<T, Allocator>::push_back(T value)
	{
		this->_size++;
		vector<T, Allocator>::update_capacity();
		this->_vector[this->_size - 1] = value;
	}


	template <typename T, class Allocator>
	void	vector<T, Allocator>::pop_back(void)
	{
		this->_size--;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::resize(int size)
	{
		this->resize(size, 0);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::resize(int size, T value)
	{
		T	*new_vector;

		if (size > this->_size)
		{
			this->_capacity = size;
			new_vector = new T[this->_capacity];
			for (int i = 0; i < size; i++)
			{
				if (i < this->_size)
					new_vector[i] = this->_vector[i];
				else
					new_vector[i] = value;
			}
			delete[] this->_vector;
			this->_vector = new_vector;
			this->_size = size;
		}
		else
			this->_size = size;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::swap(vector& other)
	{
		vector temp_vector;

		temp_vector = other;
		other = this;
		this = temp_vector;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::update_capacity(void)
	{
		T	*new_vector;

		// std::cout << "update capacity called | new size : " << this->_size << std::endl;
		if (this->_capacity < this->_size)
		{
			while (this->_capacity < this->_size)
				this->_capacity *= 2;
			this->reallocate(new_vector);
			// std::cout << "new malloc | new capacity : " << this->_capacity << std::endl;
		}
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::reallocate(T *new_vector)
	{
		new_vector = new T[this->_capacity];
		for (int i = 0; i < this->_size; i++)
			new_vector[i] = this->_vector[i];
		delete[] this->_vector;
		this->_vector = new_vector;
	}
}