#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangle(vector<int> &height);

int main()
{
	int a[] = { 2,1,6,5,2,3};
	vector<int> height(a, a + sizeof(a) / sizeof(a[0]));
	for (auto i : height)
		cout << i;
	cout << endl;
	int re = largestRectangle(height);
	cout << re << endl;
	return 0;
}

int largestRectangle(vector<int> &height)
{
	stack<int> stk;
	height.push_back(0); // 处理完所有元素
	int result = 0;
	for (int i = 0; i < height.size();)
	{
		
		// 递增栈
		if (stk.empty() || height[i] > height[stk.top()])
			stk.push(i++);
		else
		{
			int tmp = stk.top();
			stk.pop();
			result = max(result, height[tmp] * (stk.empty() ? i : i - 1 - stk.top()));
			
		}
	}
	return result;
}
