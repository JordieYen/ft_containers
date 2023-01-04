#include "ft_vector.hpp"
#include "ft_reverse_iterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "ft_is_integral.hpp"


using std::cout;
using std::endl;

int	main(void)
{
	// ft::vector<int> lol;
	cout << "\033[0m-------------------" << endl;
	cout << "\033[32m";

	// real vector tests
	std::vector<int>	real(1);
	int					*tempreal;

	if (real.empty() == true)
		cout << "real vector is empty." << endl;
	real.push_back(5);
	real.push_back(5);
	real.at(1) = 1;
	real.pop_back();
	real.resize(10);
	real.resize(1);
	real.push_back(1);
	real.push_back(2);
	real.push_back(3);
	real.push_back(4);
	real.push_back(5);
	// real.resize(10, 6);
	// real.at(1) = 1;
	// std::__1::vector<int>::iterator realte = real.erase(real.begin());
	// cout << "realte == " << *realte << endl;
	// std::__1::vector<int>::iterator realinsert = real.insert(real.begin(), 4);
	// cout << "realinsert == " << *realinsert << endl;
	// real.insert(realinsert, 3, 8);
	// real.resize(6);
	// real.erase(real.begin() + 2, real.begin() + 5);
	std::vector<int>		testreal(10, 8);
	real.insert(real.begin() + 1, testreal.begin(), testreal.end());
	// real[1000] = 1; // test out of range exception
	// real.at(1000) = 1; 
	// real.erase(real.begin() + 1);
	// real.erase(real.begin() + 1, real.begin() + 3);
	cout << "real vector | size : " << real.size() << " capacity : " << real.capacity() << endl;
	cout << "elemnts printed with vector using [] : ";
	for (int i = 0; i < real.size(); i++)
		cout << real[i] << " ";
	cout << endl;
	cout << "front element in real vector is " << real.front() << endl;
	cout << "back element in real vector is " << real.back() << endl;
	tempreal = real.data();
	cout << "elemnts printed with T pointer using [] : ";
	for (int i = 0; i < real.size(); i++)
		cout << tempreal[i] << " ";
	cout << endl;
	if (real.empty() == false)
		cout << "real vector is not empty." << endl;
	cout << "maximum size of a real vector is " << real.max_size() << endl;
	std::vector<int>	real2;

	real2.reserve(64);
	real2.push_back(5);
	real2.clear();
	cout << "real vector | size : " << real2.size() << " capacity : " << real2.capacity() << endl;

	std::vector<int>	real3;
	std::vector<int>	real4;

	real3.resize(5, 5);
	real4.resize(3, 3);
	real3.reserve(10);
	cout << "real3 | size : " << real3.size() << " capacity : " << real3.capacity() << endl;
	cout << "real3 : ";
	for (int i = 0; i < real3.size(); i++)
		cout << real3[i] << " ";
	cout << endl;
	cout << "real4 | size : " << real4.size() << " capacity : " << real4.capacity() << endl;
	cout << "real4 : ";
	for (int i = 0; i < real4.size(); i++)
		cout << real4[i] << " ";
	cout << endl;
	real3.swap(real4);
	cout << "real3 | size : " << real3.size() << " capacity : " << real3.capacity() << endl;
	cout << "real3 : ";
	for (int i = 0; i < real3.size(); i++)
		cout << real3[i] << " ";
	cout << endl;
	cout << "real4 | size : " << real4.size() << " capacity : " << real4.capacity() << endl;
	cout << "real4 : ";
	for (int i = 0; i < real4.size(); i++)
		cout << real4[i] << " ";
	cout << endl;

	real4.assign(11, 3);
	cout << "real4 | size : " << real4.size() << " capacity : " << real4.capacity() << endl;
	cout << "real4 : ";
	for (int i = 0; i < real4.size(); i++)
		cout << real4[i] << " ";
	cout << endl;

	std::vector<int>	real5;
	std::vector<int>	real6;

	real5.push_back(1);
	real5.push_back(5);
	real5.push_back(6);
	// real5.push_back(7);
	real6.push_back(1);
	real6.push_back(5);
	real6.push_back(6);
	real6.push_back(7);

	cout << "\nreal5 : ";
	for (int i = 0; i < real5.size(); i++)
		cout << real5[i] << " ";
	cout << endl;
	cout << "real6 : ";
	for (int i = 0; i < real6.size(); i++)
		cout << real6[i] << " ";
	cout << endl;

	if (real5 > real6)
		cout << "true." << endl;
	else
		cout << "false." << endl;

	for (std::vector<int>::iterator it = real6.begin(); it != real6.end(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "\033[0m-------------------" << endl;
	cout << "\033[34m";

	// my vector tests
	ft::vector<int>		mine(1);
	int					*tempmine;

	if (mine.empty() == true)
		cout << "my vector is empty." << endl;
	mine.push_back(5);
	mine.push_back(5);
	mine.at(1) = 1;
	mine.pop_back();
	mine.resize(10);
	mine.resize(1);
	mine.push_back(1);
	mine.push_back(2);
	mine.push_back(3);
	mine.push_back(4);
	mine.push_back(5);
	// mine.resize(10, 6);
	// mine.at(1) = 1;
	// ft::Iterator<int> myte = mine.erase(mine.begin() + 1);
	// cout << "myte = " << *myte << endl;
	// ft::Iterator<int> myinsert = mine.insert(mine.begin(), 4);
	// cout << "myinsert = " << *myinsert << endl;
	// mine.insert(myinsert, 3, 8);
	// mine.resize(6);
	// mine.erase(mine.begin() + 2, mine.begin() + 5);
	ft::vector<int>		testmine(10, 8);
	mine.insert(mine.begin() + 1, testmine.begin(), testmine.end());
	// mine[1000] = 1; // test out of range exception
	// mine.at(1000) = 1; 
	// ft::vector<int>::Iterator start = mine.begin();
	// mine.erase(mine.begin() + 1);
	// mine.erase(mine.begin() + 1, mine.begin() + 3);
	// mine.insert(mine.begin() + 1, 10, 8);
	// for (ft::Iterator<int> i = start; i != mine.end(); i++)
	// 	cout << *i << "-";
	// cout << endl;
	
	cout << "my vector | size : " << mine.size() << " capacity : " << mine.capacity() << endl;
	cout << "elemnts printed with vector using [] : ";
	for (int i = 0; i < mine.size(); i++)
		cout << mine[i] << " ";
	cout << endl;
	cout << "front element in my vector is " << mine.front() << endl;
	cout << "back element in my vector is " << mine.back() << endl;
	tempmine = mine.data();
	cout << "elemnts printed with T pointer using [] : ";
	for (int i = 0; i < mine.size(); i++)
		cout << tempmine[i] << " ";
	cout << endl;
	if (mine.empty() == false)
		cout << "my vector is not empty." << endl;
	cout << "maximum size of a my vector is " << mine.max_size() << endl;
	ft::vector<int>	mine2;

	mine2.reserve(64);
	mine2.push_back(5);
	mine2.clear();
	cout << "my vector | size : " << mine2.size() << " capacity : " << mine2.capacity() << endl;
	
	ft::vector<int>	mine3;
	ft::vector<int>	mine4;

	mine3.resize(5, 5);
	mine4.resize(3, 3);
	mine3.reserve(10);
	cout << "mine3 | size : " << mine3.size() << " capacity : " << mine3.capacity() << endl;
	cout << "mine3 : ";
	for (int i = 0; i < mine3.size(); i++)
		cout << mine3[i] << " ";
	cout << endl;
	cout << "mine4 | size : " << mine4.size() << " capacity : " << mine4.capacity() << endl;
	cout << "mine4 : ";
	for (int i = 0; i < mine4.size(); i++)
		cout << mine4[i] << " ";
	cout << endl;
	ft::swap(mine3, mine4);
	// mine3.swap(mine4);
	cout << "mine3 | size : " << mine3.size() << " capacity : " << mine3.capacity() << endl;
	cout << "mine3 : ";
	for (int i = 0; i < mine3.size(); i++)
		cout << mine3[i] << " ";
	cout << endl;
	cout << "mine4 | size : " << mine4.size() << " capacity : " << mine4.capacity() << endl;
	cout << "mine4 : ";
	for (int i = 0; i < mine4.size(); i++)
		cout << mine4[i] << " ";
	cout << endl;

	mine4.assign(11, 3);
	cout << "mine4 | size : " << mine4.size() << " capacity : " << mine4.capacity() << endl;
	cout << "mine4 : ";
	for (int i = 0; i < mine4.size(); i++)
		cout << mine4[i] << " ";
	cout << endl;

	ft::vector<int>	mine5;
	ft::vector<int>	mine6;

	mine5.push_back(1);
	mine5.push_back(5);
	mine5.push_back(6);
	// mine5.push_back(7);
	mine6.push_back(1);
	mine6.push_back(5);
	mine6.push_back(6);
	mine6.push_back(7);
	// mine6[3] = 8;

	cout << "\nmine5 : ";
	for (int i = 0; i < mine5.size(); i++)
		cout << mine5[i] << " ";
	cout << endl;
	cout << "mine6 : ";
	for (int i = 0; i < mine6.size(); i++)
		cout << mine6[i] << " ";
	cout << endl;

	if (mine5 > mine6)
		cout << "true." << endl;
	else
		cout << "false." << endl;

	cout << "elemnts printed with T pointer using iterator : ";
	for (ft::vector<int>::Iterator<int> it = mine6.begin(); it != mine6.end(); it++)
		cout << *it << " ";
	cout << endl;

	cout << "elemnts printed with T pointer using reverse iterator : ";
	for (ft::vector<int>::reverse_iterator it = mine6.rbegin(); it != mine6.rend(); it++)
		cout << *it << " ";
	cout << endl;
	if (std::is_integral<int>::value)
		cout << "true" << endl;

	cout << "\033[0m-------------------" << endl;

	// system("leaks con");
	return (0);
}