#include<map>
using namespace std;

class Node 
{
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) 
	{
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

//先紧跟节点的方法
Node* copyRandomList(Node* head) 
{
	if (head == nullptr) return nullptr;
	//保留原始节点
	Node* root  = head;
	Node* root_new  = nullptr;
	//先复制所有节点
	while (head != nullptr)
	{
		Node* temp = new Node(head->val);
		temp->next  = head->next;
		head->next = temp;
		head = temp->next;
	}
	
	//改变random的指向
	head = root;
	while (head != nullptr)
	{	
		if (head->random == nullptr)
			head->next->random = nullptr;
		else
			head->next->random = head->random->next;
		head = head->next->next;
	}

	//改变next的指向
	head = root;
	root_new = head->next;
	while (head != nullptr)
	{
		Node* temp = head->next->next;
		//链表的终点
		if (temp == nullptr)
			head->next->next = nullptr;
		else
			head->next->next = temp->next;
		head->next = temp;
		head = temp;
	}
	return root_new;
}

//hashmap的方法，讲节点与复制节点对应
Node* copyRandomList(Node* head)
{
	if (head == nullptr) return nullptr;
	map<Node*, Node*> mp;

	Node *dummy = new Node(0);
	Node *p = dummy;
	//相当于p为哨兵，p的next为head
	while (head)
	{
		if (mp[head] == nullptr)
		{
			mp[head] = new Node(head->val);
			p->next = mp[head];
		}
		else
			p->next = mp[head];

		if (head->random != nullptr)
		{
			if (mp[head->random] == nullptr)
			{
				mp[head->random] = new Node(head->random->val);
				p->next->random = mp[head->random];
			}
			else
				p->next->random = mp[head->random];
		}
		head = head->next;
		p = p->next;
	}
	return dummy->next;
}