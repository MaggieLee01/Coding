/* �����ӡ�����һ��n�����ӣ����ӿ� wi���� di���� hi�����Ӳ��ܷ�ת�������Ӷ�����ʱ���������ӵĿ�ȡ��߶Ⱥ���ȱ��������������ӡ�
ʵ��һ�ַ����������ߵ�һ�����ӡ���ѵĸ߶�Ϊÿ�����Ӹ߶ȵ��ܺ͡�
����ʹ������[wi, di, hi]��ʾÿ�����ӡ�
https://leetcode-cn.com/problems/pile-box-lcci 
���룺box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
�����10   */

//20200411���׻���ı����⣬���ź��ŷ�Ĳ�࣬�ŷ��Ƕ�ά���������ά�����������ŷ�Ķ��ַ���
#include<vector>
#include<algorithm>
using namespace std;
static bool comp(vector<int> box1, vector<int> box2)
{
	if (box1[0] == box2[0])
	{
		if (box1[1] == box2[1]) return box1[2] < box2[2];
		else return box1[1] < box2[1];
	}
	else return box1[0] < box2[0];
}
int pileBox(vector<vector<int>>& box)
{
	if (box.size() == 0) return 0;
	sort(box.begin(), box.end(), comp);
	//int ans = 0; //for��1 ��ʼ���ȳ�ʼ��Ϊ0��ֵ
	vector<int> height(box.size(), 0); //�洢ǰn�����Ӷ�Ӧ�����߶�
	height[0] = box[0][2];
	int ans = height[0];
	for (int i = 1; i < box.size(); i++)
	{
		//��Ŀ��Ҫ���ܺ����������������
		//int maxbefore = 0��
		for (int j = 0; j < i; j++)
		{
			if (box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2])
			{
				height[i] = max(height[i], height[j] + box[i][2]);
				//maxbefore = max(maxbefore, height[j]);
			}				
		}
		//������if���������ҵ�i֮ǰ�����ֵ��forѭ������֮��ֱ�Ӽ�i���ĸ߶ȣ�����������max�Ƚϣ���Ϊi֮ǰ�����ֵҪô����ҪôΪ0 
		//height[i] = maxbefore + box[i][2];
		height[i] = max(height[i], box[i][2]);
		ans = max(height[i], ans);
	}
	return ans;
}

//����������̬�滮���ֲ����ҹ�ϵ�ˣ�����⣬�ǵ�һ��Ԫ�ش�С���󣬵ڶ���������Ԫ�شӴ�С��ԭ���ǣ���
//�����ˣ����ں�����Ԫ�ؽ��򣬵���������Ԫ�ؾ����ڸú���ʱ����һ���е�һ��Ԫ�ش��ڸú��ӣ�������һ���ж�

int main(void)
{
	vector<vector<int>> box = { {1,2,1},{1,2,2},{1,2,3},{2,3,2},{2,3,3},{2,3,4},{3,4,3},{3,4,4},{3,4,5},{4,5,1},{4,5,2},{4,5,3} };
	int ans = pileBox(box);
	return 0;
}