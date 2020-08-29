//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

#include<stack>
using namespace std;

class Node 
{
public:
	int val;
	Node* left;
	Node* right;
	Node() {}
	Node(int _val) 
	{
		val = _val;
		left = nullptr;
		right = nullptr;
	}
	Node(int _val, Node* _left, Node* _right) 
	{
		val = _val;
		left = _left;
		right = _right;
	}
};
Node *pre, *Head; //指针的*不共用
void dfs(Node* cur)
{
	if (cur == nullptr) return;
	dfs(cur->left);
	if (pre == nullptr)
		Head = cur;
	else
		pre->right = cur;
	cur->left = pre;
	pre = cur;
	dfs(cur->right);
}
Node* treeToDoublyList(Node* root)
{
	if (root == nullptr) return nullptr;
	dfs(root);
	pre->right = Head;
	Head->left = pre;
	return Head;
}

//非递归 用栈的方法
//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/solution/bu-yao-huang-ni-de-yi-bu-yi-bu-lai-by-chopin-7/

Node* treeToDoublyList01(Node* root)
{
	//突然发现一个问题，难道全局变量的指针能自动为空，但是局部指针变量必须初始化
	Node* pre1, *Head1;
	if (root == nullptr) return root;
	stack<Node*> stk;
	stk.push(root);
	while (stk.size())
	{
		Node* top = stk.top();
		stk.pop();
		if (top != nullptr)
		{
			//只需改变根节点的压入顺序即可			
			if (top->right != nullptr) stk.push(top->right);
			stk.push(top);
			stk.push(nullptr);
			if (top->left != nullptr) stk.push(top->left);
		}
		else
		{
			if (pre == nullptr)
				Head = stk.top();
			else
				pre->right = stk.top();
			stk.top()->left = pre;
			pre = stk.top();
			stk.pop();
		}
	}
	Head->left = pre;
	pre->right = Head;
	return Head;
}

int main(void)
{
	Node* root1 = new Node(1);
	Node* root3 = new Node(3);
	Node* root5 = new Node(5);
	Node* root2 = new Node(2,root1,root3);
	Node* root4 = new Node(4,root2,root5);
	treeToDoublyList01(root4);
	return 0;
}