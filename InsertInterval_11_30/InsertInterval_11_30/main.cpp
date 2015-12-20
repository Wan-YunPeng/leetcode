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

vector<Interval> insertInterval(vector<Interval> &intervals, Interval interval);

int main()
{
	vector<Interval> intervals = { Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) };
	vector<Interval> re = insertInterval(intervals, Interval(4,9));
	for (auto & interval : re)
	{
		cout << interval.start << "  " << interval.end << endl;
	}
	return 0;
}

vector<Interval> insertInterval(vector<Interval> &intervals, Interval interval)
{
	vector<Interval>::iterator it = intervals.begin();

	while (it != intervals.end())
	{
		if (interval.end < it->start)
		{
			intervals.insert(it, interval);
			return intervals;
		}
		else if (interval.start > it->end)
		{
			it++;
			continue;
		}
		else
		{
			interval.start = min(it->start, interval.start);
			interval.end = max(it->end, interval.end);
			it = intervals.erase(it);

		}
	}
	intervals.insert(intervals.end(), interval);
	return intervals;
}