#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int solution1(const vector<int>& num);
int solution2(const vector<int>& num);
int mergeCluster(unordered_map<int, int> &map, int left, int right);
int main()
{
	int a[] = { 400, 4, 200, 1, 3, 2 };
	vector<int> num(a, a + sizeof(a)/sizeof(a[0]));
	int result = solution1(num);
	cout << result << endl;
	result = solution2(num);
	cout << result << endl;
	return 0;
}

int solution1(const vector<int>& num)
{
	unordered_map<int, bool> used;

	if (num.empty()) return 0;

	int longest = 1;

	for (auto i : num) used[i] = false;

	for (auto i : num)
	{
		// i已经被计算入某个连续长度里，跳过此次循环
		if (used[i]) continue;
		// 至少含有自己，长度为1
		int length = 1;

		used[i] = true;
		// used.find()要是没找到返回end()，不用往下找了
		for (int j = i + 1; used.find(j) != used.end(); ++j)
		{
			used[j] = true;
			++length;
		}
		for (int j = i - 1; used.find(j) != used.end(); ++j)
		{
			used[j] = true;
			++length;
		}
		longest = max(length, longest);

	}

	return longest;
}

int solution2(const vector<int>& num)
{
	// 不对map进行初始化，在循环中对num中的元素一个个添加
	unordered_map<int, int> map;
	
	int l = 1;
	int size = num.size();

	for (auto i : num)
	{
		if (map.find(i) != map.end()) continue;
		// 初始化map，该元素最大长度为1
		map[i] = 1;
		// 找到右边有一个连续的数
		if (map.find(i - 1) != map.end())
			l = max(l, mergeCluster(map, i - 1, i));
		if (map.find(i + 1) != map.end())
			l = max(l, mergeCluster(map, i, i + 1));
	}

	for (auto i : num)
		cout << map[i] << endl;
	return size == 0 ? 0 : l;
}

int mergeCluster(unordered_map<int, int> &map, int left, int right)
{
	// 从left或right开始，以自己为起点，map记录含有他们的最大长度，那么端点就是right + map[right] -1 和 left - map[left] + 1
	int upper = right + map[right] - 1;
	int lower = left - map[left] + 1;

	int length = upper - lower + 1;
	map[upper] = length;
	map[lower] = length;
	return length;
}