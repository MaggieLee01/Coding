//	https://mp.weixin.qq.com/s/v4uhNh65t2vKSW7wCpPthQ
/*	LRU������ƣ����δʹ����̭ԭ��
	https://leetcode-cn.com/problems/lru-cache/
�����������յ����ݽṹ����ƺ�ʵ��һ��  LRU (�������ʹ��) ������ơ���Ӧ��֧�����²����� ��ȡ���� get �� д������ put ��
��ȡ���� get(key) - �����Կ (key) �����ڻ����У����ȡ��Կ��ֵ�����������������򷵻� -1��
д������ put(key, value) - �����Կ�����ڣ���д��������ֵ�������������ﵽ����ʱ����Ӧ����д��������֮ǰɾ�����δʹ�õ�����ֵ���Ӷ�Ϊ�µ�����ֵ�����ռ䡣
д�������������ǰ�档
����:
���Ƿ������ O(1) ʱ�临�Ӷ�����������ֲ�����

LRUCache cache = new LRUCache( 2   );//��������������JAVA, C++��new��������ָ�롿
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // ����  1
cache.put(3, 3);    // �ò�����ʹ����Կ 2 ����
cache.get(2);       // ���� -1 (δ�ҵ�)
cache.put(4, 4);    // �ò�����ʹ����Կ 1 ����
cache.get(1);       // ���� -1 (δ�ҵ�)
cache.get(3);       // ����  3
cache.get(4);       // ����  4
*/
#include<unordered_map>
#include<utility>
#include<list>
using namespace std;

//�Լ�д���� + hash���ؼ������� ��ɾ�ڵ�֮��˫������ĸ��£�������⣬Ӧ�ý�������������������µĺ���
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
	int cap_;//����
	int cnt_;
	unordered_map<int, ListNode1*> node_;
	ListNode1* pHead_;
	ListNode1* pTail_;
public:
	//�����˸����ڵ㣬��������ͷ�����Ӹ�����˫������Ļ����߶�Ӧ������
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
		//return it->first; Ҫ���ص���val������key
		return it->second->val;
	}

	void put(int key, int value)
	{
		//if (cap_ == cnt_)
		//{
		//	ListNode1* pTodeleted = pTail_->last;//��Ȼ��һ���Ҳ���key�ˣ�����һֱ������������û�д洢��node_����
		//	pTodeleted->last->next = pNode;
		//	pNode->last = pTodeleted->last;
		//	node_.erase(pTodeleted->key);// Ӧ����delete֮ǰ�Ƴ�����Ȼָ����ڴ��ͷ���
		//	delete pTodeleted;
		//}
		//else
		//{
		//	pTail_->last->next = pNode;
		//	pNode->last = pTail_->last;//��Ҫ����last��ֵ
		//	cnt_++;
		//}
		//pNode->next = pTail_;
		//pTail_->last = pNode;
		//node_.insert({ key,pNode });


		//�����������ĩβ���룬��ĿҪ��������ǰ����룬put get ��Ӧ������ǰ�棬���˺ܶ�
		//��һ������������ˣ���putһ���Ѵ��ڵ�keyʱ������֮ǰ��value��ͬʱ������ͷ
		auto it = node_.find(key);
		ListNode1* pNode = new ListNode1(key, value);
		if (it != node_.end())//�޸ĸ���Ӧ�ø��ã����Ǵ����鷳
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
			ListNode1* pTodeleted = pTail_->last;//��Ȼ��һ���Ҳ���key�ˣ�����һֱ������������û�д洢��node_����
			pTodeleted->last->next = pTail_;
			pTail_->last = pTodeleted->last;
			node_.erase(pTodeleted->key);// Ӧ����delete֮ǰ�Ƴ�����Ȼָ����ڴ��ͷ���
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

//��׼������ + hash��������⡢cplus��վ��ϰlist�÷�����׼���е���������ʹ�û��ǲ�����
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
		pair<int, int> kv = *(it->second);//map�ĵڶ���Ԫ��Ϊ����������*Ϊȡ��λ�õ�Ԫ��
		//pair<int, int> kv = *map[key]; ������Ч��һ������ͬд��
		cache.erase(map[key]);//earse�Ĳ���Ϊ������
		cache.push_front(kv);
		//����map
		map[key] = cache.begin();
		return kv.second;
	}
	void put(int key, int val)
	{
		auto it = map.find(key);
		if (it != map.end())
		{
			cache.erase(map[key]);//earse�Ĳ���Ϊ������

		}
		else if (cache.size() == cap_)
		{
			auto lastPair = cache.back();
			map.erase(lastPair.first);//map���Ƴ�
			cache.pop_back();
		}
		cache.push_front({ key,val });
		//����map
		map[key] = cache.begin();
	}
};

int main(void)
{
	LRUCache* cache = new LRUCache(2);/* capacity (��������) */
	cache->put(2, 1);
	cache->put(1, 1);
	cache->put(2, 3);
	cache->put(4, 1);
	cache->get(1);
	cache->get(2);
	cache->get(4);

	return 0;
}


