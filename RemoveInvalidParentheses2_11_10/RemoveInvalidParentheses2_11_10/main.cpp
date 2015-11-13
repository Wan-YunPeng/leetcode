#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> removeInvalidParentheses(const string &s);
void remove(const string &s, vector<string> &re, vector<int> &path, int start, int left_removed, int right_removed);
bool isValid(const string &s);

int main()
{
	string s = ")(((()(y((u()(z()()";
	//string s = "i))((()(n(())i((((";
	vector<string> re = removeInvalidParentheses(s);
	cout << endl << "----------------------------" << endl;
	for (auto elems : re)
	{
		cout << elems << endl;
	}
	return 0;
}


vector<string> removeInvalidParentheses(const string &s)
{
	int left_removed = 0, right_removed = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			left_removed++;
		else if (s[i] == ')')
		{
			if (left_removed)
				left_removed--;
			else
				right_removed++; // 肯定要被移除的右括号： )().
		}
	}

	vector<int> path;
	vector<string> re;
	remove(s, re, path, 0, left_removed, right_removed);
	return re;
}

void remove(const string &s, vector<string> &re, vector<int> &path, int start, int left_removed, int right_removed)
{
	if (left_removed == 0 && right_removed == 0)
	{
		string tmp;
		for (int i = 0, j = 0; i < s.size(); ++i)
		{
			if (j < path.size() && i == path[j])
				j++;
			else
				tmp.push_back(s[i]);
		}

		if (isValid(tmp))
			re.emplace_back(tmp);
	}

	for (int i = start; i < s.size(); ++i) 
	{
		if (right_removed == 0 && left_removed > 0 && s[i] == '(') // 移除左括号
		{
			if (i == start || s[i] != s[i - 1]) // 跳过重复部分--->若相同，下一次remove会处理，本次不处理，节约时间
			{
				path.push_back(i);
				remove(s, re, path, i + 1, left_removed - 1, right_removed);
				path.pop_back();
			}
		}
		else if (right_removed > 0 && s[i] == ')')
		{
			if (i == start || s[i] != s[i - 1]) // 去掉结果中重复的部分， 如(()的情况下，去掉第一个和去掉第二个所得结果相同，顾不再处理去掉第二个的情况
			{
				path.push_back(i);
				remove(s, re, path, i + 1, left_removed, right_removed - 1);
				path.pop_back();
			}
		}
	}
}


bool isValid(const string &s)
{
	int sum = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			sum++;
		else if (s[i] == ')')
		{
			sum--;
		}

		if(sum < 0)
			return false;
	}
	return sum == 0;
}