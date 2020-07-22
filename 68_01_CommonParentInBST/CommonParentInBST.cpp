/*
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
���: 6
����: �ڵ� 2 �ͽڵ� 8 ��������������� 6��

����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
���: 2
����: �ڵ� 2 �ͽڵ� 4 ��������������� 2, ��Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//�ݹ��д�����ǲ�̫��Ϥ
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr) return nullptr;
	if (root->val > p->val && root->val > q->val)
		//lowestCommonAncestor(root->left, p, q);		//��֪��д����
		return lowestCommonAncestor(root->left, p, q);
	//else if (root->val < p->val && root->val < q->val)
	if (root->val < p->val && root->val < q->val)
		//lowestCommonAncestor(root->right, p, q);
		return lowestCommonAncestor(root->right, p, q);
	//else
	return root;
}

//������
TreeNode* lowestCommonAncestor01(TreeNode* root, TreeNode* p, TreeNode* q)
{
	//��֤p->val > q->val�������ж�
	if (p->val < q->val)
	{
		TreeNode* temp = p;
		p = q;
		q = temp;
	}
	while (root != nullptr)
	{
		if (root->val > p->val)
			root = root->left;
		else if (root->val < q->val)
			root = root->right;
		else break;
	}
	return root;
}