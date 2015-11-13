#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string simplifyPath(string &path);

int main()
{
	string path = "/a/./b/../c/d/e/";
	string re = simplifyPath(path);
	cout << re << endl;
	return 0;
}

string simplifyPath(string &path)
{
	vector<string> dirs; // ����ջ����·����ʼ��·����β�洢ÿһ��·��

	for (auto i = path.begin(); i != path.end();)
	{
		++i;

		auto j = find(i, path.end(), '/');
		string dir = string(i, j);

		if (!dir.empty() && dir != ".")
		{
			if (dir == ".."){
				if (!dirs.empty())
					dirs.pop_back();
			}
			else
				dirs.push_back(dir);
		}
		i = j;
	}
	stringstream out;
	if (dirs.empty())
		out << "/";
	else
	{
		for (auto dir : dirs)
			out << '/' << dir;
	}
	return out.str();	
}