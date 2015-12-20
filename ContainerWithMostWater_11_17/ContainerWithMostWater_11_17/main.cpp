#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int container(vector<int> &height);

int main()
{
	vector<int> height = { 1, 5, 24, 12, 5, 7, 10, 11 };
	int re = container(height);
	cout << re << endl;
	return 0;
}

int container(vector<int> &height)
{
	if (height.empty() || height.size() == 1) return 0;
	int re = INT_MIN;
	int start = 0, end = height.size() - 1;
	while (start < end)
	{
		int area = min(height[start], height[end]) * (end - start);
		re = max(area, re);
		if (height[start] <= height[end])
			start++;
		else
			end--;
	}
	//return re;
}