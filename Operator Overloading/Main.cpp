#include "Fraction.h"
#include "DataStructure.h"
#include "Vector.h"
#include "Utilities.h"
#include <iostream>

int main()
{
	using std::cout;
	DataStructure ds1(10);
	DataStructure ds2(ds1);
	ds1 += ds2;
	Vector v1(10, Fraction{ 1,2 });
	Vector v2(7, Fraction{ -4,20 });
	std::cout << v1 << '\n' << v2 << '\n';

	v1 -= v2;
	cout << v1 << '\n';
	v1 += v2;
	cout << v1 << '\n';
	v1 *= v2;
	cout << v1 << '\n';

	int n;
	std::cin >> n;

	return 0;
}