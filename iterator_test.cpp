#include "ft_iterator.tpp"
#include "ft_vector.tpp"
#include <vector>

using std::cout;
using std::endl;

int	main(void)
{
	ft::vector<int>		con;
	con.push_back(5);
	con.push_back(6);
	con.push_back(7);

	ft::Iterator<int>	lol(con.data());
	cout << lol[0] << lol[1] << lol[2] << endl;
	cout << "-------------" << endl;
	cout << *lol << endl;
	lol++;
	cout << *lol << endl;
	lol++;
	cout << *lol << endl;
	lol--;
	cout << *lol << endl;
	lol--;
	cout << *lol << endl;
	cout << "-------------" << endl;
	lol = lol + 2;
	cout << *lol << endl;
	lol = lol - 2;
	cout << *lol << endl;
	cout << "-------------" << endl;
	lol += 2;
	cout << *lol << endl;
	lol -= 2;
	cout << *lol << endl;
	*lol++;
	cout << *lol << endl;
	cout << "-------------" << endl;
	if (lol == lol)
		cout << "true." << endl;
	else
		cout << "false." << endl;
	// *lol = 2;
	*lol = 5;
	// cout << lol->_pointer << endl;

	return (0);
}