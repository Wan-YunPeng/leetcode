#include <iostream>
#include <algorithm>
#include <stack>



using namespace std;
/*
	从左向右扫描一遍，对于每根柱子，求左边最大值
	从右向左扫描一遍，对于每根柱子，求右边最大值
	再扫描一遍，把每个位置上的水位相加
*/
int solution1(int A[], int n);
/*
	扫描一遍，找出最高的那根柱子
	一分为二，对左半边处理，当前高度小于其左边最大高度，计算该位置水位，否则更新左边最高
	右边同理
*/
int solution2(int A[], int n);
/*
	使用一个辅助栈，小于栈顶的元素入栈，大于等于栈顶就把栈里所有小于或等于当前值的元素全部出栈处理掉
	最后把当前元素入栈
*/
int solution3(int A[], int n);

int main()
{
	int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(A) / sizeof(A[0]);
	int re1 = solution1(A, n);
	cout << re1 << endl;
	int re2 = solution2(A, n);
	cout << re2 << endl;
	return 0;
}

int solution1(int A[], int n)
{
	// 每个柱子的左边最大值和右边最大值
	int *max_left = new int[n]();
	int *max_right = new int[n]();

	for (int i = 1; i < n; ++i)
	{
		// 左边最大从第二个开始
		max_left[i] = max(max_left[i - 1], A[i - 1]);
		// 右边最大从倒数第二个开始；默认第一个的左边最大为0，最后一个的右边最大为0
		max_right[n - i - 1] = max(max_right[n - i], A[n - i]);
	}

	for (int i = 0; i < n; ++i)
		cout << max_left[i] << " ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << max_right[i] << " ";
	cout << endl;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int height = min(max_left[i], max_right[i]);
		if (height > A[i])
		{
			sum += height - A[i];
		}
	}

	delete[] max_right;
	delete[] max_left;
	return sum;
}

int solution2(int A[], int n)
{
	// 柱子最高的下标
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] > A[max])
			max = i;
	}

	int water = 0;
	// 处理左半边
	for (int i = 0, peak = 0; i < max; ++i)
	{
		if (A[i] > peak) peak = A[i];
		else water += peak - A[i];
	}
	// 处理右半边
	for (int i = n - 1, peak = 0; i > max; --i)
	{
		if (A[i] > peak) peak = A[i];
		else water += peak - A[i];
	}
	return water;
}

int solution3(int A[], int n)
{
	stack<pair<int, int>> s;
	int water = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int height = 0;

		while (!s.empty()) // 将栈里比当前元素矮或登高的元素全部处理掉
		{
			int bar = s.top().first; // 栈顶元素高度
			int pos = s.top().second; // 栈顶元素下标

			// bar,height,A[i] 三者成为凹陷
			water += (min(bar, A[i]) - height) * (i - pos - 1);
			height = bar;

			if (A[i] < bar)
				break;
			else
				s.pop();
		}
		s.push(make_pair(A[i], i));
	}
	return water;
}