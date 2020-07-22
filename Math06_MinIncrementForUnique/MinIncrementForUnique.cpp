/*������������ A��ÿ�� move ��������ѡ������ A[i]����������� 1������ʹ A �е�ÿ��ֵ����Ψһ�����ٲ���������

���룺[1,2,2]
�����1
���ͣ�����һ�� move ���������齫��Ϊ [1, 2, 3]��

���룺[3,2,1,2,1,7]
�����6
���ͣ����� 6 �� move ���������齫��Ϊ [3, 4, 1, 2, 5, 7]��
���Կ��� 5 �λ� 5 �����µ� move �����ǲ����������ÿ��ֵΨһ�ġ�
https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique */

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using std::min;
using std::sort;
using std::unordered_set;
using std::vector;

//�Լ�д�ģ���󼸸���Ĳ���������ͨ��
int minIncrementForUnique(vector<int>& A)
{
	vector<int> needChange;
	unordered_set<int> store;
	int ans = 0;
	for (int i : A)
	{
		if (store.count(i) == 1) needChange.push_back(i);
		store.insert(i);
	}
	for (int i : needChange)
	{
		while (store.count(i) == 1)
		{
			ans++;
			i++;
		}
		store.insert(i);
	}
	return ans;
}

//��󼸸���Ĳ���������ͨ���������

//����ķ����������ظ����ֲ��ϼ�1����ǰ�������ּ��ɣ��˴�ʹ�����Ż��ķ���
//�Ż��ķ������������ҵ�һ��û�г��ֹ�������ʱ�򣬽�֮ǰĳ���ظ����ֵ������ӳ����û�г��ֹ�������
//ע�⣬���� ��֮ǰĳ���ظ����ֵ����� �ǿ�������ѡ��ģ���������Ӱ�����յĴ𰸣���Ϊ�� P ���ӵ� X ���ҽ� Q ���ӵ� Y���뽫 P ���ӵ� Y ���ҽ� Q ���ӵ� X ����Ҫ���� (X + Y) - (P + Q) �β�����
//�Ż��Ĳ��������ǣ�ֱ�Ӽ�ȥ�ظ�Ԫ�ص�ֵ��Ȼ��ֱ�Ӽ�����С��û���ֵ�����
int minIncrementForUnique01(vector<int>& A)
{
	if (A.empty()) return 0;
	sort(A.begin(), A.end());
	int ans = 0, taken = 0;
	int Length = A.size();
	for (int i = 1; i < Length; i++)
	{
		if (A[i] <= A[i - 1])
		{
			taken++;
			ans -= A[i];//��ȥ�ظ���Ԫ��ֵ���������ظ�Ԫ�صļ���ֵ
		}
		else 
		{
			int give = min(taken, A[i] - 1 - A[i - 1]);//������ڴ˴����ӵ�Ԫ�ظ���
			ans += give * A[i - 1] + give * (give + 1) / 2;
			taken -= give;
		}
	}
	if (taken > 0)//
		ans += taken * A.back() + taken * (taken + 1) / 2;
	return ans;
}
//������������⣬ò�Ƹо�������Ż����岻̫��
int minIncrementForUnique0102(vector<int>& A)
{
	if (A.empty()) return 0;
	sort(A.begin(), A.end());
	int ans = 0;
	int Length = A.size();
	for (int i = 1; i < Length; i++)
	{
		if (A[i] <= A[i - 1])
		{
			ans += A[i - 1] + 1 - A[i];
			A[i] = A[i - 1] + 1;
		}
	}
	return ans;
}
//�����ķ�������������Ż�˼·һ��������һ��һ������ӣ�������Ҳ�м����������ӵķ����������Լ�¼���ֵ��һ���Ż�
//���ݷ�Χ40000
int minIncrementForUnique02(vector<int>& A) 
{
	if (A.empty()) return 0;
	int cnt[80000] = { 0 };
	for (int i : A) cnt[i]++;
	int ans = 0, taken = 0;
	for (int i = 0; i < 80000; i++)
	{
		if (cnt[i] > 1)
		{
			taken += cnt[i] - 1;
			ans -= i * (cnt[i] - 1);
		}
		else if (taken > 0 && cnt[i] == 0)
		{
			taken--;
			ans += i;
		}
	}
	return ans;
}

//ѹ��·��������̽�ⷽ�������hash�ķ���֮һ���˷���ֵ�ý��
//https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/ji-shu-onxian-xing-tan-ce-fa-onpai-xu-onlogn-yi-ya/
//��������д����vector��Ϊ�����������βΣ���ͨ��LeetCode���ԡ�

//�����۵���ʾ�£�������һ������vector��Ϊȫ�ֱ���ʱ����ʼ�������⡣Ŀǰ��֪��Ϊʲô��������������
/* ���۵�˵����	1.����¥����д���� ������int pos[80000]; ������ٳ�ʼ�� memset(pos, -1, sizeof(int)*80000);
				2.ʹ�� vector<int> �����ǲ���ֱ��ʹ��vector<int>pos(80000, -1); ����Ϊ������vector�Ĵ��ι��캯�����г�ʼ����
				��Ҫ���������ͷ����������� vector<int>pos {vector<int> (80000, -1)}; ��
				���������� vector<int>pos; ������ڹ��캯���ٽ��г�ʼ���� pos = vector<int>(80000,-1);
*/

//�����ڳ���ʹ��vector��Ϊȫ�ֱ�������������Ϊ�����������βΡ���LeetCode�в��ԣ�
//	1. vector<int> pos(80000, -1);����д��class�������ڣ��޷�ͨ������
//	2. vector<int> pos(80000, -1);д����class�����棬�������������ͨ��
//  3. vector<int>pos {vector<int> (80000, -1)}; д����class�����棬�������������ͨ����д��class�����ڣ���ͨ������
//	4. vector<int>pos; ������class���棬main������дpos = vector<int>(80000,-1); OK


// ����̽��Ѱַ����·��ѹ����
int findPos(int a, vector<int>& pos)
{
	int b = pos[a];
	if (b == -1) 
	{
		pos[a] = a;
		return a;
	}
	// �������Ѱַ
	// ��Ϊpos[a]�б�����ϴ�Ѱַ�õ��Ŀ�λ����˴�pos[a]+1��ʼѰַ�����ˣ�����Ҫ��a+1��ʼ����
	b = findPos(b+1,pos);
	pos[a] = b; // Ѱַ����¿�λҪ���¸�ֵ��pos[a]Ŷ��·��ѹ���������������
	return b;
}
int minIncrementForUnique_hash(vector<int>& A)
{
	if (A.empty()) return 0;
	int ans = 0;
	vector<int> pos(80000, -1);
	// ����ÿ������a����Ѱ��ַ�õ�λ��b, b��a���������ǲ�������
	for (int a : A)
	{
		int b = findPos(a, pos);
		ans += b - a;
	}
	return ans;
}


//�����˲��鼯��Ҳ��ѹ��·���ķ��������鼯��һ�����ݽṹ����ʱ��û��ϸ�о����Ժ��ٿ�
//https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/tan-xin-suan-fa-bing-cha-ji-java-by-liweiwei1419/

//struct node 
//{
//	node* p = new node; // error: use of implicit or defaulted node::node() 
//};
struct A
{
	A() = default;          // OK
	A(int v) : v(v) { }     // OK
	const int& v = 42;      // OK
};
int main(void)
{
	A a1;    
	A a2(a1);// error: ill-formed binding of temporary to reference
			 
	//��A�Ĺ��������Ϊ���ã�Ȼ��int�б�����ʼ��a2���ԡ�

	std::cout << a1.v << std::endl;
	std::cout << a2.v << std::endl;

	return 0;
}