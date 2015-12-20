#include <iostream>
#include <vector>

using namespace std;

int jump(int A[], int n);

int main()
{
	int A[] = { 2, 3, 1, 1, 4 };
	int re = jump(A, sizeof(A) / sizeof(A[0]));
	cout << re << endl;
	return 0;
}

int jump(int A[], int n)
{
	if (n == 0 || n == 1) return 0;

	int step = 0;
	int left = 0, right = 0;

	while (left <= right)
	{
		step++;
		const int old_right = right;
		for (int i = left; i <= old_right; ++i)
		{
			int new_right = i + A[i];
			if (new_right >= n - 1) return step;
			if (new_right > right) right = new_right;
		}
		left = old_right + 1;
	}
	return 0; // 未能到达最后一个元素
}