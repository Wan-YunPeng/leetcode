#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(vector<vector<int>> &grid);
int dfs(vector<vector<int>> &grid, vector<vector<int>> &re, int x, int y);
int getOrUpdate(vector<vector<int>> &grid, vector<vector<int>> &re, int x, int y);

// 动态规划求解
int uniquePahtsWithObstacles(vector<vector<int>> &grid);

int main()
{
	vector<vector<int>> grid = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	int re = uniquePahtsWithObstacles(grid);
	cout << re << endl;
	return 0;
}

int uniquePaths(vector<vector<int>> &grid)
{
	vector<vector<int>> f(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
	return dfs(grid, f ,grid.size(), grid[0].size());
}

int dfs(vector<vector<int>> &grid, vector<vector<int>> &re, int x, int y)
{
	if (x < 1 || y < 1) return 0;

	if (x == 1 && y == 1) return 1;

	if (grid[x - 1][y - 1] == 1) return 0;

	return getOrUpdate(grid, re, x - 1, y) + getOrUpdate(grid, re, x, y - 1);
}

int getOrUpdate(vector<vector<int>> &grid, vector<vector<int>> &re, int x, int y)
{
	if (re[x][y] > 0) return re[x][y];
	else return re[x][y] = dfs(grid, re, x, y);
}


// 动态规划求解
int uniquePahtsWithObstacles(vector<vector<int>> &grid)
{
	const int m = grid.size();
	const int n = grid[0].size();

	if (grid[0][0] || grid[m - 1][n - 1]) return 0;

	vector<int> f(n, 0);
	
	f[0] = grid[0][0] ? 0 : 1;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
			f[j] = grid[i][j] ? 0 : f[j - 1] + f[j];
	}
	
	return f.back();
	
	/*int i = 0;

	while (++i < n)
	{
		if (grid[0][i] != 1)
			f[i] = 1;
		else
			break;
	}

	if (m > 1 && grid[1][0] != 0) f[0] = 1;

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
			f[j] = f[j - 1] + f[j];
	}
	return f.back();*/
}