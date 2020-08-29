//˫ָ�뼼�ɻ����Է�Ϊ���࣬һ���ǡ�����ָ�롹��һ���ǡ�����ָ�롹��
//ǰ�߽����Ҫ��������е����⣬������͵��ж��������Ƿ����������n���ڵ㣻������Ҫ������飨�����ַ������е����⣬������ֲ��ҡ�
//2019-06-16 https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg

#include<vector>

struct ListNode 
{
	int val;			//int m_nValue��� Ϊ�����LeetCodeϵͳ
	ListNode* next;		// m_pNext
	ListNode(int val) : val(val), next(nullptr) {}
};

//����һ�������ж��������Ƿ��л���
// https://leetcode-cn.com/problems/linked-list-cycle LeetCode 141
bool hasCycle(ListNode *head)
{
	if (head == nullptr) return false;
	ListNode* fast = head;
	ListNode* low = head;
	while (fast != nullptr && fast->next != nullptr)//��Ҫ���߶���Ϊ�ղ��ܼ�������
	{
		/*if (fast == low) 	return true;*///��Ϊ������������fast��ʼ��Ϊhead->next
		fast = fast->next->next;
		low = low->next;
		if (fast == low)	return true;//ָ�붼�ƶ����жϣ�д���ƶ�ǰ��Ļ���ͷΪ��ȷ�����
	}
	return false;
}

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
// https://leetcode-cn.com/problems/linked-list-cycle-ii/ LeetCode142
ListNode* DetectCycle(ListNode* head)
{
	if (head == nullptr) return nullptr;
	ListNode* fast = head;
	ListNode* low = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		fast = fast->next->next;
		low = low->next;
		if (fast == low)//�����㲻�ǻ�����ʼ�㣬��Ҫ��������һ�飬�һ�����㻹����̫��Ϥѽ
			break;
		/*{
			int ans = 0;
			ListNode* temp = head;
			while (temp != low)
			{
				ans++;
				temp = temp->next;
			}
			return ans;
		}*/
	}
	if (fast == nullptr || fast->next == nullptr) return nullptr;//ֻ��һ���ڵ� �Լ� �����޻������
	low = head;
	while (low != fast)
	{
		low = low->next;
		fast = fast->next;
	}
	return low;
}

//Ѱ��������е㣬��ָ�뵽�յ㣬��ָ��Ϊ�е㣻��������Ķ��ַ�
//https://leetcode-cn.com/problems/middle-of-the-linked-list/
ListNode* middleNode(ListNode* head)
{
	//ListNode pDummy = ListNode(1);
	//pDummy.next = head;
	//ListNode *pFast = &pDummy;
	//ListNode *pLow = &pDummy;
	////while (pFast->next != nullptr && pFast->next->next != nullptr)//�˴����ж� �� ����ֵ ���ڲݸ�ֽ��дһд
	//{
	//	pFast = pFast->next->next;
	//	pLow = pLow->next;
	//}
	////return pLow->next;
	
	ListNode* lo = head;
	ListNode* hi = head;
	while (hi != nullptr && hi->next != nullptr)
	{
		lo = lo->next;
		hi = hi->next->next;
	}
	return lo;
}


//Ѱ������ĵ����� k ��Ԫ��
//����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
//���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣
//ʾ��������һ������ : 1->2->3->4->5, �� k = 2.	�������� 4->5.
// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
ListNode* getKthFromEnd(ListNode* head, int k)
{
	if (head == nullptr) return nullptr;
	int i = 0;
	ListNode *fast = head, *low = head;

	while (fast != nullptr && i++ < k)
		fast = fast->next;
	if (i != k) return nullptr;
	while (fast != nullptr)
	{
		fast = fast->next;
		low = low->next;
	}
	return low;
}

//����ָ��Ӧ�ã����ַ�����ת���� 

//����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������
//����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��
// ����: numbers = [2, 7, 11, 15], target = 9��	��� : [1, 2]
// ���� : 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted  LeetCode 167
// �������� ���Կ�������ָ��
using std::vector;
vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> ans(2, -1);
	//int Length = numbers.size();������ʹ��length ����Զ���һ���������˴�û��Ҫ
	/*if (Length < 2) return ans;*/

	int left = 0, right = numbers.size() - 1;
	while (left < right)
	{
		int sum = numbers[left] + numbers[right];
		//if (numbers[left] + numbers[right] == target)//��
		if (sum == target)
		{
			ans[0] = left + 1;//LeetCode����ϵͳ���������ֵ��1��ʼ
			ans[1] = right + 1;
			break;
		}
		if (sum > target)// ̫������Ҫ��С
			right--;
		else left++;
	}
	return ans;
}


int main(void)
{
	ListNode *head = new ListNode(-21);
	ListNode *p1 = new ListNode(10);
	ListNode *p2 = new ListNode(17);
	ListNode *p3 = new ListNode(8);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(26);
	ListNode *p6 = new ListNode(5);
	ListNode *p7 = new ListNode(35);
	ListNode *p8 = new ListNode(33);
	ListNode *p9 = new ListNode(-7);
	ListNode *p10 = new ListNode(-16);
	ListNode *p11 = new ListNode(27);
	ListNode *p12 = new ListNode(-12);
	ListNode *p13 = new ListNode(6);
	ListNode *p14 = new ListNode(29);
	ListNode *p15 = new ListNode(-12);
	ListNode *p16 = new ListNode(5);
	ListNode *p17 = new ListNode(9);
	ListNode *p18 = new ListNode(20);
	ListNode *p19 = new ListNode(14);
	ListNode *p20 = new ListNode(14);
	ListNode *p21 = new ListNode(2);
	ListNode *p22 = new ListNode(13);
	ListNode *p23 = new ListNode(-24);
	ListNode *p24 = new ListNode(21);
	ListNode *p25 = new ListNode(23);
	ListNode *p26 = new ListNode(-21);
	ListNode *p27 = new ListNode(5);

	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p8;
	p8->next = p9;
	p9->next = p10;
	p10->next = p11;
	p11->next = p12;
	p12->next = p13;
	p13->next = p14;
	p14->next = p15;
	p15->next = p16;
	p16->next = p17;
	p17->next = p18;
	p18->next = p19;
	p19->next = p20;
	p20->next = p21;
	p21->next = p22;
	p22->next = p23;
	p23->next = p24;
	p24->next = p25;
	p25->next = p26;
	p26->next = p27;
	hasCycle(head);
}