/* �����һ������������һ�����������ú���������ľ���*/
//https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
struct TreeNode
{ 
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m):val(m),left(nullptr),right(nullptr){}
};
//��ҳ�༭һ��ɣ����ڽ�����д�ݹ�
TreeNode* mirrorTree(TreeNode* root)
{
	if (root == nullptr) return nullptr;
	TreeNode *mirror = new TreeNode(root->val);
	mirror->left = mirrorTree(root->right);
	mirror->right = mirrorTree(root->left);
	return mirror;
}
//������⣬�ǵݹ�汾�ģ���ջ���߶��У��ݹ�汾�Ĵ�඼����ԭ���ϲ�����û���½��ڵ�