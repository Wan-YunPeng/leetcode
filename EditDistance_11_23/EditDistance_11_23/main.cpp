#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string &s1, string &s2);

int main()
{
	string s1 = "cabcd", s2 = "acbcc";
	cout << editDistance(s1, s2) << endl;
	return 0;
}

int editDistance(string &s1, string &s2)
{
	const int m = s1.size();
	const int n = s2.size();

	vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

	for (int i = 0; i <= m; ++i)
		f[i][0] = i;
	for (int j = 0; j <= n; ++j)
		f[0][j] = j;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				f[i][j] = f[i - 1][j - 1];
			}
			else
			{
				int mn = min(f[i - 1][j], f[i][j - 1]);
				f[i][j] = 1 + min(f[i - 1][j - 1], mn);
			}
		}
	}
	return f[m][n];
}