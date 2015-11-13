#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permutation(vector<int> &num);
void permutation(vector<int> &num, vector<int> &path, vector<vector<int>> &re);

int main()
{
	vector<int> num({ 1, 2, 3 });
	vector<vector<int>> re = permutation(num);
	for (auto row : re)
	{
		for (auto i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> permutation(vector<int> &num)
{
	vector<vector<int>> re;
	vector<int> path;
	permutation(num, path, re);
	return re;
}
void permutation(vector<int> &num, vector<int> &path, vector<vector<int>> &re)
{
	if (path.size() == num.size())
	{
		re.push_back(path);
		return;
	}
	else
	{
		for (auto i : num)
		{
			auto pos = find(path.begin(), path.end(), i);

			if (pos == path.end())
			{
				path.push_back(i);
				permutation(num, path, re);
				path.pop_back();
			}
		}
	}
}