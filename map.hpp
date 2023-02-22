#ifndef FTMAP_HPP
# define FTMAP_HPP

# include <iostream>
# include <memory>
# include <string>
# include "ft_pair.hpp"
# include "bst.hpp"
# include "ft_map_iterator.hpp"
# include "ft_reverse_iterator.hpp"
# include "ft_lexicographical_compare.hpp"
# include "ft_enable_if.hpp"
# include "ft_is_integral.hpp"
# include "ft_equal.hpp"

namespace ft
{


	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key 														key_type;
			typedef T															mapped_type;
			typedef ft::pair<const Key, T>										value_type;
			typedef std::size_t													size_type;
			typedef std::ptrdiff_t												difference_type;
			typedef Compare														key_compare;
			typedef Allocator													allocator_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef value_type*													pointer;
			typedef const pointer												const_pointer;
			typedef typename ft::mIterator<value_type>							iterator;
			typedef const iterator    											const_iterator;
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			class value_compare : public std::binary_function<T, T, bool>
			{
				public:
					value_compare(Compare pred) : comp(pred) {}
					bool operator()(value_type& x, value_type& y) const
					{
						return comp(x.first, y.first);
					}

				protected:
					Compare comp;
			};

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			map(typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map& clone); //
			~map();

			map&									operator=(const map& clone);

			iterator								begin(void); //
			const_iterator							begin(void) const; //
			iterator								end(void); //
			const_iterator							end(void) const; //
			reverse_iterator						rbegin(void); //
			const_reverse_iterator					rbegin(void) const; //
			reverse_iterator						rend(void); //
			const_reverse_iterator					rend(void) const; //

			bool									empty(void) const; //
			size_type								size(void) const; //
			size_type								max_size(void) const; //

			mapped_type&							operator[](const key_type& key); //
			mapped_type&							at(const key_type& key); //
			const mapped_type&						at(const key_type& key) const; //

			ft::pair<iterator,bool>					insert(const value_type& val); //
			iterator								insert(iterator position, const value_type& val); //
			void									insert(iterator first, iterator last);

			iterator								erase(iterator position); //
			size_type								erase(const key_type& key); //
			iterator								erase(iterator first, iterator last);

			void									swap( map& other );
			void									clear(void); //

			key_compare								key_comp(void) const;
			value_compare							value_comp(void) const;

			iterator								find(const key_type& key); //
			const_iterator							find(const key_type& key) const; //
			size_t									count(const key_type& key) const; //
			iterator								lower_bound(const key_type& key); //
			const_iterator							lower_bound(const key_type& key) const; //
			iterator								upper_bound(const key_type& key); //
			const_iterator							upper_bound(const key_type& key) const; //
			pair<iterator,iterator>					equal_range(const key_type& key); //
			pair<const_iterator,const_iterator>		equal_range(const key_type& key) const; //

			allocator_type							get_allocator(void) const;

		// private: 
			ft::bst< value_type, value_compare >	_bt;
			key_compare								_comp;
			allocator_type							_alloc;

	};

	template<class Key, class T, class Compare , class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other);
	template<class Key, class T, class Compare , class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other);
	template<class Key, class T, class Compare , class Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other);
	template<class Key, class T, class Compare , class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other);
	template<class Key, class T, class Compare , class Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other);
	template<class Key, class T, class Compare , class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other);
	template<class Key, class T>
	void	swap(const map<Key, T>& current, const map<Key, T>& other);
}


#include "map.tpp"

#endif