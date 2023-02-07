#include "bst.hpp"

namespace ft
{
	template < typename T, class Compare, class Allocator>
	bst<T, Compare, Allocator>::bst(void)
	{
		this->_nil = this->allocatenode();

		this->_nil->parent = NULL;
		this->_nil->left_child = this->_nil;
		this->_nil->right_child = this->_nil;

		this->_root = this->_nil;
	}

	template < typename T, class Compare, class Allocator>
	bst<T, Compare, Allocator>::~bst(void)
	{
		this->bstclear(this->_root);
		this->t_alloc.destroy(this->_nil->key);
		this->t_alloc.deallocate(this->_nil->key, 1);
		this->n_alloc.destroy(this->_nil);
		this->n_alloc.deallocate(this->_nil, 1);
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
	node<T>*    bst<T, Compare, Allocator>::allocatenode(void)
	{
		node<T>	*newnode = this->n_alloc.allocate(1);

		this->n_alloc.construct(newnode, node<T>());
		newnode->key = this->t_alloc.allocate(1);
		this->t_alloc.construct(newnode->key, T());

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
		node<T> *newnode = this->allocatenode();

		*newnode->key = key;
		newnode->left_child = this->_nil;
		newnode->right_child = this->_nil;
		if (*this->_root->key == T())
			this->_root = newnode;
		else
			this->bstinsert(newnode);
		this->setextrema(newnode);
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::setextrema(node<T> *x)
	{
		if (*x->key < *this->_nil->left_child->key || *this->_nil->left_child->key == T())
			this->_nil->left_child = x;
		if (*this->_nil->right_child->key < *x->key || *this->_nil->right_child->key == T())
			this->_nil->right_child = x;
	}

	template < typename T, class Compare, class Allocator>
	void    bst<T, Compare, Allocator>::deletenode(T key)
	{
		if (this->_root == this->_nil)
			return ;
		node<T> *x = this->_root;

		while (key != *x->key)
		{
			if (key < *x->key)
				x = x->left_child;
			else
				x = x->right_child;
			if (x == this->_nil)
				break;
		}
		if (x != this->_nil)
		{
			this->bstdelete(x);
			if (this->_nil->left_child == x)
				this->_nil->left_child = this->bstminimum(this->_root);
			if (this->_nil->right_child == x)
				this->_nil->right_child = this->bstmaximum(this->_root);
			this->t_alloc.destroy(x->key);
			this->t_alloc.deallocate(x->key, 1);
			this->n_alloc.destroy(x);
			this->n_alloc.deallocate(x, 1);
		}
	}

	template < typename T, class Compare, class Allocator>
	node<T>*    bst<T, Compare, Allocator>::searchnode(T key)
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
	ft::node<T>* bst<T, Compare, Allocator>::bstsearch(node<T> *x, T key)
	{
		if ((x == this->_nil) || (key == *x->key))
			return (x);
		if (key < *x->key)
			return (bstsearch(x->left_child, key));
		else
			return (bstsearch(x->right_child, key));
	}

	template < typename T, class Compare, class Allocator>
	ft::node<T>* bst<T, Compare, Allocator>::iterativebstsearch(node<T> *x, T key)
	{
		while ((x != this->_nil) && (key != *x->key))
		{
			if (key < *x->key)
				x = x->left_child;
			else
				x = x->right_child;
		}
		return (x);
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
			if (*z->key < *x->key)
				x = x->left_child;
			else
				x = x->right_child;
		}
		z->parent = y;
		if (y == this->_nil)
			this->_root = z;
		else if (*z->key < *y->key)
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
}