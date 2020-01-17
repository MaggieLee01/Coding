// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

//回忆思路，可以分为3种情况，
//该节点有右节点，则下一个节点为为右节点的左子树
//该节点无右节点：若该节点为左节点，下一个节点为父节点，
//				若该节点为右节点，则向上遍历父节点，直到到父节点为左节点的时候，下一个节点为该父节点的父节点，若遍历到根节点仍不满足时则为空


//根据思路，独立coding，已通过牛客网的测试，细节之处有待多看

#include<iostream>
struct BinaryTreeNode 
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
	//忘记初始化结构体怎么写了，需要在末尾加{}，相当于构造函数
	BinaryTreeNode(int val) : m_nValue(val), m_pLeft(nullptr), m_pParent(nullptr), m_pRight(nullptr){}
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	BinaryTreeNode* pNext = nullptr;
	BinaryTreeNode* pTemp = pNode;
	if (pNode != nullptr)
	{
		//该节点有右节点
		if (pTemp->m_pRight != nullptr)
		{
			pTemp = pTemp->m_pRight;
			while (pTemp->m_pLeft != nullptr)
				pTemp = pTemp->m_pLeft;
			pNext = pTemp;
		}
		//该节点无右节点
		else
		{
			BinaryTreeNode* pParent = pTemp->m_pParent;
			//该节点不为根节点
			if (pParent != nullptr)
			{
				//该节点为父节点的左节点
				if (pTemp == pParent->m_pLeft)
					pNext = pParent;
				//该节点为父节点的右节点
				//考虑到根节点 和 没有下一个节点的情况
				else 
				{
					while (pParent != nullptr)
					{
						if (pParent->m_pLeft == pTemp)
						{
							pNext = pParent;
							break;
						}							
						pTemp = pParent;
						pParent = pParent->m_pParent;
					}
					//逻辑有误，应该直接返回pParent
					//同时应该写在while循环的if内，放在此处，一定会被执行，若不是因为break跳出的while循环即出错
					//pNext = pParent->m_pParent;					
				}
			}
		}
	}
	return pNext;
}
//构造树的时候，父节点也要赋值，代码太繁琐，看看book代码的测试程序
int main(void)
{
	BinaryTreeNode* p1 = new BinaryTreeNode(1);
	BinaryTreeNode* p2 = new BinaryTreeNode(2);
	BinaryTreeNode* p3 = new BinaryTreeNode(3);
	BinaryTreeNode* p4 = new BinaryTreeNode(4);
	BinaryTreeNode* p5 = new BinaryTreeNode(5);
	BinaryTreeNode* p6 = new BinaryTreeNode(6);
	BinaryTreeNode* p7 = new BinaryTreeNode(7);
	BinaryTreeNode* p8 = new BinaryTreeNode(8);
	BinaryTreeNode* p9 = new BinaryTreeNode(9);
	BinaryTreeNode* p10 = new BinaryTreeNode(10);
	BinaryTreeNode* p11 = new BinaryTreeNode(11);
	BinaryTreeNode* p12 = new BinaryTreeNode(12);
	BinaryTreeNode* p13 = new BinaryTreeNode(13);
	BinaryTreeNode* p14 = new BinaryTreeNode(14);
	BinaryTreeNode* p15 = new BinaryTreeNode(15);

	p1->m_pLeft = p2;
	p1->m_pRight = p3;
	p2->m_pLeft = p4;
	p2->m_pRight = p5;
	p3->m_pLeft = p6;
	p3->m_pRight = p7;
	p4->m_pLeft = p8;
	p4->m_pRight = p9;
	p5->m_pLeft = p10;
	p5->m_pRight = p11;
	p6->m_pLeft = p12;
	p6->m_pRight = p13;
	p7->m_pLeft = p14;
	p7->m_pRight = p15;

	p2->m_pParent = p1;
	p3->m_pParent = p1;
	p4->m_pParent = p2;
	p5->m_pParent = p2;
	p6->m_pParent = p3;
	p7->m_pParent = p3;
	p8->m_pParent = p4;
	p9->m_pParent = p4;
	p10->m_pParent = p5;
	p11->m_pParent = p5;
	p12->m_pParent = p6;
	p13->m_pParent = p6;
	p14->m_pParent = p7;
	p15->m_pParent = p7;

	BinaryTreeNode* p20 = GetNext(p1);
	BinaryTreeNode* p21 = GetNext(p8);
	BinaryTreeNode* p22 = GetNext(p9);
	BinaryTreeNode* p23 = GetNext(p11);
	BinaryTreeNode* p24 = GetNext(p15);
	BinaryTreeNode* p25 = GetNext(p3);
	BinaryTreeNode* p26 = GetNext(p6);

	return 0;
}