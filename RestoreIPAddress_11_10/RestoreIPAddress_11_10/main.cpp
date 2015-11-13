#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> restoreIP(const string &s);
void dfs(const string &s,vector<string> &re, string ip, size_t start, size_t step);

int main()
{
	vector<string> re = restoreIP("000112");
	for (const auto& s : re)
		cout << s << endl;
	return 0;
}

vector<string> restoreIP(const string &s)
{
	vector<string> re;
	string ip;
	dfs(s, re, ip, 0, 0);
	return re;
}

void dfs(const string &s, vector<string> &re, string ip, size_t start, size_t step)
{
	if (start == s.size() && step == 4)
	{
		ip.resize(ip.size() - 1);
		re.push_back(ip);
		return;
	}

	if (s.size() - start > (4 - step) * 3) return;
	if (s.size() - start < (4 - step)) return;

	int num = 0;
	for (int i = start; i < s.size(); ++i)
	{
		num = num * 10 + s[i] - '0';

		if (num <= 255) // 第一个0被允许
		{
			ip += s[i];
			dfs(s, re, ip + '.', i + 1, step + 1);
		}

		if (num == 0) return; // 不允许前缀为0，但允许单个0
	}
}