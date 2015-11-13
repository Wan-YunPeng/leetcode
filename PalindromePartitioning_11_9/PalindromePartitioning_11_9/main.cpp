#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string>> partition(const string &s);
void dfs(const string &s, vector<vector<string>> &re, vector<string> &path, size_t prev, size_t start);
bool isPanlidrome(const string &s, int start, int end);
void dfs(const string &s, vector<vector<string>> &re, vector<string> &path, int start);

int main()
{
	const string s = "aabba";
	vector<vector<string>> re = partition(s);
	for (const auto& v : re)
	{
		for (const auto& s : v)
			cout << s << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<string>> partition(const string &s)
{
	vector<vector<string>> re;
	vector<string> path;
	dfs(s, re, path, 0);
	return re;
}

void dfs(const string &s, vector<vector<string>> &re, vector<string> &path, size_t prev, size_t start) // 将start视为刀（所切的地方）
{
	if (start == s.size())
	{
		if (isPanlidrome(s, prev, start - 1))
		{
			path.push_back(s.substr(prev, start - prev));
			re.push_back(path);
			path.pop_back(); // 回溯
		}
		return;
	}

	dfs(s, re, path, prev, start + 1); // 不将前面的回文断开
	if (isPanlidrome(s, prev, start - 1))
	{
		path.push_back(s.substr(prev, start - prev));
		dfs(s, re, path, start, start + 1);
		path.pop_back();
	}
}

bool isPanlidrome(const string &s, int start, int end)
{
	while (start < end && s[start] == s[end])
	{
		++start;
		--end;
	}
	return start >= end;
}

void dfs(const string &s, vector<vector<string>> &re, vector<string> &path, int start)
{
	if (start == s.size())
	{
		re.push_back(path);
		return;
	}

	for (int i = start; i < s.size(); ++i)
	{
		if (isPanlidrome(s, start, i)) // 从i位置砍一刀
		{
			path.push_back(s.substr(start, i - start + 1));
			dfs(s, re, path, i + 1);
			path.pop_back();
		}
	}
}