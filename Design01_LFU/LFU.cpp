/*设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。

get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。
在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。

一个项目的使用次数就是该项目被插入后对其调用 get 和 put 函数的次数之和。使用次数会在对应项目被移除后置为 0。

进阶：你是否可以在 O(1) 时间复杂度内执行两项操作？

LFUCache cache = new LFUCache( 2  );// capacity (缓存容量) 
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4

https://leetcode-cn.com/problems/lfu-cache
*/

//LRU比这个简单一些，先去整LRU再学习这个
//LFU 频率 和最近使用均考虑
//看题解，双链表+hash 或者 双哈希 或者 hash+set，查找依靠hash，内部的存储比较灵活

#include<unordered_map>
#include<list>
#include<set>
using namespace std;
//看题解，双链表比较麻烦，跟着官方题解走
//hash + set，利用了set的自动排序特性，时间复杂度 lgn，平衡树的插入删除操作
struct Node
{
	int val_, key_, cnt_, time_;
	Node(int key, int val,int cnt,int time) :key_(key), val_(val), cnt_(cnt), time_(time) {}

	//因为set的关键字为地址，所以直接地址比较了，根本没用到内部元素的比较，题解上set里面是节点类型，不是类型指针
	//bool operator < (const Node* pNode) const	//注意重载运算符的写法，
	//{
	//	return cnt_ == pNode->cnt_ ? time_ < pNode->time_ : cnt_ < pNode->cnt_;
	//}
};
struct setComp
{
	bool operator()(const Node* node1, const Node* node2) const
	{
		return node1->cnt_ == node2->cnt_ ? node1->time_ < node2->time_ : node1->cnt_ < node2->cnt_;
	}
};

class LFUCache01 {
private:
	int cap_;//容量
	int time_;
	unordered_map<int, Node*> key_table;
	set<Node*, setComp> S;//注意自定义排序算法的写法，结构体内重载（）

public:
	LFUCache01(int capacity) :cap_(capacity),time_(0)
	{
		key_table.clear();
		S.clear();
	}

	int get(int key)
	{
		if (cap_ == 0) return -1;
		auto it = key_table.find(key);
		if (it == key_table.end()) return -1;
		Node* pNode = key_table[key];
		S.erase(pNode);
		pNode->cnt_++;
		pNode->time_ = ++time_;
		S.insert(pNode);
		//it->second = node;//此处存放地址，无需更新了
		return pNode->val_;
	}

	void put(int key, int value)
	{
		if (cap_ == 0) return ;
		auto it = key_table.find(key);
		if (it != key_table.end())//已有该元素
		{
			Node* pNode = key_table[key];
			S.erase(pNode);
			pNode->cnt_++;
			pNode->time_ = ++time_;
			pNode->val_ = value;//更新value为最新值
			S.insert(pNode);
		}
		else
		{
			if (cap_ == S.size())//已满，剔除元素
			{
				Node* pNode = *(S.begin());//最小的在开头
				S.erase(pNode);
				key_table.erase(pNode->key_);
			}
			Node* pNew = new Node(key, value, 1, ++time_);
			//Node pNew =  Node(key, value,1,++time_);可以直接创建临时对象，new是堆对象的指针，糊涂了
			S.insert(pNew);
			key_table.insert({ key, pNew });
		}
	}
};

//使用哈希存储，哈希查找
struct fNode
{
	int key_, val_, freq_;
	fNode(int key,int val,int freq):key_(key),val_(val),freq_(freq){}
};
class LFUCache 
{
private:
	int cap_, minFreq_;
	unordered_map<int, list<fNode>::iterator> key_table;//key 和 对应的节点索引组成了map
	unordered_map<int, list<fNode>>freq_table;//一个频率点对应一个链表，从头部push，尾部即为最早的时间点
public:
	LFUCache(int cap) :cap_(cap), minFreq_(0)
	{
		key_table.clear();
		freq_table.clear();
	}
	int get(int key)
	{
		auto it = key_table.find(key);
		if (it == key_table.end()) return -1;
		auto itNode = it->second;
		fNode fTempNode = *key_table[key];
		int freq = fTempNode.freq_, value = fTempNode.val_;
		freq_table[freq].erase(itNode);
		if (freq_table[freq].empty())
		{
			freq_table.erase(freq);
			if (freq == minFreq_) minFreq_++;
		}
		//erase已经删除了节点，迭代器就失效了，所以后面不能再用迭代器了，应该重新创建节点
		//(*itNode).freq_++;
		freq++;		//不要忘记频率的更新呀
		freq_table[freq].push_front(fNode(key, value, freq));
		key_table[key] = freq_table[freq].begin();
		return value;
	}
	void put(int key, int value)
	{
		if (cap_ == 0) return;
		auto it1 = key_table.find(key);
		if (it1 == key_table.end())//新元素
		{
			if (cap_ == key_table.size())//满了先删元素
			{
				auto it = freq_table[minFreq_].back();//不要忘记先删除key呀
				key_table.erase(it.key_);
				freq_table[minFreq_].pop_back();//弹出最小频率的最后一个节点
				if (freq_table[minFreq_].size() == 0)
					//minFreq_++; 不是增加1，而是应该erase，因为插入的新元素频率为1呀
					freq_table.erase(minFreq_);
			}
			fNode node = fNode(key, value, 1);
			freq_table[1].push_front(node);
			key_table[key] = freq_table[1].begin();
			minFreq_ = 1;
		}
		else
		{			
			auto it = key_table[key];
			int freq = (*it).freq_;
			freq_table[freq].erase(it);
			if (freq_table[freq].empty())
			{
				freq_table.erase(freq);
				if(freq == minFreq_) minFreq_++;
			}
			//此时迭代器已经无效了
			//(*it).freq_++;
			//(*it).val_ = value;//value可能会变化
			freq++;			//不要忘记频率的更新呀
			freq_table[freq].push_front(fNode(key, value, freq));//此处参数为右值，实际调用的是移动拷贝。
			key_table[key] = freq_table[freq].begin();

		}
	}
};

int main(void)
{
	LFUCache* cache = new LFUCache(3);/* capacity (缓存容量) */
	cache->put(2, 2);
	cache->put(1, 1);

	cache->get(2);
	cache->get(1);
	cache->get(2);
	cache->put(3, 3);
	cache->put(4, 4);        
	cache->get(3);       
	cache->get(2);	
	cache->get(1); 
	cache->get(4);       

	return 0;
}

