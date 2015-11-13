#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix);
void setZeroes2(vector<vector<int>> &matrix);

int main()
{
	vector<vector<int>> matrix;
	matrix.push_back({ 1, 2, 0 });
	matrix.push_back({ 4, 5, 6 });
	matrix.push_back({ 0, 8, 9 });
	setZeroes2(matrix);
	for (auto row : matrix)
	{
		for (auto num : row)
			cout << num << " ";
		cout << endl;
	}
	return 0;
}

void setZeroes(vector<vector<int>> &matrix)
{
	// 行数
	const size_t m = matrix.size();
	// 列数
	const size_t n = matrix[0].size();
	vector<bool> row(m, 0);
	vector<bool> col(n, 0);

	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (0 == matrix[i][j])
				row[i] = col[j] = true;
		}
	}

	for (size_t i = 0; i < m; ++i)
	{
		if (true == row[i])
		{
			fill(&matrix[i][0], &matrix[i][0] + n, 0);
		}
	}

	for (size_t j = 0; j < n; ++j)
	{
		if (true == col[j])
		{
			for (size_t i = 0; i < n; ++i)
			{
				matrix[i][j] = 0;
			}
		}
	}
}

void setZeroes2(vector<vector<int>> &matrix)
{
	const size_t m = matrix.size();
	const size_t n = matrix[0].size();
	bool row_has_zero = false;
	bool col_has_zero = false;

	for (size_t i = 0; i < m; ++i)
	{
		if (0 == matrix[i][0])
		{
			col_has_zero = true;
			break;
		}
	}

	for (size_t j = 0; j < n; ++j)
	{
		if (0 == matrix[0][j])
		{
			row_has_zero = true;
			break;
		}
	}

	for (size_t i = 1; i < m; ++i)
	{
		for (size_t j = 1; j < n; ++j)
		{
			if (0 == matrix[i][j])
			{
				matrix[0][j] = matrix[i][0] = 0;
			}
		}
	}

	for (size_t i = 1; i < m; ++i)
	{
		for (size_t j = 1; j < n; ++j)
		{
			if (0 == matrix[0][j] || 0 == matrix[i][0])
				matrix[i][j] = 0;
		}
	}

	if (row_has_zero)
	{
		fill(&matrix[0][0], &matrix[0][0] + n, 0);
	}

	if (col_has_zero)
	{
		for (size_t i = 0; i < m; ++i)
		{
			matrix[i][0] = 0;
		}
	}
}