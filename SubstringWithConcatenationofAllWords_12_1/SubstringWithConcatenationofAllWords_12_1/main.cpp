#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string> &dict);

int main()
{
	string s = "barfoothefoobarmanfoobarbar";
	vector<string> dict = { "foo", "bar" };
	vector<int> re = findSubstring(s, dict);
	for (auto &i : re)
		cout << i << endl;
	return 0;
}

vector<int> findSubstring(string s, vector<string> &dict)
{
	size_t wordLength = dict.front().size(); // 单词长度
	size_t catLength = wordLength * dict.size(); // 要寻找的单词总长度
	vector<int> re;

	if (s.size() < catLength) return re;

	unordered_map<string, int> wordCount;

	for (const auto &s : dict)
		wordCount[s]++;

	for (auto i = begin(s); i <= prev(end(s), catLength); ++i)
	{
		unordered_map<string, int> unused(wordCount);

		for (auto j = i; j != next(i, catLength); j += wordLength)
		{
			auto pos = unused.find(string(j, next(j, wordLength)));

			if (pos == unused.end() || pos->second == 0) break;

			if (--pos->second == 0) unused.erase(pos);
		}
		if (unused.size() == 0)
			re.push_back(distance(begin(s), i));
	}
	return re;
}