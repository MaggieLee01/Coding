//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
//https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/

#include<vector>
#include<math.h>
#include <ctime>
#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

//ò�����ֻ�ʺϷ��󣬾���Ļ���̫��
//vector<int> spiralOrder(vector<vector<int>>& matrix) 
//{
//	int row = matrix.size();
//	if (row == 0) return {};
//	int col = matrix[0].size();
//	vector<int> vec(row*col);
//	int m = 0;
//	for (int i = 0; i < row / 2 && col > 1; i++)
//	{
//		//ע��˵㲻Ҫ�ظ���ÿ��Сѭ��Ҫ�ײ�Ҫβ������д�������Գ��ԱȽ�����
//		//right
//		for (int j = i; j < col - i - 1; j++)
//			vec[m++] = matrix[i][j];	
//		//down
//		for (int j = i; j < row - i - 1; j++)		
//			vec[m++] = matrix[j][col - i - 1];		
//		//left
//		for (int j = col - i - 1; j > i; j--)
//			vec[m++] = matrix[row - i - 1][j];
//		//up
//		for (int j = row - i - 1; j > i; j--)
//			vec[m++] = matrix[j][i];
//	}
//	//��������У����ʣ�����
//	if (row % 2 == 1)
//	{
//		for (int i = row / 2; i < col - row / 2; i++)
//			vec[m++] = matrix[row / 2][i];
//	}
//	return vec;
//
//}


//���𰸣�ֱ�Ӹ��ݴ��жϣ����������ĸ��߽磬ȫ�Ǳ����䣬��ֹ�˵��ظ��Ļ�����ǰ��++ --����
//https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/solution/mian-shi-ti-29-shun-shi-zhen-da-yin-ju-zhen-she-di/
vector<int> spiralOrder01(vector<vector<int>>& matrix)
{
	if (matrix.size() == 0 || matrix[0].size() == 0) return {};
	int up = 0, down = matrix.size() - 1;	
	int left = 0, right = matrix[0].size() - 1;
	vector<int> vec((down + 1)*(right + 1));
	int k = 0;
	while (true)
	{
		//right
		for (int i = left; i <= right; i++)
			vec[k ++] = matrix[up][i];
		if (++up > down) break;

		//down
		for (int i = up; i <= down; i++)
			vec[k++] = matrix[i][right];
		if (--right < left)	break;

		//left
		for (int i = right; i >= left; i--)
			vec[k++] = matrix[down][i];
		if (--down < up) break;

		//up
		for (int i = down; i >= up; i--)
			vec[k++] = matrix[i][left];
		if (++left > right) break;
	}
	return vec;
}

//8/23������ �ϻ����ŵı����⣬ȫ���У��ж���Ч����
//int main(void)
//{
//	vector<vector<int>> vec = { {1,2,3,4,5},{1,2,3,4,5} };
//	spiralOrder(vec);
//	return 0;
//}
//
//int main(void)
//{
//	int n = 0;
//	cin >> n;
//	int ans = 0;
//	if (n > 4)
//	{
//		ans = n / 5;
//		int m = log(n) - log(5);
//		ans += m * (m - 1) / 2;
//	}
//	cout << ans << endl;
//	return 0;
//}


//bool Isvalid(string s)
//{
//	int sLength = s.size();
//	if (sLength == 0) return true;
//	unordered_map<char, char> dictMap;
//	stack<char> signStack;
//	dictMap['('] = ')';
//	dictMap['{'] = '}';
//	dictMap['['] = ']';
//	int i = 0;
//	for (i = 0; i < sLength; i++)
//	{
//		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
//			signStack.push(s[i]);
//		else if (signStack.size() && dictMap[signStack.top()] == s[i])
//			signStack.pop();
//		else break;
//	}
//	return (signStack.empty() && i == sLength);
//}
//
//int main(void)
//{
//	string s;
//	cin >> s;
//	bool ans = true;
//	if (s.size() != 0)
//	{
//		ans = Isvalid(s);
//	}
//	if (ans)
//		cout << "True" << endl;
//	else
//		cout << "False" << endl;
//	return 0;
//}

//int main(void)
//{
//	srand((int)time(0));
//	string str;
//	cin >> str;
//	bool ans = rand() % 100 < 73 ? true : false;
//	if(ans)
//		cout << "True" << endl;
//	else
//		cout << "False" << endl;
//	return 0;
//}

//vector<vector<int>>  ans;
//int isok(vector<int> num, int x, int y)
//{
//	int i = 0;
//	if (y > x)
//		for (i = x; i < y; i++)
//			if (num[i] == num[y])
//				return 0;
//	return 1;
//}
//void backTrack(vector<int> num, int index, int end, vector<int>& track, vector<int>& flag)
//{
//	if (track.size() == end + 1)
//	{
//		for (int i = end + 1; i < num.size(); i++)
//			track.push_back(num[i]);
//		ans.push_back(vector<int>(track));
//		return;
//	}
//	for (int i = index; i <= end; i++)
//	{
//		if (isok(num, index, i))
//		{
//			swap(num[i], num[index]);//�����Ĵ�����Ϊ�˱����ظ�Ԫ��
//			backTrack(num, index, end, track, flag);
//			swap(num[index], num[i]);
//
//		}
//		//if (flag[i] == 1) continue;
//		//if (i != index && num[i] == num[i - 1] && flag[i - 1] != 1) continue;
//		//track.push_back(num[i]);
//		//flag[i] = 1;
//		////swap(num[i], num[index]);//�����Ĵ�����Ϊ�˱����ظ�Ԫ��
//		//backTrack(num, index, end, track, flag);
//		////swap(num[index], num[i]);
//		//track.pop_back();
//		//flag[i] = 0;
//	}
//}
//
//vector<vector<int> > Permutation(vector<int>& datas, int start, int end) 
//{
//	vector<int> track;
//	vector<int> flag(datas.size());
//	for (int i = 0; i < start; i++)
//		track.push_back(datas[i]);
//	backTrack(datas, start, end, track, flag);
//	return ans;
//}
//
//int main(void)
//{
//	vector<int> num = { 1,2,2,3,5 };
//	Permutation(num, 0, 3);
//	return 0;
//}
//
