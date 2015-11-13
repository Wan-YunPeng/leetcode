#include <iostream>
#include <string>

using namespace std;

// 暴力破解法
char *strStr(const char *haystack, const char *needle);

// kmp算法，失配时，向后跳跃一定步数
char *strStr2(const char*haystack, const char *needle);
void compute_prefix(const char *pattern, int next[]);
int kmp(const char *text, const char *pattern);

int main()
{
	char *p1 = "ddabcee";
	char *p2 = "abc";
	char *re = strStr(p1, p2);
	if (re)
		cout << *re << endl;
	else
		cout << "aa" << endl;
	return 0;
}

char *strStr(const char *haystack, const char *needle)
{
	// if needle is empty return the full string
	if (!*needle) return (char*)haystack;

	const char* p1 = haystack;
	const char* p2 = needle;
	const char* p1_advance = haystack;

	for (p2 = &needle[1]; *p2; p2++)
		p1_advance++;

	while (*p1_advance)
	{
		char *p1_old = (char*)p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2)
		{
			++p1;
			++p2;
		}
		if (!*p2) return p1_old;

		p1 = p1_old + 1;
		p1_advance++;
	}

	return nullptr;

}

// kmp算法，失配时，向后跳跃一定步数
char *strStr2(const char*haystack, const char *needle)
{
	int pos = kmp(haystack, needle);
	if (pos == -1) return nullptr;
	else
		return (char*)haystack + pos;
}

// 计算各个元素的next
void compute_prefix(const char *pattern, int next[])
{
	int i, j = -1;
	const int m = strlen(pattern);

	next[0] = j;
	for (i = 1; i < m; ++i)
	{
		while (j > -1 && pattern[i] != pattern[j + 1]) j = next[j]; // 向后失配，next[j]的部分与i进行比较；视为一次自己与自己的匹配

		if (pattern[i] == pattern[j + 1]) ++j;
		next[i] = j;
	}
}
int kmp(const char *text, const char *pattern)
{
	int i, j = -1;
	const int n = strlen(text);
	const int m = strlen(pattern);
	if (n == 0 && m == 0) return 0;
	if (m == 0) return 0;
	int *next = (int*)malloc(sizeof(int)* m);

	compute_prefix(pattern, next);

	for (i = 0; i < n; ++i)
	{
		while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
		if (pattern[i] == text[j + 1]) j++;
		if (j == m - 1)
		{
			free(next);
			return i - j;
		}
	}

	free(next);
	return -1;
}