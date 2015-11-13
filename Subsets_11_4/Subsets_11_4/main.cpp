#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> subSets(vector<int> S);
void subSets(vector<int> S, vector<int> &path, int step, vector<vector<int>> &result);
vector<vector<int>> subSets2(vector<int> S);

int main()
{
	vector<int> S({ 1, 2, 3, 4 });
	vector<vector<int>> re = subSets2(S);
	for (auto row : re)
	{
		for (auto i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> subSets(vector<int> S)
{
	sort(S.begin(), S.end());
	vector<vector<int>> result;
	vector<int> path;
	subSets(S, path, 0, result);
	return result;
}
void subSets(vector<int> S, vector<int> &path, int step, vector<vector<int>> &result)
{
	if (step == S.size())
	{
		result.push_back(path);
		return;
	}
	// 选择此路径
	path.push_back(S[step]);
	subSets(S, path, step + 1, result);
	path.pop_back();
	// 不选此路径
	subSets(S, path, step + 1, result);
}

vector<vector<int>> subSets2(vector<int> S)
{
	vector<vector<int>> re;
	vector<int> v;
	const size_t n = S.size();

	for (size_t i = 1; i < 1 << n; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (i & 1 << j)
				v.push_back(S[j]);
		}
		re.push_back(v);
		v.clear();
	}
	return re;
}