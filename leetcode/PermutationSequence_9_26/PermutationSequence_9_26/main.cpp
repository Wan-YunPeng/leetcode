#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
 
string solution1(int n, int k);
string getPermutation(int n, int k);
int factorial(int n);
template<typename Sequence>
Sequence kth_permutation(const Sequence& seq, int k);

int main()
{
	string re = solution1(3, 3);
	cout << re << endl;
	re = getPermutation(3, 3);
	cout << re << endl;
	return 0;
}

string solution1(int n, int k)
{
	string s(n, '0');
	for (int i = 0; i < n; ++i)
		s[i] += i + 1;
	for (int i = 0; i < k - 1; ++i)
		next_permutation(s.begin(), s.end());
	return s;
}

string getPermutation(int n, int k)
{
	string s(n, '0');
	for (int i = 0; i < s.size(); ++i)
		s[i] += i + 1;
	return kth_permutation(s, k);
}

int factorial(int n)
{
	if (n == 0) return 1;
	int result = 1;
	for (int i = 1; i <= n; ++i)
		result *= i;
	return result;
}

template<typename Sequence>
Sequence kth_permutation(const Sequence& seq, int k)
{
	const int n = seq.size();
	Sequence S(seq);
	Sequence re;

	int base = factorial(n - 1);
	--k; // 康托编码从0开始，下标减一

	for (int i = n - 1; i > 0; k %= base, base /= i, --i)
	{
		auto a = next(S.begin(), k / base); // a为第k次排序第一个元素在初始序列中的下标
		re.push_back(*a);
		S.erase(a);
	}

	re.push_back(S[0]);
	return re;
}