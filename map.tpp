#include "map.hpp"

namespace ft
{
	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>::map(const key_compare& comp, const allocator_type& alloc) : _bt(comp, alloc), _comp(comp), _alloc(alloc)
	{
	}

	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>::~map()
	{
	}

	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>::map(const map<Key, T, Compare, Allocator>& clone) : _bt(clone._comp, clone._alloc)
	{
		this->_comp = clone._comp;
		this->_alloc = clone._alloc;
		this->_bt = clone._bt;
	}

	template<class Key, class T, class Compare , class Allocator>
	template <class InputIterator>
	map<Key, T, Compare, Allocator>::map(typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type first,
		InputIterator last, const key_compare& comp, const allocator_type& alloc) : _bt(comp, alloc), _comp(comp), _alloc(alloc)
	{
		for (; first != last; ++first)
			this->insert(*(first));
	}

	template<class Key, class T, class Compare , class Allocator>
	map<Key, T, Compare, Allocator>&	map<Key, T, Compare, Allocator>::operator=(const map& clone)
	{
		this->_bt = clone._bt;
		return (*this);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator		map<Key, T, Compare, Allocator>::begin(void)
	{
		ft::mIterator<ft::pair<const Key, T> >	it(this->_bt._nil->left_child);

		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator			map<Key, T, Compare, Allocator>::begin(void) const
	{
		ft::mIterator<const ft::pair<const Key, T> >	it(this->_bt._nil->left_child);

		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator			map<Key, T, Compare, Allocator>::end(void)
	{
		ft::mIterator<ft::pair<const Key, T> >	it(this->_bt._nil);
		
		return (it);
	}
	
	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator			map<Key, T, Compare, Allocator>::end(void) const
	{
		ft::mIterator<const ft::pair<const Key, T> >	it(this->_bt._nil);
		
		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator	map<Key, T, Compare, Allocator>::rbegin(void)
	{
		typename map<Key, T, Compare, Allocator>::reverse_iterator	it(this->_bt._nil);

		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::reverse_iterator	map<Key, T, Compare, Allocator>::rend(void)
	{
		typename map<Key, T, Compare, Allocator>::reverse_iterator	it(this->_bt._nil->left_child);
		
		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator	map<Key, T, Compare, Allocator>::rbegin(void) const
	{
		typename map<Key, T, Compare, Allocator>::const_reverse_iterator	it(this->_bt._nil);

		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_reverse_iterator	map<Key, T, Compare, Allocator>::rend(void) const
	{
		typename map<Key, T, Compare, Allocator>::const_reverse_iterator	it(this->_bt._nil->left_child);
		
		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	map<Key, T, Compare, Allocator>::empty(void) const
	{
		return (this->_bt.empty());
	}

	template<class Key, class T, class Compare , class Allocator>
	size_t	map<Key, T, Compare, Allocator>::size(void) const
	{
		return (this->_bt.size());
	}

	template<class Key, class T, class Compare , class Allocator>
	size_t	map<Key, T, Compare, Allocator>::max_size(void) const
	{
		return (this->_bt.max_size());
	}

	template<class Key, class T, class Compare , class Allocator>
	T&	map<Key, T, Compare, Allocator>::operator[](const key_type& key)
	{
		node<map<Key, T, Compare, Allocator>::value_type>	*temp;

		temp = this->_bt.searchnode(ft::make_pair(key, T()));
		if (!temp)
			return (this->insert(ft::make_pair(key, T())).first.base->second);
		return (temp->key->second);
	}

	template<class Key, class T, class Compare , class Allocator>
	T&	map<Key, T, Compare, Allocator>::at(const key_type& key)
	{
		node<map<Key, T, Compare, Allocator>::value_type>	*temp;

		temp = this->_bt.searchnode(ft::make_pair(key, T()));
		if (!temp)
			throw std::out_of_range("out of raaange");
		return (temp->key->second);
	}

	template<class Key, class T, class Compare , class Allocator>
	const T&	map<Key, T, Compare, Allocator>::at(const key_type& key) const
	{
		node<map<Key, T, Compare, Allocator>::value_type>	*temp;

		temp = this->_bt.searchnode(ft::make_pair(key, T()));
		if (!temp)
			throw std::out_of_range("out of raaange");
		return (temp->key->second);
	}

	template<class Key, class T, class Compare , class Allocator>
	ft::pair<typename map<Key, T, Compare, Allocator>::iterator, bool>	map<Key, T, Compare, Allocator>::insert(const value_type& val)
	{
		ft::node<typename map<Key, T, Compare, Allocator>::value_type>	*temp;
		typename map<Key, T, Compare, Allocator>::iterator				it;
		bool															is_dup;
		
		temp = this->_bt.searchnode(val);
		if (temp)
		{
			it._node = temp;
			is_dup = false;
		}
		else
		{
			this->_bt.insertnode(val);
			it._node = this->_bt.searchnode(val);
			is_dup = true;
		}
		it.base = it._node->key;
		return (ft::make_pair(it, is_dup));
	}

	template<class Key, class T, class Compare , class Allocator>
	template<class InputIterator>
	void	map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
	{
		for (;first != last; first++)
			this->insert(*(first));
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::insert(iterator position, const value_type& val)
	{
		(void)position;

		this->insert(val);
		return (this->_bt.searchnode(val));
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::erase(iterator position)
	{
		typename map<Key, T, Compare, Allocator>::iterator		ret;
		ft::node<map<Key, T, Compare, Allocator>::value_type>	*temp;

		temp = this->_bt.searchnode(*position);
		if (!temp)
			ret = this->end();
		else
		{
			ret = position + 1;
			this->_bt.deletenode(*position);
		}
		return (ret);
	}

	template<class Key, class T, class Compare , class Allocator>
	size_t	map<Key, T, Compare, Allocator>::erase(const key_type& key)
	{
		ft::node<map<Key, T, Compare, Allocator>::value_type>	*temp;

		temp = this->_bt.searchnode(ft::make_pair(key, T()));
		if (!temp)
			return (0);
		else
		{
			this->_bt.deletenode(ft::make_pair(key, T()));
			return (1);
		}
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
	{
		for (;first != last;)
			this->erase(first++);
		return (first);
	}

	template<class Key, class T, class Compare , class Allocator>
	void	map<Key, T, Compare, Allocator>::swap( map& other )
	{
		std::swap(this->_bt._root, other._bt._root);
		std::swap(this->_bt._nil, other._bt._nil);
		std::swap(this->_bt._size, other._bt._size);
		std::swap(this->_bt.n_alloc, other._bt.n_alloc);
		std::swap(this->_bt.t_alloc, other._bt.t_alloc);
		std::swap(this->_bt.comp, other._bt.comp);
	}

	template<class Key, class T, class Compare , class Allocator>
	void	map<Key, T, Compare, Allocator>::clear(void)
	{
		for (map<Key, T, Compare, Allocator>::iterator it = this->begin(); it != this->end(); ++it)
			this->_bt.deletenode(*(it));
	}

	template<class Key, class T, class Compare , class Allocator>
	size_t	map<Key, T, Compare, Allocator>::count(const key_type& key) const
	{
		node<map<Key, T, Compare, Allocator>::value_type>	*temp;

		temp = this->_bt.searchnode(ft::make_pair(key, T()));
		if (!temp)
			return (0);
		return (1);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::find(const key_type& key)
	{
		typename map<Key, T, Compare, Allocator>::iterator	it;

		it._node = this->_bt.searchnode(ft::make_pair(key, T()));
		if (it._node == NULL)
			return (this->end());
		it.base = it._node->key;
		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::find(const key_type& key) const
	{
		typename map<Key, T, Compare, Allocator>::const_iterator	it;

		it._node = this->_bt.searchnode(ft::make_pair(key, T()));
		if (it._node == NULL)
			return (this->end());
		it.base = it._node->key;
		return (it);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::lower_bound(const key_type& key)
	{
		for (typename map<Key, T, Compare, Allocator>::iterator	it = this->begin(); it != this->end(); it++)
		{
			if (!(it->first < key))
				return (it);
		}
		return (this->end());
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::lower_bound(const key_type& key) const
	{
		for (typename map<Key, T, Compare, Allocator>::const_iterator	it = this->begin(); it != this->end(); it++)
		{
			if (!(it->first < key))
				return (it);
		}
		return (this->end());
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::iterator	map<Key, T, Compare, Allocator>::upper_bound(const key_type& key)
	{
		for (typename map<Key, T, Compare, Allocator>::iterator	it = this->begin(); it != this->end(); it++)
		{
			if (!(it->first<= key))
				return (it);
		}
		return (this->end());
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::const_iterator	map<Key, T, Compare, Allocator>::upper_bound(const key_type& key) const
	{
		for (typename map<Key, T, Compare, Allocator>::const_iterator	it = this->begin(); it != this->end(); it++)
		{
			if (!(it->first <= key))
				return (it);
		}
		return (this->end());
	}

	template<class Key, class T, class Compare , class Allocator>
	ft::pair<typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator>	map<Key, T, Compare, Allocator>::equal_range(const key_type& key)
	{
		ft::pair<typename map<Key, T, Compare, Allocator>::iterator, typename map<Key, T, Compare, Allocator>::iterator>	ret(this->lower_bound(key), this->upper_bound(key));
		
		return (ret);
	}

	template<class Key, class T, class Compare , class Allocator>
	ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator>	map<Key, T, Compare, Allocator>::equal_range(const key_type& key) const
	{
		ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator, typename map<Key, T, Compare, Allocator>::const_iterator>	ret(this->lower_bound(key), this->upper_bound(key));
		
		return (ret);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::allocator_type	map<Key, T, Compare, Allocator>::get_allocator(void) const
	{
		return (this->_alloc);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::key_compare	map<Key, T, Compare, Allocator>::key_comp(void) const
	{
		return (this->_comp);
	}

	template<class Key, class T, class Compare , class Allocator>
	typename map<Key, T, Compare, Allocator>::value_compare	map<Key, T, Compare, Allocator>::value_comp(void) const
	{
		return (this->_bt.comp);
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other)
	{
		bool	ret;

		ret = ft::equal(current.begin(), current.end(), other.begin(), other.end());
		return (ret);
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other)
	{
		bool	ret;

		ret = ft::equal(current.begin(), current.end(), other.begin(), other.end());
		return (!(ret));
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other)
	{
		bool	ret;

		if (current == other)
			return false;
		ret = ft::lexicographical_compare(current.begin(), current.end(), other.begin(), other.end(), current._bt.comp);
		return (ret);
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other)
	{
		bool	ret;

		if (current == other)
			return true;
		ret = ft::lexicographical_compare(other.begin(), other.end(), current.begin(), current.end(), current._bt.comp);
		return (!(ret));
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other)
	{
		bool	ret;

		if (current == other)
			return false;
		ret = ft::lexicographical_compare(other.begin(), other.end(), current.begin(), current.end(), current._bt.comp);
		return (ret);
	}

	template<class Key, class T, class Compare , class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator>& current, const map<Key, T, Compare, Allocator>& other)
	{
		bool	ret;

		if (current == other)
			return true;
		ret = ft::lexicographical_compare(current.begin(), current.end(), other.begin(), other.end(), current._bt.comp);
		return (!(ret));
	}

	template<class Key, class T>
	void	swap(const map<Key, T>& current, const map<Key, T>& other)
	{
		current.swap(other);
	}

}