#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> combinationSum(vector<int> nums, int target);
void dfs(const vector<int> &nums, int gap, vector<int> &path, int n, vector<vector<int>> &re);

int main()
{
	vector<int> nums = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;
	vector<vector<int>> re = combinationSum(nums, target);
	for (const auto& row : re)
	{
		for (const auto& i : row)
			cout << i << "  ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> combinationSum(vector<int> nums, int target)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> re;
	vector<int> path;
	dfs(nums, target, path, 0, re);
	return re;
}

void dfs(const vector<int> &nums, int gap, vector<int> &path, int n, vector<vector<int>> &re)
{
	if (gap == 0)
	{
		re.push_back(path);
		return;
	}

	if (n == nums.size() || gap < 0) return; // 剪枝
	int previous = -1;
	for (int i = n; i < nums.size(); ++i)
	{
		if (previous == nums[i]) continue;  //确保nums[i]只取一次，不然1，2，5和1，2，5的1来自不同的1.但结果相同

		if (gap < nums[i]) return;

		previous = nums[i];

		path.push_back(nums[i]);
		dfs(nums, gap - nums[i], path, i + 1, re);
		path.pop_back();
	}
}