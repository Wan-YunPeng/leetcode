#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generator(int n);
void dfs(vector<string> &re, string s, int left, int right);
void dfs(vector<string> &re, string s, int left, int right, int n);


int main()
{
	int n = 3;
	vector<string> re = generator(n);
	for (auto& s : re)
		cout << s << endl;
	return 0;
}

vector<string> generator(int n)
{
	vector<string> re;
	string s = "";
	//dfs(re, s, n, n);
	dfs(re, s, 0, 0, n);
	return re;
}


void dfs(vector<string> &re, string s, int left, int right, int n)
{
	if (left == n)
	{
		re.push_back(s.append(n - right, ')'));
		return;
	}

	dfs(re, s + '(', left + 1, right, n);
	if (left > right) dfs(re, s + ')', left, right + 1, n);
}



void dfs(vector<string> &re, string s, int left, int right)
{
	if (left == 0 && right == 0)
	{
		re.push_back(s);
		return;
	}

	if (left == right) // 只能放左括号
		dfs(re, s + '(', left - 1, right);

	if (left == 0 && right > 0) // 只能放右括号
		dfs(re, s + ')', left, right - 1);

	if (right > left && left > 0) // 当前左括号比右括号多
	{
		dfs(re, s + '(', left - 1, right); // 继续放入一个左括号
		dfs(re, s + ')', left, right - 1); // 或者放入一个右括号
	}
	
}