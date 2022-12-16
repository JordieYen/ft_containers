#ifndef NEWVECTOR_HPP
# define NEWVECTOR_HPP

# include <iostream>
# include <limits>
# include <memory>
# include "ft_iterator.tpp"

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

			explicit vector(const allocator_type& alloc = allocator_type());
			explicit vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			vector(Iterator<T> first, Iterator<T> last, const allocator_type& alloc = allocator_type());
			vector(const vector& clone);
			~vector(void);

			Allocator	get_allocator(void);
			size_t		size(void);
			int			capacity(void);
			T			*data(void);

			size_t		max_size(void);
			T&			front(void);
			T&			back(void);
			bool		empty(void);
			void		swap(vector& other);

			void		clear(void);
			void		assign(size_t i, T value);
			T&			at(size_t index);
			void		reserve(size_t size);
			void		push_back(T value);
			void		pop_back(void);
			void		resize(size_t size);
			void		resize(size_t size, T value);

			vector<T>&	operator=(const vector& clone);
			T&			operator[](size_t i);

			Iterator<T>	insert(Iterator<T> pos, const value_type& val);
			void		insert(Iterator<T> pos, size_t n, const value_type& val);
			void		insert(Iterator<T> pos, Iterator<T> first, Iterator<T> last);
			Iterator<T>	erase(Iterator<T> pos);
			Iterator<T>	erase(Iterator<T> first, Iterator<T> last);
			Iterator<T>	begin(void);
			Iterator<T>	end(void);

		private:
			void	destroy_vector(void);
			bool	validate_iterator(Iterator<T> pos);
			T*		create_vector(size_t new_capacity);

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