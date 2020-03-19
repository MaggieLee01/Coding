/*	����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ������·�����ܴ�������㡣
	����������

		  1
		 / \
		2   3
	   / \
	  4   5
	���� 3, ���ĳ�����·�� [4,2,1,3] ���� [5,2,1,3]��ע�⣺�����֮���·��������������֮��ߵ���Ŀ��ʾ��
	https://leetcode-cn.com/problems/diameter-of-binary-tree */

//��ҳ�༭���ⲻ�����ļ򵥲�����������
#include<algorithm>
using std::max;
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int ans = 0;
int diameterOfBinaryTreeCore(TreeNode* root)
{
	if (root == nullptr) return -1;
	int left = diameterOfBinaryTreeCore(root->left) + 1;
	int right = diameterOfBinaryTreeCore(root->right) + 1;
	ans = max(ans, left + right);
	return max(left, right);
}
int diameterOfBinaryTree(TreeNode* root)
{
	if (root == nullptr) return 0;
	diameterOfBinaryTreeCore(root);
	return ans;
}
//��һ��дҲ���˴�������ֱ�����Բ��������ڵ㣬�������Ҫ�������ڵ�
//https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/hot-100-9er-cha-shu-de-zhi-jing-python3-di-gui-ye-/
//������⣬������������ݹ�ķ���
//ϸ�ڴ���֮����+1��ʱ������
int diameterOfBinaryTreeCore_others(TreeNode* root)
{
	if (root == nullptr) return 0;
	int left = diameterOfBinaryTreeCore(root->left) ;
	int right = diameterOfBinaryTreeCore(root->right) ;
	ans = max(ans, left + right);
	return max(left, right) + 1;//�ڴ˴���һ���򲻻�����������ֶ�ӵ�������˴�rootһ����Ϊ�գ�����һ�����Լ�һ��
	//������д�ģ�root->left��Ϊ�յ������Ҳ��1�����¶����
}

//https://leetcode-cn.com/problems/diameter-of-binary-tree/comments/277575
//�ܶ�����˼·����Ŀ