#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestPrefix(vector<string> A);

// 横向
string longestPrefix2(vector<string> A);

int main()
{
	string A[] = {"aabbbcc","aa","aacd"};
	vector<string> B(A, A + 3);
	string re = longestPrefix2(B);
	cout << re << endl;
	return 0;
}
// 
string longestPrefix(vector<string> A)
{
	if (A.empty()) return "";

	for (int idx = 0; idx < A[0].size(); ++idx)
	{
		for (int i = 1; i < A.size(); ++i)
		{
			if (A[0][idx] != A[i][idx]) return A[0].substr(0, idx);
		}
	}
	return A[0];
}

string longestPrefix2(vector<string> A)
{
	if (A.empty()) return "";

	int right_most = A[0].size() - 1;
	for (int i = 1; i < A.size(); ++i)
	{
		for (int j = 0; j < right_most; ++j){
			if (A[i][j] != A[0][j]) right_most = j - 1;
		}
	}
	return A[0].substr(0, right_most + 1); // right_most表示最大元素下标，+1表示个数
}