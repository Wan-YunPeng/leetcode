#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minCut(string s);

int main()
{
	string s = "adbbc";
	cout << minCut(s) << endl;
	return 0;
}
// 双动态规划
int minCut(string s)
{
	const int n = s.size();
	vector<int> f(n + 1, 0);
	vector<vector<bool>> p(n, vector<bool>(n, false));

	for (int i = 0; i <= n; ++i)
		f[i] = n - i - 1; // f[n]为-1

	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i; j < n; ++j)
		{
			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
			{
				p[i][j] = true;
				f[i] = min(f[i], f[j + 1] + 1);
			}
		}
	}
	return f[0];
}