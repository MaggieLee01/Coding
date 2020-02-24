//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};
//头部 中间 尾部
ListNode* DeleteNode(ListNode* head, int val) 
{
	ListNode *temp = head;
	if (temp == nullptr) return nullptr;
	if (temp->val == val) return temp->next;

	while (temp->next != nullptr  && temp->next->val != val)
		temp = temp->next;
	if (temp->next->val == val) 
		temp->next = temp->next->next; 
	return head;
}
//上述已通过测试，思考如何在O(1)时间内删除节点呢