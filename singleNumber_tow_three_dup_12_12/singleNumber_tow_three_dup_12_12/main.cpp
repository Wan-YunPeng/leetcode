#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums);
int singleNumber2(vector<int> &nums);

int main()
{
	vector<int> nums = { 1, 2, 2, 2, 3, 3,3,4, 4, 4,  5, 5, 5 };
	cout << singleNumber(nums) << endl;
	vector<int> nums2 = { 1,1,1,1, 2, 2, 2, 2,3,3,3,3 ,5};
	cout << singleNumber2(nums2) << endl;
	return 0;
}

int singleNumber(vector<int> &nums)
{
	int one = 0, two = 0, three = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		two |= (nums[i] & one);
		one ^= nums[i];
		three = ~(one & two);
		one &= three;
		two &= three;
	}
	return one;
}

int singleNumber2(vector<int> &nums)
{
	int one = 0, two = 0, three = 0, four = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		three |= (two & nums[i]);
		two |= (one & nums[i]);
		four = ~(one & three);
		one ^= nums[i];
		one &= four;
		two &= four;
		three &= four;
	}
	return one;
}
/*

*/