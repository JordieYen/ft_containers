#ifndef FTBST_HPP
# define FTBST_HPP

# include <iostream>
# include <algorithm>
# include <limits>
# include <memory>
# include <string>

namespace ft
{
	template <typename T>
	struct	node
	{
		node(){};
		node(T key)
		{
				this->key = key;
		}
		node(const ft::node<T>& clone)
		{
			this->key = clone.key;
			this->left_child = clone.left_child;
			this->right_child = clone.right_child;
			this->parent = clone.parent;
			this->is_nil = clone.is_nil;
		}
		~node(){};

		void  printdata(std::string name)
		{
			std::cout << "----------------------------------" << std::endl;
			std::cout << "temp name of node   : " << name << std::endl;
			std::cout << "parent of node      : " << *this->parent->key << std::endl;
			std::cout << "left child of node  : " << *this->left_child->key << std::endl;
			std::cout << "right child of node : " << *this->right_child->key << std::endl;
			std::cout << "key of node         : " << *this->key << std::endl;
			std::cout << "----------------------------------" << std::endl;
		}
		
		T*		key;
		node*	left_child;
		node*	right_child;
		node*	parent;
		bool	is_nil;
	};

	template < typename T, class Compare, class Allocator = std::allocator<T> >
	class bst
	{
		public:
			typedef Allocator														allocator_type;
			typedef	typename allocator_type::template rebind< node<T> >::other		node_allocator;
			typedef Compare															compare;

			explicit bst(const compare& compp = compare(), const allocator_type& alloc = allocator_type());
			bst(bst& clone);
			bst<T, Compare, Allocator>&			operator=(const bst& clone);
			~bst();

			bool			empty(void) const;
			size_t			size(void) const;
			size_t			max_size(void) const;
			node_allocator	get_allocator(void) const;

			T			min(void);
			T			max(void);

			node<T>*	bstminimum(node<T> *x);
			node<T>*	bstmaximum(node<T> *x);

			void		setextrema(node<T> *x);

			void		insertnode(T key);
			void		deletenode(T key);
			node<T>*	searchnode(T key) const;
			node<T>*	iterativesearchnode(T key);
			void		printBT(void);
			node<T>*	bstsuccessor(node<T> *x);
			void		bstclear(node<T> *x);

			node<T>			*_root;
			node<T>			*_nil;
			size_t			_size;
			node_allocator	n_alloc;
			allocator_type	t_alloc;

		private:
			void		bstclone(node<T> *x, node<T> *nil);
			void		bstwalk(node<T> *x);
			node<T>*	bstsearch(node<T> *x, T key) const;
			node<T>*	iterativebstsearch(node<T> *x, T key);
			void		bstinsert(node<T> *z);
			void		bsttransplant(node<T> *u, node<T> *v);
			void		bstdelete(node<T> *z);
			void		printBT(const std::string& prefix, const node<T>* node, bool isLeft);
			node<T>*	allocatenode(T key);

		public:
			compare			comp;

	};
}

# include "bst.tpp"

#endif