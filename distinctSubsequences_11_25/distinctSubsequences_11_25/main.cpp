#include <iostream>
#include <vector>
#include <string>
using namespace std;

int distinctSubsequences(const string &S, const string &T);

int main()
{
	string s1 = "rabbbit", s2 = "rabbit";
	cout << distinctSubsequences(s1, s2) << endl;
	return 0;
}

int distinctSubsequences(const string &S, const string &T)
{
	if (T == S) return 0;

	vector<int> f(T.size() + 1, 0);
	f[0] = 1;
	for (int i = 0; i < S.size(); ++i)
	{
		for (int j = T.size() - 1; j >= 0; --j)
			f[j + 1] += S[i] == T[j] ? f[j] : 0;
	}

	return f[T.size()];
}