#include <iostream>
#include <vector>

using namespace std;

bool sudokuSolver(vector<vector<int>> &grid);
bool isValid(vector<vector<int>> &grid, int x, int y);

int main()
{
	vector<vector<int>> grid = 
	{
		{ 5, 3, 0, 0, 7, 0, 0, 0, 0 },
		{ 6, 0, 0, 1, 9, 5, 0, 0, 0 },
		{ 0, 9, 8, 0, 0, 0, 0, 6, 0 },
		{ 8, 0, 0, 0, 6, 0, 0, 0, 3 },
		{ 4, 0, 0, 8, 0, 3, 0, 0, 1 },
		{ 7, 0, 0, 0, 2, 0, 0, 0, 6 },
		{ 0, 6, 0, 0, 0, 0, 2, 8, 0 },
		{ 0, 0, 0, 4, 1, 9, 0, 3, 5 },
		{ 0, 0, 0, 0, 8, 0, 0, 7, 9 }
	};
	bool re = sudokuSolver(grid);
	if (re)
	{
		for (const auto& row : grid)
		{
			for (const auto& i : row)
				cout << i << " ";
			cout << endl;
		}
	}
	else
		cout << "The sudoku is unvalid!!!" << endl;
	return 0;
}

bool sudokuSolver(vector<vector<int>> &grid)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (grid[i][j] != 0) continue;
			for (int n = 1; n <= 9; ++n)
			{
				grid[i][j] = n;
				if (isValid(grid, i, j) && sudokuSolver(grid))
					return true;
				grid[i][j] = 0; // 撤销
			}
			return false; // 此位置从1取到9都不合法，返回false
		}
	}
	return true;
}

bool isValid(vector<vector<int>> &grid, int x, int y)
{
	// 检查行、列是否有效
	for (int j = 0; j < grid.size(); ++j)
	{
		if (j != y && grid[x][j] == grid[x][y]) // hang
			return false;
		if (j != x && grid[j][y] == grid[x][y]) // lie
			return false;
	}

	// 检查正方形
	int row = x / 3 , col = y / 3 ;
	for (int i = row * 3; i < (row + 1) * 3; ++i)
	{
		for (int j = col * 3; j < (col + 1) * 3; ++j)
		{
			if (i != x && j != y && grid[i][j] == grid[x][y])
				return false;
		}
	}

	return true;	
}