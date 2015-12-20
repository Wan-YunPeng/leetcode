#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

vector<string> wordBreak(unordered_set<string> &dict, string s);
void gen_path(const string &s, const vector<vector<bool>> &prev, int cur, vector<string> &path, vector<string> &result);

int main()
{
	unordered_set<string> dict = { "cat", "cats", "and", "sand", "dog" };
	string s = "catsanddog";
	vector<string> re = wordBreak(dict, s);
	for (auto &s : re)
		cout << s << endl;
	return 0;
}


vector<string> wordBreak(unordered_set<string> &dict, string s)
{
	vector<bool> f(s.size() + 1, false);
	// prev[i][j]表示s[j,i)是一个合法的单词，可以从j出切开
	vector<vector<bool>> prev(s.length() + 1, vector<bool>(s.length()));
	f[0] = true;
	for (int i = 1; i <= s.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (f[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
			{
				f[i] = true;
				prev[i][j] = true;
			}
		}
	}
	vector<string> path;
	vector<string> re;
	gen_path(s, prev, s.size(), path, re);
	return re;
}


void gen_path(const string &s, const vector<vector<bool>> &prev, int cur, vector<string> &path, vector<string> &result)
{
	if (cur == 0)
	{
		string tmp;
		for (auto itr = path.crbegin(); itr != path.crend(); ++itr)
			tmp += *itr + " ";
		tmp.erase(tmp.end() - 1);
		result.push_back(tmp);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (prev[cur][i])
		{
			path.push_back(s.substr(i, cur - i));
			gen_path(s, prev, i, path, result);
			path.pop_back();
		}
	}
}