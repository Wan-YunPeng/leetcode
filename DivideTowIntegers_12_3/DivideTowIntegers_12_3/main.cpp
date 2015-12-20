#include <iostream>

using namespace std;

int divide(int divisor, int dividend);

int main()
{
	cout << divide(2, 10) << endl;
	return 0;
}

int divide(int divisor, int dividend)
{
	// 当dividend = INT_MIN时， -dividend会溢出，所以用long long
	long long a = dividend >= 0 ? dividend : -(long long)dividend;
	long long b = divisor >= 0 ? divisor : -(long long)divisor;
	// 当dividend = INT_MIN时，divisor = -1时， -dividend会溢出，所以用long long
	long long result = 0;

	while (a >= b)
	{
		long long c = b;
		for (int i = 0; a >= c; ++i, c <<= 1)
		{
			a -= c;
			result += 1 << i;
		}
	}
	return ((dividend ^ divisor) >> 31) ? (-result) : result;
}