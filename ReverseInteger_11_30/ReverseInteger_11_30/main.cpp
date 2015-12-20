#include <iostream>

using namespace std;

int reverseInteger(int n);

int main()
{
	int n = 1000000002;
	cout << reverseInteger(n) << endl;
	return 0;
}

int reverseInteger(int n)
{
	int re = 0;
	for (; n != 0; n /= 10)
	{
		re = re * 10 + n % 10;
	}
	return re;
}