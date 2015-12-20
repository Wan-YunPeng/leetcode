#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> bigint;

string multiply(string num1, string num2);
bigint make_bigint(string num);
bigint operator*(bigint const &num1, bigint const &num2);
string to_string(bigint const &num);

int main()
{
	string n1 = "3123", n2 = "123123";
	cout << multiply(n1, n2) << endl;
	cout << 3123 * 123123 << endl;
	return 0;
}

string multiply(string num1, string num2)
{
	return to_string(make_bigint(num1) * make_bigint(num2));
}

bigint make_bigint(string num)
{
	bigint re;
	for (int i = num.size() - 1; i >= 0; --i)
	{
		re.push_back(num[i] - '0');
	}
	return re;
}

bigint operator*(bigint const &num1, bigint const &num2)
{
	bigint re(num1.size() + num2.size());
	// 个位到最大位
	for (size_t i = 0; i < num1.size(); ++i)
	{
		for (size_t j = 0; j < num2.size(); ++j)
		{
			re[i + j] += num1[i] * num2[j];
			re[i + j + 1] += re[i + j] / 10;
			re[i + j] %= 10;
		}
	}
	return re;
}

string to_string(bigint const &num)
{
	string str;
	transform(find_if(num.rbegin(), prev(num.rend()),
		[](char c){ return c > '\0'; }), num.rend(), back_inserter(str),
		[](char c){return c + '0'; });
	return str;
}
