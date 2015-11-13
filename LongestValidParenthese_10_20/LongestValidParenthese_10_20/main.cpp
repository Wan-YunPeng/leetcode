#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParenthese(string s);
void subValidParenthese(string s, int& max, int &tmp);

int longestValidParenthese2(string s);

int main()
{
	string s = "(())";
	//cout << s.substr(2, s.size() - 2) << endl;
	int re = longestValidParenthese(s);
	cout << re << endl;
	re = longestValidParenthese2(s);
	cout << re << endl;
	return 0;
}

int longestValidParenthese(string s)
{
	if (s.empty() || s.size() == 1) return 0;

	int max_length = 0, tmp_length = 0;
	subValidParenthese(s, max_length, tmp_length);
	return max_length;	
}

void subValidParenthese(string s, int& max, int &tmp)
{
	if (s.empty() || s.size() == 1) return;

	if (s[0] == '(' && s[1] == ')')
	{
		tmp = tmp + 2;
		if (tmp > max)
			max = tmp;
		if (s.size() > 2)
			subValidParenthese(s.substr(2, s.size() - 2),max,tmp);
	}
	else
	{
		tmp = 0; 
		subValidParenthese(s.substr(1, s.size() - 1), max, tmp);
	}
}

int longestValidParenthese2(string s)
{
	int max_len = 0;
	int last = -1; // 上次‘)’的位置
	stack<char> lefts; // 存储所有非匹配的‘(’

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			lefts.push(i);
		else{
			if (lefts.empty())
				// 没有匹配的‘）’
				last = i;
			else{
				// 找到匹配的‘（’; 判断是否为连续匹配
				lefts.pop();
				if (lefts.empty())
					max_len = max(max_len, i - last);
				else
					max_len = max(max_len, i - lefts.top());
			}
		}
	}
	return max_len;
}