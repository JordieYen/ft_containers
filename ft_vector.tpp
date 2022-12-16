#include "ft_vector.hpp"

namespace ft
{
	template <typename T, class Allocator>
	vector<T, Allocator>::vector(void)
	{
		this->_vector = this->allocator.allocate(0);
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
		this->_vector = this->allocator.allocate(this->_capacity);
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::vector(const vector& clone)
	{
		this->_capacity = clone._capacity;
		this->_vector = this->allocator.allocate(clone._capacity);
		for (int i = 0; i < clone._size; i++)
			this->_vector[i] = clone._vector[i];
		this->_size = clone._size;
	}

	template <typename T, class Allocator>
	vector<T, Allocator>&	vector<T, Allocator>::operator=(const vector& clone)
	{
		this->_capacity = clone._capacity;
		this->_vector = this->allocator.allocate(clone._capacity);
		for (int i = 0; i < clone._size; i++)
			this->_vector[i] = clone._vector[i];
		this->_size = clone._size;

		return (*this);
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::~vector()
	{
		this->allocator.deallocate(this->_vector, this->_capacity);
	}

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::operator[](int i)
	{
		if (i < 0 || i > this->_size - 1)
			throw std::out_of_range("out of raaange");
		else
			return (this->_vector[i]);
	}

	template <typename T, class Allocator>
	Allocator	vector<T, Allocator>::get_allocator(void)
	{
		return (this->allocator);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::assign(int i, T value)
	{
		if (i < this->_capacity)
		{
			this->_size = i;
			for (int i = 0; i < this->_size; i++)
				this->_vector[i] = value;
		}
		else
		{
			this->allocator.deallocate(this->_vector, this->_capacity);
			this->_capacity = i;
			this->_size = i;
			this->_vector = this->allocator.allocate(this->_capacity);
			for (int i = 0; i < this->_size; i++)
				this->_vector[i] = value;
		}
	}

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
	int	vector<T, Allocator>::size(void) const
	{
		return (this->_size);
	}
	#include <limits>

	template <typename T, class Allocator>
	size_t	vector<T, Allocator>::max_size(void)
	{
		return (this->allocator.max_size());
	}

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
			new_vector = this->allocator.allocate(this->_capacity);
			for (int i = 0; i < size; i++)
			{
				if (i < this->_size)
					new_vector[i] = this->_vector[i];
				else
					new_vector[i] = value;
				if (i + 1 == size)
					this->allocator.deallocate(this->_vector, i);
			}
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
	Iterator<T>	vector<T, Allocator>::begin(void)
	{
		Iterator<T>	temp;

		temp._pointer = &this->_vector[0];
		return(temp);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::end(void)
	{
		Iterator<T>	temp;

		temp._pointer = &this->_vector[this->_size];
		return(temp);
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
		new_vector = this->allocator.allocate(this->_capacity);
		for (int i = 0; i < this->_size; i++)
		{
			new_vector[i] = this->_vector[i];
			if (i + 1 == this->_size)
				this->allocator.deallocate(this->_vector, i);
		}
		this->_vector = new_vector;
	}

	template <typename T>
	bool	operator==(vector<T>& current, vector<T>& other)
	{
		if (current.size() == other.size())
		{
			for (int i = 0; i < current.size(); i++)
			{
				if (current[i] != other[i])
					return (false);
			}
		}
		else
			return (false);
		return (true);
	}

	template <typename T>
	bool	operator!=(vector<T>& current, vector<T>& other)
	{
		if (current == other)
			return (false);
		return (true);
	}

	template <typename T>
	bool	operator<(vector<T>& current, vector<T>& other)
	{
		int	tempsize;

		if (current == other)
			return (false);
		if (current.size() < other.size())
			tempsize = current.size();
		else
			tempsize = other.size();
		for (int i = 0; i < tempsize; i++)
		{
			if (current[i] != other[i])
			{
				if (current[i] > other[i])
					return (false);
			}
		}
		if (current.size() > other.size())
			return (false);
		return (true);
	}

	template <typename T>
	bool	operator<=(vector<T>& current, vector<T>& other)
	{
		int	tempsize;

		if (current == other)
			return (true);
		if (current.size() < other.size())
			tempsize = current.size();
		else
			tempsize = other.size();
		for (int i = 0; i < tempsize; i++)
		{
			if (current[i] != other[i])
			{
				if (current[i] > other[i])
					return (false);
			}
		}
		if (current.size() > other.size())
			return (false);
		return (true);
	}

	template <typename T>
	bool	operator>(vector<T>& current, vector<T>& other)
	{
		int	tempsize;

		if (current == other)
			return (false);
		if (current.size() < other.size())
			tempsize = current.size();
		else
			tempsize = other.size();
		for (int i = 0; i < tempsize; i++)
		{
			if (current[i] != other[i])
			{
				if (current[i] < other[i])
					return (false);
			}
		}
		if (current.size() < other.size())
			return (false);
		return (true);
	}

	template <typename T>
	bool	operator>=(vector<T>& current, vector<T>& other)
	{
		int	tempsize;

		if (current == other)
			return (true);
		if (current.size() < other.size())
			tempsize = current.size();
		else
			tempsize = other.size();
		for (int i = 0; i < tempsize; i++)
		{
			if (current[i] != other[i])
			{
				if (current[i] < other[i])
					return (false);
			}
		}
		if (current.size() < other.size())
			return (false);
		return (true);
	}

	template <typename T, class Allocator>
	void	swap(const vector<T>& current, const vector<T>& other)
	{
		vector<T> temp_vector;

		temp_vector = other;
		other = current;
		current = temp_vector;
	}
}