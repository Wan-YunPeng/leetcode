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

		// 把当前访问的节点移到链表头部，并更新map中该节点的地址
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void set(int key, int value)
	{
		if (cacheMap.find(key) == cacheMap.end())
		{
			if (cacheList.size() == capacity){ // 删除链表尾部节点
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			// 插入新节点到链表头部，并在map中增加该节点
			cacheList.push_front(cacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else
		{
			// 更新该节点的值，并将该节点放于链表头部
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
};

int main()
{

}