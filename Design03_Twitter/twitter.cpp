/*���һ���򻯰������(Twitter)���������û�ʵ�ַ������ģ���ע/ȡ����ע�����û����ܹ�������ע�ˣ������Լ��������ʮ�����ġ���������Ҫ֧�����µļ������ܣ�


	postTweet(userId, tweetId): ����һ���µ�����
	getNewsFeed(userId): ���������ʮ�����ġ�ÿ�����Ķ��������ɴ��û���ע���˻������û��Լ������ġ����ı��밴��ʱ��˳��������Ŀ�ʼ����
	follow(followerId, followeeId): ��עһ���û�
	unfollow(followerId, followeeId): ȡ����עһ���û�

	https://leetcode-cn.com/problems/design-twitter */

#include<vector>
#include<functional>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//˼·������������labuladong�����
//�ο����룺https://leetcode-cn.com/problems/design-twitter/solution/leetcode355-mian-xiang-guo-cheng-zui-da-de-kge-shu/
int now_ = 0;//ȫ�ֱ���
class Tweet
{
public:
	int id;
	int time;
	Tweet* next;
	Tweet(int i) :id(i), time(now_++), next(nullptr) {}
};

class user
{
	int id;
public:
	unordered_set<int> followed;
	Tweet* head;
	user(int userId) :id(userId), head(nullptr)
	{
		followed.insert(id);
	}
	void follow(int followedId)
	{
		followed.insert(followedId);
	}
	void unfollow(int followedId)
	{
		if (followed.count(id) && followedId != id)
		{
			followed.erase(followedId);
		}
	}
	void postTweet(int tweetId)
	{
		Tweet* temp = new Tweet(tweetId);
		temp->next = head;
		head = temp;
	}
};
class Twitter
{
	unordered_map<int, user*>userMap;//�����ָ��
public:
	Twitter()
	{
		userMap.clear();
	}
	void postTweet(int userId, int tweetId)
	{
		if (userMap.count(userId) == 0)
			userMap[userId] = new user(userId);
		userMap[userId]->postTweet(tweetId);
	}
	void follow(int followerId, int followeeId)
	{
		if (userMap.count(followerId) == 0)
			userMap[followerId] = new user(followerId);
		userMap[followerId]->follow(followeeId);
	}
	void unfollow(int followerId, int followeeId)
	{
		if (userMap.count(followerId) == 0) return;
		userMap[followerId]->unfollow(followeeId);
	}
	vector<int> getNewsFeed(int userId)
	{
		if (userMap.count(userId) == 0) return{};
		typedef function<bool(const Tweet*a, const Tweet*b)> Compare;//�����˺��������ͣ����Ƿ���ֵ�����ͣ���function
		Compare comp = [](const Tweet*a, const Tweet*b) { return a->time < b->time; };
		//��ΪCompare��������function������Ӧ��ʹ����������������һ����䣬��β�ӣ�
		priority_queue< Tweet*, vector<Tweet*>, Compare> pq(comp);

		//���ϵĶ������д��������
		//ע���׼�⺯�����÷�
		//���У����ȼ����е�Ĭ�ϱȽϺ�������Ӧ���Ǵ���� ���� С����
		auto comp1 = [](const Tweet*a, const Tweet*b) { return a->time < b->time; };//�������ֵ����֪����ʲô����������Ҫд������
		priority_queue< Tweet*, vector<Tweet*>, decltype(comp1)> pq1(comp1);

		//�ϲ�K�������������ǰ�ȫ������ѹ��pq�����ǱȽ�����ͷ�����Ƚ���֮�󵯳���ֵԪ�أ�ѹ�뵯��Ԫ�ص���һ��Ԫ��
		//�ǳ���������   
		for (auto followeeId : userMap[userId]->followed)//�ڸ��û���ע���û��������
		{
			if (userMap.count(followeeId) == 0)
				userMap[followeeId] = new user(followeeId);//�ȴ����� ��ͳһ��head���ж�
			Tweet* Head = userMap[followeeId]->head;
			if (Head == nullptr) continue;
			pq.push(Head);
		}
		vector<int> ans;
		while (pq.size())
		{
			Tweet *top = pq.top();
			pq.pop();
			ans.push_back(top->id);
			if (ans.size() == 10) break;
			if (top->next)	pq.push(top->next);//���ж��Ƿ�������
		}
		return ans;
	}
};

int main(void)
{
	Twitter *twitter = new Twitter();

	// �û�1������һ�������� (�û�id = 1, ����id = 5).
	twitter->postTweet(1, 5);

	// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
	twitter->getNewsFeed(1);

	// �û�1��ע���û�2.
	twitter->follow(1, 2);

	// �û�2������һ�������� (����id = 6).
	twitter->postTweet(2, 6);

	// �û�1�Ļ�ȡ����Ӧ������һ���б����а����������ģ�id�ֱ�Ϊ -> [6, 5].
	// ����id6Ӧ��������id5֮ǰ����Ϊ������5֮���͵�.
	twitter->getNewsFeed(1);

	// �û�1ȡ����ע���û�2.
	twitter->unfollow(1, 2);

	// �û�1�Ļ�ȡ����Ӧ������һ���б����а���һ��idΪ5������.
	// ��Ϊ�û�1�Ѿ����ٹ�ע�û�2.
	twitter->getNewsFeed(1);

	return 0;
}