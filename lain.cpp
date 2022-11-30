#include "ft_vector.tpp"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int	main(void)
{
	// real vector tests
	std::vector<int> real(1);

	real.push_back(5);
	real.push_back(5);
	cout << "real vector | size : " << real.size() << " capacity : " << real.capacity() << endl;
	for (int i = 0; i < real.size(); i++)
		cout << real[i] << " ";
	cout << endl;

	// my vector tests
	ft::vector<int> mine(1);

	mine.push_back(5);
	mine.push_back(5);
	cout << "my vector | size : " << mine.size() << " capacity : " << mine.capacity() << endl;
	for (int i = 0; i < mine.size(); i++)
		cout << mine[i] << " ";
	cout << endl;
	// system("leaks con");
	return (0);
}