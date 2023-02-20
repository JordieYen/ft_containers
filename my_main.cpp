#include "ft_vector.hpp"
#include "ft_stack.hpp"
#include "ft_reverse_iterator.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <iterator>
#include "ft_is_integral.hpp"
#include "ft_map.hpp"


using std::cout;
using std::endl;

template< class T>
void	printvector(T& _vector, std::string name)
{
	// size(void), capacity(void), empty(void) test
	cout << "\033[34m";
	cout << name << ": [";
	for (size_t i = 0; i < _vector.size(); i++)
		cout << " " << _vector[i];
	cout << "] size: " << _vector.size();
	cout << " capacity: " << _vector.capacity();
	cout << " empty: ";
	if (_vector.empty() == 0)
		cout << "false";
	else
		cout << "true";
	cout << "\033[0m" << endl;
}

void	vector_test(void)
{
	cout << "\n----------------------- Vector test start -----------------------" << endl;

	std::vector<std::string>	realvector;
	ft::vector<std::string>		myvector;

	cout <<"\nInitialized vectors with default constructor:" << endl;
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// max_size(void) test 
	cout << "\nRan max_size() on vectors: " << endl;
	cout << "\033[34mrealvector: " << realvector.max_size() << "\033[0m" << endl; 
	cout << "\033[34mmyvector  : " << myvector.max_size() << "\033[0m" << endl;

	// push_back(T value) test
	cout << "\nRan push_back [apple], [bottom], [jeans] on vectors: " << endl;
	realvector.push_back("apple");
	realvector.push_back("bottom");
	realvector.push_back("jeans");
	myvector.push_back("apple");
	myvector.push_back("bottom");
	myvector.push_back("jeans");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// pop_back(void) test 
	cout << "\nRan pop_back on vectors: " << endl;
	realvector.pop_back();
	myvector.pop_back();
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// front(void) back(void) test 
	cout << "\nRan front() and back() on vectors: " << endl;
	cout << "\033[34mfront: realvector.front() - [" << realvector.front() << "] myvector.front() - [" << myvector.front() << "]\033[0m" << endl;
	cout << "\033[34mback : realvector.back() - [" << realvector.back() << "] myvector.back() - [" << myvector.back() << "]\033[0m" << endl;

	// reserve(size_t size) test 
	cout << "\nRan reserve(5) on vectors: " << endl;
	realvector.reserve(5);
	myvector.reserve(5);
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "reserve(4):" << endl;
	realvector.reserve(4);
	myvector.reserve(4);
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// resize(size_t size) test 
	cout << "\nRan resize(10) on vectors: " << endl;
	realvector.resize(10);
	myvector.resize(10);
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "resize(4):" << endl;
	realvector.resize(4);
	myvector.resize(4);
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "resize(0):" << endl;
	realvector.resize(0);
	myvector.resize(0);
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// resize(size_t size, T value) test 
	cout << "\nRan resize(5, [extra]) on vectors: " << endl;
	realvector.resize(5, "extra");
	myvector.resize(5, "extra");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "resize(12, [extra1]): " << endl;
	realvector.resize(12, "extra1");
	myvector.resize(12, "extra1");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// clear(void) test 
	cout << "\nRan clear() on vectors: " << endl;
	realvector.clear();
	myvector.clear();
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	std::vector<std::string>	temprealvector(3, "test");
	ft::vector<std::string>		tempmyvector(3, "test");

	cout <<"\nInitialized temp vectors with \033[33mvector(size_t, const value_type&, const allocator_type&)\033[0m constructor:" << endl;
	printvector(temprealvector, "temprealvector");
	printvector(tempmyvector, "tempmyvector  ");

	// swap(vector& other) test 
	cout << "\nRan vector.swap(vector1) on vectors: " << endl;
	cout << "before swap(): " << endl;
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	printvector(temprealvector, "temprealvector");
	printvector(tempmyvector, "tempmyvector  ");
	realvector.swap(temprealvector);
	myvector.swap(tempmyvector);
	cout << "after swap(): " << endl;
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	printvector(temprealvector, "temprealvector");
	printvector(tempmyvector, "tempmyvector  ");

	// at(size_t index) test 
	cout << "\nRan vector.at(1) and vector.at(1) = [in] on vectors: " << endl;
	cout << "\033[34mrealvector at [1] : " << realvector.at(1) << "\033[0m" << endl;
	cout << "\033[34mmyvector   at [1] : " << myvector.at(1) << "\033[0m" << endl;
	cout << "vector.at(1) = [in]: " << endl;
	realvector.at(1) = "in";
	myvector.at(1) = "in";
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// assign(size_t i, T value) test 
	cout << "\nRan assign(2, lol) on vectors: " << endl;
	realvector.assign(2, "lol");
	myvector.assign(2, "lol");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "assign(0, lol): " << endl;
	realvector.assign(0, "lol");
	myvector.assign(0, "lol");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "assign(5, lol): " << endl;
	realvector.assign(5, "lol");
	myvector.assign(5, "lol");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// operator[](size_t i) test 
	cout << "\nRan vector[1] on vectors: " << endl;
	cout << "\033[34mrealvector[1] : " << realvector[1] << "\033[0m" << endl;
	cout << "\033[34mmyvector[1]   : " << myvector[1] << "\033[0m" << endl;
	cout << "vector[1] = [in]: " << endl;
	realvector[1] = "in";
	myvector[1] = "in";
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "vector[6]: out of range test (no exception but will segfault if vector tries to access malloced mem)" << endl;
	cout << "\033[34mrealvector[6] : " << "\033[0m" << endl;
	cout << "\033[34mmyvector[6]   : " << "\033[0m" << endl;
	
	// insert(Iterator<T> pos, const value_type& val) test 
	cout << "\nRan vector.insert(vector.begin() + 1, poop) on vectors: " << endl;
	realvector.insert(realvector.begin() + 1, "poop");
	myvector.insert(myvector.begin() + 1, "poop");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// insert(Iterator<T> pos, size_t n, const value_type& val) test 
	cout << "\nRan vector.insert(vector.begin() + 1, 2, bruh) on vectors: " << endl;
	realvector.insert(realvector.begin() + 1, 2, "bruh");
	myvector.insert(myvector.begin() + 1, 2, "bruh");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "vector.insert(vector.begin() + 1, 3, okay): " << endl;
	realvector.insert(realvector.begin() + 1, 3, "okay");
	myvector.insert(myvector.begin() + 1, 3, "okay");
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// insert(Iterator<T> pos, Iterator<T> first, Iterator<T> last) test 
	cout << "\nRan vector.insert(vector.begin() + 1, tempvector.begin(), tempvector.last()) on vectors: " << endl;
	temprealvector.assign(5, "new");
	tempmyvector.assign(5, "new");
	printvector(temprealvector, "temprealvector");
	printvector(tempmyvector, "tempmyvector  ");
	realvector.insert(realvector.begin() + 1, temprealvector.begin(), temprealvector.end());
	myvector.insert(myvector.begin() + 1, tempmyvector.begin(), tempmyvector.end());
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");
	cout << "vector.insert(vector.begin() + 1, tempvector.begin(), tempvector.last()): " << endl;
	temprealvector.assign(5, "pew");
	tempmyvector.assign(5, "pew");
	printvector(temprealvector, "temprealvector");
	printvector(tempmyvector, "tempmyvector  ");
	realvector.insert(realvector.begin() + 1, temprealvector.begin(), temprealvector.end());
	myvector.insert(myvector.begin() + 1, tempmyvector.begin(), tempmyvector.end());
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// erase(Iterator<T> pos) test 
	cout << "\nRan vector.erase(vector.begin()) on vectors: " << endl;
	realvector.erase(realvector.begin());
	myvector.erase(myvector.begin());
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	// erase(Iterator<T> first, Iterator<T> last) test 
	cout << "\nRan vector.erase(vector.begin(), vector.begin() + 5) on vectors: " << endl;
	realvector.erase(realvector.begin(), realvector.begin() + 5);
	myvector.erase(myvector.begin(), myvector.begin() + 5);
	printvector(realvector, "realvector");
	printvector(myvector, "myvector  ");

	cout << "\nElements printed with T pointer using iterator : " << endl;
	cout <<  "\033[34mrealvector :" ;
	for (std::vector<std::string>::iterator it = realvector.begin(); it != realvector.end(); it++)
		cout << *it << " ";
	cout << "\033[0m" << endl;
	cout <<  "\033[34mmyvector   :" ;
	for (ft::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); it++)
		cout << *it << " ";
	cout << "\033[0m" << endl;

	cout << "\nElements printed with T pointer using reverse iterator : " << endl;
	cout <<  "\033[34mrealvector :" ;
	for (std::vector<std::string>::reverse_iterator it = realvector.rbegin(); it != realvector.rend(); it++)
		cout << *it << " ";
	cout << "\033[0m" << endl;
	cout <<  "\033[34mmyvector   :" ;
	for (ft::vector<std::string>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); it++)
		cout << *it << " ";
	cout << "\033[0m" << endl;

	cout << "\n------------------------ Vector test end ------------------------\n" << endl;
}

template <class T>
void	printstackdata(T _stack, std::string name)
{
	// empty(void), size(void), top(void) test
	cout << "\033[34m";
	cout << name << " :";
	cout << " top: [";
	if (_stack.size() > 0)
		cout << _stack.top();
	else
		cout << "stack is empty";
	cout << "] size: " << _stack.size();
	cout << " empty: ";
	if (_stack.empty() == 0)
		cout << "false";
	else
		cout << "true";
	cout << "\033[0m" << endl;
}

void	stack_test(void)
{
	cout << "\n----------------------- Stack test start -----------------------" << endl;

	std::stack<std::string>	realstack;
	ft::stack<std::string>	mystack;

	cout << "\nInitialized stacks with default constructor:" << endl;
	printstackdata(realstack, "realstack");
	printstackdata(mystack, "mystack  ");

	// push(T val) test
	cout << "\nRan push() [apple] [bottom] [jeans] on stacks: " << endl;
	realstack.push("apple");
	realstack.push("bottom");
	realstack.push("jeans");
	mystack.push("apple");
	mystack.push("bottom");
	mystack.push("jeans");
	printstackdata(realstack, "realstack");
	printstackdata(mystack, "mystack  ");

	// push(T val) test
	cout << "\nRan pop() on stacks: " << endl;
	realstack.pop();
	mystack.pop();
	printstackdata(realstack, "realstack");
	printstackdata(mystack, "mystack  ");

	std::stack<std::string>	temprealstack;
	ft::stack<std::string>	tempmystack;

	cout << "\nInitialized tempstacks with default constructor and push() [new]:" << endl;
	temprealstack.push("new");
	tempmystack.push("new");
	printstackdata(temprealstack, "temprealstack");
	printstackdata(tempmystack, "tempmystack  ");

	// swap(stack& other) test
	cout << "\nRan stack.swap(tempstack) on stacks: " << endl;
	realstack.swap(temprealstack);
	mystack.swap(tempmystack);
	printstackdata(realstack, "realstack");
	printstackdata(mystack, "mystack  ");
	printstackdata(temprealstack, "temprealstack");
	printstackdata(tempmystack, "tempmystack  ");

	// operator=( const stack& other ) test
	cout << "\nRan operator=(tempstacks) on stacks: " << endl;
	realstack = temprealstack;
	mystack = tempmystack;
	printstackdata(realstack, "realstack");
	printstackdata(mystack, "mystack  ");
	printstackdata(temprealstack, "temprealstack");
	printstackdata(tempmystack, "tempmystack  ");

	cout << "\nInitialized copystacks with copy constructor(stack):" << endl;
	std::stack<std::string>	copyrealstack(realstack);
	ft::stack<std::string>	copymystack(mystack);
	printstackdata(copyrealstack, "copyrealstack");
	printstackdata(copymystack, "copymystack  ");

	cout << "\n------------------------ Stack test end ------------------------\n" << endl;
}

template <class T>
void	printmapdata(T _map, std::string name)
{
	// empty(void), size(void), top(void) test
	cout << "\033[34m";
	cout << name << " : ";
	for (typename T::iterator it = _map.begin(); it != _map.end(); it++)
		cout << "[" << it->first << ", " << it->second << "] ";
	cout << "size: " << _map.size();
	cout << " empty: ";
	if (_map.empty() == 0)
		cout << "false";
	else
		cout << "true ";
	cout << "\033[0m" << endl;
}

void	map_test(void)
{
	cout << "\n----------------------- Map test start -----------------------" << endl;

	std::map<int, std::string>	realmap;
	ft::map<int, std::string>	mymap;

	cout << "\nInitialized stacks with default constructor:" << endl;
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");

	cout << "\nRan max_size() on maps: " << endl;
	cout << "\033[34mrealmap : " << realmap.max_size() << "\033[0m" << endl; 
	cout << "\033[34mmymap   : " << mymap.max_size() << "\033[0m" << endl;

	cout << "\nInserted [9, 1]:" << endl;
	realmap.insert(std::make_pair(9, "one"));
	realmap.insert(std::make_pair(1, "two"));
	mymap.insert(ft::make_pair(9, "one"));
	mymap.insert(ft::make_pair(1, "two"));
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");
	cout << "Ran clear() on maps :" << endl;
	realmap.clear();
	mymap.clear();
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");

	cout << "\nInserted [9, 1, 10, 2, 3, 5]:" << endl;
	realmap.insert(std::make_pair(9, "one"));
	realmap.insert(std::make_pair(1, "two"));
	realmap.insert(std::make_pair(10, "three"));
	realmap.insert(std::make_pair(2, "four"));
	realmap.insert(std::make_pair(3, "five"));
	realmap.insert(std::make_pair(5, "six"));
	mymap.insert(ft::make_pair(9, "one"));
	mymap.insert(ft::make_pair(1, "two"));
	mymap.insert(ft::make_pair(10, "three"));
	mymap.insert(ft::make_pair(2, "four"));
	mymap.insert(ft::make_pair(3, "five"));
	mymap.insert(ft::make_pair(5, "six"));
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");
	cout << "Ran insert(begin(), (11, 'seven')); on maps :" << endl;
	realmap.insert(realmap.begin(), std::make_pair(11, "seven"));
	mymap.insert(mymap.begin(), ft::make_pair(11, "seven"));
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");

	cout << "\nRan erase(2) on maps :" << endl;
	realmap.erase(2);
	mymap.erase(2);
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");
	cout << "Ran erase(begin()) on maps :" << endl;
	realmap.erase(realmap.begin());
	mymap.erase(mymap.begin());
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");

	cout << "\nRan at(10) on maps :" << endl;
	cout << "\033[34mrealmap.at(10) : " << realmap.at(10) << "\033[0m" << endl;
	cout << "\033[34mmymap.at(10)   : " << mymap.at(10) << "\033[0m" << endl;
	// cout << "Ran at(10) on maps :" << endl;
	// cout << "\033[34mrealmap.at(10) : " << realmap.at(20) << "\033[0m" << endl;
	// cout << "\033[34mmymap.at(10)   : " << mymap.at(20) << "\033[0m" << endl;

	cout << "\nRan map[10] on maps :" << endl;
	cout << "\033[34mrealmap[10] : " << realmap[10] << "\033[0m" << endl;
	cout << "\033[34mmymap[10]   : " << mymap[10] << "\033[0m" << endl;

	cout << "\nRan map.find(5) on maps :" << endl;
	cout << "\033[34mrealmap.find(5) : " << realmap.find(5)->first << ", " << realmap.find(5)->second << "\033[0m" << endl;
	cout << "\033[34mmymap.find(5)   : " << mymap.find(5)->first << ", " << mymap.find(5)->second << "\033[0m" << endl;
	// cout << "\nRan map.find(6) on maps :" << endl;
	// cout << "\033[34mrealmap.find(6) : " << realmap.find(6)->first << ", " << realmap.find(6)->second << "\033[0m" << endl;
	// cout << "\033[34mmymap.find(6)   : " << mymap.find(6)->first << ", " << mymap.find(6)->second << "\033[0m" << endl;

	cout << "\nRan map.count(5) on maps :" << endl;
	cout << "\033[34mrealmap.count(5) : " << realmap.count(5) << "\033[0m" << endl;
	cout << "\033[34mmymap.count(5)   : " << mymap.count(5) << "\033[0m" << endl;
	cout << "Ran map.count(6) on maps :" << endl;
	cout << "\033[34mrealmap.count(6) : " << realmap.count(6) << "\033[0m" << endl;
	cout << "\033[34mmymap.count(6)   : " << mymap.count(6) << "\033[0m" << endl;

	cout << "\nRan map.lower_bound(5) on maps :" << endl;
	cout << "\033[34mrealmap.lower_bound(5) : " << realmap.lower_bound(5)->first << ", " << realmap.lower_bound(5)->second << "\033[0m" << endl;
	cout << "\033[34mmymap.lower_bound(5)   : " << mymap.lower_bound(5)->first << ", " << realmap.lower_bound(5)->second << "\033[0m" << endl;
	cout << "Ran map.lower_bound(6) on maps :" << endl;
	cout << "\033[34mrealmap.lower_bound(6) : " << realmap.lower_bound(6)->first << ", " << realmap.lower_bound(6)->second << "\033[0m" << endl;
	cout << "\033[34mmymap.lower_bound(6)   : " << mymap.lower_bound(6)->first << ", " << realmap.lower_bound(6)->second << "\033[0m" << endl;
	cout << "Ran map.lower_bound(0) on maps :" << endl;
	cout << "\033[34mrealmap.lower_bound(0) : " << realmap.lower_bound(0)->first << ", " << realmap.lower_bound(0)->second << "\033[0m" << endl;
	cout << "\033[34mmymap.lower_bound(0)   : " << mymap.lower_bound(0)->first << ", " << realmap.lower_bound(0)->second << "\033[0m" << endl;

	cout << "\nRan map.equal_range(5) on maps :" << endl;
	std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>	realpr = realmap.equal_range(5);
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator>	mypr = mymap.equal_range(5);

	cout <<  "\033[34mrealmap   :" ;
	for (std::map<int, std::string>::iterator it = realpr.first; it != realpr.second; it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;
	cout <<  "\033[34mmymap     :" ;
	for (ft::map<int, std::string>::iterator it = mypr.first; it != mypr.second; it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;

	cout << "Ran map.equal_range(6) on maps :" << endl;
	std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator>	realpr1 = realmap.equal_range(6);
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator>	mypr1 = mymap.equal_range(6);

	cout <<  "\033[34mrealmap   :" ;
	for (std::map<int, std::string>::iterator it = realpr1.first; it != realpr1.second; it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;
	cout <<  "\033[34mmymap     :" ;
	for (ft::map<int, std::string>::iterator it = mypr1.first; it != mypr1.second; it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;

	cout << "\nRan erase(begin(), begin() + 1) on maps :" << endl;
	realmap.erase(realmap.begin(), ++realmap.begin());
	mymap.erase(mymap.begin(), mymap.begin() + 1);
	printmapdata(realmap, "realmap");
	printmapdata(mymap, "mymap  ");

	cout << "\nIterated through maps with map iterator :" << endl;
	cout <<  "\033[34mmymap     :" ;
	for (std::map<int, std::string>::iterator it = realmap.begin(); it != realmap.end(); it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;

	cout <<  "\033[34mmymap     :" ;
	for (ft::map<int, std::string>::iterator it = mymap.begin(); it != mymap.end(); it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;

	cout << "Iterated through maps with map reverse_iterator :" << endl;
	cout <<  "\033[34mmymap     :" ;
	for (std::map<int, std::string>::reverse_iterator it = realmap.rbegin(); it != realmap.rend(); it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;

	cout <<  "\033[34mmymap     :" ;
	for (ft::map<int, std::string>::reverse_iterator it = mymap.rbegin(); it != mymap.rend(); it++)
		cout << it->first << " ";
	cout << "\033[0m" << endl;

	cout << "\n------------------------ Map test end ------------------------\n" << endl;
}

int	main(void)
{
	vector_test();
	// stack_test();
	map_test();

	// system("leaks con");

	return (0);
}