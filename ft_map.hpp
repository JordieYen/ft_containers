#ifndef FTMAP_HPP
# define FTMAP_HPP

#include <iostream>
#include "ft_pair.hpp"

namespace ft
{
	template <class T>
	struct	node
	{
		node();
		~node();
		
		T		key;
		node*	left_child;
		node*	right_child;
		node*	parent;
	};

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
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
			typedef typename std::allocator_traits<Allocator>::pointer			pointer;
			typedef typename std::allocator_traits<Allocator>::const_pointer	const_pointer;

			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map& clone);
			~map();

			map&									operator=(const map& clone);

			iterator								begin(void);
			const_iterator							begin(void) const;
			iterator								end(void);
			const_iterator							end(void) const;
			reverse_iterator						rbegin(void);
			const_reverse_iterator					rbegin(void) const;
			reverse_iterator						rend(void);
			const_reverse_iterator					rend(void) const;

			bool									empty(void) const;
			size_type								size(void) const;
			size_type								max_size(void) const;

			mapped_type&							operator[](const key_type& key);
			mapped_type&							at(const key_type& key);
			const mapped_type&						at(const key_type& key) const;

			pair<iterator,bool>						insert(const value_type& val);
			iterator								insert(iterator position, const value_type& val);
			template <class InputIterator>
			void									insert(InputIterator first, InputIterator last);

			void									erase(iterator position);
			size_type								erase(const key_type& key);
			void									erase(iterator first, iterator last);

			void									swap( map& other );
			void									clear(void);

			key_compare								key_comp(void) const;
			value_compare							value_comp(void) const;

			iterator								find(const key_type& key);
			const_iterator							find(const key_type& key) const;
			size_type								count(const key_type& key) const;
			iterator								lower_bound(const key_type& key);
			const_iterator							lower_bound(const key_type& key) const;
			iterator								upper_bound(const key_type& key);
			const_iterator							upper_bound(const key_type& key) const;
			pair<iterator,iterator>					equal_range(const key_type& key);
			pair<const_iterator,const_iterator>		equal_range(const key_type& key) const;

			allocator_type							get_allocator(void) const;

		private:
			node<value_type>	_root;
			node<value_type>	_nil;

	};
}


#include "ft_map.tpp"

#endif