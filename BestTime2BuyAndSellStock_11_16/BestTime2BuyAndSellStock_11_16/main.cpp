#include <iostream>
#include <algorithm>
using namespace std;

double maxProfile(double A[], int n);

int main()
{
	double A[] = { 1.2, 3, 4.2, 7.3, 2, 3.4, 11.1 };
	cout << maxProfile(A, sizeof(A) / sizeof(A[0])) << endl;
	return 0;
}

double maxProfile(double A[], int n)
{
	if (n < 2) return 0;

	double profile = 0, curmin = A[0];
	for (int i = 1; i < n; ++i)
	{
		profile = max(profile, A[i] - curmin);
		curmin = min(curmin, A[i]);
	}
	return profile;
}