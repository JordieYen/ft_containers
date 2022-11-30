#include "ft_vector.tpp"
#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	ft::vector<int> lol(5);

	cout << "size : " << lol.size() << " capacity : " << lol.capacity() << endl;
	// system("leaks con");
	return (0);
}