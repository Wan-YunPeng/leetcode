#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate1(vector<vector<int>>& matrix);
void rotate2(vector<vector<int>>& matrix);

int main()
{
	vector<vector<int>> matrix;
	matrix.push_back({ 1, 2 });
	matrix.push_back({ 3, 4 });
	rotate1(matrix);
	for (auto row : matrix)
	{
		for (auto num : row)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}

void rotate1(vector<vector<int>>& matrix)
{
	const int n = matrix.size();

	// 副对角线反转
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
			swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
	}

	// 水平中线反转
	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = 0; j < n; ++j)
			swap(matrix[i][j], matrix[n - 1 - i][j]);
	}
}