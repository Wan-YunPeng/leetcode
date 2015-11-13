#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

int ladderLength(const string &start, const string &end, const unordered_set<string> &dict);

int main()
{
	unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
	// cout << *dict.begin() << endl;
	string start = "hit", end = "cog";
	int re = ladderLength(start, end, dict);
	cout << re << endl;
	return 0;
}

int ladderLength(const string &start, const string &end, const unordered_set<string> &dict)
{
	queue<string> current, next; // 当前层和下一层
	unordered_set<string> visited;

	int level = 0;
	bool found = false;

	auto state_is_target = [&](const string &s){return s == end; };
	auto state_extend = [&](const string &s)
	{
		cout << s << endl;
		vector<string> result;

		for (size_t i = 0; i < s.size(); ++i)
		{
			string new_word(s);
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (new_word[i] == c) continue;

				swap(c, new_word[i]);

				if (dict.count(new_word) > 0 && !visited.count(new_word) || new_word == end)
				{
					result.push_back(new_word);
					visited.insert(new_word);
				}

				swap(c, new_word[i]);

			}
		}
		return result;
	};

	current.push(start);
	while (!current.empty() && !found)
	{
		++level;
		while (!current.empty() && !found)
		{
			const string str = current.front();
			current.pop();

			const auto &new_states = state_extend(str);
			for (const auto &state : new_states)
			{
				next.push(state);
				if (state_is_target(state))
				{
					found = true;
					break;
				}
			}
			
		}
		swap(next, current);
	}
	if (found) return level + 1;
	else return 0;
}