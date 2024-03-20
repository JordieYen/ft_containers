#include "bst.hpp"

namespace ft
{
	template < typename T, class Compare, class Allocator>
	bst<T, Compare, Allocator>::bst(const compare& compp, const allocator_type& alloc) : t_alloc(alloc), comp(compp)
	{
		this->_nil = this->allocatenode(T());

		this->_nil->parent = this->_nil;
		this->_nil->left_child = this->_nil;
		this->_nil->right_child = this->_nil;
		this->_nil->is_nil = true;

		this->_root = this->_nil;

		this->_size = 0;
	}

	template < typename T, class Compare, class Allocator>
	bst<T, Compare, Allocator>::~bst(void)
	{
		this->t_alloc.destroy(this->_nil->key);
		this->t_alloc.deallocate(this->_nil->key, 1);
		this->n_alloc.destroy(this->_nil);
		this->n_alloc.deallocate(this->_nil, 1);
	}

	template < typename T, class Compare, class Allocator>
	bst<T, Compare, Allocator>::bst(bst& clone)
	{
		this->_nil = this->allocatenode(T());

		this->_nil->parent = NULL;
		this->_nil->left_child = this->_nil;
		this->_nil->right_child = this->_nil;
		this->_nil->is_nil = true;

		this->_root = this->_nil;
		if (clone._root != clone._nil)
		{
			this->insertnode(*clone._root->key);
			bstclone(clone._root, clone._nil);
		}

		this->_size = clone._size;
	}

	template < typename T, class Compare, class Allocator>
	bst<T, Compare, Allocator>&	bst<T, Compare, Allocator>::operator=(const bst& clone)
	{
		this->~bst();
		this->_nil = this->allocatenode(T());

		this->_nil->parent = NULL;
		this->_nil->left_child = this->_nil;
		this->_nil->right_child = this->_nil;
		this->_nil->is_nil = true;

		this->_root = this->_nil;
		if (clone._root != clone._nil)
		{
			this->insertnode(*clone._root->key);
			bstclone(clone._root, clone._nil);
		}

		this->_size = clone._size;

		return (*this);
	}

	template < typename T, class Compare, class Allocator>
	void bst<T, Compare, Allocator>::bstclone(node<T> *x, node<T> *nil)
	{
		if (x != nil)
		{	
			if (x->left_child != nil)
				this->insertnode(*x->left_child->key); 
			bstclone(x->left_child, nil);

			if (x->right_child != nil)
				this->insertnode(*x->right_child->key); 
			bstclone(x->right_child, nil);
		}
	}

	template < typename T, class Compare, class Allocator>
	void bst<T, Compare, Allocator>::bstclear(node<T> *x)
	{
		if (x != this->_nil)
		{
			bstclear(x->left_child);
			this->t_alloc.destroy(x->key);
			this->t_alloc.deallocate(x->key, 1);
			this->n_alloc.destroy(x);
			this->n_alloc.deallocate(x, 1);
			bstclear(x->right_child);
		}
	}

	template < typename T, class Compare, class Allocator>
	node<T>*    bst<T, Compare, Allocator>::allocatenode(T key)
	{
		node<T>	*newnode = this->n_alloc.allocate(1);

		this->n_alloc.construct(newnode, node<T>());
		newnode->key = this->t_alloc.allocate(1);
		this->t_alloc.construct(newnode->key, key);

		return (newnode);
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::printBT(const std::string& prefix, const node<T>* node, bool isLeft)
	{
		if( node != this->_nil)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "├─l──" : "└─r──" );
			std::cout << *node->key << std::endl;
			printBT( prefix + (isLeft ? "│   " : "    "), node->left_child, true);
			printBT( prefix + (isLeft ? "│   " : "    "), node->right_child, false);
		}
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::printBT(void)
	{
		this->bstwalk(this->_root);
		std::cout << "\n-" << std::endl;
		printBT("", this->_root, false); 
	}

	template < typename T, class Compare, class Allocator>
	T	bst<T, Compare, Allocator>::min(void)
	{
		return (*this->_nil->left_child->key);
	}

	template < typename T, class Compare, class Allocator>
	T	bst<T, Compare, Allocator>::max(void)
	{
		return (*this->_nil->right_child->key);
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::insertnode(T key)
	{
		node<T> *newnode = this->allocatenode(key);

		newnode->parent = this->_nil;
		newnode->left_child = this->_nil;
		newnode->right_child = this->_nil;
		newnode->is_nil = false;
		
		if (this->_root == this->_nil)
			this->_root = newnode;
		else
			this->bstinsert(newnode);
		this->setextrema(newnode);
		this->_size++;
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::setextrema(node<T> *x)
	{
		if (this->comp(*x->key, *this->_nil->left_child->key) || this->_nil->left_child == this->_nil)
			this->_nil->left_child = x;
		if (this->comp(*this->_nil->right_child->key, *x->key) || this->_nil->right_child == this->_nil)
			this->_nil->right_child = x;
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::deletenode(T key)
	{
		if (this->_root == this->_nil)
			return ;
		node<T> *x = this->_root;

		x = this->iterativebstsearch(this->_root, key);
		if (x != this->_nil)
		{
			this->bstdelete(x);
			if (this->_nil->left_child == x && this->_nil->right_child == x)
			{
				this->_root = this->_nil;
				this->_nil->left_child = this->_nil;
				this->_nil->right_child = this->_nil;
			}
			if (this->_nil->left_child == x)
				this->_nil->left_child = this->bstminimum(this->_root);
			if (this->_nil->right_child == x)
				this->_nil->right_child = this->bstmaximum(this->_root);
			this->t_alloc.destroy(x->key);
			this->t_alloc.deallocate(x->key, 1);
			this->n_alloc.destroy(x);
			this->n_alloc.deallocate(x, 1);
			this->_size--;
		}
	}

	template < typename T, class Compare, class Allocator>
	node<T>*    bst<T, Compare, Allocator>::searchnode(T key) const
	{
		return (this->bstsearch(this->_root, key));
	}

	template < typename T, class Compare, class Allocator>
	node<T>*    bst<T, Compare, Allocator>::iterativesearchnode(T key)
	{
		return (this->iterativebstsearch(this->_root, key));
	}

	template < typename T, class Compare, class Allocator>
	void bst<T, Compare, Allocator>::bstwalk(node<T> *x)
	{
		if (x != this->_nil)
		{
			bstwalk(x->left_child);
			std::cout << *x->key << " ";
			bstwalk(x->right_child);
		}
	}

	template < typename T, class Compare, class Allocator>
	ft::node<T>* bst<T, Compare, Allocator>::bstsearch(node<T> *x, T key) const
	{
		if (x == this->_nil)
			return (NULL);
		if (this->comp(key, *x->key))
			return (bstsearch(x->left_child, key));
		else if (this->comp(*x->key, key))
			return (bstsearch(x->right_child, key));
		return (x);
	}

	template < typename T, class Compare, class Allocator>
	ft::node<T>* bst<T, Compare, Allocator>::iterativebstsearch(node<T> *x, T key)
	{
		node<T> *y = x;
		while ((y != this->_nil))
		{
			if (this->comp(key, *y->key))
				y = y->left_child;
			else if (this->comp(*y->key, key))
				y = y->right_child;
			else
				break;
		}
		return (y);
	}

	template < typename T, class Compare, class Allocator>
	ft::node<T>* bst<T, Compare, Allocator>::bstminimum(node<T> *x)
	{
		node<T> *y = x;

		while (y->left_child != this->_nil)
			y = y->left_child;
		return (y);
	}

	template < typename T, class Compare, class Allocator>
	ft::node<T>* bst<T, Compare, Allocator>::bstmaximum(node<T> *x)
	{
		node<T> *y = x;

		while (y->right_child != this->_nil)
			y = y->right_child;
		return (y);
	}

	template < typename T, class Compare, class Allocator>
	ft::node<T>* bst<T, Compare, Allocator>::bstsuccessor(node<T> *x)
	{
		node<T> *y;

		if (x->right_child != NULL)
			return (bstminimum(x->right_child));
		y = x->parent;
		while ((y != NULL) && (x == y->right_child))
		{
			x = y;
			y = y->parent;
		}
		return (y);
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::bstinsert(node<T> *z)
	{
		node<T> *y;
		node<T> *x = this->_root;

		while (x != this->_nil)
		{
			y = x;
			if (this->comp(*z->key, *x->key))
				x = x->left_child;
			else
				x = x->right_child;
		}
		z->parent = y;
		if (y == this->_nil)
			this->_root = z;
		else if (this->comp(*z->key, *y->key))
			y->left_child = z;
		else
			y->right_child = z;
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::bsttransplant(node<T> *u, node<T> *v)
	{
		if (u->parent == this->_nil)
			this->_root = v;
		else if (u == u->parent->left_child)
			u->parent->left_child = v;
		else
			u->parent->right_child = v;
		
		if (v != this->_nil)
			v->parent = u->parent;
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::bstdelete(node<T> *z)
	{
		node<T> *y;

		if (z->left_child == this->_nil)
			bsttransplant(z, z->right_child);
		else if (z->right_child == this->_nil)
			bsttransplant(z, z->left_child);
		else
		{
			y = bstminimum(z->right_child);
			// std::cout << "y parent =" <<  y->parent->key << std::endl;
			if (y->parent != z)
			{
				bsttransplant(y, y->right_child);
				y->right_child = z->right_child;
				y->right_child->parent = y;
			}
			bsttransplant(z, y);
			y->left_child = z->left_child;
			y->left_child->parent = y;
		}
	}

	template < typename T, class Compare, class Allocator>
	bool		bst<T, Compare, Allocator>::empty(void) const
	{
		if (this->_root == this->_nil)
			return (true);
		return (false);
	}

	template < typename T, class Compare, class Allocator>
	size_t		bst<T, Compare, Allocator>::size(void) const
	{
		return (this->_size);
	}

	template < typename T, class Compare, class Allocator>
	size_t		bst<T, Compare, Allocator>::max_size(void) const
	{
		return (this->n_alloc.max_size());
	}

	template < typename T, class Compare, class Allocator>
	typename bst<T, Compare, Allocator>::node_allocator	bst<T, Compare, Allocator>::get_allocator(void) const
	{
		return (this->n_alloc);
	}
}