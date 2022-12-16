#include "new_vector.tpp"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;

int main()
{
	std::vector<int> real(4);

	real.push_back(4);
	real.reserve(10);
	cout << "real vector | size : " << real.size() << " capacity : " << real.capacity() << endl;
	cout << "elemnts printed with vector using [] : ";
	for (int i = 0; i < real.size(); i++)
		cout << real[i] << " ";
	cout << endl;
	// ft::vector<string> lol(4, "aple", std::allocator<string>());

	// for (size_t i = 0; i < lol.size(); i++)
	// 	cout << lol[i] << endl;
	// cout << "------------\n";
	// for (ft::Iterator<string> i = lol.begin(); i != lol.end(); i++)
	// 	cout << *i << endl;
	// cout << "------------\n";

	// ft::vector<string> bruh(lol.begin(), lol.end(), std::allocator<string>());

	// for (size_t i = 0; i < bruh.size(); i++)
	// 	cout << bruh[i] << endl;
	// cout << "------------\n";

	// ft::vector<string> kol(bruh);

	// for (size_t i = 0; i < kol.size(); i++)
	// 	cout << kol[i] << endl;
	// cout << "------------\n";

	// ft::vector<string> loop;

	// loop = kol;

	// for (size_t i = 0; i < loop.size(); i++)
	// 	cout << loop[i] << endl;
	// cout << "------------\n";

	return (0);
}