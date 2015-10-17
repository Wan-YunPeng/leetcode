#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
/*
	@author wyp   9-26  此方法已被stl实现为模板函数，next_permutation
*/
void solution1(vector<int> &num);
// leetcode STL implementation
void solution2(vector<int> &num);
template <typename BidiIt>
bool next_permutation2(BidiIt first, BidiIt last);
int main()
{
	int a[] = { 6, 8, 7, 4, 3, 2 };
	vector<int> num(a, a + sizeof(a) / sizeof(a[0]));
	vector<int> num2(num);
	solution1(num);
	solution2(num2);
	for (auto i : num)
		cout << i << " ";
	cout << endl;
	for (auto i : num2)
		cout << i << " ";
	cout << endl;
	return 0;
}

void solution1(vector<int>& num)
{
	int length = num.size();

	if (length == 0) return;
	// find the partitionNumber
	auto last = prev(num.end());  // last element
	auto first = num.begin();
	auto partition = prev(last);  // before the last element
	while (last != first)
	{
		if (*partition > *(last)) // check if it is the ascent
		{
			--partition;
			--last;
		}
		else
			break;
	}

	// che if there is a partitionNumber
	if (last == first)
	{
		sort(num.begin(), num.end());
		return;
	}

	auto change = prev(num.end());
	while (change != partition)
	{
		if (*change < *partition)
			--change;
		else
			break;
	}
	swap(*change, *partition);
	reverse(partition + 1, num.end());
}

void solution2(vector<int> &num)
{
	next_permutation2(num.begin(), num.end());
}
template<typename BidiIt>
bool next_permutation2(BidiIt first, BidiIt last)
{
	// Get a reversed range to simplify reversed traversal
	const auto rfirst = reverse_iterator<BidiIt>(last);
	const auto rlast = reverse_iterator<BidiIt>(first);

	// begin from the second last element to the first element;
	auto pivot = next(rfirst);

	while (pivot != rlast && *pivot >= *prev(pivot))
		++pivot;
	
	if (pivot == rlast)
	{
		reverse(first, last);
		return false;
	}

	// find the changeNumber
	auto change = find_if(rfirst, rlast, bind2nd(greater<int>(), *pivot)); // or bind2nd(greator<int>(); *pivot) ----

	swap(*pivot, *change);
	reverse(rfirst, pivot);
	return true;
}