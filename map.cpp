// #include "ft_map.hpp"
#include "bst.hpp"
#include <iostream>

using std::cout;
using std::endl;


int main(void)
{
    ft::bst<int> tree;

    tree.insertnode(9);
    tree.insertnode(1);
    tree.insertnode(10);
    tree.insertnode(2);
    tree.insertnode(1);
    tree.insertnode(3);
    tree.deletenode(9);
    tree.deletenode(10);
    tree.deletenode(30);
    tree.printBT();
    return (0);
}
