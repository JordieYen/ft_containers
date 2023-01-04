#include "ft_vector.hpp"

namespace ft
{
	template <typename T, class Allocator>
	vector<T, Allocator>::vector(const allocator_type& alloc)
	{
		this->_vector = this->allocator.allocate(0);
		this->_capacity = 0;
		this->_size = 0;
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::vector(size_t n, const value_type& val, const allocator_type& alloc)
	{
		this->_vector = this->allocator.allocate(n);
		this->_capacity = n;
		this->_size = n;
		for (int i = 0; i < this->_size; i++)
			this->allocator.construct(&this->_vector[i], val);
			
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::vector(Iterator<T> first, Iterator<T> last, const allocator_type& alloc)
	{
		int	counter = 0;
		for (Iterator<T> i = first; i != last; i++)
			counter++;
		this->_vector = this->allocator.allocate(counter);
		this->_capacity = counter;
		this->_size = counter;
		for (int i = 0; i < this->_size; i++)
		{
			this->allocator.construct(&this->_vector[i], *first);
			first++;
		}
	}

	template <typename T, class Allocator>
	vector<T, Allocator>::vector(const vector& clone)
	{
		this->allocator = clone.allocator;
		this->_capacity = clone._capacity;
		this->_vector = this->allocator.allocate(clone._capacity);
		for (int i = 0; i < clone._size; i++)
			this->allocator.construct(&this->_vector[i], clone._vector[i]);
		this->_size = clone._size;
	}


	template <typename T, class Allocator>
	vector<T, Allocator>::~vector(void)
	{
		for (int i = 0; i < this->_size; i++)
			this->allocator.destroy(&this->_vector[i]);
		this->allocator.deallocate(this->_vector, this->_capacity);
	}

	template <typename T, class Allocator>
	Allocator	vector<T, Allocator>::get_allocator(void)
	{
		return (this->allocator);
	}

	template <typename T, class Allocator>
	size_t	vector<T, Allocator>::size(void) const
	{
		return (this->_size);
	}

	template <typename T, class Allocator>
	int	vector<T, Allocator>::capacity(void)
	{
		return (this->_capacity);
	}

	template <typename T, class Allocator>
	T	*vector<T, Allocator>::data(void)
	{
		return (this->_vector);
	}

	template <typename T, class Allocator>
	size_t	vector<T, Allocator>::max_size(void)
	{
		return (this->allocator.max_size());
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
	bool	vector<T, Allocator>::empty(void)
	{
		if (this->_size == 0)
			return (true);
		return (false);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::swap(vector& other)
	{
		vector<T, Allocator> temp_vector(other);

		other = *this;
		*this = temp_vector;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::clear(void)
	{
		for (int i = 0; i < this->_size; i++)
			this->allocator.destroy(&this->_vector[i]);
		this->_size = 0;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::assign(size_t i, T value)
	{
		if (i < this->_capacity)
		{
			for (int n = 0; n < i; i++)
			{
				if (n < this->_size)
					this->_vector[n] = value;
				else
					this->allocator.construct(&this->_vector[n], value);
			}
			this->_size = i;
		}
		else
		{
			for (int i = 0; i < this->_size; i++)
				this->allocator.destroy(&this->_vector[i]);
			this->allocator.deallocate(this->_vector, this->_capacity);
			this->_capacity = i;
			this->_size = i;
			this->_vector = this->allocator.allocate(this->_capacity);
			for (int i = 0; i < this->_size; i++)
				this->allocator.construct(&this->_vector[i], value);
		}
	}

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::at(size_t index)
	{
		if (index >= this->_size)
			throw std::out_of_range("my vector");
		return (this->_vector[index]);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::reserve(size_t size)
	{
		T	*new_vector;

		if (size > this->_capacity)
		{
			new_vector = this->allocator.allocate(size);
			for (int i = 0; i < this->_size; i++)
				this->allocator.construct(&new_vector[i], this->_vector[i]);
			this->destroy_vector();
			this->_vector = new_vector;
			this->_capacity = size;
		}
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::push_back(T value)
	{
		T	*new_vector;

		if (this->_capacity == 0)
		{
			this->_capacity = 1;
			this->allocator.deallocate(this->_vector, this->_capacity);
			this->_vector = this->allocator.allocate(1);
			this->allocator.construct(&this->_vector[this->_size], value);
		}
		else if (this->_size + 1 > this->_capacity)
		{
			new_vector = this->create_vector(this->_capacity * 2);
			this->allocator.construct(&new_vector[this->_size], value);
			this->destroy_vector();
			this->_vector = new_vector;
			this->_capacity = this->_capacity * 2;
		}
		else
			this->allocator.construct(&this->_vector[this->_size], value);
		this->_size++;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::pop_back(void)
	{
		this->allocator.destroy(&this->_vector[this->_size - 1]);
		this->_size--;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::resize(size_t size)
	{
		this->resize(size, 0);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::resize(size_t size, T value)
	{
		T	*new_vector;

		if (size > this->_size)
		{
			new_vector = this->create_vector(size);
			for (int i = this->_size; i < size; i++)
				this->allocator.construct(&new_vector[i], value);
			this->destroy_vector();
			this->_vector = new_vector;
			this->_capacity = size;
			this->_size = size;
		}
		else
		{
			for (int i = size; i < this->_size; i++)
				this->allocator.destroy(&this->_vector[i]);
			this->_size = size;
		}
	}

	template <typename T, class Allocator>
	vector<T>& vector<T, Allocator>::operator=(const vector& clone)
	{
		this->~vector();
		this->allocator = clone.allocator;
		this->_capacity = clone._capacity;
		this->_vector = this->allocator.allocate(clone._capacity);
		for (int i = 0; i < clone._size; i++)
			this->allocator.construct(&this->_vector[i], clone._vector[i]);
		this->_size = clone._size;

		return (*this);
	}

	template <typename T, class Allocator>
	T&	vector<T, Allocator>::operator[](size_t i)
	{
		return (this->_vector[i]);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::insert(Iterator<T> pos, const value_type& val)
	{
		int	i = 0;
		int	ret = 0;

		if (this->validate_iterator(pos) == false)
			return (0);
		for (Iterator<T> it = this->begin(); it != this->end(); it++)
		{
			if (it == pos)
			{
				ret = i;
				i++;
			}
			i++;
		}
		this->insert(pos, 1, val);
		return (this->begin() + ret);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::insert(Iterator<T> pos, size_t n, const value_type& val)
	{
		T				*new_vector;
		difference_type	dif = pos.base - this->begin().base;
		int				min = 0;
		int				temp_capacity = this->_capacity;

		if (this->validate_iterator(pos) == false)
			return ;
		if (this->_size + n > this->_capacity)
		{
			while (this->_size + n > temp_capacity)
				temp_capacity *= 2;
			new_vector = this->allocator.allocate(temp_capacity);
			for (Iterator<T> it = this->begin(); it != this->end(); it++)
			{
				if (it == pos)
				{
					for (int j = 0; j < n; j++)
					{
						this->allocator.construct(&new_vector[min], val);
						min++;
					}
				}
				this->allocator.construct(&new_vector[min], *it);
				min++;
			}
			this->destroy_vector();
			this->_capacity = temp_capacity;
			this->_vector = new_vector;
		}
		else
		{
			min = dif - n - 1;
			for (int j = this->size() - 1; j > min; j--)
			{
				if (j + n > this->size() - 1)
					this->allocator.construct(&this->_vector[j + n], this->_vector[j]);
				else if (j + n >= dif + n)
					this->_vector[j + n] = this->_vector[j];
				else
					this->_vector[j + n] = val;
			}
		}
		this->_size += n;
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::insert(Iterator<T> pos, Iterator<T> first, Iterator<T> last)
	{
		T				*new_vector;
		int				min = 0;
		int				temp_capacity = this->_capacity;
		difference_type	dif = pos.base - this->begin().base;
		difference_type	n = last.base - first.base;

		if (this->_size + n > this->_capacity)
		{
			while (this->_size + n > temp_capacity)
				temp_capacity *= 2;
			new_vector = this->allocator.allocate(temp_capacity);
			for (Iterator<T> it = this->begin(); it != this->end(); it++)
			{
				if (it == pos)
				{
					for (Iterator<T> sec_it = first; sec_it != last; sec_it++)
					{
						this->allocator.construct(&new_vector[min], *sec_it);
						min++;
					}
				}
				this->allocator.construct(&new_vector[min], *it);
				min++;
			}
			this->destroy_vector();
			this->_capacity = temp_capacity;
			this->_vector = new_vector;
		}
		else
		{
			min = dif - n - 1;
			for (int j = this->size() - 1; j > min; j--)
			{
				if (j + n > this->size() - 1)
					this->allocator.construct(&this->_vector[j + n], this->_vector[j]);
				else if (j + n >= dif + n)
					this->_vector[j + n] = this->_vector[j];
				else
				{
					this->_vector[j + n] = *first;
					first++;
				}
			}
		}
		this->_size += n;
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::erase(Iterator<T> pos)
	{
		difference_type	dif = pos.base - this->begin().base;
		int				ret = dif;

		if (this->validate_iterator(pos) == false)
			return (0);
		for (int i = 0; i < this->size(); i++)
		{
			if (dif == i)
			{
				this->allocator.destroy(&this->_vector[i]);
				if (i + 1 != this->size())
					this->allocator.construct(&this->_vector[i], this->_vector[i + 1]);
				dif++;
			}
		}
		this->_size--;
		return (this->begin() + ret);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::erase(Iterator<T> first, Iterator<T> last)
	{
		difference_type	first_dif = first.base - this->begin().base;
		difference_type	last_dif = last.base - this->begin().base;
		difference_type	dif = last_dif - first_dif;
		int				ret = first_dif;

		if (this->validate_iterator(first) == false || this->validate_iterator(last) == false || dif < 0)
			return (0);
		if (first == last)
			return (last);
		for (int i = 0; i < this->size(); i++)
		{
			if (first_dif == i)
			{
				this->allocator.destroy(&this->_vector[i]);
				if (i + dif != this->size())
					this->allocator.construct(&this->_vector[i], this->_vector[i + dif]);
				first_dif++;
			}
		}
		this->_size -= dif;
		return (this->begin() + ret);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::begin(void)
	{
		Iterator<T>	temp;

		temp.base = &this->_vector[0];
		return(temp);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::end(void)
	{
		Iterator<T>	temp;

		temp.base = &this->_vector[this->_size];
		return(temp);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::begin(void) const
	{
		Iterator<T>	temp;

		temp.base = &this->_vector[0];
		return(temp);
	}

	template <typename T, class Allocator>
	Iterator<T>	vector<T, Allocator>::end(void) const
	{
		Iterator<T>	temp;

		temp.base = &this->_vector[this->_size];
		return(temp);
	}

	template <typename T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rbegin(void)
	{
		typename vector<T, Allocator>::reverse_iterator	temp(this->end() - 1);

		return(temp);
	}

	template <typename T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rend(void)
	{
		typename vector<T, Allocator>::reverse_iterator	temp(this->begin() - 1);

		return(temp);
	}

	template <typename T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rbegin(void) const
	{
		typename vector<T, Allocator>::reverse_iterator	temp(this->end() - 1);

		return(temp);
	}

	template <typename T, class Allocator>
	typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rend(void) const
	{
		typename vector<T, Allocator>::reverse_iterator	temp(this->begin() - 1);

		return(temp);
	}

	template <typename T, class Allocator>
	size_t	vector<T, Allocator>::count_iterator(Iterator<T> first, Iterator<T> last)
	{
		size_t	i;

		i = 0;
		for (Iterator<T> it = first; it != last; it++)
			i++;
		return (i);
	}

	template <typename T, class Allocator>
	bool	vector<T, Allocator>::validate_iterator(Iterator<T> pos)
	{
		for (Iterator<T> it = this->begin(); it != this->end(); it++)
		{
			if (it == pos)
				return (true);
		}
		return (false);
	}

	template <typename T, class Allocator>
	void	vector<T, Allocator>::destroy_vector(void)
	{
		for (int i = 0; i < this->_size; i++)
			this->allocator.destroy(&this->_vector[i]);
		this->allocator.deallocate(this->_vector, this->_capacity);
	}

	template <typename T, class Allocator>
	T*	vector<T, Allocator>::create_vector(size_t new_capacity)
	{
		T	*new_vector;

		new_vector = this->allocator.allocate(new_capacity);
		for (int i = 0; i < this->_size; i++)
			this->allocator.construct(&new_vector[i], this->_vector[i]);
		return(new_vector);
	}

	template <typename T, class Allocator>
	bool	operator==(const vector<T, Allocator>& current, const vector<T, Allocator>& other)
	{
		bool	ret;

		ret = ft::equal(current.begin(), current.end(), other.begin());
		return (ret);
	}

	template <typename T, class Allocator>
	bool	operator!=(const vector<T, Allocator>& current, const vector<T, Allocator>& other)
	{
		bool	ret;

		ret = ft::equal(current.begin(), current.end(), other.begin());
		return (!(ret));
	}

	template <typename T, class Allocator>
	bool	operator<(const vector<T, Allocator>& current, const vector<T, Allocator>& other)
	{
		bool	ret;

		ret = ft::lexicographical_compare(current.begin(), current.end(), other.begin(), other.end());
		return (ret);
	}

	template <typename T, class Allocator>
	bool	operator<=(const vector<T, Allocator>& current, const vector<T, Allocator>& other)
	{
		bool	ret;

		ret = ft::lexicographical_compare(other.begin(), other.end(), current.begin(), current.end());
		return (!(ret));
	}

	template <typename T, class Allocator>
	bool	operator>(const vector<T, Allocator>& current, const vector<T, Allocator>& other)
	{
		bool	ret;

		ret = ft::lexicographical_compare(other.begin(), other.end(), current.begin(), current.end());
		return (ret);
	}

	template <typename T, class Allocator>
	bool	operator>=(const vector<T, Allocator>& current, const vector<T, Allocator>& other)
	{
		bool	ret;

		ret = ft::lexicographical_compare(current.begin(), current.end(), other.begin(), other.end());
		return (!(ret));
	}

	template <typename T>
	void	swap(vector<T>& current, vector<T>& other)
	{
		current.swap(other);
	}
}