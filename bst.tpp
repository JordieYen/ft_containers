#include "bst.hpp"

namespace ft
{
    template <typename T>
    bst<T>::bst(void)
    {
        this->_nil = new node<T>();
        this->_root = new node<T>();

        this->_nil->parent = NULL;
        this->_nil->left_child = NULL;
        this->_nil->right_child = NULL;
        this->_nil->key = T();

        this->_root->parent = this->_nil;
        this->_root->left_child = this->_nil;
        this->_root->right_child = this->_nil;
        this->_root->key = this->_nil->key;
    }

    template <typename T>
    bst<T>::~bst(void)
    {
        this->bstclear(this->_root);
        delete this->_nil;
    }

    template <typename T>
    void bst<T>::bstclear(node<T> *x)
    {
        if (x != this->_nil)
        {
            bstclear(x->left_child);
            delete x;
            bstclear(x->right_child);
        }
    }

    template <typename T>
    void    bst<T>::printBT(const std::string& prefix, const node<T>* node, bool isLeft)
    {
        if( node != this->_nil)
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├─l──" : "└─r──" );

            // print the value of the node
            std::cout << node->key << std::endl;

            // enter the next tree level - left and right branch
            printBT( prefix + (isLeft ? "│   " : "    "), node->left_child, true);
            printBT( prefix + (isLeft ? "│   " : "    "), node->right_child, false);
        }
    }

    template <typename T>
    void    bst<T>::printBT(void)
    {
        this->bstwalk(this->_root);
        std::cout << "\n-" << std::endl;
        printBT("", this->_root, false); 
    }

    template <typename T>
    void    bst<T>::insertnode(T key)
    {
        // std::cout << "inserted " << key << std::endl;
        if (this->_root->key == T())
        {
            this->_root->key = key;
            this->_nil->parent = this->_root;
            this->_nil->left_child = this->_root;
            this->_nil->right_child = this->_root;

            // std::cout << "parent of root : " << this->_root->parent->key << std::endl;
            // std::cout << "left child of root : " << this->_root->left_child->key << std::endl;
            // std::cout << "right child of root : " << this->_root->right_child->key << std::endl;
            // std::cout << "key of root : " << this->_root->key << std::endl;
        }
        else
        {
            node<T> *newnode = new node<T>(key);

            newnode->left_child = this->_nil;
            newnode->right_child = this->_nil;
            this->bstinsert(newnode);

            // std::cout << "parent of newnode : " << newnode->parent->key << std::endl;
            // std::cout << "left child of newnode : " << newnode->left_child->key << std::endl;
            // std::cout << "right child of newnode : " << newnode->right_child->key << std::endl;
            // std::cout << "key of newnode : " << newnode->key << std::endl;
        }

        // std::cout << "\nparent of root : " << this->_root->parent->key << std::endl;
        // std::cout << "left child of root : " << this->_root->left_child->key << std::endl;
        // std::cout << "right child of root : " << this->_root->right_child->key << std::endl;
        // std::cout << "key of root : " << this->_root->key << std::endl;
        // std::cout << "\n---------------" << std::endl;
    }

    template <typename T>
    void    bst<T>::deletenode(T key)
    {
        node<T> *x = this->_root;

        while (key != x->key)
        {
            if (key < x->key)
                x = x->left_child;
            else
                x = x->right_child;
            if (x == this->_nil)
                break;
        }
        if (x != this->_nil)
        {
            this->bstdelete(x);
            delete x;
        }
    }

    template <typename T>
    void bst<T>::bstwalk(node<T> *x)
    {
        if (x != this->_nil)
        {
            bstwalk(x->left_child);
            std::cout << x->key << " ";
            bstwalk(x->right_child);
        }
    }

    template <typename T>
    ft::node<T> bst<T>::bstsearch(node<T> *x, T key)
    {
        if ((x == NULL) || (key == x->key))
            return (x);
        if (key < x->key)
            return (bstsearch(x->left_child, key));
        else
            return (bstsearch(x->right_child, key));
    }

    template <typename T>
    ft::node<T> bst<T>::iterativebstsearch(node<T> *x, T key)
    {
        while ((x != NULL) && (key != x->key))
        {
            if (key < x->key)
                x = x->left_child;
            else
                x = x->right_child;
        }
        return (x);
    }

    template <typename T>
    ft::node<T>* bst<T>::bstminimum(node<T> *x)
    {
        node<T> *y = x;

        while (y->left_child != this->_nil)
            y = y->left_child;
        return (y);
    }

    template <typename T>
    ft::node<T>* bst<T>::bstmaximum(node<T> *x)
    {
        node<T> *y = x;

        while (y->right_child != this->_nil)
            y = y->right_child;
        return (y);
    }

    template <typename T>
    ft::node<T>* bst<T>::bstsuccessor(node<T> *x)
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

    template <typename T>
    void    bst<T>::bstinsert(node<T> *z)
    {
        node<T> *y;
        node<T> *x = this->_root;

        while (x != this->_nil)
        {
            y = x;
            if (z->key < x->key)
                x = x->left_child;
            else
                x = x->right_child;
        }
        z->parent = y;
        if (y == NULL)
            this->_root = z;
        else if (z->key < y->key)
            y->left_child = z;
        else
            y->right_child = z;
    }

    template <typename T>
    void    bst<T>::bsttransplant(node<T> *u, node<T> *v)
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

    template <typename T>
    void    bst<T>::bstdelete(node<T> *z)
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