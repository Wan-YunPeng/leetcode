#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

pair<int ,int> solution1(const vector<int>& num, int target);

int main()
{
	int a[] = { 2, 7, 9, 11, 23, 13 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	int target = 19;
	pair<int, int> index = solution1(num, target);
	;
	if (index.first == 0 && index.second == 0)
	{
		cout << "not found" << endl;
		return 0;
	}
	cout << index.first << "  " << index.second << endl;
	return 0;
}

pair<int, int> solution1(const vector<int>& num, int target)
{
	// 第一个记录元素内容---数字大小； 第二个记录其下标，利用map.find进行查找
	unordered_map<int, int> map;
	int j = 0;
	for (auto i : num)
	{
		map[i] = j++;
	}
	pair<int, int> index(0,0);
	for (auto i : num)
	{
		const int gap = target - i;
		if (map.find(gap) != map.end() && map[gap] > map[i])
		{
			index.first = map[i];
			index.second = map[gap];
		}
	}
	return index;
}