#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution
{
private:
	vector<int> main_dialog;
	vector<int> anti_dialog;
	vector<int> columns;
	int count = 0;
	void dfs(vector<int> &path, int row)
	{
		const int N = path.size();
		if (row == N)
		{
			++count;
			for (auto i : path)
				cout << i << " ";
			cout << endl;
			return;
		}

		for (int j = 0; j < N; ++j)
		{
			const bool ok = columns[j] == 0 && main_dialog[row - j + N] == 0 && anti_dialog[row + j] == 0;
			if (!ok) continue;
			path[row] = j;
			columns[j] = main_dialog[row - j + N] = anti_dialog[row + j] = 1;
			dfs(path, row + 1);
			columns[j] = main_dialog[row - j + N] = anti_dialog[row + j] = 0;
		}
	}

public:
	int solveNQueens(int n)
	{
		main_dialog = vector<int>(2 * n, 0);
		anti_dialog = vector<int>(2 * n, 0);
		columns = vector<int>(n, 0);

		vector<int> path(n, 0);
		dfs(path, 0);
		return count;
	}
};

int main()
{
	solution s;
	int re = s.solveNQueens(8);
	cout << re << endl;
	return 0;
}