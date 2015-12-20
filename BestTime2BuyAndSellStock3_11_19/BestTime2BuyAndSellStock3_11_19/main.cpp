#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> &prices);

int main()
{
	vector<int> prices = { 1, 4, 6, 2, 5, 1, 4 };
	cout << maxProfit(prices) << endl;
	return 0;
}

int maxProfit(vector<int> &prices)
{
	if (prices.size() < 2) return 0;

	const int n = prices.size();
	vector<int> f(n, 0);
	vector<int> g(n, 0);
	// f(i)表示从[0,i]的最大利润
	for (int i = 1, valley = prices[0]; i < n; ++i)
	{
		valley = min(valley, prices[i]); // 不卖
		f[i] = max(f[i - 1], prices[i] - valley); // 卖
	}
	// g(i)表示[i,n-1]的最大利润
	for (int j = n - 2, peak = prices[n - 1]; j >= 0; --j)
	{
		peak = max(peak, prices[j]);
		g[j] = max(g[j + 1], peak - prices[j]);
	}

	int max_profit = 0;
	for (int i = 0; i < n; ++i)
	{
		max_profit = max(max_profit, g[i] + f[i]);
	}

	return max_profit;
}