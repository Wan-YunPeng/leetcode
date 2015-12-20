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
	// ��dividend = INT_MINʱ�� -dividend�������������long long
	long long a = dividend >= 0 ? dividend : -(long long)dividend;
	long long b = divisor >= 0 ? divisor : -(long long)divisor;
	// ��dividend = INT_MINʱ��divisor = -1ʱ�� -dividend�������������long long
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