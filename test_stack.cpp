#include "ft_stack.hpp"
#include <stack>

using std::cout;
using std::endl;

int	main()
{
	std::stack<int>		real;
	std::stack<int>		real1;
	ft::stack<int>		lol;
	ft::stack<int>		lol1;

	lol.push(3);
	lol.push(2);
	lol.push(1);
	lol1.push(3);
	lol1.push(2);
	lol1.push(1);

	if (lol == lol1)
		std::cout << "yes!" << std::endl;

	while (!lol.empty())
	{
		cout << lol.top() << " ";
		lol.pop();
	}
	cout << endl;

	// real.push(10);
	// real1.push(0);
	// if (real == real1)
	// 	std::cout << "yes!" << std::endl;
	// if (lol == lol1)
	// 	std::cout << "yes!" << std::endl;

	return (0);
}