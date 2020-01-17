// ������8������������һ�����
// ��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
// ���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣

//����˼·�����Է�Ϊ3�������
//�ýڵ����ҽڵ㣬����һ���ڵ�ΪΪ�ҽڵ��������
//�ýڵ����ҽڵ㣺���ýڵ�Ϊ��ڵ㣬��һ���ڵ�Ϊ���ڵ㣬
//				���ýڵ�Ϊ�ҽڵ㣬�����ϱ������ڵ㣬ֱ�������ڵ�Ϊ��ڵ��ʱ����һ���ڵ�Ϊ�ø��ڵ�ĸ��ڵ㣬�����������ڵ��Բ�����ʱ��Ϊ��


//����˼·������coding����ͨ��ţ�����Ĳ��ԣ�ϸ��֮���д��࿴

#include<iostream>
struct BinaryTreeNode 
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
	//���ǳ�ʼ���ṹ����ôд�ˣ���Ҫ��ĩβ��{}���൱�ڹ��캯��
	BinaryTreeNode(int val) : m_nValue(val), m_pLeft(nullptr), m_pParent(nullptr), m_pRight(nullptr){}
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	BinaryTreeNode* pNext = nullptr;
	BinaryTreeNode* pTemp = pNode;
	if (pNode != nullptr)
	{
		//�ýڵ����ҽڵ�
		if (pTemp->m_pRight != nullptr)
		{
			pTemp = pTemp->m_pRight;
			while (pTemp->m_pLeft != nullptr)
				pTemp = pTemp->m_pLeft;
			pNext = pTemp;
		}
		//�ýڵ����ҽڵ�
		else
		{
			BinaryTreeNode* pParent = pTemp->m_pParent;
			//�ýڵ㲻Ϊ���ڵ�
			if (pParent != nullptr)
			{
				//�ýڵ�Ϊ���ڵ����ڵ�
				if (pTemp == pParent->m_pLeft)
					pNext = pParent;
				//�ýڵ�Ϊ���ڵ���ҽڵ�
				//���ǵ����ڵ� �� û����һ���ڵ�����
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
					//�߼�����Ӧ��ֱ�ӷ���pParent
					//ͬʱӦ��д��whileѭ����if�ڣ����ڴ˴���һ���ᱻִ�У���������Ϊbreak������whileѭ��������
					//pNext = pParent->m_pParent;					
				}
			}
		}
	}
	return pNext;
}
//��������ʱ�򣬸��ڵ�ҲҪ��ֵ������̫����������book����Ĳ��Գ���
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