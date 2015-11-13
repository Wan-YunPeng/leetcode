#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef vector<pair<int, int> >::const_iterator Iter;

vector<vector<int>> permuteUnique(vector<int> &num);

void permute(vector<vector<int>> &re, vector<int> &p, Iter first, Iter last, int size);

int main()
{
	vector<int> num({ 1, 1, 2 });
	vector<vector<int>> re = permuteUnique(num);
	for (auto elem : re)
	{
		for_each(elem.begin(), elem.end(), [](const int i)
		{
			cout << i << " ";
		});
	/*	for (auto i : elem)
		{
			cout << i << " ";
		}*/
		cout << endl;
	}
	return 0;
}

vector<vector<int>> permuteUnique(vector<int> &num)
{
	unordered_map<int, int> map;
	for (int i = 0; i < num.size(); ++i)
	{
		if (map.find(num[i]) == map.end())
			map[num[i]] = 1;
		else
			map[num[i]]++;
	}

	// 将map中的元素拷贝到一个vector中
	vector<pair<int, int> > elems;
	for_each(map.begin(), map.end(), [&elems](const pair<int, int> &e)
	{
		elems.push_back(e);
	});

	vector<vector<int>> re;
	vector<int> p;

	permute(re, p, elems.begin(), elems.end(), num.size());
	return re;
}

void permute(vector<vector<int>> &re, vector<int> &p, Iter first, Iter last, int size)
{
	if (p.size() == size)
	{
		re.push_back(p);
		return;
	}

	for (auto i = first; i != last; ++i)
	{
		int count = 0;
		for (auto j = p.begin(); j != p.end(); ++j)
		{
			if (i->first == *j)
				count++;
		}
		if (i->second > count)
		{
			p.push_back(i->first);
			permute(re, p, first, last, size);
			p.pop_back();
		}
	}
}

