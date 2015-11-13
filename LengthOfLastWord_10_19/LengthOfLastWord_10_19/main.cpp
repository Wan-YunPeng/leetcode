#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lenghtOfLastWord(string s);

int lenghtOfLastWord2(string s);

int main()
{
	string s = "hello world again";
	int re = lenghtOfLastWord2(s);
	cout << re << endl;
	return 0;
}

int lenghtOfLastWord(string s)
{
	if (s == "") return 0; 
	const string str(s);
	auto rfirst = find_if(s.rbegin(), s.rend(), ::isalpha);
	auto rlast = find_if_not(s.rbegin(), s.rend(), ::isalpha);
	return distance(rfirst, rlast);
}

int lenghtOfLastWord2(string s)
{
	if (s.empty()) return 0;
	int len = 0, i = 0;
	
	while (i<s.size())
	{
		if (s[i] && s[i] != ' '){
			len++;
		}
		else
			len = 0;
		i++;
	}
	//copy()
	return len;
}