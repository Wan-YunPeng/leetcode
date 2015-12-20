#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 越界后用string计算
bool isAdditiveNumber(string num);
bool dfs(const string &num, int i, const int len, vector<long long> &path);
bool isValid(vector<int> &number, vector<vector<int>> &path);
bool large(vector<int> &number, vector<vector<int>> &path);

int main()
{
	string s = "121474836472147483648";
	cout << isAdditiveNumber(s) << endl;
	return 0;
}

bool isAdditiveNumber(string num) {
	if (num.empty() || num.size() < 3) return false;
	vector<long long> path;
	return dfs(num, 0, num.size(), path);
}

bool dfs(const string &num, int i, const int len, vector<long long> &path)
{
	if (i == num.size() && path.size() > 2)
	{
		return true;
	}

	if (num[i] == '0' && path.size() < 2)
	{
		path.push_back(0);
		bool re = dfs(num, i + 1,len, path);
		path.pop_back();
		return re;
	}
	else if (num[i] == '0' && path.size() >= 2)
	{
		return false;
	}

	long long number = 0;
	for (int n = i; n < len; ++n)
	{
		if (number > LLONG_MAX / 10 || (number == LLONG_MAX / 10 && (num[n] - '0') > LLONG_MAX % 10)) // 越界
			return false;

		number = number * 10 + (num[n] - '0');
	
		if (path.size() >= 2)
		{
			if (number == path[path.size() - 1] + path[path.size() - 2])
			{
				
				path.push_back(number);
				bool re = dfs(num, n + 1,len, path);
				path.pop_back();
				if (re)
					return true;
			}
			else if (number > path[path.size() - 1] + path[path.size() - 2])
				return false;
		}
		else
		{
			path.push_back(number);
			bool re = dfs(num, n + 1, len, path);
			path.pop_back();
			if (re)
				return true;
		}
	}
	return false;
}