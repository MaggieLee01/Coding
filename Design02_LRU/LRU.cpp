//	https://mp.weixin.qq.com/s/v4uhNh65t2vKSW7wCpPthQ
/*	LRU缓存机制：最久未使用淘汰原则
	https://leetcode-cn.com/problems/lru-cache/
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
写入的新数据在最前面。
进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？

LRUCache cache = new LRUCache( 2   );//缓存容量【这是JAVA, C++中new出来了新指针】
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/
#include<unordered_map>
#include<utility>
#include<list>
using namespace std;

//自己写链表 + hash，关键点在于 增删节点之后，双向链表的更新；看了题解，应该将链表操作独立出来成新的函数
struct ListNode1
{
	int val;
	int key;
	ListNode1* next;
	ListNode1* last;
	ListNode1(int m, int n) :key(m), val(n), next(nullptr), last(nullptr) {}
};
class LRUCache01 {
private:
	int cap_;//容量
	int cnt_;
	unordered_map<int, ListNode1*> node_;
	ListNode1* pHead_;
	ListNode1* pTail_;
public:
	//增加了辅助节点，单向链表头部增加辅助，双向链表的话两边都应该增加
	LRUCache01(int capacity) :cap_(capacity), cnt_(0), node_(), pHead_(new ListNode1(-1, -1)), pTail_(new ListNode1(-1, -1))
	{
		pHead_->next = pTail_;
		pTail_->last = pHead_;
	}

	int get(int key)
	{
		auto it = node_.find(key);
		if (it == node_.end()) return -1;
		ListNode1* node = it->second;
		node->next->last = node->last;
		node->last->next = node->next;
		node->next = pHead_->next;
		node->last = pHead_;
		node->next->last = node;
		pHead_->next = node;
		//return it->first; 要返回的是val，不是key
		return it->second->val;
	}

	void put(int key, int value)
	{
		//if (cap_ == cnt_)
		//{
		//	ListNode1* pTodeleted = pTail_->last;//果然这一步找不到key了，而且一直在完善链表，并没有存储在node_里面
		//	pTodeleted->last->next = pNode;
		//	pNode->last = pTodeleted->last;
		//	node_.erase(pTodeleted->key);// 应该在delete之前移除，不然指针的内存释放了
		//	delete pTodeleted;
		//}
		//else
		//{
		//	pTail_->last->next = pNode;
		//	pNode->last = pTail_->last;//不要忘记last赋值
		//	cnt_++;
		//}
		//pNode->next = pTail_;
		//pTail_->last = pNode;
		//node_.insert({ key,pNode });


		//上面的是在最末尾插入，题目要求是在最前面插入，put get 的应该在最前面，简单了很多
		//有一个情况被忽略了，当put一个已存在的key时，覆盖之前的value，同时移至开头
		auto it = node_.find(key);
		ListNode1* pNode = new ListNode1(key, value);
		if (it != node_.end())//修改覆盖应该更好，但是代码麻烦
		{
			ListNode1* node = it->second;
			node->val = value;
			node->next->last = node->last;
			node->last->next = node->next;
			node_.erase(node->key);
			delete node;
		}
		else if (cap_ == cnt_)
		{
			ListNode1* pTodeleted = pTail_->last;//果然这一步找不到key了，而且一直在完善链表，并没有存储在node_里面
			pTodeleted->last->next = pTail_;
			pTail_->last = pTodeleted->last;
			node_.erase(pTodeleted->key);// 应该在delete之前移除，不然指针的内存释放了
			delete pTodeleted;
		}
		else cnt_++;

		pNode->next = pHead_->next;
		pHead_->next = pNode;
		pNode->next->last = pNode;
		pNode->last = pHead_;

		node_.insert({ key,pNode });
	}
};

//标准库链表 + hash，看着题解、cplus网站复习list用法，标准库中迭代器各种使用还是不熟练
class LRUCache
{
private:
	int cap_;
	list<pair<int, int>>cache;
	unordered_map<int, list<pair<int, int>>::iterator >map;
public:
	LRUCache(int m) :cap_(m) {}
	int get(int key)
	{
		auto it = map.find(key);
		if (it == map.end()) return -1;
		pair<int, int> kv = *(it->second);//map的第二个元素为迭代器，加*为取该位置的元素
		//pair<int, int> kv = *map[key]; 这两个效果一样，不同写法
		cache.erase(map[key]);//earse的参数为迭代器
		cache.push_front(kv);
		//更新map
		map[key] = cache.begin();
		return kv.second;
	}
	void put(int key, int val)
	{
		auto it = map.find(key);
		if (it != map.end())
		{
			cache.erase(map[key]);//earse的参数为迭代器

		}
		else if (cache.size() == cap_)
		{
			auto lastPair = cache.back();
			map.erase(lastPair.first);//map中移除
			cache.pop_back();
		}
		cache.push_front({ key,val });
		//更新map
		map[key] = cache.begin();
	}
};

int main(void)
{
	LRUCache* cache = new LRUCache(2);/* capacity (缓存容量) */
	cache->put(2, 1);
	cache->put(1, 1);
	cache->put(2, 3);
	cache->put(4, 1);
	cache->get(1);
	cache->get(2);
	cache->get(4);

	return 0;
}


