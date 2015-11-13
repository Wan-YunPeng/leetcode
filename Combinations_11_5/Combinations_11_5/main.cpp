#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k);
void dfs(int next, int n, int k, vector<vector<int>> &re, vector<int> p);

int main()
{
	vector<vector<int>> re = combine(4, 3);
	for (auto elems : re)
	{
		for (auto i : elems)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

vector<vector<int>> combine(int n, int k)
{
	if (k > n) return{};
	vector<vector<int>> re;
	vector<int> path;
	dfs(1,n, k, re, path);
	return re;
}

void dfs(int next, int n, int k, vector<vector<int>> &re, vector<int> p)
{
	if (p.size() == k)
	{
		re.push_back(p);
		return;
	}
	for (int i = next; i <= n; ++i)
	{
		p.push_back(i);
		dfs(i + 1, n, k, re, p);
		p.pop_back();
	}
	
}