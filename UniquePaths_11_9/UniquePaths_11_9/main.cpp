#include <iostream>
#include <vector>
using namespace std;

class solution
{
private:
	vector<vector<int>> re;
	int dfs(int m, int n)
	{
		if (m < 1 || n < 1) return 0;
		if (m == 1 && n == 1) return 1;
		return getOrUpdate(m - 1, n) + getOrUpdate(m, n - 1);
	}
	int getOrUpdate(int m, int n)
	{
		if (re[m][n] > 0) return re[m][n];
		else
			return re[m][n] = dfs(m, n);
	}
public:
	// ʹ�ñ���¼���������ڹ涨ʱ����ͨ��
	int uniquePathsdfs(int m, int n)
	{
		this->re = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
		return dfs(m, n);;
	}	
};

// ���������С���Ͽ��Թ����󼯺ϻᳬʱ
int uniquePaths(int m, int n);


// ��̬�滮���
int uniquePaths2(int m, int n);

int main()
{
	int m = 3, n = 7;
	solution s;
	
	int re = s.uniquePathsdfs(m, n);
	cout << re << endl;
	return 0;
}

int uniquePaths(int m, int n)
{
	if (m < 1 || n < 1) return 0;
	if (m == 1 && n == 1) return 1;
	return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

// ��̬�滮���
int uniquePaths2(int m, int n)
{
	vector<int> f(n, 0);
	f[0] = 1; // �Լ����ұ���һ��·���� �Լ����±���һ��·��
	for (int i = 0; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
			f[j] = f[j - 1] + f[j];
	}
	return f.back();
}

