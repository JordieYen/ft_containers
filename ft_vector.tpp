#include "ft_vector.hpp"

namespace ft
{
	template <typename T>
	vector<T>::vector(void)
	{
		this->_vector = new T[0];
		this->_capacity = 1;
		this->_size = 0;
	}

	template <typename T>
	vector<T>::vector(int i)
	{
		if (i < 0)
			throw std::length_error("ft_vector");
		this->_capacity = 1;
		this->_size = i;
		while (this->_capacity < this->_size)
			this->_capacity *= 2;
		this->_vector = new T[this->_capacity];
	}

	template <typename T>
	vector<T>::vector(const vector& clone)
	{
		this->_capacity = clone._capacity;
		this->_vector = new T[clone._capacity];
		for (int i = 0; i < clone._size; i++)
			this->_vector[i] = clone._vector[i];
		this->_size = clone._size;
	}

	template <typename T>
	vector<T>&	vector<T>::operator=(const vector& clone)
	{
		this->_capacity = clone._capacity;
		this->_vector = new T[clone._capacity];
		for (int i = 0; i < clone._size; i++)
			this->_vector[i] = clone._vector[i];
		this->_size = clone._size;

		return (*this);
	}

	template <typename T>
	vector<T>::~vector()
	{
		delete[] this->_vector;
	}

	template <typename T>
	T&	vector<T>::operator[](int i)
	{
		if (i < 0 || i > this->_size - 1)
			throw std::out_of_range("out of raaange");
		else
			return (this->_vector[i]);
	}

	// template <typename T>
	// void	vector<T>::append(T input)
	// {
	// 	this->_vector.append(input);
	// 	this->_size++;
	// }

	template <typename T>
	void	vector<T>::push_back(T value)
	{
		this->_size++;
		vector<T>::update_capacity();
		this->_vector[this->_size - 1] = value;
	}

	template <typename T>
	T&	vector<T>::at(int index)
	{
		if (index >= this->_size)
			throw std::out_of_range("my vector");
		return (this->_vector[index]);
	}

	template <typename T>
	T&	vector<T>::front(void)
	{
		return (this->_vector[0]);
	}

	template <typename T>
	T&	vector<T>::back(void)
	{
		return (this->_vector[this->_size - 1]);
	}

	template <typename T>
	T	*vector<T>::data(void)
	{
		return (this->_vector);
	}

	template <typename T>
	bool	vector<T>::empty(void)
	{
		if (this->_size == 0)
			return (true);
		return (false);
	}

	template <typename T>
	int	vector<T>::size(void)
	{
		return (this->_size);
	}

	// template <typename T>
	// int	vector<T>::max_size(void)
	// {
	// 	return (std::numeric_limits<difference_type>::max());
	// }

	template <typename T>
	void	vector<T>::reserve(int size)
	{
		T	*new_vector;

		if (size > this->_capacity)
		{
			this->_capacity = size;
			this->reallocate(new_vector);
		}
	}

	template <typename T>
	int	vector<T>::capacity(void)
	{
		return (this->_capacity);
	}

	template <typename T>
	void	vector<T>::shrink_to_fit(void)
	{
		T	*new_vector;

		if (this->_size != this->_capacity)
		{
			this->_capacity = this->_size;
			this->reallocate(new_vector);
		}
	}

	template <typename T>
	void	vector<T>::update_capacity(void)
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

	template <typename T>
	void	vector<T>::reallocate(T *new_vector)
	{
		new_vector = new T[this->_capacity];
		for (int i = 0; i < this->_size; i++)
			new_vector[i] = this->_vector[i];
		delete[] this->_vector;
		this->_vector = new_vector;
	}
}