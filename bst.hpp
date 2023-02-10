#ifndef FTBST_HPP
# define FTBST_HPP

# include <iostream>

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
	};

	template < typename T, class Compare , class Allocator = std::allocator<T> >
	class bst
	{
		public:
			typedef Allocator														allocator_type;
			typedef	typename allocator_type::template rebind< node<T> >::other		node_allocator;
			typedef	typename allocator_type::template rebind< T >::other			t_allocator;
			typedef Compare															compare;

			bst(const compare& compp);
			explicit bst(const compare& compp = compare(), const allocator_type& alloc = allocator_type());
			bst(bst& clone);
			bst<T, Compare, Allocator>&			operator=(bst& clone);
			~bst();

			T			min(void);
			T			max(void);
			void		setextrema(node<T> *x);
			void		insertnode(T key);
			void		deletenode(T key);
			node<T>*	searchnode(T key);
			node<T>*	iterativesearchnode(T key);
			void		printBT(void);
			node<T>*	bstsuccessor(node<T> *x);

		private:
			void		bstclone(node<T> *x, node<T> *nil);
			void		bstwalk(node<T> *x);
			node<T>*	bstsearch(node<T> *x, T key);
			node<T>*	iterativebstsearch(node<T> *x, T key);
			node<T>*	bstminimum(node<T> *x);
			node<T>*	bstmaximum(node<T> *x);
			void		bstinsert(node<T> *z);
			void		bsttransplant(node<T> *u, node<T> *v);
			void		bstdelete(node<T> *z);
			void		printBT(const std::string& prefix, const node<T>* node, bool isLeft);
			void		bstclear(node<T> *x);
			node<T>*	allocatenode(T key);

			node_allocator	n_alloc;
			t_allocator		t_alloc;
			node<T>			*_root;
			node<T>			*_nil;
			compare			comp;
	};
}


# include "bst.tpp"

#endif