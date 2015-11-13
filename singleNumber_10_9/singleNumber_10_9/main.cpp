#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;

int getSingleNumber(const vector<int> &nums);
int getSingleNumber2(const vector<int> &nums);

int main()
{
	int a[] = { 2, 2, 3, 1, 1, 4, 4, 8, 8 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	int re1 = getSingleNumber(num);
	cout << re1 << endl;
	int re2 = getSingleNumber2(num);
	cout << re2 << endl;
	return 0;
}

int getSingleNumber(const vector<int> &nums)
{
	int re = 0;
	for (size_t i = 0; i < nums.size(); ++i)
	{
		re ^= nums[i];
	}
	return re;
}

int getSingleNumber2(const vector<int> &nums)
{
	return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
}