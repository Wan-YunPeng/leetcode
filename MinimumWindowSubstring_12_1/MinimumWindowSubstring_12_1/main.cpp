#include <iostream>
#include <string>
#define ASCII_MAX 256

using namespace std;

string minimumWindow(string S, string T);

int main()
{
	string S = "DADOBECODEBANC", T = "ABC";
	cout << minimumWindow(S, T) << endl;
	return 0;
}

string minimumWindow(string S, string T)
{
	if (S.empty()) return "";
	if (S.size() < T.size()) return "";

	int expected_count[ASCII_MAX];
	int appeared_count[ASCII_MAX];
	fill(expected_count, expected_count + ASCII_MAX, 0);
	fill(appeared_count, appeared_count + ASCII_MAX, 0);

	for (int i = 0; i < T.size(); ++i)
		expected_count[T[i]]++;

	int wnd_start = 0, min_start = 0; //窗口大小的起点和最小窗口的起点
	int minWnd = INT_MAX;
	int appeared = 0; // 统计出现的个数

	for (int wnd_end = 0; wnd_end < S.size(); wnd_end++)
	{
		if (expected_count[S[wnd_end]] > 0)
		{
			appeared_count[S[wnd_end]]++;
			if (appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]])
				appeared++;

		}
		if (appeared == T.size())// 完整包含一个T
		{
			// 收缩头指针
			while ((appeared_count[S[wnd_start]] > expected_count[S[wnd_start]]) ||
				expected_count[S[wnd_start]] == 0)
			{
				appeared_count[S[wnd_start]]--;
				wnd_start++;
			}

			if (minWnd > wnd_end - wnd_start + 1)
			{
				minWnd = wnd_end - wnd_start + 1;
				min_start = wnd_start;
			}
		}
	}

	if (minWnd == INT_MAX) return "";
	return S.substr(min_start, minWnd);
}