#include "ft_is_integral.hpp"
#include <iostream>

using std::cout;
using std::endl;

class A {};
 
struct B { int x; };
// using BF = decltype(B::x); // bit-field's type
 
enum E : int {};
 
template <class T>
T f(T i)
{
    static_assert(std::is_integral<T>::value, "Integral required.");
    return i;
}

int	main(void)
{
    if ( ft::is_integral<A>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<E>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<float>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<int*>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<int>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<const int>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<bool>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;
	// ---------------------------------------
    if ( ft::is_integral<char>::value )
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return (0);
}