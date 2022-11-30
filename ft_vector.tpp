#include "ft_vector.hpp"

namespace ft
{
	template <typename T>
	vector<T>::vector(void)
	{
		this->_vector = new T[0];
		this->_capacity = 0;
		this->_size = 0;
	}

	template <typename T>
	vector<T>::vector(unsigned int i)
	{
		if (i > 0)
			this->_capacity = 1;
		while (this->_capacity < i)
			this->_capacity *= 2;
		this->_vector = new T[this->_capacity];
		this->_size = i;
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
	int	vector<T>::size(void)
	{
		return (this->_size);
	}

	template <typename T>
	int	vector<T>::capacity(void)
	{
		return (this->_capacity);
	}

}