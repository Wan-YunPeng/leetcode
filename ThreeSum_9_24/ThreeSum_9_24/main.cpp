#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>



using namespace std;

vector<vector<int>> solution1(vector<int>& num);

int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	vector<vector<int> > result = solution1(num);
	if (result.empty())
		cout << "not found" << endl;
	for (vector<vector<int> >::iterator i = result.begin(); i < result.end(); ++i)
	{
		for (vector<int>::iterator j = (*i).begin(); j < (*i).end(); ++j)
			cout << *j << "  ";
		cout << endl;
	}
	return 0;
}

vector<vector<int> > solution1(vector<int>& num)
{
	vector<vector<int> > result;
	if (num.size() < 3) return result;
	// ¶ÔvectorÅÅÐò
	sort(num.begin(), num.end());
	const int target = 0;

	auto last = num.end();
	for (auto a = num.begin(); a < prev(last, 2); ++a)
	{
		auto b = next(a);
		auto c = prev(last);
		while (b < c)
		{
			if (*a + *b + *c < target)
				++b;
			else if (*a + *b + *c > target)
				--c;
			else
			{
				result.push_back({ *a, *b, *c });
				++b;
				--c;
			}
		} 
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}