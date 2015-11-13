#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution1(vector<int>& num, int target);
// 利用map存储两个数之和
vector<vector<int>> solution2(vector<int>& num, int target);
// 同上，不过使用multimap
vector<vector<int>> solution3(vector<int>& num, int target);
void test(vector<int>& num);
int main()
{
	int a[] = { 2, 1, 3, -4, 6, -7, 4 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	int target = -1;
	vector<vector<int>> re1 = solution1(num, target);
	// 使用auto大大简化了循环输出的过程，此for循环的语法也起到了很大作用
	for (auto i : re1)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	
	vector<vector<int>> re2 = solution2(num, target);
	// 使用auto大大简化了循环输出的过程，此for循环的语法也起到了很大作用
	for (auto i : re2)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	
	vector<vector<int>> re3 = solution3(num, target);
	// 使用auto大大简化了循环输出的过程，此for循环的语法也起到了很大作用
	for (auto i : re3)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	test(num);
	return 0;
}

void test(vector<int>& num)
{
	sort(num.begin(), num.end());
	auto a = num.begin();
	auto last = num.end();
	a = upper_bound(a,last,*a);
	cout << *a << endl;
	a = lower_bound(a, last, 6);
	cout << *a << endl;
}


/*
* 对数组排序，之后利用夹比准则进行查找
*/
vector<vector<int>> solution1(vector<int>& num, int target)
{
	vector<vector<int>> re;
	sort(num.begin(), num.end());

	if (num.size() < 4) exit(0);

	for (auto a = num.begin(); a != prev(num.end(), 3); ++a)
	{
		for (auto b = next(a); b != prev(num.end(), 2); ++b)
		{
			auto c = next(b);
			auto d = prev(num.end());
			while (c < d)
			{
				if (*a + *b + *c + *d < target)
					++c;
				else if (*a + *b + *c + *d > target)
					--d;
				else
				{
					re.push_back({ *a, *b, *c, *d });
					++c;
					--d;
				}
			}
		}
	}
	sort(re.begin(), re.end());
	re.erase(unique(re.begin(), re.end()), re.end());
	return re;

}

vector<vector<int>> solution2(vector<int>& num, int target)
{
	vector<vector<int>> re;
	if (num.size() < 4) return re;
	sort(num.begin(), num.end());

	// 将向量中的数两两相加，并记录其和和下标，将四个数之和看成是两个数之和
	unordered_map<int, vector<pair<int, int> > > cache;
	for (size_t a = 0; a < num.size(); ++a)
	{
		for (size_t b = a + 1; b < num.size(); ++b)
			// 和---下标
			cache[num[a] + num[b]].push_back(pair<int, int>(a, b));
	}

	// 依次取出之前两个数和的缓存，求另外两个数
	for (size_t c = 0; c < num.size(); ++c)
	{
		for (size_t d = c + 1; d < num.size(); ++d)
		{
			const int key = target - num[c] - num[d];
			if (cache.find(key) == cache.end()) continue;

			// 若含有多个解，那么剩下的两个数不唯一，那cache[key]返回的vector不唯一
			const auto& vec = cache[key];
			for (size_t k = 0; k < vec.size(); ++k)
			{
				if (c <= vec[k].second)
					continue; // 有重叠

				re.push_back({ num[vec[k].first], num[vec[k].second], num[c], num[d] });
			}
		}
	}
	sort(re.begin(), re.end());
	re.erase(unique(re.begin(), re.end()), re.end());
	return re;
}

vector<vector<int>> solution3(vector<int>& num, int target)
{
	vector<vector<int>> re;
	if (num.size() < 4) return re;
	sort(num.begin(), num.end());


	unordered_multimap<int,pair<int, int> > cache;
	for (size_t i = 0; i < num.size(); ++i)
	{
		for (size_t j = i + 1; j < num.size(); ++j)
			cache.insert(make_pair(num[i] + num[j], make_pair(i, j)));
	}

	for (auto i = cache.begin(); i != cache.end(); ++i)
	{
		int x = target - i->first;
		// 找到x，并返回指向它元素的迭代器
		auto range = cache.equal_range(x);
		for (auto j = range.first; j != range.second; ++j)
		{
			auto a = i->second.first;
			auto b = i->second.second;
			auto c = j->second.first;
			auto d = j->second.second;
			if (a != c && a != d && b != c && b != d)
			{
				vector<int> vec = { num[a], num[b], num[c], num[d] };
				sort(vec.begin(), vec.end());
				re.push_back(vec);
			}
		}

	}
	sort(re.begin(), re.end());
	re.erase(unique(re.begin(), re.end()), re.end());
	return re;
}