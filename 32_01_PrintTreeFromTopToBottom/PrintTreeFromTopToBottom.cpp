#include<vector>
#include<queue>
using std::queue;
using std::vector;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int m):val(m),left(nullptr),right(nullptr){}
};

//��Ѱ�Ҹ��ý���һ�⣬�Ѿ�ѧ���˶������BFS�ķ�����ͬʱ֪���˷ֲ�ķ�������ӡ����ǰ������Ŀ���Եúܼ���
//������࿴��⣬�����˵ķ������õķ���ѧ����

/*���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ��*/
vector<int> levelOrder_01(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ans;
	queue<TreeNode *> node;
	node.push(root);
	while (node.size())
	{
		TreeNode *top = node.front();
		node.pop();
		ans.push_back(top->val);
		if (top->left != nullptr)
			node.push(top->left);
		if (top->right != nullptr)
			node.push(top->right);
	}
	return ans;
}

//���ϵ��°����ӡ��������ͬһ��Ľڵ㰴�����ҵ�˳���ӡ��ÿһ���ӡ��һ�С�
//����һ����Ƚϣ��ؼ����ڷֲ㣬����ǰͳ�Ƴ�queue����������
vector<vector<int>> levelOrder_02(TreeNode* root) {
	if (root == nullptr) return {};
	vector<vector<int>> ans;
	queue<TreeNode *> node;
	node.push(root);
	while (node.size())
	{
		vector<int> sub;
		int length = node.size();
		for (int i = 0; i < length; i++)
		{
			TreeNode *top = node.front();
			node.pop();
			sub.push_back(top->val);
			if (top->left != nullptr)
				node.push(top->left);
			if (top->right != nullptr)
				node.push(top->right);
		}
		ans.push_back(sub);
	}
	return ans;
}

//��ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳���ӡ��
//�ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ���������Դ����ơ�