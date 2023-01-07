#include "ft_vector.hpp"
#include "ft_reverse_iterator.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include "ft_is_integral.hpp"


using std::cout;
using std::endl;

template< class T>
void	printvector(T& _vector, std::string name)
{
	cout << "\033[34m";
	cout << name << ": [";
	for (int i = 0; i < _vector.size(); i++)
		cout << " " << _vector[i];
	cout << "] size: " << _vector.size();
	cout << " capacity: " << _vector.capacity();
	cout << " empty: ";
	if (_vector.empty() == 0)
		cout << "false";
	else
		cout << "true";
	cout << endl;
	cout << "\033[0m";
}

void	vector_test(void)
{
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
	for (ft::vector<std::string>::Iterator it = myvector.begin(); it != myvector.end(); it++)
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

	cout << endl;
}

int	main(void)
{
	vector_test();

	// system("leaks con");

	return (0);
}