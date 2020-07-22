//https://mp.weixin.qq.com/s/GqehrBu9m7qf5FgFqlV-Uw 2019-06-14 �������н�������������� 
//https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg 2019-06-16 ˫ָ�뼼�ɻ���
//https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ 2019-06-19 ���������㷨����Ӵ�����
//https://mp.weixin.qq.com/s/o7tdyLiYm668dpUWd-x7Lg 2019-07-30 ͼ��������ѣ�ʵ�����ȼ�����
//https://mp.weixin.qq.com/s/4TxF0xVhlUO6v3teip9Jzg 2019-08-23 ǰ׺�ͼ��ɣ��������������
//https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A 2019-09-16 ��θ�Ч����������/����ȥ�أ�
//https://mp.weixin.qq.com/s/CVHfkEiIG3KTw65Z7FLGXg 2019-09-18 ������ⲻ�򵥣�Ѱ��ȱʧԪ��
//https://mp.weixin.qq.com/s/o3GQ4fXjPkS04Sr9uPH8ZQ 2020-03-01 ��ЧѰ��ȱʧ���ظ�������
//https://mp.weixin.qq.com/s/3CMQaY1mO1Iqt4j30bUVcA 2019-09-23 Two Sum ����ĺ���˼��
//https://mp.weixin.qq.com/s/zjJ43PrJdYg3xFzGTwtqhA 2019-10-22 ���ݽṹ��ƣ���ջʵ�ֶ���/�ö���ʵ��ջ 


//https://leetcode-cn.com/problems/sliding-window-maximum/solution/239-hua-dong-chuang-kou-zui-da-zhi-by-alexer-660/ ����������ϰ��
/*	����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ��ֻ���Կ����ڻ��������ڵ� k �����֡�
	��������ÿ��ֻ�����ƶ�һλ�����ػ��������е����ֵ��
	https://leetcode-cn.com/problems/sliding-window-maximum
*/
//queue�ǵ��˶��У�deque��˫�˶��е����ݽṹ
#include<deque>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
using std::deque;

class Monotonicqueue {
private:
	deque<int> data;
public:
	void push(int n)//�Ӷ�β���룬�Ӷ�ͷɾ��
	{
		while (data.size() && data.back() < n)
			data.pop_back();
		data.push_back(n);
	}
	void pop(int n)
	{
		if (data.size() && data.front() == n)//�˴�Ϊif������������Ԫ����pop
			data.pop_front();
	}
	int max()
	{
		return data.front();
	}
};
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	Monotonicqueue window;
	int Length = nums.size();
	vector<int> ans;
	if (Length == 0) return ans;
	//�𰸽�ǰk���ͺ���ķŵ�һ��forѭ�������ˣ���if�жϣ���࣬ÿ��if�ж�Ҳ��ʱ��
	for (int i = 0; i < k; i++)
		window.push(nums[i]);
	ans.push_back(window.max());//���Ӧ�÷�����Ԫ�ص�����£�������Ԫ��ʱ�˴���ֵ��������ǰ���ж�
	for (int i = k; i < Length; i++)
	{		
		window.pop(nums[i - k]);
		window.push(nums[i]);
		ans.push_back(window.max());
	}
	return ans;
}
//���˹ٷ���⣬ֱ��deque�ķ������洢����ֵ��Ϊ�˿��ƻ������ڵĴ�С
vector<int> maxSlidingWindow_deque(vector<int>& nums, int k)
{
	int Length = nums.size();
	vector<int> ans;
	deque<int> monotonic;				//ͷ����β���������ݼ�
	for (int i = 0; i < Length; i++)
	{
		while (monotonic.size() && nums[monotonic.back()] < nums[i])
			monotonic.pop_back();
		monotonic.push_back(i);		
		if (monotonic.front() <= i - k)//�ڴ���֮��Ӧ��pop
			monotonic.pop_front();
		if (i + 1 >= k)
			ans.push_back(nums[monotonic.front()]);
	}
	return ans;
}
//�ٷ����ķֿ鶯̬�滮�������ر�������õ�
vector<int> maxSlidingWindow_dp(vector<int>& nums, int k)
{
	int Length = nums.size();
	//vector<int> ans(Length - k + 1, 0);//�˴���ֵ0�ˣ�lengthΪ0 ʱ����ֵ����
	vector<int> ans;
	if (Length * k == 0) return ans;
	//if (k == 1) return nums;//

	vector<int> left(Length, 0);
	vector<int> right(Length, 0);
	left[0] = nums[0];
	right[Length - 1] = nums[Length - 1];

	for (int i = 1; i < Length; i++)//dp��base case��ȷ���������0��ʼ����ʱǰһ��״̬�����
	{
		if (i % k == 0) left[i] = nums[i];//���
		else left[i] = max(nums[i], left[i - 1]);

		int j = Length - 1 - i;//��������
		if ((j + 1) % k == 0) right[j] = nums[j];
		else right[j] = max(nums[j], right[j + 1]);
	}
	//right[i] �������ڵ����Ԫ�أ� left[j] ���Ҳ���ڵ����Ԫ�ء���˻��������е����Ԫ��Ϊ max(right[i], left[j])��
	//���ں����������Ĵ��ڣ��ֱ�����߿�����ֵ ���ұ߿�����ֵ�����Ǵӿ�ı߽���������ɢ
	for (int i = 0; i < Length - k + 1; i++)
		ans.push_back( max(right[i], left[i + k - 1]) );//vector������ͨ��[]������Ԫ��
	return ans;
}
int main(void)
{
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> ans = maxSlidingWindow_dp(nums, 3);

	nums = { -7,-8,7,5,7,1,6,0 };
	ans = maxSlidingWindow(nums, 4);

	nums = { 1,-1 };
	ans = maxSlidingWindow_dp(nums, 1);
	return 0;
}