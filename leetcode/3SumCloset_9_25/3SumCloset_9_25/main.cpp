#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution1(vector<int>& num, int target);

int main()
{
	int a[] = { 2,-1,1,4 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	int target = 1;
	int result = solution1(num, target);
	cout << result << endl;
	return 0;
}

int solution1(vector<int>& num, int target)
{
	int result = 0;
	int min_gap = INT_MAX;
	
	// ����������
	sort(num.begin(), num.end());
	
	//auto a = num.begin();
	for (auto a = num.begin(); a != prev(num.end(), 2); ++a)
	{
		auto b = next(a);
		auto c = prev(num.end());

		while (b < c)
		{
			// ��ǰ����ܺ�
			const int sum = *a + *b + *c;
			// ��Ŀ��ֵ�Ĳ�ֵ��ȡ����ֵ�����ò�ֵ��С
			const int gap = abs(target - sum);
			if (gap < min_gap)
			{
				result = sum;
				min_gap = gap;
			}
			if (gap == 0) return result;
			if (sum < target) ++b;
			else --c;
		}
	}
	return result;

}
