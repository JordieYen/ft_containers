#ifndef FTBST_HPP
# define FTBST_HPP

#include <iostream>

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
		
		T		key;
		node*	left_child;
		node*	right_child;
		node*	parent;
	};

      template <typename T>
	class bst
	{
		public:
            bst();
            bst(const bst& clone);
            ~bst();

            void        insertnode(T key);
            void        deletenode(T key);
            void        bstwalk(node<T> *x);
            node<T>     bstsearch(node<T> *x, T key);
            node<T>     iterativebstsearch(node<T> *x, T key);
            node<T>*     bstminimum(node<T> *x);
            node<T>*     bstmaximum(node<T> *x);
            node<T>*     bstsuccessor(node<T> *x);
            void        bstinsert(node<T> *z);
            void        bsttransplant(node<T> *u, node<T> *v);
            void        bstdelete(node<T> *z);
            void        printBT(const std::string& prefix, const node<T>* node, bool isLeft);
            void        printBT(void);
            void        bstclear(node<T> *x);

		private:
            node<T> *_root;
            node<T> *_nil;

	};
}


#include "bst.tpp"

#endif