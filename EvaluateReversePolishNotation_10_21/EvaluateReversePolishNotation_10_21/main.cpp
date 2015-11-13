#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int reversePolish(vector<string> s);

bool is_operator(const string &op);
int evalRPN(vector<string> s);

int main()
{
	vector<string> s{ "4","13","5","/","+" };
	int re = reversePolish(s);
	cout << re << endl;
	re = evalRPN(s);
	cout << re << endl;
	return 0;
}

int reversePolish(vector<string> s)
{
	stack<int> stk;
	int re = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		re = 0;
		if(s[i] == "+"){
				int p1 = stk.top(); stk.pop();
				re = p1 + stk.top();
				stk.pop();
				stk.push(re);
		}
		else if (s[i] == "-"){
			int p2 = stk.top(); stk.pop();
			re = stk.top() - p2;
			stk.pop();
			stk.push(re);
		}
		else if (s[i] == "/"){
			int p3 = stk.top(); stk.pop();
			re = stk.top() / p3;
			stk.pop();
			stk.push(re);
		}
		else if (s[i] == "*"){
			int p4 = stk.top(); stk.pop();
			re = stk.top() * p4;
			stk.pop();
			stk.push(re);
		}
		else{
			stringstream ss; int p;
			ss << s[i]; ss >> p;
			
			stk.push(p);
		}
	}
	return re;
}

int evalRPN(vector<string> s)
{
	stack<string> stk;
	for (int i = 0; i < s.size(); ++i)
	{
		if (is_operator(s[i]))
		{
			int x = stoi(stk.top());
			stk.pop();
			int y = stoi(stk.top());
			stk.pop();
			if (s[i] == "+") y += x;
			else if (s[i] == "-") y -= x;
			else if (s[i] == "*") y *= x;
			else y /= x;
			stk.push(to_string(y));
		}
		else
			stk.push(s[i]);
	}
	return stoi(stk.top());
}
bool is_operator(const string &op)
{
	return op.size() == 1 && string("+-*/").find(op) != string::npos;
}
