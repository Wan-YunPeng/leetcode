#include <iostream>
#include <vector>
using namespace std;

int uniqueTrees(int n, int f[]);
int uniqueTrees(int n);

int main()
{
	const int n = 5;
	int f[n];
	fill(f, f + n, 0);
	f[0] = 1;
	f[1] = 1;
	int re = uniqueTrees(n, f);
	cout << re << endl;
	re = uniqueTrees(n);
	cout << re << endl;
	return 0;
}

int uniqueTrees(int n, int f[])
{
	if (n == 0 || n == 1) return 1;
	int re = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (f[i - 1] == 0) f[i - 1] = uniqueTrees(i - 1, f);
		if (f[n - i] == 0) f[n - i] = uniqueTrees(n - i, f);
		re += f[i - 1]*f[n - i];
	}
	return re;
}

int uniqueTrees(int n)
{
	vector<int> f(n + 1, 0);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int k = 1; k <= i; ++k)
			f[i] += f[k - 1] * f[i - k];
	}
	return f[n];
}