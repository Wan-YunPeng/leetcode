#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> ladder(const string &start, const string &end, const unordered_set<string> &dict);
void gen_path(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &end, vector<vector<string>> &re);

int main()
{
	unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
	string start = "hit", end = "cog";
	vector<vector<string>> re = ladder(start, end, dict);
	for (auto elem : re)
	{
		for (auto s : elem)
			cout << s << "  ";
		cout << endl;
	}
	return 0;
}

vector<vector<string>> ladder(const string &start, const string &end, const unordered_set<string> &dict)
{
	vector<vector<string>> result;
	unordered_set<string> current, next; // 当前层和下一层， 集合去重
	unordered_map<string, vector<string> > father; // 树，记录该string的所有父节点字符
	unordered_set<string> visited; // 去重

	bool found = false;

	auto state_is_found = [&](const string &s){return s == end; };
	auto state_extend = [&](const string &s)
	{
		vector<string> re;
		
		for (int i = 0; i < s.size(); ++i)
		{
			string new_word(s);
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (new_word[i] == c) continue;

				swap(c, new_word[i]);

				if ((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word))
					re.push_back(new_word);

				swap(c, new_word[i]);
			}
		}
		return re;
	};

	current.insert(start);
	while (!current.empty() && !found)
	{
		// 将本层全部指定为已访问，以防止同层之间相互指向
		for (const auto& word : current)
			visited.insert(word);

		for (const auto& word : current)
		{
			const auto new_states = state_extend(word);
			for (const auto& state : new_states)
			{
				if (state_is_found(state)) found = true;
				next.insert(state);
				father[state].push_back(word);
			}
		}
		current.clear();
		swap(current, next);
	}
	if (found)
	{
		vector<string> path;
		gen_path(father, path, start, end, result);
	}
	return result;
}

void gen_path(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &word, vector<vector<string>> &re)
{
	path.push_back(word);
	if (word == start)
	{
		re.push_back(path);
		reverse(re.back().begin(), re.back().end());
	}
	else
	{
		for (const auto& f : father[word])
		{
			gen_path(father, path, start, f, re);
		}
	}
	path.pop_back();
}