#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int> &S);
void dfs(vector<int> &S, vector<int>::iterator start, vector<int> path, vector<vector<int>> &result);
vector<vector<int>> subsetsWithDup2(vector<int> &S);

int main()
{
	vector<int> S({ 1, 2, 2, 3, 3 });
	vector<vector<int>> re = subsetsWithDup2(S);
	for (auto row : re)
	{
		for (auto i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> subsetsWithDup(vector<int> &S)
{
	sort(S.begin(), S.end());
	vector<vector<int>> re;
	vector<int> path;

	dfs(S, S.begin(), path, re);
	return re;
}

void dfs(vector<int> &S, vector<int>::iterator start, vector<int> path, vector<vector<int>> &result)
{
	result.push_back(path);

	for (auto i = start; i < S.end(); ++i)
	{
		if (i != start && *i == *(i - 1)) continue;
		path.push_back(*i);
		dfs(S, i + 1, path, result);
		path.pop_back();
	}
}

vector<vector<int>> subsetsWithDup2(vector<int> &S)
{
	sort(S.begin(), S.end());
	set<vector<int> > re;
	const size_t n = S.size();
	vector<int> v;

	for (size_t i = 0; i < 1U << n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (i & 1 << j)
				v.push_back(S[j]);
		}
		re.insert(v);
		v.clear();
	}
	vector<vector<int>> real_re;
	copy(re.begin(), re.end(), back_inserter(real_re));
	return real_re;
}