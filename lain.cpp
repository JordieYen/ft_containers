#include "ft_vector.tpp"
// #include "test.tpp"
#include <iostream>
#include <vector>

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
	real.resize(10, 6);
	// real[1000] = 1; // test out of range exception
	// real.at(1000) = 1; 
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
	// cout << "maximum size of a real vector is " << real.max_size() << endl;
	std::vector<int>	real2;

	real2.reserve(64);
	real2.push_back(5);
	real2.shrink_to_fit();
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
	mine.resize(10, 6);
	// mine[1000] = 1; // test out of range exception
	// mine.at(1000) = 1; 
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
	std::vector<int>	mine2;

	mine2.reserve(64);
	mine2.push_back(5);
	mine2.shrink_to_fit();
	mine2.clear();
	cout << "my vector | size : " << mine2.size() << " capacity : " << mine2.capacity() << endl;
	
	std::vector<int>	mine3;
	std::vector<int>	mine4;

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
	mine3.swap(mine4);
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

	cout << "\033[0m-------------------" << endl;

	// system("leaks con");
	return (0);
}