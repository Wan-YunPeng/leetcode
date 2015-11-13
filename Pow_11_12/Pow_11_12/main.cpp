#include <iostream>

using namespace std;

int pow(int a, int b);
int pow2(int a, int b);

int main()
{
	int a = 3;
	int b = 2;
	int re = pow(a, b);
	cout << re << endl;
	return 0;
}

int pow(int a, int b)
{
	if (b == 0) return 1;
	
	int r = 1, base = a;
	while (b != 0)
	{
		if (b & 1)
			r *= base;
		base *= base; // ÿ�Ƴ�һλ��ƽ��
		b >>= 1;
	}
	return r;
}

// ���ֲ���
int pow2(int a, int b)
{
	int r = 1, base = a;
	while (b != 0)
	{
		if (b % 2)
			r *= base;
		base *= base;
		b /= 2;
	}
	return r;
}