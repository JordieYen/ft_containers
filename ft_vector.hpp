#ifndef FTVECTOR_HPP
# define FTVECTOR_HPP

# include <iostream>
# include <limits>
// # include <iterator>
# include <memory>
# include "ft_iterator.hpp"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T															value_type;
			typedef Allocator													allocator_type;
			typedef typename std::allocator_traits<Allocator>::pointer			pointer;
			typedef typename std::allocator_traits<Allocator>::const_pointer	const_pointer;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;

			vector(void);
			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class Iterator>
			vector(Iterator first, Iterator last, const allocator_type& alloc = allocator_type());
			vector(int i);
			vector(const vector& clone);
			vector&	operator=(const vector& clone);
			T&	operator[](int i);
			~vector();
			
			Allocator	get_allocator(void);
			void		assign(int i, T value);
			T&			at(int index);
			T&			front(void);
			T&			back(void);
			T			*data(void);
			bool		empty(void);
			int			size(void) const;
			size_t		max_size(void);
			void		reserve(int size);
			int			capacity(void);
			void		shrink_to_fit(void); //c++11
			void		clear(void);
			// void		insert(void); //requires iterator
			// void		erase(void); //requires iterator
			void		push_back(T value);
			void		pop_back(void);
			void		resize(int size);
			void		resize(int size, T value);
			void		swap(vector& other);
			ft::Iterator<T>	begin(void);
			ft::Iterator<T>	end(void);

		private:
			void	update_capacity(void);
			void	reallocate(T *new_vector);

			allocator_type	allocator;
			T				*_vector;
			int				_capacity;
			int				_size;
	};

	template <typename T>
	bool	operator==(vector<T>& current, vector<T>& other);
	template <typename T>
	bool	operator!=(vector<T>& current, vector<T>& other);
	template <typename T>
	bool	operator<(vector<T>& current, vector<T>& other);
	template <typename T>
	bool	operator<=(vector<T>& current, vector<T>& other);
	template <typename T>
	bool	operator>(vector<T>& current, vector<T>& other);
	template <typename T>
	bool	operator>=(vector<T>& current, vector<T>& other);
	template <typename T>
	void	swap(vector<T>& current, vector<T>& other);

}

#endif