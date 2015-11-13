#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> anagrams(vector<string> &strs);

int main()
{
	string s[] = { "dormitory", "dirtyroom", "tea", "eat", "aa" }; // 空格会使dormitory 和 dirty room不相等
	vector<string> vs(s, s + 5);
	vector<string> re = anagrams(vs);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<string> anagrams(vector<string> &strs)
{
	unordered_map<string, vector<string>> group;
	for (int i = 0; i < strs.size(); ++i)
	{
		string key = strs[i];
		sort(key.begin(), key.end());
		group[key].push_back(strs[i]);
	}
	vector<string> result;
	for (auto it = group.cbegin(); it != group.cend(); ++it)
	{
		if (it->second.size()>1)
			result.insert(result.end(), it->second.begin(), it->second.end());
	}
	return result;
}