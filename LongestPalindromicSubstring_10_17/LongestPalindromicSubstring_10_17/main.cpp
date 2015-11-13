#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestPalindromic(string s);

// transform S into T.
// For instance, S = "aba", T = "^#a#b#c#$"
// ^ and $ signs are sentinels appended to each end to avoid bounds checking.
string preProcess(string s);
string longestPalindromic2(string s);

int main()
{
	
	string const  s("aaaaabbbbaaa");
	cout << sizeof(s[0]) << " " << sizeof(s.substr(0, 1))<<endl;
	string a = "bb";
	a += "a" + 'b'; cout << a << endl;
	// cout << "#" + 'a' << endl;
	//const int n = s.size();
	//int a[n];  // n的值在编译期间不能确定
	//int *a = new int[n];
	cout << s << endl;
	string re = longestPalindromic2(s);
	cout << re << endl;
	return 0;
}

string longestPalindromic(string s)
{
	const int n = s.size();
	/*bool **f;
	f = new bool*[n];
	f[0] = new bool[n * n];
	for (size_t i = 1; i < n; ++i)
		f[i] = f[i - 1] + n;
	fill_n(f, n * n, false);*/
	// 用
	vector<vector<bool> > f(n, vector<bool>(n, false)); 
	// 会超时
	size_t max_len = 1, start = 0; // 最长回文字串的长度， 起点

	for (size_t i = 0; i < s.size(); ++i)
	{
		f[i][i] = true;
		for (size_t j = 0; j < i; ++j) // [j,i]
		{
			f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
			if (f[j][i] && max_len < i - j + 1)
			{
				max_len = i - j + 1;
				start = j;
			}
		}
	}
	/*for (size_t i = 0; i < n; ++i)
		delete[] f[i];
	delete[] f;*/
	return s.substr(start, max_len);
}

string preProcess(string s)
{
	int n = s.size();
	if (n == 0) return "^$";

	string ret = "^";
	for (int i = 0; i < n; ++i){
		ret += "#" + s.substr(i, 1);
		
	}
	ret += "#$";
	return ret;
}

string longestPalindromic2(string s)
{
	string T = preProcess(s);
	const int n = T.length(); 
	cout << T << endl;
	// 以T[i]为中心，向左/向右扩张的长度，不包含T[i]自己，
	// 因此P[i]是源字符串中以i为中心回文串的长度
	int *P = new int[n];
	//vector<int> P(n, 0);
	int C = 0, R = 0;

	for (int i = 1; i < n - 1; ++i)
	{
		int i_mirror = 2 * C - i; // equals to i` = C - （i - C）

		P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

		// Attempt to expand palindrome centered at i
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) ++P[i];

		// if palindorme centered at i expand past R,
		// adjust center based on expanded palindrome
		if (i + P[i] > R)
		{
			C = i;
			R = i + P[i];
		}
	}

	// find the maximum element in P
	int max_len = 0;
	int center_index = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		if (P[i] > max_len)
		{
			max_len = P[i];
			center_index = i;
		}
	}
	delete[] P;
	return s.substr((center_index - 1 - max_len) / 2, max_len);
}