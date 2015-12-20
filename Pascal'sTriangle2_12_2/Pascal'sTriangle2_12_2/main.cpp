#include <iostream>
#include <vector>

using namespace std;

vector<int> kthRow(int k);

int main()
{
	vector<int> re = kthRow(2);
	for (auto &i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> kthRow(int k)
{
	if (k == 1) return vector<int>(1, 1);
	if (k == 2) return vector<int>(2, 1);

	vector<int> re(2, 1);
	for (int i = 3; i <= k; ++i)
	{
		for (int j = i - 2; j > 0; --j)
		{
			re[j] = re[j] + re[j - 1];
		}
		re.push_back(1);
	}
	return re;
}