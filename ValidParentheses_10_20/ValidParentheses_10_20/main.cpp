#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool validParenthese(const string &parenthese);

int main()
{
	char *s = "[][][]([])";
	bool re = validParenthese(s);
	cout << s << " : " << re << endl;
	return 0;
}

bool validParenthese(const string &parenthese)
{
	string left("[{(");
	string right("]})");
	stack<char> tmp;

	for (auto c : parenthese)
	{
		if (left.find(c) != string::npos)
			tmp.push(c);
		else
		{
			if (tmp.empty() || tmp.top() != left[right.find(c)])
				return false;
			else
				tmp.pop();
		}
	}
	
	return tmp.empty();
}