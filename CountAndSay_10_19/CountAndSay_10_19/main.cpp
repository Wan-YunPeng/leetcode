#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
using namespace std;

vector<string> countAndSay(const int n);


void countAndSay2(int n);
string getNext(const string &s);

int main()
{
	string a("11");
	int i = 19;
	stringstream ss;
	ss << i;
//	string a;
	ss >> a;
	cout << a << endl;
	vector<string> re = countAndSay(6);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	countAndSay2(6);
	return 0;
}

vector<string> countAndSay(const int n)
{
	if (n == 0) return { "" };
	if (n == 1) return{ "1" };

	
	vector<string> result;
	result.push_back("1");
	for (int i = 1; i < n; ++i)
	{
		const string last = result.back();
		int counter = 1;
		string re("");
		for (int j = 0; j < last.size(); ++j)
		{
			
			while ((j < (last.size() - 1)) && last[j] == last[j + 1])
			{
				counter++;
				j++;
			}
			stringstream ss;
			ss << counter;
			// cout << ss.str() << endl;
			re += ss.str() + last.substr(j,1);
			counter  = 1;
		}
		result.push_back(re);
	}
	return result;
}

void countAndSay2(int n)
{
	if (n == 0) return;
	string s("1");
	cout << s << endl;
	while (--n)
	{
		s = getNext(s);
		cout << s << endl;
	}
}
string getNext(const string &s)
{
	stringstream ss;

	for (auto i = s.begin(); i != s.end();)
	{
		auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
		ss << distance(i, j) << *i;
		i = j;
	}
	return ss.str();
}