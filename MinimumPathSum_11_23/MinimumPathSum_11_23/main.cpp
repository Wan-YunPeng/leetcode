#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumPath(const vector<vector<int>> &grid);

int main()
{
	vector<vector<int>> grid = 
	{
		{1,4,3,6,2},
		{3,2,1,5,4},
		{8,3,2,5,8}
	};
	cout << minimumPath(grid) << endl;
	return 0;
}

int minimumPath(const vector<vector<int>> &grid)
{
	if (grid.empty()) return 0;
	const int m = grid.size();
	const int n = grid[0].size();

	vector<vector<int>> f(m, vector<int>(n, 0));
	f[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i)
		f[i][0] = grid[i][0] + f[i - 1][0];

	for (int j = 1; j < n; ++j)
		f[0][j] = grid[0][j] + f[0][j - 1];

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
		}
	}
	return f[m - 1][n - 1];
}