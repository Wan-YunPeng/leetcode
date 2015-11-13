#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(const vector<vector<int>> matrix, int target);

int main()
{
	vector<vector<int>> matrix;
	matrix.push_back({ 1, 3, 5, 7 });
	matrix.push_back({ 10, 11, 16, 20 });
	matrix.push_back({ 23, 30, 34, 50 });
	bool re = searchMatrix(matrix, 20);
	cout << re << endl;
	return 0;
}

bool searchMatrix(const vector<vector<int>> matrix, int target)
{
	if (matrix.empty()) return false;
	const int m = matrix.size();
	const int n = matrix.front().size();
	int first = 0, last = m * n;
	while (first != last)
	{
		int mid = first + (last - first) / 2;
		if (matrix[mid / n][mid % n] == target)
			return true;
		else if (matrix[mid / n][mid % n] > target)
		{
			last = mid;
		}
		else
			first = ++mid;
	}
	return false;
}