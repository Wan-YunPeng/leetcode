#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(const vector<vector<char>> &board);
bool check(char ch, bool used[9]);

int main()
{
	//char a[][9] =
	//{
	//	{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	//	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	//	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	//	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	//	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	//	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	//	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	//	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	//	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }

	//};
	vector<vector<char>> board;
	board.push_back({ '5', '3', '.', '.', '7', '.', '.', '.', '.' });
	board.push_back({ '6', '.', '.', '1', '9', '5', '.', '.', '.' });
	board.push_back({ '.', '9', '8', '.', '.', '.', '.', '6', '.' });
	board.push_back({ '8', '.', '.', '.', '6', '.', '.', '.', '3' });
	board.push_back({ '4', '.', '.', '8', '.', '3', '.', '.', '1' });
	board.push_back({ '7', '.', '.', '.', '2', '.', '.', '.', '6' });
	board.push_back({ '.', '6', '.', '.', '.', '.', '2', '8', '.' });
	board.push_back({ '.', '.', '.', '4', '1', '9', '.', '.', '5' });
	board.push_back({ '.', '.', '.', '.', '8', '.', '.', '7', '9' });
	bool re = isValidSudoku(board);
	if (re)
		cout << "The Sudoku is Valid" << endl;
	else
		cout << "The Sudoku is not Valid" << endl;
	return 0;
}

bool isValidSudoku(const vector<vector<char>> &board)
{
	// 每次检查9个数
	bool used[9];

	for (int i = 0; i < 9; ++i)
	{
		fill(used, used + 9, false);
		// 检查行
		for (int j = 0; j < 9; ++j)
		{
			if (!check(board[i][j], used))
				return false;
		}

		fill(used, used + 9, false);
		// 检查列
		for (int j = 0; j < 9; ++j)
		{
			if (!check(board[j][i], used))
				return false;
		}
	}

	// 检查九个格子
	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			fill(used, used + 9, false);
			for (int i = r * 3; i < r * 3 + 3; ++i)
			{
				for (int j = c * 3; j < c * 3 + 3; ++j)
				{
					if (!check(board[i][j], used))
						return false;
				}
			}
		}
	}
	return true;
}

bool check(char ch, bool used[9])
{
	if (ch == '.') return true;
	if (used[ch - '1']) return false;
	return used[ch - '1'] = true;
}