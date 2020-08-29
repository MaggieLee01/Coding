//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
/*����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻� true�����򷵻� false��
�������������������������ֶ�������ͬ��
*/

#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;

//�ݹ�ķ���
bool recur(vector<int>& postorder, int i, int j)
{
	if (i >= j) return true;
	int m = i;
	//Ѱ�����������ı߽�
	while (postorder[m] < postorder[j])
		m++;
	int n = m;
	while (postorder[n] > postorder[j])
		n++;
	return (n == j) && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
}
bool verifyPostorder(vector<int>& postorder) 
{
	return recur(postorder, 0, postorder.size() - 1);
}


//����ջ�ķ�����������������У������ǵ����ģ��������Ӻ���ǰ���ǵ�����ʱ��֤��Ϊ���ڵ�
bool verifyPostorder01(vector<int>& postorder)
{
	stack<int> stk;
	int root = INT_MAX;
	for (int i = postorder.size() - 1; i >= 0; i--)
	{
		if (postorder[i] > root) return false;
		while (stk.size() && stk.top() > postorder[i])
		{
			root = stk.top();
			stk.pop();
		}
		stk.push(postorder[i]);
	}
	return true;
}



//vector<vector<int>> ans;
//void backTrack(vector<int> num, int index, vector<int>& track)
//{
//	if (track.size() == num.size())
//	{
//		ans.push_back(vector<int>(track));
//		return;
//	}
//	set<int> s;
//	for (int i = index; i < num.size(); i++)
//	{
//		//�������к��������ͬ��λ�á���ͬһ��ݹ��forѭ�����桿���ܳ�������һ��������
//		if (s.count(num[i]))
//			continue;
//		s.insert(num[i]);
//
//		track.push_back(num[i]);
//		swap(num[i], num[index]);//�����Ĵ�����Ϊ�˱����ظ�Ԫ��
//		backTrack(num, index + 1, track);
//		swap(num[index], num[i]);
//		track.pop_back();
//	}
//}
//
//int perfectArrayNum(vector < int > array)
//{
//	vector<int> track;
//	int cnt = 0;
//	backTrack(array, 0, track);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		bool flag = true;
//		for (int j = 1; j < ans[0].size() ; j++)
//		{
//			int sum = ans[i][j] + ans[i][j - 1];
//			int sqrt1 = sqrt(sum);
//			if (sqrt1 * sqrt1 != sum)
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (flag) cnt++;
//	}
//	return cnt;
//}

//����������
//int main(void)
//{
//	int c = 0;
//	vector<int> a;
//	vector<int> b;
//	
//	while (cin >> c)
//	{
//		a.push_back(c);
//		if (cin.get() == '\n')break;
//	}
//		
//	while (cin >> c)
//	{
//		b.push_back(c);
//		if (cin.get() == '\n')break;
//	}
//		
//	//mp1 keyΪ����
//	map<int, int> mpb;
//	//mp2��keyΪֵ
//	map<int, int> mpa;
//	for (int i = 0; i < b.size(); i++)
//	{
//		mpb[i] = b[i];
//	}
//	for (int i = 0; i < a.size(); i++)
//	{
//		mpa[a[i]] ++;
//	}
//	vector<int> ans(a.size());
//	int k = 0;
//		
//	for (auto num : mpb)
//	{
//		if (mpa.count(num.second))
//		{
//			while (mpa[num.second] > 0)
//			{
//				ans[k++] = num.second;
//				mpa[num.second]--;
//			}
//				
//			mpa.erase(num.second);
//		}		
//	}
//	for (auto num : mpa)
//	{
//		ans[k++] = num.first;
//	}
//	cout << ans[0];
//	for (int i = 1; i < ans.size(); i++)
//		cout << ' ' << ans[i];
//	return 0;
//}

//ͳ�ƶ����� 1 �ĸ���
//int main(void)
//{
//	int i = 0;
//	cin >> i;
//	int ans = 0;
//	while (i != 0)
//	{
//		if (i & 1 == 1) ans++;
//		i = i >> 1;
//	}
//	cout << ans << endl;
//	return 0;
//}

//int main(void)
//{
//	int N = 0;
//	cin >> N;
//	vector<int> vec(N);
//	for (int i = 0; i < N; i++)
//		cin >> vec[i];
//	int time = 0;
//	cin >> time;
//	int ans = 0;
//	sort(vec.begin(), vec.end());
//	for (int i = N - 1; i >= 0; i -= 2)
//	{
//		ans += vec[i];
//		if (ans > time) break;
//	}
//
//	cout << (ans <= time) << endl;
//	return 0;
//}

//int main(void)
//{
//	int c = 0;
//	vector<int> a;
//	vector<int> b;
//	
//	while (cin >> c)
//	{
//		a.push_back(c);
//		if (cin.get() == '\n')break;
//	}
//		
//	while (cin >> c)
//	{
//		b.push_back(c);
//		if (cin.get() == '\n')break;
//	}
//	int ans = INT_MAX;
//	//numΪ�Ѿ��źõ�����
//	vector<int> num = b;
//	sort(num.begin(), num.end());
//	int k = 0;
//	for (int i = 0; i < a.size() - 1; i++)
//	{
//		int minmin = INT_MAX;
//		for (int j = i + 1; j < b.size(); j++)
//		{
//			minmin = min(b[j], minmin);
//		}
//		ans = min(ans, a[i] + minmin);
//	}
//	cout << ans << endl;
//	return 0;
//}