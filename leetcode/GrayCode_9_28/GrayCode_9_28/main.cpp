#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode1(int n);
vector<int> grayCode2(int n);
static unsigned int binary_to_gray(unsigned int n);

int main()
{
	int n = 3;
	vector<int> re1 = grayCode1(n);
	for (auto i : re1)
		cout << i << " ";
	cout << endl;
	re1 = grayCode2(n);
	for (auto i : re1)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> grayCode1(int n)
{
	vector<int> re;
	const size_t size = 1 << n; // 2^n
	re.reserve(size); // re��������2^n��Ԫ��
	
	for (size_t i = 0; i < size; ++i)
		re.push_back(binary_to_gray(i));
	return re;
}

static unsigned int binary_to_gray(unsigned int n)
{
	return n ^ (n >> 1);
}

vector<int> grayCode2(int n)
{
	vector<int> re;
	re.reserve(1 << n);
	re.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		const int highest_bit = 1 << i;
		for (int j = re.size() - 1; j >= 0; --j) // ���ű��������ܶԳ�
			re.push_back(highest_bit | re[j]);
	}
	return re;
}