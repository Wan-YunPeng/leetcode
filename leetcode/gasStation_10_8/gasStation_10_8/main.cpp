#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

int main()
{
	int g[] = { 2, 5, 6, 7, 3, 1, 4 };
	int c[] = { 3, 5, 2, 1, 3, 2, 1 };
	vector<int> gas(g, g + sizeof(g) / sizeof(g[0]));
	vector<int> cost(c, c + sizeof(c) / sizeof(c[0]));
	int re = canCompleteCircuit(gas, cost);
	cout << re << endl;
	return 0;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
	int total = 0;
	int re = -1;
	for (int i = 0, sum = 0; i < gas.size(); ++i)
	{
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];
		if (sum < 0)
		{
			re = i;
			sum = 0;
		}
	}      
	return total >= 0 ? re + 1 : -1;
}