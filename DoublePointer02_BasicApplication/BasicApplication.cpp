//双指针技巧还可以分为两类，一类是「快慢指针」，一类是「左右指针」。
//前者解决主要解决链表中的问题，比如典型的判定链表中是否包含环、第n个节点；后者主要解决数组（或者字符串）中的问题，比如二分查找。
//2019-06-16 https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg

#include<vector>

struct ListNode 
{
	int val;			//int m_nValue最佳 为了配合LeetCode系统
	ListNode* next;		// m_pNext
	ListNode(int val) : val(val), next(nullptr) {}
};

//给定一个链表，判断链表中是否有环。
// https://leetcode-cn.com/problems/linked-list-cycle LeetCode 141
bool hasCycle(ListNode *head)
{
	if (head == nullptr) return false;
	ListNode* fast = head;
	ListNode* low = head;
	while (fast != nullptr && fast->next != nullptr)//需要两者都不为空才能继续遍历
	{
		/*if (fast == low) 	return true;*///曾为了这个问题错误将fast初始化为head->next
		fast = fast->next->next;
		low = low->next;
		if (fast == low)	return true;//指针都移动过判断，写在移动前面的话则开头为相等返回了
	}
	return false;
}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
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
		if (fast == low)//相遇点不是环的起始点，需要再重新走一遍，找环的起点还不是太熟悉呀
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
	if (fast == nullptr || fast->next == nullptr) return nullptr;//只有一个节点 以及 其他无环的情况
	low = head;
	while (low != fast)
	{
		low = low->next;
		fast = fast->next;
	}
	return low;
}

//寻找链表的中点，快指针到终点，慢指针为中点；用于链表的二分法
//https://leetcode-cn.com/problems/middle-of-the-linked-list/
ListNode* middleNode(ListNode* head)
{
	//ListNode pDummy = ListNode(1);
	//pDummy.next = head;
	//ListNode *pFast = &pDummy;
	//ListNode *pLow = &pDummy;
	////while (pFast->next != nullptr && pFast->next->next != nullptr)//此处的判断 和 返回值 多在草稿纸上写一写
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


//寻找链表的倒数第 k 个元素
//输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
//例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
//示例：给定一个链表 : 1->2->3->4->5, 和 k = 2.	返回链表 4->5.
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

//左右指针应用：二分法，翻转数组 

//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
// 输入: numbers = [2, 7, 11, 15], target = 9，	输出 : [1, 2]
// 解释 : 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted  LeetCode 167
// 数组有序 所以可以左右指针
using std::vector;
vector<int> twoSum(vector<int>& numbers, int target)
{
	vector<int> ans(2, -1);
	//int Length = numbers.size();如果多次使用length 则可以定义一个变量，此处没必要
	/*if (Length < 2) return ans;*/

	int left = 0, right = numbers.size() - 1;
	while (left < right)
	{
		int sum = numbers[left] + numbers[right];
		//if (numbers[left] + numbers[right] == target)//简化
		if (sum == target)
		{
			ans[0] = left + 1;//LeetCode测试系统此题的索引值从1开始
			ans[1] = right + 1;
			break;
		}
		if (sum > target)// 太大了需要缩小
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