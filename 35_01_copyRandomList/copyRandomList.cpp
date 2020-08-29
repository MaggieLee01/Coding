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

//�Ƚ����ڵ�ķ���
Node* copyRandomList(Node* head) 
{
	if (head == nullptr) return nullptr;
	//����ԭʼ�ڵ�
	Node* root  = head;
	Node* root_new  = nullptr;
	//�ȸ������нڵ�
	while (head != nullptr)
	{
		Node* temp = new Node(head->val);
		temp->next  = head->next;
		head->next = temp;
		head = temp->next;
	}
	
	//�ı�random��ָ��
	head = root;
	while (head != nullptr)
	{	
		if (head->random == nullptr)
			head->next->random = nullptr;
		else
			head->next->random = head->random->next;
		head = head->next->next;
	}

	//�ı�next��ָ��
	head = root;
	root_new = head->next;
	while (head != nullptr)
	{
		Node* temp = head->next->next;
		//������յ�
		if (temp == nullptr)
			head->next->next = nullptr;
		else
			head->next->next = temp->next;
		head->next = temp;
		head = temp;
	}
	return root_new;
}

//hashmap�ķ��������ڵ��븴�ƽڵ��Ӧ
Node* copyRandomList(Node* head)
{
	if (head == nullptr) return nullptr;
	map<Node*, Node*> mp;

	Node *dummy = new Node(0);
	Node *p = dummy;
	//�൱��pΪ�ڱ���p��nextΪhead
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