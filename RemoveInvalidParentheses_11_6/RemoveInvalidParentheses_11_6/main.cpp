#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string &s)
	{
		vector<string> re;
		deque<string> q;
		q.push_back(s);
		bool isfind = false;

		while (!q.empty())
		{
			string tmp = q.front();
			q.pop_front();

			if (validParentheses(tmp))
			{
				re.push_back(tmp);
				isfind = true;
			}

			if (isfind) // 已经找到，就不用在拆分了,长度固定
				continue;

			for (int i = 0; i < tmp.size(); ++i)
			{
				if (tmp[i] != '(' && tmp[i] != ')')
					continue;
				string next = tmp;
				next.erase(i, 1);
				// set
				if (find(q.begin(), q.end(), next) == q.end())
					q.push_back(next);
			}
				
		}
		return re;
	}
	bool validParentheses(string s) {
		cout << s << endl;
		int sum = 0;
		for (const auto &c : s) {
			if (c == '(') {
				++sum;
			}
			else if (c == ')') {
				--sum;
			}
			if (sum < 0) {
				return false;
			}
		}
		return sum == 0;
	}
};


// DFS solution with removed array. (4ms)
class Solution2 {
public:
	vector<string> removeInvalidParentheses(string s)  {
		int left_removed = 0, right_removed = 0;
		findMinRemove(s, &left_removed, &right_removed);

		vector<string> res;
		vector<int> removed;
		removeInvalidParenthesesHelper(s, 0, left_removed, right_removed, &removed, &res);
		return res;
	}

private:
	void findMinRemove(const string& s, int *left_removed, int *right_removed) {
		// Calculate the minimum left and right parantheses to remove.
		for (const auto& c : s) {
			if (c == '(') {
				++(*left_removed);
			}
			else if (c == ')') {
				if (!(*left_removed)) { // left_removed为0
					++(*right_removed);
				}
				else {
					--(*left_removed);
				}
			}
		}
	}

	void removeInvalidParenthesesHelper(const string& s, int start,
		int left_removed, int right_removed,
		vector<int> *removed, vector<string> *res) {

		if (left_removed == 0 && right_removed == 0) { // left_removed 和 right_removed全为0
			string tmp;
			for (int i = 0, j = 0; i < s.length(); ++i) {
				if (j < removed->size() && i == (*removed)[j]) {
					++j;
				}
				else {
					tmp.push_back(s[i]);
				}
			}
			if (isValid(tmp)) {
				res->emplace_back(tmp); //避免额外类的复制和移动操作.
			}
			return;
		}

		for (int i = start; i < s.length(); ++i) {
			if (right_removed == 0 && left_removed > 0 && s[i] == '(') { // 左括号多了且开始为左括号
				if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
					removed->emplace_back(i);
					removeInvalidParenthesesHelper(s, i + 1, left_removed - 1, right_removed,
						removed, res);
					removed->pop_back();
				}
			}
			else if (right_removed > 0 && s[i] == ')') {
				if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
					removed->emplace_back(i);
					removeInvalidParenthesesHelper(s, i + 1, left_removed, right_removed - 1,
						removed, res);
					removed->pop_back();
				}
			}

		}
	}

	// Check whether s is valid or not.
	bool isValid(string s) {
		cout << s << endl;
		int sum = 0;
		for (const auto &c : s) {
			if (c == '(') {
				++sum;
			}
			else if (c == ')') {
				--sum;
			}
			if (sum < 0) {
				return false;
			}
		}
		return sum == 0;
	}
};

int main()
{
	string s = ")(((()(y((u()(z()()";
	//string s = "i))((()(n(())i((((";
	Solution2 solu;
	vector<string> re = solu.removeInvalidParentheses(s);
	cout << endl << "----------------------------" << endl;
	for (auto elems : re)
	{
		cout << elems << endl;
	}
	//cout << solu.validParentheses(s) << endl;
}