#include <iostream>
#include <vector>
using namespace std;

int maxProfile(vector<int> &prices);

int main()
{
	vector<int> prices = { 1, 2, 4, 3, 6, 11, 9 };
	cout << maxProfile(prices) << endl;
	return 0;
}

int maxProfile(vector<int> &prices)
{
	if (prices.size() < 2) return 0;
	int sum = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		int diff = prices[i] - prices[i - 1];
		if (diff > 0) sum += diff;
	}
	return sum;
}