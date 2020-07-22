//https://mp.weixin.qq.com/s/gUwLfi25TYamq8AJVIopfA
//看着文章学习并查集的实现

#include<vector>
using namespace std;

class UF
{
private:
	//记录分量的个数
	int count;
	//用数组的形式储存一棵树，想到了堆排序，类似
	vector<int> parents;
	//树的重量
	vector<int> size;
public:
	UF(int n) :count(n)
	{
		//parents.reserve(n);//cap变成n，size依然为0，reserve之后仍不可访问
		parents.resize(n);//cap变成n，size依然为0，reserve之后仍不可访问
		size.resize(n);
		for (int i = 0; i < n; i++)
		{
			//自己的父类是自己，自己的节点大小为1 
			parents[i] = i;
			size[i] = 1;
		}
	}
	//查找父节点的过程中进行路径压缩，使该节点成为父节点的父节点的子节点，即减少一层
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
			/*size[p] += size[q];*/ //应该用根节点的大小，合并的也是根节点大小
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