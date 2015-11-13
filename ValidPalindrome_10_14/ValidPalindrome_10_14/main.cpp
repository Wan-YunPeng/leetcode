#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class solution{
public:
	bool validPalindrome(string s)
	{
		// 将大写变成小写
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left != right)
		{
			if (!isalnum(*left)) ++left;
			else if (!isalnum(*right)) --right;
			else if (*left != *right) return false;
			else{
				++left; --right;
			}

		}
		return true;
	}
};

int main()
{
	string s("A man, a plan, a canal: Panama");
	solution so;
	bool valid = so.validPalindrome(s);
	cout << s << "  is valid panlindrome: " << valid << endl;
}