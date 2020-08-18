/*	���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
	����ѹ��ջ���������־�����ȡ�

	���룺pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
	�����true
	���ͣ����ǿ��԰�����˳��ִ�У�
	push(1), push(2), push(3), push(4), pop() -> 4,
	push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

	���룺pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
	�����false
	���ͣ�1 ������ 2 ֮ǰ������

	https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof */

#include<vector>
#include<stack>
using std::stack;
using std::vector;

// �����Ŀ֮ǰ������ûӡ���ˣ��Լ���˼·��˫ָ�룬����push��˳����ջ��������pop������ʱ����
// ϸ�ڵ㣺pushed������������Ϸ��أ�Ӧ���ж�ջ�е������Ƿ��popped�����е�һ��
bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	stack<int> simu;
	int i = 0, j = 0;
	int iLength = pushed.size();
	int jLength = popped.size();
	if (iLength != jLength) return false;
	while (i <= iLength && j < jLength)
	{
		if (simu.size() && simu.top() == popped[j])
		{
			simu.pop();
			j++;
		}
		else if (i < iLength)
		{
			simu.push(pushed[i]);
			i++;
		}
		else break;
	}
	return (i == iLength && j == jLength && simu.empty());
}

//������⣬�к��ҷ������Ƶģ�����ģ��ջ����,д����һ����ԭ������������ͬ��pop()�������ͽ���̰���㷨
bool validateStackSequences_01(vector<int>& pushed, vector<int>& popped)
{
	stack<int> simu;
	int j = 0;
	if (pushed.size() != popped.size()) return false;
	for (auto i : pushed)
	{
		simu.push(i);
		while (simu.size() && simu.top() == popped[j])//  һ���� j < popped.size() 
		{
			simu.pop();
			j++;
		}
	}
	return (j == popped.size());
}
//����һ��ʱ�任ȥ�ռ�ķ�����Ѱ���ؾ����������ң���ǰ��������˼·����⣬���˸о����鷳��δ���������
//https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/zhao-gui-lu-by-xixihahag/
/*��popped���б����������е�ÿһ�����ֵ�pushed�н��в��ң����ҵ�����Ϊ-1��
����popped��һ������Ϊ4����ô�Ͱ�pushed��4��λ�ñ�Ϊ-1��
������pushed����popped�ĵڶ�������5����ס�ղ�����4��pushed�е�λ�ã��Դ�λ��Ϊ�磬
���տھ���5���Գ��������λ�õĺ��棬���������������ֶ��С�
����������������λ�õ�ǰ�棬�Ͳ�������δ���ʹ������֣��ȣ�����������Ϊ-1�����֣� */

int main(void)
{
	vector<int> m = { 1,2,3,4,5 };
	vector<int> n = { 4,5,3,2,1 };
	bool l = validateStackSequences(m, n);

	m = { 1,2,3,4,5 };
	n = { 4,3,5,1,2 };
	l = validateStackSequences(m, n);
	return 0;
}
