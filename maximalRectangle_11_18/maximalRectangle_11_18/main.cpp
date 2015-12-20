#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalRectangle(vector<vector<char>> &matrix);

int main()
{
	vector<vector<char>> matrix = 
	{
		{ '0', '0', '1', '0' },
		{ '0', '0', '1', '1' },
		{ '0', '1', '1', '1' },
		{ '0', '0', '1', '1' }
	};
	cout << maximalRectangle(matrix) << endl;
	return 0;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
	if (matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0)
		return 0;

	const int m = matrix.size();
	const int n = matrix[0].size();

	vector<int> H(n, 0);
	vector<int> L(n, 0);
	vector<int> R(n, n);
	int ret = 0;
	for (int i = 0; i < m; ++i)
	{
		int left = 0, right = n;
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == '1')
			{
				++H[j];
				L[j] = max(left, L[j]);
			}
			else
			{
				left = j + 1;
				L[j] = 0; H[j] = 0; R[j] = n;
			}
		}
		for (int j = n - 1; j >= 0; --j)
		{
			if (matrix[i][j] == '1') // º∆À„
			{
				R[j] = min(R[j], right);
				ret = max(ret, H[j] * (R[j] - L[j]));
			}
			else
				right = j;
		}
	}
	return ret;
}