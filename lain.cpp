#include "ft_vector.tpp"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int	main(void)
{
	cout << "-------------------" << endl;

	// real vector tests
	std::vector<int>	real(1);
	int					*tempreal;

	if (real.empty() == true)
		cout << "real vector is empty." << endl;
	real.push_back(5);
	real.push_back(5);
	real.at(1) = 1;
	// real.at(3) = 1; // test out of range exception
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
	real2.shrink_to_fit();
	cout << "real vector | size : " << real2.size() << " capacity : " << real2.capacity() << endl;


	cout << "-------------------" << endl;

	// my vector tests
	ft::vector<int>		mine(1);
	int					*tempmine;

	if (mine.empty() == true)
		cout << "my vector is empty." << endl;
	mine.push_back(5);
	mine.push_back(5);
	mine.at(1) = 1;
	// mine.at(3) = 1; // test out of range exception
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
	cout << "my vector | size : " << mine2.size() << " capacity : " << mine2.capacity() << endl;

	cout << "-------------------" << endl;

	// system("leaks con");
	return (0);
}