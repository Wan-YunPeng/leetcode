#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestSubstring(const string &s);

int main()
{
	string s = "qpxrjxkltzyx";
	cout << longestSubstring(s) << endl;
	return 0;
}

// 大小写？只含26个英文字母？
int longestSubstring(const string &s)
{
	if (s.empty() || s.size() == 1) return s.empty() ? s.empty() : 1;

	int last[26]; // 记录字符上次出现的位置
	int start = 0; // 记录当前字符串的起始位置

	memset(last, -1, 26);
	int max_len = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (last[s[i] - 'a'] >= start)
		{
			max_len = max(i - start, max_len);
			start = last[s[i] - 'a'] + 1;
		}
		last[s[i] - 'a'] = i;
	}

	return max(static_cast<int>(s.size()) - start, max_len);
}