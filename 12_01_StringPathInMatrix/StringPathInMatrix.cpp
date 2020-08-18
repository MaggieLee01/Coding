/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
[["a", "b", "c", "e"],
["s", "f", "c", "s"],
["a", "d", "e", "e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
*/ //https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof

//最后有借鉴题解的优化细节：空间优化
//一遍程序写完通过81/87，检查特殊用例，子函数的前两句判断顺序有误，稍稍修改后OK，比我想象的顺利

#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;

//第一感觉 回溯法
//判断四周是否存在下一个元素的子函数
bool exitNext(vector<vector<char>>& board, string word, int c, int r, int k, vector<vector<int>>& flag)
{
	if (flag[c][r] == 1) return false;//一定要放在判断k是否到长度的前面，
	//不然在还没判断是否有标志的情况下就返回true了，最后一个字符没正确判断，如board = {{'a','a'}}; word = "aaa";样例
	if (k >= word.size()) return true;

	int column = board.size();//列数
	int row = board[0].size();

	bool up = false, down = false, left = false, right = false;
	flag[c][r] = 1;

	if (c < column - 1 && board[c + 1][r] == word[k])
		down = exitNext(board, word, c + 1, r, k + 1, flag);	//可以在上面统一k++，不用写那么多次了		
	if (r < row - 1 && board[c][r + 1] == word[k])
		right = exitNext(board, word, c, r + 1, k + 1, flag);
	if (c > 0 && board[c - 1][r] == word[k])
		up = exitNext(board, word, c - 1, r, k + 1, flag);
	if (r > 0 && board[c][r - 1] == word[k])
		left = exitNext(board, word, c, r - 1, k + 1, flag);

	bool ans = up || down || right || left;
	flag[c][r] = ans;
	return ans;
}
//看了书本答案以及题解，此子函数可以判断[c][r]处的值相等后想四周扩散，可以精简后面四个方向判断的代码
//我写的，减少了压入函数栈的次数，代码不够精简判断是否相等的次数一样
//不同的写法 前面的终止顺序不一样呀 不然就会出界或者遍历不到，一定要在遍历的数组位置之前保证该点有意义
bool exitNext_answer(vector<vector<char>>& board, string word, int c, int r, int k, vector<vector<int>>& flag)
{
	if (k >= word.size()) return true;//此种方法不同于上面的细节，一定要在判断标准之前判断，防止board = {{'a'}}; word = "a";一个元素的样例
	int column = board.size();//列数
	int row = board[0].size();
	if (c >= column || c < 0 || r >= row || r < 0) return false;
	if (flag[c][r] == 1 || board[c][r] != word[k]) return false;

	flag[c][r] = 1;
	bool down = exitNext_answer(board, word, c + 1, r, k + 1, flag);
	bool right = exitNext_answer(board, word, c, r + 1, k + 1, flag);
	bool up = exitNext_answer(board, word, c - 1, r, k + 1, flag);
	bool left = exitNext_answer(board, word, c, r - 1, k + 1, flag);

	bool ans = up || down || right || left;
	flag[c][r] = ans;
	return ans;
}
bool exist(vector<vector<char>>& board, string word) {
	int column = board.size();//列数
	if (column == 0) return 0;
	int row = board[0].size();
	if (row == 0) return 0;
	vector<vector<int>> flag(column + 1, vector<int>(row + 1, 0));
	int k = 0;				//string 的索引，其实没必要
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			//下面注释的内容对应exitNext子函数，在if条件成立下调用
			//if (board[i][j] == word[k])
			//{	
			//	//如果没有，重新寻找起始字符
			//	/*if ((exitNext(board, word, i, j, k + 1, flag)) == false)
			//		continue;
			//	else return true;*/

			//	//稍稍修改写法，更简洁
			//	if (exitNext(board, word, i, j, k + 1, flag)) return true;				
			//}

			//两种子函数的判断顺序不一样，传参 遍历节点也不一样，
			//exitNext_answer函数不应该在if (board[i][j] == word[k])条件下调用			
			//if (exitNext_answer(board, word, i, j, k, flag)) return true;

			//不不！ 还是放在if里面能减少函数调用次数，即使重新开始，也需要保证首先和word[0]相同
			if (board[i][j] == word[k] && exitNext_answer(board, word, i, j, k, flag)) return true;
		}
	}
	return false;
}
int main(void)
{
	vector<vector<char>> board = {  {'A','B','C','E'},
									{'S','F','C','S'},
									{'A','D','E','E'} };
	string word = "ABCCED";
	bool n = exist(board, word);

	board = { {'a','d'},{'c','d'} };
	word = "abcd";
	n = exist(board, word);

	//一遍程序写完通过81/87，检查特殊用例，子函数的前两句判断顺序有误
	board = { {'a','a'}};
	word = "aaa";
	n = exist(board, word);

	return 0;
}
//看了题解 https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/shen-sou-hui-su-by-hanwn/
//在不想为flag额外开辟新空间的情况下，将遍历的board[c][r]的字符替换为特殊字符作为标志，四个方向调用递归之后，在将特殊字符换回来

//比较模块换的写法 https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/hui-su-by-lai_haha/

//https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/dfs-yuan-di-suan-fa-jie-sheng-kong-jian-by-jal/
//在某个方向能成功之后直接返回了，没有对四个方向的结果求或运算，不知道这样子是否能缩短时间，
//这样子正确性好奇怪呀，如果up不行，down方向可以，最深层的结果不能直接返回吧
//明白了，外面有全局变量默认false，当OK时直接给全局变量赋值为true了，所以不用管递归函数的返回值