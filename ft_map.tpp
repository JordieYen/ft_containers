#include "ft_map.hpp"

namespace ft
{
	template <class T>
    void    left_rotate(ft::node<T> x, ft::node<T> y)
    {
		//			p
		//			|
 		//		   (x)
		//		  /  |
        ///      a   (y)
		//	        /  |
		///		   B    v

        if (y.left_child->parent == y) // If y has a left subtree (or) if left_child of y is not null
            y.left_child->parent = x; // make x the parent of y -> left child 
        x.right_child = y.left_child; // make the right_child of x into the left_child of y
        if (x.parent->root == x) // if x is root
            x.parent->root = y; // make y the root
        else if (x == x.parent->left_child) // if x is a left child
            x.parent->left_child = y; // make y the left child of x -> parent
        else // if x is a right child
            x.parent->right_child = y; // make y the right child of x -> parent
        y.parent = x.parent; // y -> parent to x -> parent
        x.parent = y; // make x -> parent to y
        y.left_child = x; // make x the left child of y
    }

    template <class T>
    void    right_rotate(ft::node<T> x, ft::node<T> y)
    {
		//			p
		//			|
 		//		   (y)
		//		  /  |
        ///     (x)   a
		//	   /  |
		///	  v    B

        if (x.right_child != NULL) // If x has a right subtree
        {
            x.right_child->parent = y; // assign y as the parent of the right subtree of x
            if (y.parent == NULL) // If the parent of y is NULL
                x.parent = y.parent; // make x as the root of the tree
            else if (y == y.parent->right_child) // Else if y is the right child of its parent p
                y.parent->right_child = x; // make x as the right child of p
            else
                y.parent->left_child = x; // Else assign x as the left child of p
            y.parent = x; // Make x as the parent of y
        }
    }

	template <class T>
    void    left_right_rotation(ft::node<T> x, ft::node<T> y, ft::node<T> z)
    {
		//				p
		//				|
 		//			   (z)
		//			  /  |
        ///	    	(y)   e
		//		   /  |
		///		 (x)   v
		// 	 	/  |
		///    a    B

		left_rotate(x, y);
		right_rotate(y, z);
    }

	template <class T>
    void    right_left_rotation(ft::node<T> x, ft::node<T> y, ft::node<T> z)
    {
		//			p
		//			|
 		//		   (z)
		//		  /  |
        ///      f   (x)
		//	   		/  |
		///	  	  (y)   a
		//	   	 /  |
		///	    v    B

		right_rotate(x, y);
		left_rotate(z, y);
    }
}