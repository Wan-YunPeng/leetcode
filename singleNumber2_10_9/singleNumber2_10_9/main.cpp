#include <iostream>
#include <vector>
#include <list>
#include <numeric>
using namespace std;

int singleNumber(const vector<int> num);
int singleNumber2(const vector<int> num);

int main()
{
	int a[] = { 1, 1, 1, 2, 2, 2, 3 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	int re = singleNumber(num);
	cout << re << endl;
	re = singleNumber2(num);
	cout << re << endl;
	list<int> data(a, a + sizeof(a) / sizeof(a[0]));
	int ab = accumulate(data.begin(), data.end(), 0);
	cout << ab << endl;
	fill(data.begin(), data.end(), 0);
	for (auto i : data)
		cout << i << " ";
	cout << endl;
	fill_n(data.begin(), data.size(), 1);
	for (auto i : data)
		cout << i << " ";
	cout << endl;
	return 0;
}

int singleNumber(const vector<int> num)
{
	const int W = sizeof(int)* 8; // 一个整数bit位
	int counts[W];
	fill_n(&counts[0], W, 0);
	for (auto i : num)
	{
		for (size_t j = 0; j < W; ++j)
		{
			counts[j] += (i >> j) & 1;
			counts[j] %= 3;
		}
	}

	int re = 0;
	for (size_t i = 0; i < W; ++i)
	{
		re += (counts[i] << i);
	}
	return re;
}
int singleNumber2(const vector<int> num)
{
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		two |= (one & num[i]);
		one ^= num[i];
		three = ~(one & two);
		one &= three;
		two &= three;
	}
	return one;
}