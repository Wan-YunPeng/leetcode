#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits);

int main()
{
	int a[] = { 9, 9, 8 };
	vector<int> digits(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> re = plusOne(digits);
	for (auto i : re)
		cout << i;
	cout << endl;
}

vector<int> plusOne(vector<int> &digits)
{
	// ��λ
	int c = 1;

	for (auto rfirst = digits.rbegin(); rfirst != digits.rend(); ++rfirst)
	{
		int sum = *rfirst + c;
		*rfirst = sum % 10;
		c = sum / 10;

	}
	// ����֮��Ҫ�ٽ�һλ
	if (c > 0) digits.insert(digits.begin(), c);
	return digits;
}