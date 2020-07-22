//https://mp.weixin.qq.com/s/gUwLfi25TYamq8AJVIopfA
//��������ѧϰ���鼯��ʵ��

#include<vector>
using namespace std;

class UF
{
private:
	//��¼�����ĸ���
	int count;
	//���������ʽ����һ�������뵽�˶���������
	vector<int> parents;
	//��������
	vector<int> size;
public:
	UF(int n) :count(n)
	{
		//parents.reserve(n);//cap���n��size��ȻΪ0��reserve֮���Բ��ɷ���
		parents.resize(n);//cap���n��size��ȻΪ0��reserve֮���Բ��ɷ���
		size.resize(n);
		for (int i = 0; i < n; i++)
		{
			//�Լ��ĸ������Լ����Լ��Ľڵ��СΪ1 
			parents[i] = i;
			size[i] = 1;
		}
	}
	//���Ҹ��ڵ�Ĺ����н���·��ѹ����ʹ�ýڵ��Ϊ���ڵ�ĸ��ڵ���ӽڵ㣬������һ��
	int find(int x)
	{
		while (parents[x] != x)
		{
			parents[x] = parents[parents[x]];
			x = parents[x];
		}
		return x;
	}
	bool BeConnected(int x, int y)
	{
		int xp = find(x);
		int yp = find(y);
		return xp == yp;
	}
	void Conn(int p, int q)
	{
		int rootP = find(p);
		int rootQ = find(q);
		if (rootP == rootQ) return;

		if (size[p] > size[q])
		{
			parents[rootQ] = rootP;
			/*size[p] += size[q];*/ //Ӧ���ø��ڵ�Ĵ�С���ϲ���Ҳ�Ǹ��ڵ��С
			size[rootP] += parents[rootQ];
		}
		else
		{
			parents[rootP] = rootQ;
			size[rootQ] += size[rootP];
		}
		count--;
	}
};