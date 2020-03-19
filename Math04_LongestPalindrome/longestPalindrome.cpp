/*给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意: 假设字符串的长度不会超过 1010。

输入: "abccccdd"; 输出: 7
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。*/

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
		else { ans += i - 1; flag = 1; }//之前忘记ans+=i-1这一句，直接整了个flag，遇到了ccc输出11才意识到问题
	}
	return (ans + flag);
}
//对了取余，可以直接用 & 位运算

//看了题解，128大小的数组不用区分大小写的判断，而且是统计奇数个数的次数，最后直接减去
int longestPalindrome01(string s)
{
	// 找出可以构成最长回文串的长度
	vector<int> arr(128, 0);
	for (char c : s)
		arr[c]++;

	int count = 0;
	for (int i : arr)
		count += (i % 2);

	return count == 0 ? s.length() : (s.length() - count + 1);
}
//ans += x - (x & 1); 也有这样子写的

//也有定义58个数组，直接 i-'A'的

//题解里面有用位运算的
int longestPalindrome01(string s)
{
	int odd = 0;
	long freq = 0b0L; // 64 bits > 58 chars(from A to z)
	for (char c : s)
	{
		long ori = freq;
		freq ^= 1L << (c - 'A'); // 异或占位，1L 为 long，而非 1 的 int
		if (freq > ori) odd++; // 统计后增加，说明多了一个等待者
		else odd--; // 统计后减少，说明来了相同字符凑成偶数，故奇数统计 - 1
	}
	return s.length() - odd + (odd > 0 ? 1 : 0);
}
