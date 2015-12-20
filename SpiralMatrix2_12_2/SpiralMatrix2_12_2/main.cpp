#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int n);
vector<vector<int>> generateMatrix(int n);

int main()
{
	vector<vector<int>> re = generateMatrix(3);
	for (const auto &row : re)
	{
		for (const auto &i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> generate(int n)
{
	vector<vector<int>> grid(n, vector<int>(n)); // n x n
	int num = 1;
	int startX = 0, endX = n - 1;
	int startY = 0, endY = n - 1;

	while (true)
	{
		for (int j = startX; j <= endX; ++j) grid[startY][j] = num++;
		if (++startY > endY) break;

		for (int i = startY; i <= endY; ++i) grid[i][endX] = num++;
		if (startX > --endX) break;

		for (int j = endX; j >= startX; --j) grid[endY][j] = num++;
		if (startY > --endY) break;

		for (int i = endY; i >= startY; --i) grid[i][startX] = num++;
		if (++startX > endX) break;
	}

	return grid;

}

vector<vector<int>> generateMatrix(int n)
{
	int begin = 0, end = n - 1;
	int num = 1;
	vector<vector<int>> re(n, vector<int>(n));
	while (begin < end)
	{
		for (int j = begin; j < end; ++j) re[begin][j] = num++;
		for (int i = begin; i < end; ++i) re[i][end] = num++;
		for (int j = end; j > begin; --j) re[end][j] = num++;
		for (int i = end; i > begin; --i) re[i][begin] = num++;
		begin++; end--;
	}
	if (begin == end)
		re[begin][end] = num;
	return re;
}