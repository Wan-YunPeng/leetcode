#include <iostream>

using namespace std;

int sqrt(int x);

int main()
{
	cout << sqrt(16) << endl;
	return 0;
}

int sqrt(int x)
{
	int left = 1, right = x / 2;
	int last_mid;

	if (x < 2) return x;

	while (left <= right)
	{
		const int mid = left + (right - left) / 2;
		if (x / mid > mid)
		{
			left = mid + 1;
			last_mid = mid;
		}
		else if (x / mid < mid)
			right = mid - 1;
		else
			return mid;
	}
	return last_mid;
}