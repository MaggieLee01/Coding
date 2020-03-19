/*输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
B是A的子结构， 即 A中有出现和B相同的结构和节点值。*/

#include<queue>
using std::queue;
struct TreeNode 
{
	int val; 
	TreeNode* left;
	TreeNode *right;
	TreeNode(int m):val(m),left(nullptr),right(nullptr){}
};

//判断开头相同的两个树，B是否为A的子树
bool isSameStruct_Re(TreeNode *A, TreeNode *B)
{
	//B可以没有A有的，但不能有A没有的
	if (A == nullptr && B != nullptr) return false;
	if (B == nullptr) return true; 
	if (A->val != B->val) return false;
	else
	{
		if (isSameStruct_Re(A->left, B->left))
			return isSameStruct_Re(A->right, B->right);
		return false;
	}
}
bool isSubStructure(TreeNode *A, TreeNode *B)
{
	if (A == nullptr || B == nullptr) return false;
	TreeNode *ATemp = A;
	queue<TreeNode *> Dict;
	//先层次遍历寻找开头
	Dict.push(ATemp);
	while (Dict.size())
	{
		TreeNode *top = Dict.front();
		Dict.pop();
		//找到节点值相同时，判断是否为子树
		if (top->val == B->val && isSameStruct_Re(top, B))	
			return true;		
		if (top->left != nullptr) Dict.push(top->left);
		if (top->right != nullptr) Dict.push(top->right);
	}
	return false;
}

//上面自己写的代码通过了，是不是为回溯思想；看看题解与课本答案
//看了题解，答案，寻找起始节点 和 判断是否为子树，均用了递推
bool isSameStruct_Reanswer(TreeNode *A, TreeNode *B)
{
	if (B == nullptr) return true;
	if (A == nullptr) return false;//一定要B写在前面
	return (A->val == B->val) 
		&& isSameStruct_Reanswer(A->right, B->right) 
		&& isSameStruct_Reanswer(A->left, B->left);
}
bool isSubStructure_answer(TreeNode *A, TreeNode *B)
{
	if (A == nullptr || B == nullptr) return false;
	return isSameStruct_Reanswer(A, B) 
		|| isSubStructure_answer(A->left, B) // ||运算，第一个为true 即返回true
		|| isSubStructure_answer(A->right,B);// A的子节点分别也B比较
}

int main(void)
{
	TreeNode *root1 = new TreeNode(1);
	TreeNode *root2 = new TreeNode(3);

	root1->left = new TreeNode(2);
	//root2->left = new TreeNode(2);

	root1->right = new TreeNode(3);
	//root2->right = new TreeNode(3);

	root1->left->left = new TreeNode(4);
	//root2->left->right = new TreeNode(4);

	bool n = isSubStructure_answer(root1, root2);

	root1 = new TreeNode(1);
	root2 = new TreeNode(1);

	root1->left = new TreeNode(2);
	root2->left = new TreeNode(2);

	root1->right = new TreeNode(3);
	root2->right = new TreeNode(3);

	root1->left->left = new TreeNode(4);
	root1->left->right = new TreeNode(4);

	n = isSameStruct_Re(root1, root2);

	root1 = new TreeNode(1);
	root2 = new TreeNode(1);

	root1->left = new TreeNode(2);
	root2->left = new TreeNode(2);

	root1->right = new TreeNode(3);
	root2->right = new TreeNode(3);

	root1->left->left = new TreeNode(4);
	root1->left->right = new TreeNode(5);

	root2->right->left = new TreeNode(4);
	root2->right->right = new TreeNode(5);

	n = isSameStruct_Re(root1, root2);
}