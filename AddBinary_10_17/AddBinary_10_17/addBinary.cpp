#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b);

int main()
{
	string a("11");
	string b("1");
	string c = addBinary(a, b);
	cout << c << endl;
	return 0;
}

string addBinary(string a, string b)
{
	if (!a.size() || a == "0") return b;
	if (!b.size() || b == "0") return a;
	string re;
	const size_t n = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (int i = 0; i < n; ++i)
	{
		const int ai = i < a.size() ? a[i] - '0' : 0;
		const int bi = i < b.size() ? b[i] - '0' : 0;
		const int val = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		re.insert(re.begin(), val + '0');
	}
	if (carry == 1)
		re.insert(re.begin(), '1');
	return re;
}