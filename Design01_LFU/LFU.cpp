/*��Ʋ�ʵ�������ʹ�ã�LFU����������ݽṹ����Ӧ��֧�����²�����get �� put��

get(key) - ����������ڻ����У����ȡ����ֵ�����������������򷵻� -1��
put(key, value) - ����������ڣ������û����ֵ��������ﵽ������ʱ����Ӧ���ڲ�������Ŀ֮ǰ��ʹ�����ʹ�õ���Ŀ��Ч��
�ڴ������У�������ƽ�֣���������������������ͬʹ��Ƶ�ʣ�ʱ���������ʹ�õļ�����ȥ����

һ����Ŀ��ʹ�ô������Ǹ���Ŀ������������� get �� put �����Ĵ���֮�͡�ʹ�ô������ڶ�Ӧ��Ŀ���Ƴ�����Ϊ 0��

���ף����Ƿ������ O(1) ʱ�临�Ӷ���ִ�����������

LFUCache cache = new LFUCache( 2  );// capacity (��������) 
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // ���� 1
cache.put(3, 3);    // ȥ�� key 2
cache.get(2);       // ���� -1 (δ�ҵ�key 2)
cache.get(3);       // ���� 3
cache.put(4, 4);    // ȥ�� key 1
cache.get(1);       // ���� -1 (δ�ҵ� key 1)
cache.get(3);       // ���� 3
cache.get(4);       // ���� 4

https://leetcode-cn.com/problems/lfu-cache
*/

//LRU�������һЩ����ȥ��LRU��ѧϰ���
//LFU Ƶ�� �����ʹ�þ�����
//����⣬˫����+hash ���� ˫��ϣ ���� hash+set����������hash���ڲ��Ĵ洢�Ƚ����

#include<unordered_map>
#include<list>
#include<set>
using namespace std;
//����⣬˫����Ƚ��鷳�����Źٷ������
//hash + set��������set���Զ��������ԣ�ʱ�临�Ӷ� lgn��ƽ�����Ĳ���ɾ������
struct Node
{
	int val_, key_, cnt_, time_;
	Node(int key, int val,int cnt,int time) :key_(key), val_(val), cnt_(cnt), time_(time) {}

	//��Ϊset�Ĺؼ���Ϊ��ַ������ֱ�ӵ�ַ�Ƚ��ˣ�����û�õ��ڲ�Ԫ�صıȽϣ������set�����ǽڵ����ͣ���������ָ��
	//bool operator < (const Node* pNode) const	//ע�������������д����
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
	int cap_;//����
	int time_;
	unordered_map<int, Node*> key_table;
	set<Node*, setComp> S;//ע���Զ��������㷨��д�����ṹ�������أ���

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
		//it->second = node;//�˴���ŵ�ַ�����������
		return pNode->val_;
	}

	void put(int key, int value)
	{
		if (cap_ == 0) return ;
		auto it = key_table.find(key);
		if (it != key_table.end())//���и�Ԫ��
		{
			Node* pNode = key_table[key];
			S.erase(pNode);
			pNode->cnt_++;
			pNode->time_ = ++time_;
			pNode->val_ = value;//����valueΪ����ֵ
			S.insert(pNode);
		}
		else
		{
			if (cap_ == S.size())//�������޳�Ԫ��
			{
				Node* pNode = *(S.begin());//��С���ڿ�ͷ
				S.erase(pNode);
				key_table.erase(pNode->key_);
			}
			Node* pNew = new Node(key, value, 1, ++time_);
			//Node pNew =  Node(key, value,1,++time_);����ֱ�Ӵ�����ʱ����new�ǶѶ����ָ�룬��Ϳ��
			S.insert(pNew);
			key_table.insert({ key, pNew });
		}
	}
};

//ʹ�ù�ϣ�洢����ϣ����
struct fNode
{
	int key_, val_, freq_;
	fNode(int key,int val,int freq):key_(key),val_(val),freq_(freq){}
};
class LFUCache 
{
private:
	int cap_, minFreq_;
	unordered_map<int, list<fNode>::iterator> key_table;//key �� ��Ӧ�Ľڵ����������map
	unordered_map<int, list<fNode>>freq_table;//һ��Ƶ�ʵ��Ӧһ��������ͷ��push��β����Ϊ�����ʱ���
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
		//erase�Ѿ�ɾ���˽ڵ㣬��������ʧЧ�ˣ����Ժ��治�����õ������ˣ�Ӧ�����´����ڵ�
		//(*itNode).freq_++;
		freq++;		//��Ҫ����Ƶ�ʵĸ���ѽ
		freq_table[freq].push_front(fNode(key, value, freq));
		key_table[key] = freq_table[freq].begin();
		return value;
	}
	void put(int key, int value)
	{
		if (cap_ == 0) return;
		auto it1 = key_table.find(key);
		if (it1 == key_table.end())//��Ԫ��
		{
			if (cap_ == key_table.size())//������ɾԪ��
			{
				auto it = freq_table[minFreq_].back();//��Ҫ������ɾ��keyѽ
				key_table.erase(it.key_);
				freq_table[minFreq_].pop_back();//������СƵ�ʵ����һ���ڵ�
				if (freq_table[minFreq_].size() == 0)
					//minFreq_++; ��������1������Ӧ��erase����Ϊ�������Ԫ��Ƶ��Ϊ1ѽ
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
			//��ʱ�������Ѿ���Ч��
			//(*it).freq_++;
			//(*it).val_ = value;//value���ܻ�仯
			freq++;			//��Ҫ����Ƶ�ʵĸ���ѽ
			freq_table[freq].push_front(fNode(key, value, freq));//�˴�����Ϊ��ֵ��ʵ�ʵ��õ����ƶ�������
			key_table[key] = freq_table[freq].begin();

		}
	}
};

int main(void)
{
	LFUCache* cache = new LFUCache(3);/* capacity (��������) */
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

