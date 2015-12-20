#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int start, end;
	Interval() :start(0), end(0){}
	Interval(int s, int e) :start(s), end(e){}
};

void insert(vector<Interval> &intervals, Interval newInterval);
vector<Interval> merge(vector<Interval> &intervals);

int main()
{
	vector<Interval> intervals = { Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
	vector<Interval> re = merge(intervals);
	for (auto & interval : re)
	{
		cout << interval.start << "  " << interval.end << endl;
	}
	return 0;
}

void insert(vector<Interval> &intervals, Interval newInterval)
{
	vector<Interval>::iterator itr = intervals.begin();
	while (itr != intervals.end())
	{
		if (newInterval.end < itr->start)
		{
			intervals.insert(itr, newInterval);
			return;
		}
		else if (newInterval.start > itr->end)
		{
			itr++;
			continue;
		}
		else
		{
			newInterval.start = min(newInterval.start, itr->start);
			newInterval.end = max(newInterval.end, itr->end);
			itr = intervals.erase(itr);
		}
	}
	intervals.insert(intervals.end(), newInterval);
}

vector<Interval> merge(vector<Interval> &intervals)
{
	vector<Interval> re;
	for (int i = 0; i < intervals.size(); ++i)
	{
		insert(re, intervals[i]);
	}
	return re;
}