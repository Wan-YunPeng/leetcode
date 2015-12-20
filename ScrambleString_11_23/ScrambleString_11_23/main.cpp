#include <iostream>
#include <vector>

using namespace std;

bool scramble(string &s1, string &s2);

int main()
{
	string s1 = "rgeat", s2 = "rgtae";
	cout << scramble(s1, s2) << endl;
	return 0;
}

bool scramble(string &s1, string &s2)
{
	const int N = s1.size();
	if (N != s2.size()) return false;

	vector<vector<vector<bool>>> f(N + 1, vector<vector<bool>>(N, vector<bool>(N, false)));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			f[1][i][j] = s1[i] == s2[j];
	}

	for (int n = 1; n <= N; ++n)
	{
		for (int i = 0; i + n <= N; ++i)
		{
			for (int j = 0; j + n <= N; ++j)
			{
				for (int k = 1; k < n; ++k)
				{
					if ((f[k][i][j] && f[n - k][i + k][j + k]) || f[k][i][j + n - k] && f[n - k][i + k][j]){
						f[n][i][j] = true;
						break;
					}
				}
			}
		}
	}
	return f[N][0][0];
}