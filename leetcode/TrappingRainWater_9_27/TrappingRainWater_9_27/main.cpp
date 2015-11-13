#include <iostream>
#include <algorithm>
#include <stack>



using namespace std;
/*
	��������ɨ��һ�飬����ÿ�����ӣ���������ֵ
	��������ɨ��һ�飬����ÿ�����ӣ����ұ����ֵ
	��ɨ��һ�飬��ÿ��λ���ϵ�ˮλ���
*/
int solution1(int A[], int n);
/*
	ɨ��һ�飬�ҳ���ߵ��Ǹ�����
	һ��Ϊ���������ߴ�����ǰ�߶�С����������߶ȣ������λ��ˮλ���������������
	�ұ�ͬ��
*/
int solution2(int A[], int n);
/*
	ʹ��һ������ջ��С��ջ����Ԫ����ջ�����ڵ���ջ���Ͱ�ջ������С�ڻ���ڵ�ǰֵ��Ԫ��ȫ����ջ�����
	���ѵ�ǰԪ����ջ
*/
int solution3(int A[], int n);

int main()
{
	int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	int n = sizeof(A) / sizeof(A[0]);
	int re1 = solution1(A, n);
	cout << re1 << endl;
	int re2 = solution2(A, n);
	cout << re2 << endl;
	return 0;
}

int solution1(int A[], int n)
{
	// ÿ�����ӵ�������ֵ���ұ����ֵ
	int *max_left = new int[n]();
	int *max_right = new int[n]();

	for (int i = 1; i < n; ++i)
	{
		// ������ӵڶ�����ʼ
		max_left[i] = max(max_left[i - 1], A[i - 1]);
		// �ұ����ӵ����ڶ�����ʼ��Ĭ�ϵ�һ����������Ϊ0�����һ�����ұ����Ϊ0
		max_right[n - i - 1] = max(max_right[n - i], A[n - i]);
	}

	for (int i = 0; i < n; ++i)
		cout << max_left[i] << " ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << max_right[i] << " ";
	cout << endl;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int height = min(max_left[i], max_right[i]);
		if (height > A[i])
		{
			sum += height - A[i];
		}
	}

	delete[] max_right;
	delete[] max_left;
	return sum;
}

int solution2(int A[], int n)
{
	// ������ߵ��±�
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] > A[max])
			max = i;
	}

	int water = 0;
	// ��������
	for (int i = 0, peak = 0; i < max; ++i)
	{
		if (A[i] > peak) peak = A[i];
		else water += peak - A[i];
	}
	// �����Ұ��
	for (int i = n - 1, peak = 0; i > max; --i)
	{
		if (A[i] > peak) peak = A[i];
		else water += peak - A[i];
	}
	return water;
}

int solution3(int A[], int n)
{
	stack<pair<int, int>> s;
	int water = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int height = 0;

		while (!s.empty()) // ��ջ��ȵ�ǰԪ�ذ���Ǹߵ�Ԫ��ȫ�������
		{
			int bar = s.top().first; // ջ��Ԫ�ظ߶�
			int pos = s.top().second; // ջ��Ԫ���±�

			// bar,height,A[i] ���߳�Ϊ����
			water += (min(bar, A[i]) - height) * (i - pos - 1);
			height = bar;

			if (A[i] < bar)
				break;
			else
				s.pop();
		}
		s.push(make_pair(A[i], i));
	}
	return water;
}