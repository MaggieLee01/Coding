/*�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ������
[["a", "b", "c", "e"],
["s", "f", "c", "s"],
["a", "d", "e", "e"]]
�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
*/ //https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof

//����н�������Ż�ϸ�ڣ��ռ��Ż�
//һ�����д��ͨ��81/87����������������Ӻ�����ǰ�����ж�˳�����������޸ĺ�OK�����������˳��

#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;

//��һ�о� ���ݷ�
//�ж������Ƿ������һ��Ԫ�ص��Ӻ���
bool exitNext(vector<vector<char>>& board, string word, int c, int r, int k, vector<vector<int>>& flag)
{
	if (flag[c][r] == 1) return false;//һ��Ҫ�����ж�k�Ƿ񵽳��ȵ�ǰ�棬
	//��Ȼ�ڻ�û�ж��Ƿ��б�־������¾ͷ���true�ˣ����һ���ַ�û��ȷ�жϣ���board = {{'a','a'}}; word = "aaa";����
	if (k >= word.size()) return true;

	int column = board.size();//����
	int row = board[0].size();

	bool up = false, down = false, left = false, right = false;
	flag[c][r] = 1;

	if (c < column - 1 && board[c + 1][r] == word[k])
		down = exitNext(board, word, c + 1, r, k + 1, flag);	//����������ͳһk++������д��ô�����		
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
//�����鱾���Լ���⣬���Ӻ��������ж�[c][r]����ֵ��Ⱥ���������ɢ�����Ծ�������ĸ������жϵĴ���
//��д�ģ�������ѹ�뺯��ջ�Ĵ��������벻�������ж��Ƿ���ȵĴ���һ��
//��ͬ��д�� ǰ�����ֹ˳��һ��ѽ ��Ȼ�ͻ������߱���������һ��Ҫ�ڱ���������λ��֮ǰ��֤�õ�������
bool exitNext_answer(vector<vector<char>>& board, string word, int c, int r, int k, vector<vector<int>>& flag)
{
	if (k >= word.size()) return true;//���ַ�����ͬ�������ϸ�ڣ�һ��Ҫ���жϱ�׼֮ǰ�жϣ���ֹboard = {{'a'}}; word = "a";һ��Ԫ�ص�����
	int column = board.size();//����
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
	int column = board.size();//����
	if (column == 0) return 0;
	int row = board[0].size();
	if (row == 0) return 0;
	vector<vector<int>> flag(column + 1, vector<int>(row + 1, 0));
	int k = 0;				//string ����������ʵû��Ҫ
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			//����ע�͵����ݶ�ӦexitNext�Ӻ�������if���������µ���
			//if (board[i][j] == word[k])
			//{	
			//	//���û�У�����Ѱ����ʼ�ַ�
			//	/*if ((exitNext(board, word, i, j, k + 1, flag)) == false)
			//		continue;
			//	else return true;*/

			//	//�����޸�д���������
			//	if (exitNext(board, word, i, j, k + 1, flag)) return true;				
			//}

			//�����Ӻ������ж�˳��һ�������� �����ڵ�Ҳ��һ����
			//exitNext_answer������Ӧ����if (board[i][j] == word[k])�����µ���			
			//if (exitNext_answer(board, word, i, j, k, flag)) return true;

			//������ ���Ƿ���if�����ܼ��ٺ������ô�������ʹ���¿�ʼ��Ҳ��Ҫ��֤���Ⱥ�word[0]��ͬ
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

	//һ�����д��ͨ��81/87����������������Ӻ�����ǰ�����ж�˳������
	board = { {'a','a'}};
	word = "aaa";
	n = exist(board, word);

	return 0;
}
//������� https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/shen-sou-hui-su-by-hanwn/
//�ڲ���Ϊflag���⿪���¿ռ������£���������board[c][r]���ַ��滻Ϊ�����ַ���Ϊ��־���ĸ�������õݹ�֮���ڽ������ַ�������

//�Ƚ�ģ�黻��д�� https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/hui-su-by-lai_haha/

//https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/dfs-yuan-di-suan-fa-jie-sheng-kong-jian-by-jal/
//��ĳ�������ܳɹ�֮��ֱ�ӷ����ˣ�û�ж��ĸ�����Ľ��������㣬��֪���������Ƿ�������ʱ�䣬
//��������ȷ�Ժ����ѽ�����up���У�down������ԣ������Ľ������ֱ�ӷ��ذ�
//�����ˣ�������ȫ�ֱ���Ĭ��false����OKʱֱ�Ӹ�ȫ�ֱ�����ֵΪtrue�ˣ����Բ��ùܵݹ麯���ķ���ֵ