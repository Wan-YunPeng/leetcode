#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

bool wordBreak(unordered_set<string> &dict, string s);

int main()
{
	unordered_set<string> dict = { "leet", "code", "good" };
	string s = "leetcode";
	cout << wordBreak(dict, s) << endl;
	return 0;
}

bool wordBreak(unordered_set<string> &dict, string s)
{
	vector<bool> f(s.size() + 1, false);
	f[0] = true;

	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (f[j] && dict.find(s.substr(j, i - j)) != dict.end())
			{
				f[i] = true;
				break;
			}
		}
	}
	return f[s.size()];
}