#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombine(string digits);
void dfs(vector<string> &re, string &p, string digits, size_t cur);
vector<string> keyboard({ " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" });
int main()
{
	string digits = "213";
	vector<string> re = letterCombine(digits);
	for (auto s : re)
		cout << s << "   ";
	cout << endl;
	return 0;
}

vector<string> letterCombine(string digits)
{
	vector<string> re;
	string p;
	dfs(re, p, digits, 0);
	return re;
}

void dfs(vector<string> &re, string &p, string digits, size_t cur)
{
	while (digits.substr(cur, 1) == "1")
	{
		cur++;
	}

	if (cur == digits.size())
	{
		re.push_back(p);
		return;
	}

	for (auto c : keyboard[digits[cur] - '0'])
	{
		dfs(re, p + c, digits, cur + 1);
	}
}