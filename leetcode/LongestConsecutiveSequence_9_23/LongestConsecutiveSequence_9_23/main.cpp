#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int solution1(const vector<int>& num);
int solution2(const vector<int>& num);
int mergeCluster(unordered_map<int, int> &map, int left, int right);
int main()
{
	int a[] = { 400, 4, 200, 1, 3, 2 };
	vector<int> num(a, a + sizeof(a)/sizeof(a[0]));
	int result = solution1(num);
	cout << result << endl;
	result = solution2(num);
	cout << result << endl;
	return 0;
}

int solution1(const vector<int>& num)
{
	unordered_map<int, bool> used;

	if (num.empty()) return 0;

	int longest = 1;

	for (auto i : num) used[i] = false;

	for (auto i : num)
	{
		// i�Ѿ���������ĳ����������������˴�ѭ��
		if (used[i]) continue;
		// ���ٺ����Լ�������Ϊ1
		int length = 1;

		used[i] = true;
		// used.find()Ҫ��û�ҵ�����end()��������������
		for (int j = i + 1; used.find(j) != used.end(); ++j)
		{
			used[j] = true;
			++length;
		}
		for (int j = i - 1; used.find(j) != used.end(); ++j)
		{
			used[j] = true;
			++length;
		}
		longest = max(length, longest);

	}

	return longest;
}

int solution2(const vector<int>& num)
{
	// ����map���г�ʼ������ѭ���ж�num�е�Ԫ��һ�������
	unordered_map<int, int> map;
	
	int l = 1;
	int size = num.size();

	for (auto i : num)
	{
		if (map.find(i) != map.end()) continue;
		// ��ʼ��map����Ԫ����󳤶�Ϊ1
		map[i] = 1;
		// �ҵ��ұ���һ����������
		if (map.find(i - 1) != map.end())
			l = max(l, mergeCluster(map, i - 1, i));
		if (map.find(i + 1) != map.end())
			l = max(l, mergeCluster(map, i, i + 1));
	}

	for (auto i : num)
		cout << map[i] << endl;
	return size == 0 ? 0 : l;
}

int mergeCluster(unordered_map<int, int> &map, int left, int right)
{
	// ��left��right��ʼ�����Լ�Ϊ��㣬map��¼�������ǵ���󳤶ȣ���ô�˵����right + map[right] -1 �� left - map[left] + 1
	int upper = right + map[right] - 1;
	int lower = left - map[left] + 1;

	int length = upper - lower + 1;
	map[upper] = length;
	map[lower] = length;
	return length;
}