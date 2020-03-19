/*�������б� [x1, y1, x2, y2] ����ʽ��ʾ������ (x1, y1) Ϊ���½ǵ����꣬(x2, y2) �����Ͻǵ����ꡣ
����ཻ�����Ϊ��������������ص�����Ҫ��ȷ���ǣ�ֻ�ڽǻ�߽Ӵ����������β������ص���
�����������Σ��ж������Ƿ��ص������ؽ����

���룺rec1 = [0,0,2,2], rec2 = [1,1,3,3]
�����true

���룺rec1 = [0,0,1,1], rec2 = [1,0,2,1]
�����false

https://leetcode-cn.com/problems/rectangle-overlap */

#include<vector>
#include<algorithm>
using std::min;
using std::max;
using std::vector;

//�Լ�һֱ�����ص������ ̫�����ˣ�ûд��ȷ���������
//����Ϊ�Լ�δ��ȷ�Ĵ���
bool isRec2InRec1(vector<int>& rec1, vector<int>& rec2)
{
	if (rec1[0] <= rec2[0] && rec2[0] < rec1[2] && rec1[1] <= rec2[1] && rec2[1] < rec1[3]) return true;
	if (rec1[0] < rec2[2] && rec2[2] <= rec1[2] && rec1[1] < rec2[3] && rec2[3] <= rec1[3]) return true;
	//�������е������rec2��������һ��ƽ�� x�ᡢ������һ��ƽ�� y��ı���rec1��Χ��
	//����ֻ��ǰ���У����԰������� �� ���ص������������������������������������ֳ�����[0,0,1,1]	[1, 0, 2, 1]�ķ�����˼·���ԣ�����
	if (rec1[0] <= rec2[0] && rec2[0] < rec1[2] && rec1[0] < rec2[4] && rec2[4] <= rec1[2]) return true;
	if (rec1[1] <= rec2[1] && rec2[1] < rec1[3] && rec1[1] < rec2[3] && rec2[3] <= rec1[3]) return true;
	else return false;
}
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
{
	if (isRec2InRec1(rec1, rec2) || isRec2InRec1(rec2, rec1)) return true;
	else return false;
}

//���˴���⣬�ŷ������������⣬�Ѷ�ά�ľ��󽵼���һά�߶��ϣ������ص�Ҳ������x��y�᷽���ϵ�ͶӰ�����ص���labuladong֮ǰд�������ص�������
//���ص���������̫���ӣ����ҷ��ص������
//����ķ��������û���ص�����rec2��rec1�����������¸�����
bool isRectangleOverlap01(vector<int>& rec1, vector<int>& rec2)
{
	return !(rec1[2] <= rec2[0]   // left
		|| rec1[3] <= rec2[1]    // bottom
		|| rec1[0] >= rec2[2]    // right
		|| rec1[1] >= rec2[3]);    // top
}
//λ�õķ�����������ص����������߶ε��Ҷ˵����Сֵ������˵�����ֵ
bool isRectangleOverlap02(vector<int>& rec1, vector<int>& rec2) {
	return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
			min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));
}
bool isRectangleOverlap04(vector<int>& rec1, vector<int>& rec2) 
{
	return rec2[0] < rec1[2] && rec2[2] > rec1[0] && rec2[1] < rec1[3] && rec2[3] > rec1[1];
}



//��������������
/*��ȡ�������ε��м�����꣬��߽������
�������ĵ�ĺ�����ľ���պõ�����������һ�볤���
�������ĵ��������ľ���պõ�����������һ������
���ҵ���һ�����������������������ĵ�ľ��룬����β��غ�
�ɴ˿��Եõ��������������붼С�����ĵ������������ʱ�򣬾����غ�

���ӣ�https://leetcode-cn.com/problems/rectangle-overlap/solution/fang-fa-1zhong-xin-dian-ju-chi-fang-fa-2zuo-biao-z/ */

