/*����һ�����������ж����Ƿ���һ����Ч�Ķ�����������
����һ��������������������������
	�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
	�ڵ��������ֻ�������ڵ�ǰ�ڵ������
	�������������������������Ҳ�Ƕ�����������

����:
    2
   / \
  1   3
���: true

����:
    5
   / \
  1   4
     / \
    3   6
���: false
����: ����Ϊ: [5,1,4,null,null,3,6]��
     ���ڵ��ֵΪ 5 �����������ӽڵ�ֵΪ 4 ��
https://leetcode-cn.com/problems/validate-binary-search-tree */

//ע��BST�ĸ�����������еĽڵ㶼С�ڸ��ڵ�
#include<limits>
using namespace std;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}	
};
//bool isValidBST(TreeNode* root)
//{
//	 //Ҫ��¼ ��������ֵ������ֱ�������ӱȽ�
//	 if (root == nullptr || root->left == nullptr && root->right == nullptr)
//		 return true;
//	 bool isLeftNode = false, isRightNode = false;
//	 if (root->left != nullptr)
//	 {
//		 isLeftNode = root->val > root->left->val && isValidBST(root->left);
//		 if (isLeftNode == false) return false;
//	 }
//	 if (root->right != nullptr)
//	 {
//		 isRightNode = root->val < root->right->val && isValidBST(root->right);
//		 if (isRightNode == false) return isRightNode;
//	 }
//	 return true;
//}

//�������ԣ������̵���⣬��Ȼ�������͸㶨�ˣ��������˼·
//���������ά�����ֵ�������ֵ���������ﴫ��
//������������ж����������ҵ���������max��max�͸��ڵ�ֵ�Ƚϲ����£�Ȼ���ж�������
bool InOrder(TreeNode* root, long &pre)
{
	if (root == nullptr) return true;
	if (!InOrder(root->left, pre)) return false;
	if (root->val <= pre) return false;
	pre = root->val;
	return InOrder(root->right, pre);
}
bool isVaildBST(TreeNode* root)
{
	long pre = LONG_MIN;
	return InOrder(root, pre);
}
/*
����:
  5
 / \
 1  6
/ \
0  7
*/
//�е��ɻ���ô��������ߵ����ֵ�أ������ˣ�preά���ľ������ֵ
int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(6);
	bool ans = isVaildBST(root);
	return 0;

}







