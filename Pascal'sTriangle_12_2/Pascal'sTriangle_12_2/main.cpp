#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascal(int numRows);

int main()
{
	vector<vector<int>> re = pascal(8);
	for (auto &row : re)
	{
		for (auto &i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> pascal(int numRows)
{
	vector<vector<int>> re;
	int row = 0;
	while (row < numRows)
	{
		re.push_back(vector<int>());
		re.back().push_back(1);
		for (int i = 1; i < row; ++i)
			re.back().push_back(re[re.size() - 2][i - 1] + re[re.size() - 2][i]);
		if (row > 0)
			re.back().push_back(1);
		row++;
	}
	return re;
}