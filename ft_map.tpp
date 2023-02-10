#include "ft_map.hpp"

namespace ft
{
	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>::map(const key_compare& comp, const allocator_type& alloc) //: _bt(lol)
	{
		
	}

	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>::~map()
	{

	}

	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>::map(const map& clone)
	{
		this->_bt = clone._bt;
	}

	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>&	map<Key, T, Compare, Allocator>::operator=(const map& clone)
	{
		this->_bt = clone._bt;
		return (*this);
	}


}