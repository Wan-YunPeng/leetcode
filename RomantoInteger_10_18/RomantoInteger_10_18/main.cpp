#include <iostream>

using namespace std;

int romanToInt(string roman);
inline int map(const char c);

int main()
{
	string a = "MCMI";
	int re = romanToInt(a);
	cout << re << endl;
	return 0;
}

inline int map(const char c)
{
	switch (c)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	default: return 0;
	}
}

int romanToInt(string roman)
{
	int result = 0;
	for (size_t i = 0; i < roman.size(); ++i)
	{
		if (i > 0 && map(roman[i]) > map(roman[i - 1]))
			result += (map(roman[i]) - 2 * map(roman[i - 1]));
		else
			result += map(roman[i]);
	}
	return result;
}