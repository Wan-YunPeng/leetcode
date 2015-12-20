#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool panlindromeNumber(int n);
bool isPanlindrome(int n);

int main()
{
	int i = 1233321;
	cout << panlindromeNumber(i) << endl;
	cout << isPanlindrome(i) << endl;
	return 0;
}

bool panlindromeNumber(int n)
{
	if (n < 0)
		n *= -1;
	if (n = 0)
		return true;
	stringstream ss;
	ss << n;
	string s;
	ss >> s;
	auto start = s.begin(), end = s.end() - 1;
	while (start < end)
	{
		if (*start != *end)
			return false;
		start++;
		end--;
	}
	return true;
}

bool isPanlindrome(int n)
{
	int d = 1, tmp = n;
	while (tmp / 10)
	{
		d *= 10;
		tmp /= 10;
	}
	int k = 0, m = 0;
	while (n > 0)
	{
		k = n % 10;
		m = n / d;
		if (k != m)
			return false;
		n %= d;
		n /= 10;
		d /= 100;
	}
	return true;
}