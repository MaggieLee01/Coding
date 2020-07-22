/*输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。*/

//网页编辑问题不大，树的简单操作基本掌握
#include<algorithm>
#include<stack>
#include<iostream>
using std::cout;
using std::endl;
using std::stack;
using std::max;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int maxDepth(TreeNode* root)
{
	if (root == nullptr)  return 0;
	int depth = max(maxDepth(root->left), maxDepth(root->right)) + 1;
	return depth;
}

//练习非递归形式的写法，层次遍历更好写，且自己熟练一些；看题解有后序非递归的写法
//int maxDepth_01(TreeNode* root)
//{
//	if (root == nullptr)  return 0;
//	int ans = 0, num = 0;
//	stack<TreeNode *> s;
//	s.push(root);
//	while(s.size())
//	{
//		TreeNode *temp = s.top();
//		while (temp->left != nullptr)
//		{
//			s.push(temp->left);
//			num++;
//		}
//		
//		if(temp->right != nullptr)
//			num++;
//		ans = max(ans, num);
//		s.pop();
//	}
//}
//思考呀一会，不太会写
//参考题解：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/solution/san-chong-jie-fa-hou-xu-bian-li-di-gui-fa-hou-xu-b/
int maxDepth_stack(TreeNode* root)
{
	if (root == nullptr)  return 0;
	int ans = 0;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size())//经验，while循环里面套if，或者if里面套while，然后遍历。尽量不要while 嵌套while
	{
		int length = s.size();
		ans = max(ans, length);//栈中的元素在一条路径上
		TreeNode *topNode = s.top();
		//if (topNode->left != nullptr && topNode->left != lastVisited && topNode->right != nullptr && topNode->right != lastVisited)
		//开始自作聪明 在上面加了右子树非空的判断，运行之后才发现，判断子树是否为空是为了压入栈，而判断是否等于LastVisited 是为了看该节点的子树是否被访问过
		if (topNode->left != nullptr && topNode->left != lastVisited && topNode->right != lastVisited)
			s.push(topNode->left);
		else if (topNode->right != nullptr && topNode->right != lastVisited)
			s.push(topNode->right);
		else
		{  
			lastVisited = topNode;
			s.pop();
		}
	}
}
//思考。是不是可以利用上面那一套模板完成前中后的非递归遍历呢
void PrintPreOrder(TreeNode* root)
{
	if (root == nullptr)  return ;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	std::cout << root->val << ' ';
	while (s.size())//经验，while循环里面套if，或者if里面套while，然后遍历。尽量不要while 嵌套while
	{		
		TreeNode *topNode = s.top();
		if (topNode->left != nullptr && topNode->left != lastVisited && topNode->right != lastVisited)
		{
			s.push(topNode->left);
			std::cout << topNode->left->val << ' ';
		}
			
		else if (topNode->right != nullptr && topNode->right != lastVisited)
		{
			s.push(topNode->right);
			std::cout << topNode->right->val << ' ';
		}			
		else
		{
			lastVisited = topNode;
			s.pop();
		}
	}
	std::cout << endl;
}
//前序改后序很简单，遍历顺序不变，打印的时间变化即可，只需一个栈，无需辅助栈
void PrintPostOrder(TreeNode* root)
{
	if (root == nullptr)  return;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size())//经验，while循环里面套if，或者if里面套while，然后遍历。尽量不要while 嵌套while
	{
		TreeNode *topNode = s.top();
		if (topNode->left != nullptr && topNode->left != lastVisited && topNode->right != lastVisited)
			s.push(topNode->left);
		else if (topNode->right != nullptr && topNode->right != lastVisited)
			s.push(topNode->right);		
		else
		{
			lastVisited = topNode;
			std::cout << topNode->val << ' ';
			s.pop();
		}
	}
	std::cout << endl;
}
//中序方法，弹出节点的时候再次打印栈顶节点，那第一次怎么整，没想好怎么处理
void PrintInOrder(TreeNode* root)
{
	if (root == nullptr)  return;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size())
	{
		TreeNode *topNode = s.top();
		if (topNode->left != nullptr && topNode->left != lastVisited && topNode->right != lastVisited)
			s.push(topNode->left);
		else if (topNode->right != nullptr && topNode->right != lastVisited)
			s.push(topNode->right);
		else
		{
			lastVisited = topNode;
			std::cout << topNode->val << ' ';
			s.pop();
			/*TreeNode *temp = s.top();
			std::cout << temp->val << ' ';*/
		}
	}
	std::cout << endl;
}
//左神视频里面的方法，非递归遍历
void PrintPreOrder_zuo(TreeNode* root)
{
	if (root == nullptr)  return;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size())
	{
		TreeNode *topNode = s.top();
		s.pop();
		std::cout << topNode->val << ' ';
		if (topNode->right != nullptr)
			s.push(topNode->right);
		if (topNode->left != nullptr)
			s.push(topNode->left);
	}
	std::cout << endl;
}
//将弹出的节点压入辅助栈，然后压入左子树 右子树 ，最后打印辅助栈
void PrintPostOrder_zuo(TreeNode* root)
{
	if (root == nullptr)  return;
	stack<TreeNode *> s;
	stack<TreeNode *> s2;
	s.push(root);
	while (s.size())
	{
		TreeNode *topNode = s.top();
		s.pop();
		s2.push(topNode);
		if (topNode->left != nullptr)
			s.push(topNode->left);
		if (topNode->right != nullptr)
			s.push(topNode->right);		
	}
	while (s2.size())
	{
		std::cout << s2.top()->val << ' ';
		s2.pop();
	}	
	std::cout << endl;
}

void PrintInOrder_zuo(TreeNode* root)
{
	if (root == nullptr)  return;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size() || root != nullptr)
	{
		if (root != nullptr)
		{
			s.push(root);
			root = root->left;
		}
		else
		{ 
			root = s.top();
			s.pop();
			std::cout << root->val << ' ';
			root = root->right;
		}
	}
	std::cout << endl;
}

//非递归遍历树：分为辅助节点 和 左神 两种方法
//辅助节点：前序的话压入即打印，后序的话弹出即打印；不知道如何处理中序
//左神方法：弹出栈顶节点，前序先右后左，后序先左后右，外加辅助栈


int main(void)
{
	TreeNode*p = nullptr;
	TreeNode*p1 = new TreeNode(1);
	TreeNode*p2 = new TreeNode(2);
	TreeNode*p3 = new TreeNode(3);
	TreeNode*p4 = new TreeNode(4);
	TreeNode*p5 = new TreeNode(5);
	TreeNode*p6 = new TreeNode(6);
	TreeNode*p7 = new TreeNode(7);

	p1->left = p2;
	p1->right = p3;
	p2->left = p4;
	p2->right = p5;
	p3->left = p6;
	p3->right = p7;
	
	PrintInOrder(p1);
	PrintInOrder_zuo(p1);

	PrintPostOrder(p1);
	PrintPostOrder_zuo(p1);
	
	return 0;
}