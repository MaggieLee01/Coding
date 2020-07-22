/*����һ�ö������ĸ��ڵ㣬���������ȡ��Ӹ��ڵ㵽Ҷ�ڵ����ξ����Ľڵ㣨������Ҷ�ڵ㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�*/

//��ҳ�༭���ⲻ�����ļ򵥲�����������
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

//��ϰ�ǵݹ���ʽ��д������α�������д�����Լ�����һЩ��������к���ǵݹ��д��
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
//˼��ѽһ�ᣬ��̫��д
//�ο���⣺https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/solution/san-chong-jie-fa-hou-xu-bian-li-di-gui-fa-hou-xu-b/
int maxDepth_stack(TreeNode* root)
{
	if (root == nullptr)  return 0;
	int ans = 0;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size())//���飬whileѭ��������if������if������while��Ȼ�������������Ҫwhile Ƕ��while
	{
		int length = s.size();
		ans = max(ans, length);//ջ�е�Ԫ����һ��·����
		TreeNode *topNode = s.top();
		//if (topNode->left != nullptr && topNode->left != lastVisited && topNode->right != nullptr && topNode->right != lastVisited)
		//��ʼ�������� ����������������ǿյ��жϣ�����֮��ŷ��֣��ж������Ƿ�Ϊ����Ϊ��ѹ��ջ�����ж��Ƿ����LastVisited ��Ϊ�˿��ýڵ�������Ƿ񱻷��ʹ�
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
//˼�����ǲ��ǿ�������������һ��ģ�����ǰ�к�ķǵݹ������
void PrintPreOrder(TreeNode* root)
{
	if (root == nullptr)  return ;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	std::cout << root->val << ' ';
	while (s.size())//���飬whileѭ��������if������if������while��Ȼ�������������Ҫwhile Ƕ��while
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
//ǰ��ĺ���ܼ򵥣�����˳�򲻱䣬��ӡ��ʱ��仯���ɣ�ֻ��һ��ջ�����踨��ջ
void PrintPostOrder(TreeNode* root)
{
	if (root == nullptr)  return;
	TreeNode* lastVisited = root;
	stack<TreeNode *> s;
	s.push(root);
	while (s.size())//���飬whileѭ��������if������if������while��Ȼ�������������Ҫwhile Ƕ��while
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
//���򷽷��������ڵ��ʱ���ٴδ�ӡջ���ڵ㣬�ǵ�һ����ô����û�����ô����
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
//������Ƶ����ķ������ǵݹ����
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
//�������Ľڵ�ѹ�븨��ջ��Ȼ��ѹ�������� ������ ������ӡ����ջ
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

//�ǵݹ����������Ϊ�����ڵ� �� ���� ���ַ���
//�����ڵ㣺ǰ��Ļ�ѹ�뼴��ӡ������Ļ���������ӡ����֪����δ�������
//���񷽷�������ջ���ڵ㣬ǰ�����Һ��󣬺���������ң���Ӹ���ջ


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