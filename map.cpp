// #include "ft_map.hpp"
#include "bst.hpp"
#include "ft_pair.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace ft 
{
	// template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	// class map : public std::binary_function<ft::pair<const Key, T>, ft::pair<const Key, T>, bool>
	// {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
	// 	friend class map;

	// 	protected:
	// 		Compare comp;
	// 	public:
	// 		typedef bool		result_type;
	// 		typedef ft::pair<const Key, T>		value_type;
	// 		typedef typename value_type::first_type		first_argument_type;
	// 		typedef typename value_type::second_type		second_argument_type;
			template <class Key, class T, class Compare = std::less<Key> >
			class value_compare : public std::binary_function<ft::pair<Key, T>, ft::pair<Key, T>, bool>
			{
				public:
					value_compare(){};
					~value_compare(){};
					typedef ft::pair< Key, T>		value_type;

					bool operator()(value_type& x, value_type& y) const
					{
						return comp(x.first, y.first);
					}
					value_compare(Compare pred) : comp(pred) {}
				protected:
					Compare comp;
			};
	// };
}

int main(void)
{
	// ft::pair<int, std::string>	pr;
	// ft::pair<int, std::string>	pr1;

	// pr = ft::make_pair(7, "bruh");
	// pr1 = ft::make_pair(2, "lol");
	// cout << pr << endl;
	// cout << pr1 << endl;

	// const ft::value_compare<int, std::string>	comp;
	// if (comp(pr, pr1))
	// 	cout << "IT WORKSS" << endl;

	ft::bst< ft::pair<int, std::string>, ft::value_compare<int, std::string > >	btree;
	// ft::bst< ft::pair<int, std::string>, ft::value_compare<int, std::string>, std::allocator<ft::pair<int, std::string> > >	btree2();

	btree.insertnode(ft::make_pair(9, "a"));
	btree.insertnode(ft::make_pair(1, "b"));
	btree.insertnode(ft::make_pair(10, "c"));
	btree.insertnode(ft::make_pair(2, "d"));
	btree.insertnode(ft::make_pair(1, "e"));
	btree.insertnode(ft::make_pair(3, "f"));

	btree.deletenode(ft::make_pair(9, std::string()));
	// btree.deletenode(10);
	// btree.deletenode(1);
	// btree.deletenode(30);

	btree.printBT();
	// ft::bst< ft::pair<int, std::string> >	btree(std::less<int>);

	// btree.insertnode(ft::make_pair(1, "lol"));
	ft::bst<int, std::less<int>, std::allocator<int> >	tree;
	
	tree.insertnode(9);
	tree.insertnode(1);
	tree.insertnode(10);
	tree.insertnode(2);
	tree.insertnode(1);
	tree.insertnode(3);

	tree.deletenode(9);
	// tree.deletenode(10);
	// tree.deletenode(1);
	// tree.deletenode(30);



	// ft::node<int> *p = tree.searchnode(1);
	// p->printdata("p");
	// cout << "min : " << tree.min() << " max : " << tree.max() << endl;
	tree.printBT();

	// system("leaks con");
	return (0);
}
