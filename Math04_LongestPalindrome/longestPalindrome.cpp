/*����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ���
�ڹ�������У���ע�����ִ�Сд������ "Aa" ���ܵ���һ�������ַ�����
ע��: �����ַ����ĳ��Ȳ��ᳬ�� 1010��

����: "abccccdd"; ���: 7
���ǿ��Թ������Ļ��Ĵ���"dccaccd", ���ĳ����� 7��*/

#include<vector>
#include<string>
using std::string;
using std::vector;
int longestPalindrome(string s)
{
	vector<int> dict(52, 0);
	int ans = 0, flag = 0;
	for (char i : s)
	{
		if ('a' <= i && i <= 'z') dict[i - 'a']++;
		else if ('A' <= i && i <= 'Z') dict[i - 'A' + 26]++;
	}
	for (int i : dict)
	{
		if (i % 2 == 0) ans += i;
		else { ans += i - 1; flag = 1; }//֮ǰ����ans+=i-1��һ�䣬ֱ�����˸�flag��������ccc���11����ʶ������
	}
	return (ans + flag);
}
//����ȡ�࣬����ֱ���� & λ����

//������⣬128��С�����鲻�����ִ�Сд���жϣ�������ͳ�����������Ĵ��������ֱ�Ӽ�ȥ
int longestPalindrome01(string s)
{
	// �ҳ����Թ�������Ĵ��ĳ���
	vector<int> arr(128, 0);
	for (char c : s)
		arr[c]++;

	int count = 0;
	for (int i : arr)
		count += (i % 2);

	return count == 0 ? s.length() : (s.length() - count + 1);
}
//ans += x - (x & 1); Ҳ��������д��

//Ҳ�ж���58�����飬ֱ�� i-'A'��

//�����������λ�����
int longestPalindrome01(string s)
{
	int odd = 0;
	long freq = 0b0L; // 64 bits > 58 chars(from A to z)
	for (char c : s)
	{
		long ori = freq;
		freq ^= 1L << (c - 'A'); // ���ռλ��1L Ϊ long������ 1 �� int
		if (freq > ori) odd++; // ͳ�ƺ����ӣ�˵������һ���ȴ���
		else odd--; // ͳ�ƺ���٣�˵��������ͬ�ַ��ճ�ż����������ͳ�� - 1
	}
	return s.length() - odd + (odd > 0 ? 1 : 0);
}
