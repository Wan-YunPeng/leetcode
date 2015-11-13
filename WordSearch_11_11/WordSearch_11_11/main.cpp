#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool exist(const vector<vector<char>> &dict, const string& target);
bool dfs(const vector<vector<char>> &dict, vector<vector<bool>> &visited, int n, const string& target, int x, int y);

int main()
{
	vector<vector<char>> dict = 
	{
		{ 'A', 'B', 'C', 'E' },
		{ 'S', 'F', 'C', 'S' },
		{ 'A', 'D', 'E', 'E' }
	};
	bool re = exist(dict, "ABCCED");
	cout << "ABCCED exist ? : " << re << endl;
	re = exist(dict, "SFCS");
	cout << "SFCS exist ? : " << re << endl;
	re = exist(dict, "ABCB");
	cout << "ABCB exist ? : " << re << endl;

	return 0;
}

bool exist(const vector<vector<char>> &dict, const string& target)
{
	vector<vector<bool>> visited(dict.size(), vector<bool>(dict[0].size(), false));
	for (int i = 0; i < dict.size(); ++i)
	{
		for (int j = 0; j < dict[0].size(); ++j)
		{
			if (dfs(dict, visited, 0, target, i, j))
				return true;
		}
	}
	return false;
}
bool dfs(const vector<vector<char>> &dict, vector<vector<bool>> &visited, int n, const string& target, int x, int y)
{
	if (n == target.size())
		return true;

	if (x < 0 || y < 0 || x >= dict.size() || y >= dict[0].size()) return false;

	if (visited[x][y]) return false;

	if (dict[x][y] != target[n]) return false;

	visited[x][y] = true;
	bool ret = dfs(dict, visited, n + 1, target, x - 1, y) || // up
		dfs(dict, visited, n + 1, target, x + 1, y) || // down
		dfs(dict, visited, n + 1, target, x, y - 1) || // left
		dfs(dict, visited, n + 1, target, x, y + 1); // right
	visited[x][y] = false; // ³·Ïú
	return ret;
}