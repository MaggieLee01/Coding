//�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣����ɾ����������ͷ�ڵ㡣
// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};
//ͷ�� �м� β��
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
//������ͨ�����ԣ�˼�������O(1)ʱ����ɾ���ڵ���