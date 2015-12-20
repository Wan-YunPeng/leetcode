#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &grid);

int main()
{
	vector<vector<int>> grid = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
		{10,11,12}
	};
	vector<int> re = spiralMatrix(grid);
	for (auto &i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> spiralMatrix(vector<vector<int>> &grid)
{
	if (grid.empty()) return{};
	vector<int> re;
	int startX = 0, startY = 0;
	int endX = grid[0].size() - 1, 
		endY = grid.size() - 1;

	while (true)
	{
		// left to right
		for (int j = startX; j <= endX; ++j) re.push_back(grid[startY][j]);
		if (++startY > endY) break;

		// up to bottom
		for (int i = startY; i <= endY; ++i) re.push_back(grid[i][endX]);
		if (startX > --endX) break;

		// right to left
		for (int j = endX; j >= startX; --j) re.push_back(grid[endY][j]);
		if (startY > --endY) break;

		// bottom to up
		for (int i = endY; i >= startY; --i) re.push_back(grid[i][startX]);
		if (++startX > endX) break;
	}
	return re;
}