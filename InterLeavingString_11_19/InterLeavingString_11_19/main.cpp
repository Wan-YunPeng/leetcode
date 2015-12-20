#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterLeavingString(string &s1, string &s2, string &s3);

int main()
{
	int i = 0x99DE38E8;
	cout << i << endl;
	cout << INT_MAX << endl;
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	cout << isInterLeavingString(s1, s2, s3) << endl;
	return 0;
}

bool isInterLeavingString(string &s1, string &s2, string &s3)
{
	if (s3.length() != s1.length() + s2.length())
		return false;

	vector<vector<bool>> f(s1.length() + 1, vector<bool>(s2.length() + 1, true));

	for (int i = 1; i <= s1.length(); ++i)
	{
		f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
	}

	for (int j = 1; j <= s2.length(); ++j)
	{
		f[0][j] = f[0][j - 1] && s2[j - 1] == s3[j - 1];
	}

	for (int i = 1; i <= s1.length(); ++i)
	{
		for (int j = 1; j <= s2.length(); ++j)
		{
			f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[i + j - 1])
				|| (f[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
		}
	}

	return f[s1.length()][s2.length()];
}