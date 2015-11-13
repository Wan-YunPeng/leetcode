#include <iostream>
#include <vector>
#include <string>
using namespace std;

class solution{
private:
	vector<int> main_dialog; // ���Խ��ߣ�����ֻ��ľ���ֵ���
	vector<int> anti_dialog; // ���Խ��ߣ�����֮�͵����
	vector<int> columns; // ��ǰ���Ƿ�ռ��
	int count = 0;
	void dfs(vector<vector<string>> &re, vector<int> &path, int row)
	{
		const int N = path.size();
		if (row == N)
		{
			vector<string> s;
			for (int i = 0; i < N; ++i)
			{
				string S(N, '.');
				S[path[i]] = 'Q';
				s.push_back(S);
			}
			count++;
			re.push_back(s);
			return;
		}

		for (int j = 0; j < N; ++j)
		{
			const bool ok = columns[j] == 0 && main_dialog[row - j + N] == 0 && anti_dialog[row + j] == 0;
			if (!ok) continue;
			path[row] = j;
			columns[j] = main_dialog[row - j + N] = anti_dialog[row + j] = 1;
			dfs(re, path, row + 1);
			columns[j] = main_dialog[row - j + N] = anti_dialog[row + j] = 0;
		}
	}

public:
	vector<vector<string>> solveNQueens(int n)
	{
		main_dialog = vector<int>(2 * n, 0);
		anti_dialog = vector<int>(2 * n, 0);
		columns = vector<int>(n, 0);

		vector<vector<string>> re;
		vector<int> path(n, 0); // path[i]��ʾ��i���ʺ�������
		dfs(re, path, 0);
		cout << count << endl;
		return re;
	}
	
};


int main()
{
	vector<vector<string>> re;
	solution s;
	re = s.solveNQueens(8);
	for (const auto& row : re)
	{
		for (const auto& col : row)
			cout << col << endl;
		cout << endl << endl;
	}
	return 0;
}

