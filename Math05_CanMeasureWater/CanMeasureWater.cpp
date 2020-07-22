/*	�����������ֱ�Ϊ x�� �� y�� ��ˮ���Լ����޶��ˮ�����ж��ܷ�ͨ��ʹ��������ˮ�����Ӷ����Եõ�ǡ�� z�� ��ˮ��
	������ԣ������������ˮ���е�һ��������ʢ��ȡ�õ� z�� ˮ��
	������
	װ������һ��ˮ��
	�������һ��ˮ��
	��һ��ˮ��������һ��ˮ����ˮ��ֱ��װ�����ߵ���
	
	����: x = 3, y = 5, z = 4�����: True	
	����: x = 2, y = 6, z = 5�����: False
*/

//����Ŀ��û˼·�������
//#include<bits/stdc++.h>
#include<utility>
#include<unordered_set>
#include<stack>
#include<functional>
#include<algorithm>
using std::swap;
using std::min;
using std::hash;
using std::unordered_set;
using std::stack;
using std::pair;

//DFS�㷨�������˺ܶ಻���õ�C++���ԣ�Ŀǰ unordered_set Ĭ�ϵ�hash������֧��build-in���ͼ�string���������͡��������ͻ��û��Զ������ͣ���Ҫ�Լ���дhash����
//�������״̬ת��

using PII = pair<int, int>;
bool canMeasureWater(int x, int y, int z) 
{
	stack<PII> stk;
	stk.emplace(0, 0);
	//ע������һ��hash�����Ķ��壬�ܶ�C++11���﷨��
	//auto�Զ��Ʋ����ͣ�
	//[]�������������Ժ������ڵ����Ӧ���ԣ�����
	//template <class T> struct hash;  std::hash��һ��ģ���࣬���� hash<int>()��typename����()Ϊ������ʱ����Ȼ��hash������()�����ز�����hashֵ
	//����ʹ��hash�����ķ�����
	/*	char nts1[] = "Test";
		std::hash<char*> ptr_hash;
		ptr_hash(nts1);//�õ���Test�Ĺ�ϣֵ
	*/
	auto hash_function = [](const PII &o) {return hash<int>() (o.first) ^ hash<int>() (o.second); };
	//�˴�Ϊdecltype�ؼ��֣�hash_function�൱����һ��function object��ͨ��decltype�����type
	unordered_set<PII, decltype(hash_function) > seen(0, hash_function);//��������Ҳһ��Ҫ��hash_function
	while (stk.size())
	{
		if (seen.count(stk.top()))
		{
			stk.pop();
			continue;
		}
		seen.emplace(stk.top());
		//auto[remain_x, remain_y] = stk.top(); �����������ҵı������Ƶ�������
		auto remain = stk.top();
		stk.pop();
		if (remain.first == z || remain.second == z || remain.first + remain.second == z)
			return true;
		//��6�ֿ��Խ��еĲ�����ʾ������ѭ������
		stk.emplace(x, remain.second);		//��X������
		stk.emplace(remain.first, y);		//��y������
		stk.emplace(0, remain.second);		//��x������
		stk.emplace(remain.first, 0);		//��y������
		stk.emplace(remain.first - min(remain.first, y - remain.second), 
					remain.second + min(remain.first, y - remain.second));		// �� X ����ˮ��� Y ����ֱ�������򵹿ա�
		stk.emplace(remain.first + min(x - remain.first, remain.second), 
					remain.second - min(x - remain.first, remain.second));		// �� Y ����ˮ��� X ����ֱ�������򵹿ա�
	}
	return false;
}
//��ѧ������������ˮ���������������仯Ϊ ����x������y
//���涨��������ǣ�ax + by = z �н⵱�ҽ��� z �� x y �����Լ���ı������������ֻ��Ҫ��x, y �����Լ�����ж� z �Ƿ������ı������ɡ�
int gcd(int x, int y)//�Ѿ���֤ x > y
{
	if (x % y == 0) return y;
	gcd(y, x % y);
}
bool canMeasureWater01(int x, int y, int z)
{
	if (x + y < z) return false;
	if (x == 0 || y == 0) return (z == 0 || x + y == z);
	if (x < y) swap(x, y);
	return z % gcd(x, y) == 0;
}

//�����������˼��ͼƬ��������ѧ������ͬʱҲʹ����BFS(·����̣��㷨���������е�Ԫ�ز���pair������������ˮ������
//https://leetcode-cn.com/problems/water-and-jug-problem/solution/hu-dan-long-wei-liang-zhang-you-yi-si-de-tu-by-ant/
//https://leetcode-cn.com/problems/water-and-jug-problem/solution/cjian-dan-hui-su-si-chong-zhuang-tai-by-zhuangmeng/
int main()
{
	bool ans = canMeasureWater(3, 5, 4);
	ans = canMeasureWater01(3, 5, 4);
	return 0;
}