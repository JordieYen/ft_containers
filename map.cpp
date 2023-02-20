#include "ft_map.hpp"
#include "bst.hpp"
#include "ft_pair.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "ft_map_iterator.hpp"

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

	// ft::bst< ft::pair<int, std::string>, ft::value_compare<int, std::string > >	btree;
	// ft::bst< ft::pair<int, std::string>, ft::value_compare<int, std::string > >	ctree(btree);
	// ft::bst< ft::pair<int, std::string>, ft::value_compare<int, std::string>, std::allocator<ft::pair<int, std::string> > >	btree2();

	// btree.insertnode(ft::make_pair(9, "a"));
	// btree.insertnode(ft::make_pair(1, "b"));
	// btree.insertnode(ft::make_pair(10, "c"));
	// btree.insertnode(ft::make_pair(2, "d"));
	// btree.insertnode(ft::make_pair(1, "e"));
	// btree.insertnode(ft::make_pair(3, "f"));

	// btree.deletenode(ft::make_pair(9, std::string()));

	// ft::node<ft::pair<int, std::string> > *bp = btree.searchnode(ft::make_pair(1, std::string()));
	// bp->printdata("bp");
	// cout << "min : " << btree.min() << " max : " << btree.max() << endl;

	// btree.printBT();

	// ft::bst<int, std::less<int>, std::allocator<int> >	tree;
	
	// tree.insertnode(90);
	// tree.insertnode(1);
	// tree.insertnode(100);
	// tree.insertnode(9);
	// tree.insertnode(20);
	// tree.insertnode(40);
	// tree.insertnode(10);
	// tree.insertnode(50);
	// tree.insertnode(80);
	// tree.insertnode(130);
	// tree.insertnode(110);
	// tree.insertnode(120);
	// tree.insertnode(30);
	// tree.insertnode(25);
	// tree.insertnode(24);
	// tree.insertnode(26);
	// tree.insertnode(78);

	// tree.deletenode(9);
	// tree.deletenode(10);
	// tree.deletenode(1);
	// tree.deletenode(30);



	// ft::node<int> *p = tree.searchnode(1);
	// p->printdata("p");
	// cout << "min : " << tree.min() << " max : " << tree.max() << endl;
	// tree.printBT();

	// std::less<int>	lol;
	// ft::bst<int, std::less<int> >	tree;
	// tree.insertnode(9);
	// tree.insertnode(1);
	// tree.insertnode(10);
	// tree.insertnode(2);
	// tree.insertnode(1);
	// tree.insertnode(3);

	// tree.printBT();

	// ft::node<int> *lol = tree.searchnode(90);

	// if (lol == NULL)
	// 	cout << "NULL" << endl;
	// else
	// 	cout << "NOT NULL" << endl;
	// ft::bst<int, std::less<int> >	btree = tree;

	// tree.printBT();
	// btree.printBT();

	ft::map<int, std::string>	mp;

	// mp._bt.insertnode(ft::make_pair(9, "a"));
	// mp._bt.insertnode(ft::make_pair(1, "a"));
	// mp._bt.insertnode(ft::make_pair(3, "a"));
	// mp._bt.insertnode(ft::make_pair(10, "a"));
	// mp._bt.insertnode(ft::make_pair(5, "a"));

	// for (ft::map<int, std::string>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
	// 	cout << it->first << endl;
	ft::pair<ft::map<int, std::string>::iterator, bool>	pool(mp.insert(ft::make_pair(9, "a")));
	ft::pair<ft::map<int, std::string>::iterator, bool>	loop(mp.insert(ft::make_pair(9, "a")));

	cout << *pool.first.base << " " << pool.first.base << " " << pool.second  << endl;
	cout << *loop.first.base << " " << loop.first.base<< " " << loop.second  << endl;

	mp.insert(ft::make_pair(10, "alolo"));
	mp.insert(ft::make_pair(3, "leaks"));
	mp.insert(ft::make_pair(5, "sanitize"));

	cout << "val = " << mp[5] << "." << endl;
	// cout << "bruh = " << mp.at(1) << "." << endl;
	cout << "count = " << mp.count(10) << "." << endl;

	// ft::map<int, std::string>::iterator	it = mp.find(6);
	// ft::map<int, std::string>::iterator	it = mp.lower_bound(6);
	// ft::map<int, std::string>::iterator	it = mp.upper_bound(5);

	// cout << *it << endl;

	// ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator>	pr = mp.equal_range(5);

	// for (ft::map<int, std::string>::iterator i = pr.first; i != pr.second; i++)
	// {
	// 	cout << *i.base << endl;
	// }

	for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++)
		cout << *it << ", ";
	cout << endl;

	ft::map<int, std::string>::iterator pol = mp.erase(mp.begin() + 1, mp.begin() + 3);
	cout << *pol << endl;

	for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++)
		cout << *it << ", ";
	cout << endl;

	// ft::map<int, std::string>::iterator lol = mp.erase(mp.begin() + 2);
	// cout << *lol << endl;

	// cout << mp.erase(11) << endl;

	// mp.clear();
	// cout << mp.size() << endl;

	// for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	ft::map<int, std::string>	mp1;

	mp1.insert(ft::make_pair(1, "peal"));
	mp1.insert(ft::make_pair(4, "coop"));
	mp1.insert(ft::make_pair(8, "reeks"));
	mp1.insert(ft::make_pair(5, "rook"));

	// cout << "bruh: " << endl;
	// for (ft::map<int, std::string>::iterator it = mp1.begin(); it != mp1.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// ft::map<int, std::string>	mp3(mp1.begin(), mp1.end());

	// for (ft::map<int, std::string>::iterator it = mp3.begin(); it != mp3.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// for (ft::map<int, std::string>::iterator it = mp1.begin(); it != mp1.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// mp.swap(mp1);
	// cout << "swapped" << endl;

	// mp.insert(mp1.begin(), mp1.end());

	// for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// for (ft::map<int, std::string>::iterator it = mp1.begin(); it != mp1.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// ft::map<int, std::string>	mp2(mp1);

	// for (ft::map<int, std::string>::iterator it = mp2.begin(); it != mp2.end(); it++)
	// 	cout << *it << ", ";
	// cout << endl;

	// cout << *it.base->key << "\n" << endl;
	// mp._bt.printBT();

	// mp._bt.insertnode(ft::make_pair(9, "a"));
	// mp._bt.insertnode(ft::make_pair(1, "b"));
	// mp._bt.insertnode(ft::make_pair(10, "c"));
	// mp._bt.insertnode(ft::make_pair(2, "d"));
	// mp._bt.insertnode(ft::make_pair(1, "e"));
	// mp._bt.insertnode(ft::make_pair(3, "f"));

	// std::cout << mp[11] << endl;
	// mp._bt.searchnode(ft::);

	// mp._bt.deletenode(ft::make_pair(9, std::string()));

	// ft::bst< ft::pair<int, std::string>, ft::value_compare<int, std::string > >	btree;

	// btree.insertnode(ft::make_pair(9, "a"));
	// btree.insertnode(ft::make_pair(1, "b"));
	// btree.insertnode(ft::make_pair(10, "c"));
	// btree.insertnode(ft::make_pair(2, "d"));
	// btree.insertnode(ft::make_pair(1, "e"));
	// btree.insertnode(ft::make_pair(3, "f"));

	// cout  << btree[11]->key << endl;

	// ft::bst< int, std::less<int> >	ctree;

	// ctree.insertnode(9);
	// ctree.insertnode(1);
	// ctree.insertnode(10);
	// ctree.insertnode(2);
	// ctree.insertnode(1);
	// ctree.insertnode(3);
	// cout << ctree.searchnode(10) << endl;

	// ctree.searchnode(11);

	// std::map<int, std::string>	pol;

	// pol.insert(std::make_pair(9, "a"));

	// cout << pol[11] << endl;

	// btree.deletenode(ft::make_pair(9, std::string()));

	// btree.printBT();

	// btree.printBT();

	// ft::mIterator<ft::node<ft::pair<int, std::string> > > lol(btree._root->left_child);

	// std::cout << *lol.base->key << endl;
	// lol++;
	// std::cout << *lol.base->key << endl;
	// lol++;
	// std::cout << *lol.base->key << endl;
	// lol++;
	// std::cout << *lol.base->key << endl;
	// lol++;
	// std::cout << *lol.base->key << endl;
	// lol++;
	// lol--;
	// std::cout << *lol.base->key << endl;
	// lol--;
	// std::cout << *lol.base->key << endl;
	// lol--;
	// std::cout << *lol.base->key << endl;
	// lol--;
	// std::cout << *lol.base->key << endl;

	// ft::map<int, std::string> lel;

	// lel._bt.insertnode(ft::make_pair(9, "a"));
	// lel._bt.insertnode(ft::make_pair(1, "b"));
	// lel._bt.insertnode(ft::make_pair(10, "c"));
	// lel._bt.insertnode(ft::make_pair(2, "d"));
	// lel._bt.insertnode(ft::make_pair(3, "e"));

	// cout << lel[11] << endl;

	// for (ft::map<int, std::string>::iterator it = lel.begin(); it != lel.end(); it++)
	// 	std::cout << *it->key << endl;

	// for (ft::map<int, std::string>::reverse_iterator it = lel.rbegin(); it != lel.rend(); it++)
	// 	std::cout << *it->key << endl;

	// ft::map<int, std::string>::iterator test = lel.begin();
	// ft::map<int, std::string>::iterator test1 = lel.begin() + 1;

	// std::cout << *test->key << endl;
	// std::cout << *test1->key << endl;

	// test += 1;

	// std::cout << *test->key << endl;

	// if (test < test1)
	// 	cout << "true";
	// else
	// 	cout << "false";
	// cout << endl;

	// lel._bt.printBT();

	// ft::map<int, std::string>::iterator it = lel.begin();
	// ft::map<int, std::string>::iterator it = lel.end();

	// std::cout << *it.base->key << endl;
	// it--;
	// std::cout << *it.base->key << endl;

	// std::cout << *it.base->key << endl;
	// it++;
	// std::cout << *it.base->key << endl;
	// it++;
	// std::cout << *it.base->key << endl;
	// it++;
	// std::cout << *it.base->key << endl;
	// it++;
	// std::cout << *it.base->key << endl;
	// it++;
	// std::cout << *it.base->key << endl;
	// it--;
	// std::cout << *it.base->key << endl;
	// it--;
	// std::cout << *it.base->key << endl;
	// it--;
	// std::cout << *it.base->key << endl;
	// it--;
	// std::cout << *it.base->key << endl;
	// it--;
	// std::cout << *it.base->key << endl;

	// std::map<int, std::string>::iterator bruh = lol.begin();
	// cout << bruh-> << endl;
	// mp._bt.printBT();

	// system("leaks con");
	return (0);
}
