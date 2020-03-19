/*�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)
B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��*/

#include<queue>
using std::queue;
struct TreeNode 
{
	int val; 
	TreeNode* left;
	TreeNode *right;
	TreeNode(int m):val(m),left(nullptr),right(nullptr){}
};

//�жϿ�ͷ��ͬ����������B�Ƿ�ΪA������
bool isSameStruct_Re(TreeNode *A, TreeNode *B)
{
	//B����û��A�еģ���������Aû�е�
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
	//�Ȳ�α���Ѱ�ҿ�ͷ
	Dict.push(ATemp);
	while (Dict.size())
	{
		TreeNode *top = Dict.front();
		Dict.pop();
		//�ҵ��ڵ�ֵ��ͬʱ���ж��Ƿ�Ϊ����
		if (top->val == B->val && isSameStruct_Re(top, B))	
			return true;		
		if (top->left != nullptr) Dict.push(top->left);
		if (top->right != nullptr) Dict.push(top->right);
	}
	return false;
}

//�����Լ�д�Ĵ���ͨ���ˣ��ǲ���Ϊ����˼�룻���������α���
//������⣬�𰸣�Ѱ����ʼ�ڵ� �� �ж��Ƿ�Ϊ�����������˵���
bool isSameStruct_Reanswer(TreeNode *A, TreeNode *B)
{
	if (B == nullptr) return true;
	if (A == nullptr) return false;//һ��ҪBд��ǰ��
	return (A->val == B->val) 
		&& isSameStruct_Reanswer(A->right, B->right) 
		&& isSameStruct_Reanswer(A->left, B->left);
}
bool isSubStructure_answer(TreeNode *A, TreeNode *B)
{
	if (A == nullptr || B == nullptr) return false;
	return isSameStruct_Reanswer(A, B) 
		|| isSubStructure_answer(A->left, B) // ||���㣬��һ��Ϊtrue ������true
		|| isSubStructure_answer(A->right,B);// A���ӽڵ�ֱ�ҲB�Ƚ�
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