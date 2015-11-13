#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combinationSum(const vector<int> &nums, int target);
void dfs(vector<vector<int>> &re, int target, int n, int sum, vector<int> &path, const vector<int> &nums);

int main()
{
	vector<int> nums = { 2, 3, 5, 7 };
	int target = 7;
	vector<vector<int>> re = combinationSum(nums, target);
	for (const auto& row : re)
	{
		for (const auto& i : row)
			cout << i << "  ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> combinationSum(const vector<int> &nums, int target)
{
	vector<vector<int>> re;
	vector<int> path;
	dfs(re, target, 0, 0, path, nums);
	return re;
}

void dfs(vector<vector<int>> &re, int target, int n, int sum, vector<int> &path, const vector<int> &nums)
{
	if (sum == target)
	{
		re.push_back(path);
		return;
	}

	if (sum > target || n == nums.size()) return; 

	for (int i = n; i < nums.size(); ++i)
	{
		path.push_back(nums[i]); 
		//dfs(re, target, i + 1, sum + nums[i], path, nums);
		dfs(re, target, i, sum + nums[i], path, nums);
		path.pop_back();
	}
}
