#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPath(vector<vector<int>> & triangle);
int minPath2(vector<vector<int>> & triangle);

int main()
{
	vector<vector<int>> triangle = 
	{
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	int re = minPath2(triangle);
	cout << re << endl;
	return 0;
}

int minPath(vector<vector<int>> & triangle)
{
	if (triangle.empty()) return 0;
	if (triangle.size() == 1) return triangle[0][0];

	vector<int> f(triangle.back().size(), 0);
	f[0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); ++i)
	{
		for (int j = triangle[i].size() - 1; j >= 0; --j)
		{
			if (j == triangle[i].size() - 1)
			{
				f[j] = f[j - 1] + triangle[i][j];
			}
			else if (j == 0)
			{
				f[j] = f[j] + triangle[i][j];
			}
			else
			{
				f[j] = min(f[j] + triangle[i][j], f[j - 1] + triangle[i][j]);
			}
		}
	}
	int re = INT_MAX;
	for (int i = 0; i < f.size(); ++i)
	{
		re = min(re, f[i]);
	}
	return re;
}

int minPath2(vector<vector<int>> & triangle)
{
	if (triangle.empty()) return 0;
	if (triangle.size() == 1) return triangle[0][0];
	for (int i = triangle.size() - 2; i >= 0; --i)
	{
		for (int j = 0; j < triangle[i].size(); ++j)
		{
			triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return triangle[0][0];
}