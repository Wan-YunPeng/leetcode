#include <iostream>
#include <vector>
using namespace std;

int decode(const string &s);
int decodeWays(const string &s);

int main()
{
	string s = "102";
	cout << decodeWays(s) << endl;
	return 0;
}

int decode(const string &s)
{
	if (s.empty() || s[0] == '0') return 0;
	vector<int> f(s.size() + 1, 0);
	f[0] = 1; f[1] = 1;
	for (int i = 2; i <= s.size(); ++i)
	{
		if (s[i - 1] != 0)
			f[i] = f[i - 1];
		else
			f[i] = 0;
		if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
			f[i] += f[i - 2];
	}
	for (auto i : f)
		cout << i << "  ";
	cout << endl;
	return f.back();
}

int decodeWays(const string &s)
{
	if (s.empty() || s[0] == '0') return 0;
	int prev = 0;
	int cur = 1;
	for (int i = 1; i <= s.size(); ++i)
	{
		if (s[i - 1] == '0')
			cur = 0;

		if (i < 2 || !(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')) // 不能与前面的数字构成一个有效字母
			prev = 0;

		int tmp = cur;
		cur = cur + prev;
		prev = tmp;
	}
	return cur;
}