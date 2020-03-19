/*矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标。
如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。
给出两个矩形，判断它们是否重叠并返回结果。

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true

输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false

https://leetcode-cn.com/problems/rectangle-overlap */

#include<vector>
#include<algorithm>
using std::min;
using std::max;
using std::vector;

//自己一直在找重叠的情况 太复杂了，没写正确，看了题解
//下面为自己未正确的代码
bool isRec2InRec1(vector<int>& rec1, vector<int>& rec2)
{
	if (rec1[0] <= rec2[0] && rec2[0] < rec1[2] && rec1[1] <= rec2[1] && rec2[1] < rec1[3]) return true;
	if (rec1[0] < rec2[2] && rec2[2] <= rec1[2] && rec1[1] < rec2[3] && rec2[3] <= rec1[3]) return true;
	//上面两行的情况，rec2的至少有一条平行 x轴、至少有一条平行 y轴的边在rec1范围内
	//本来只有前两行，测试案例中有 井 字重叠的情况，不符合上述情况，加完下面两条又出现了[0,0,1,1]	[1, 0, 2, 1]的反例，思路不对，放弃
	if (rec1[0] <= rec2[0] && rec2[0] < rec1[2] && rec1[0] < rec2[4] && rec2[4] <= rec1[2]) return true;
	if (rec1[1] <= rec2[1] && rec2[1] < rec1[3] && rec1[1] < rec2[3] && rec2[3] <= rec1[3]) return true;
	else return false;
}
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
{
	if (isRec2InRec1(rec1, rec2) || isRec2InRec1(rec2, rec1)) return true;
	else return false;
}

//看了答案题解，才发现是区间问题，把二维的矩阵降级都一维线段上，矩阵重叠也就是在x轴y轴方向上的投影都有重叠，labuladong之前写过区间重叠的问题
//找重叠区域的情况太复杂，则找非重叠的情况
//区域的方法，如果没有重叠，则rec2在rec1的上下左右下个方向
bool isRectangleOverlap01(vector<int>& rec1, vector<int>& rec2)
{
	return !(rec1[2] <= rec2[0]   // left
		|| rec1[3] <= rec2[1]    // bottom
		|| rec1[0] >= rec2[2]    // right
		|| rec1[1] >= rec2[3]);    // top
}
//位置的方法，如果有重叠，则两条线段的右端点的最小值大于左端点的最大值
bool isRectangleOverlap02(vector<int>& rec1, vector<int>& rec2) {
	return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
			min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));
}
bool isRectangleOverlap04(vector<int>& rec1, vector<int>& rec2) 
{
	return rec2[0] < rec1[2] && rec2[2] > rec1[0] && rec2[1] < rec1[3] && rec2[3] > rec1[1];
}



//看到了其他方法
/*先取两个矩形的中间点坐标，最边界情况：
两个中心点的横坐标的距离刚好等于两个矩形一半长相加
两个中心点的纵坐标的距离刚好等于两个矩形一半宽相加
并且当有一个距离大于这个的这两个中心点的距离，则矩形不重合
由此可以得到，当这两个距离都小于中心点横纵坐标距离的时候，矩形重合

链接：https://leetcode-cn.com/problems/rectangle-overlap/solution/fang-fa-1zhong-xin-dian-ju-chi-fang-fa-2zuo-biao-z/ */

