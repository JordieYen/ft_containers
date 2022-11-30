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
	vector<T>::vector(int i)
	{
		if (i < 0)
			throw std::length_error("ft_vector");
		if (i > 0)
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
	int	vector<T>::size(void)
	{
		return (this->_size);
	}

	template <typename T>
	int	vector<T>::capacity(void)
	{
		return (this->_capacity);
	}

	template <typename T>
	void	vector<T>::update_capacity(void)
	{
		T	*new_vector;

		while (this->_capacity < this->_size)
			this->_capacity *= 2;
		new_vector = new T[this->_capacity];
		for (int i = 0; i < this->_size; i++)
			new_vector[i] = this->_vector[i];
		delete[] this->_vector;
		this->_vector = new_vector;
		std::cout << "lol" << std::endl;
	}
}