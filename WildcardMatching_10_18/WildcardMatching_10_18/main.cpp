#include <iostream>

using namespace std;

bool isMatch(const char *s, const char *p);

// 迭代版
bool isMatch2(const char *s, const char *p);

int main()
{
	char *s = "aabbc";
	char *p = "*b*c";
	bool is = isMatch2(s, p);
	cout << s << " is matching with " << p << " is: " << is << endl;
	return 0;
}

bool isMatch(const char *s, const char *p)
{
	if (*p == '\0') return *s == '\0';

	if (*p == '?' || *p == *s)
		isMatch(s + 1, p + 1);
	else if (*p == '*')
	{
		while (*s != '\0')
		{
			if (isMatch(s + 1, p + 1))
				return true;
			s++;
		}
	}
	else
		return false;
}

bool isMatch2(const char *s, const char *p)
{
	const char *str, *ptr;
	bool star = false; // 当前比较的元素前面有没有*

	for (str = s, ptr = p; *str != '\0'; ++str, ++ptr)
	{
		switch (*ptr)
		{
		case '?':
			break;
		case '*':
			star = true;
			s = str;
			p = ptr;
			while (*p == '*') ++p;
			if (*p == '\0') return true;
			str = s - 1;
			ptr = p - 1;
			break;
		default:
			if (*str != *ptr)
			{
				if (!star) return false;
				++s;
				str = s - 1;
				ptr = p - 1;
			}
			break;
		}
	}
	while (*ptr == '*') ptr++;
	return (*ptr == '\0');
}