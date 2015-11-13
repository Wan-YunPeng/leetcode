#include <iostream>

using namespace std;

int climbingStairs(int n);
int climbingStairs2(int n);

int main()
{
	int n = 10;
	int re = climbingStairs(n);
	cout << re << endl;
	re = climbingStairs2(n);
	cout << re << endl;
	return 0;
}

int climbingStairs(int n)
{
	int prev = 0;
	int cur = 1;
	for (int i = 1; i <= n; ++i)
	{
		int temp = cur;
		cur += prev;
		prev = temp;
	}
	return cur;
}

int climbingStairs2(int n)
{
	const double s = sqrt(5);
	return floor((pow((1 + s) / 2, n + 1) + pow((1 - s) / 2, n + 1)) / s + 0.5);
}