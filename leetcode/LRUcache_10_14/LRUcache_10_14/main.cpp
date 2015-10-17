#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache{
private:
	struct cacheNode{
		int key;
		int value;
		cacheNode(int k, int v) :key(k), value(v){}
	};

	int capacity;
	list<cacheNode> cacheList;
	unordered_map<int, list<cacheNode>::iterator> cacheMap;
public:
	LRUCache(int capacity)
	{
		this->capacity = capacity;
	}

	int get(int key)
	{
		if (cacheMap.find(key) == cacheMap.end()) return -1;

		// �ѵ�ǰ���ʵĽڵ��Ƶ�����ͷ����������map�иýڵ�ĵ�ַ
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value)
	{
		if (cacheMap.find(key) == cacheMap.end())
		{
			if (cacheList.size() == capacity){ // ɾ������β���ڵ�
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			// �����½ڵ㵽����ͷ��������map�����Ӹýڵ�
			cacheList.push_front(cacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			// ���¸ýڵ��ֵ�������ýڵ��������ͷ��
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
};

int main()
{

}