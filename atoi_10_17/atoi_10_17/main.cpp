#include <iostream>

using namespace std;

int atoi(const char *str);

int main()
{
	char *str = "+2147483645";
	int re = atoi(str);
	if (re)
		cout << re << endl;
	cout << INT_MAX / 10 << endl;
	return 0;
}

int atoi(const char *str)
{
	int num = 0;
	int sign = 1;
	const int n = strlen(str);
	int i = 0;

	while (str[i] == ' ' && i < n) i++;

	if (str[i] == '+')
		++i;
	else if (str[i] == '-'){
		sign = -1;
		++i;
	}
	else
		return NULL;

	for (; i < n; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return sign == -1 ? INT_MIN : INT_MAX;
		num = num * 10 + str[i] - '0';
	}
	return num * sign;
}