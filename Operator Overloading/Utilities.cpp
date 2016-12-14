#include "Utilities.h"

int gcd(int a, int b)
{
	int min = (a < b) ? a : b;
	int max = (a > b) ? a : b;

	while (max % min > 0)
	{
		int temp = max % min;
		max = min;
		min = temp;
	}
	return min;
}
