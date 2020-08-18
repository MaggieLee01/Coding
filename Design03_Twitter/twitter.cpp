/*设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：


	postTweet(userId, tweetId): 创建一条新的推文
	getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
	follow(followerId, followeeId): 关注一个用户
	unfollow(followerId, followeeId): 取消关注一个用户

	https://leetcode-cn.com/problems/design-twitter */

#include<vector>
#include<functional>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//思路不清晰，看了labuladong的题解
//参考代码：https://leetcode-cn.com/problems/design-twitter/solution/leetcode355-mian-xiang-guo-cheng-zui-da-de-kge-shu/
int now_ = 0;//全局变量
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
	unordered_map<int, user*>userMap;//存的是指针
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
		typedef function<bool(const Tweet*a, const Tweet*b)> Compare;//定义了函数的类型，不是返回值的类型，是function
		Compare comp = [](const Tweet*a, const Tweet*b) { return a->time < b->time; };
		//因为Compare的类型是function，所以应该使用匿名函数，这是一条语句，结尾加；
		priority_queue< Tweet*, vector<Tweet*>, Compare> pq(comp);

		//以上的定义可以写成这样子
		//注意标准库函数的用法
		//还有，优先级队列的默认比较函数，对应的是大根堆 还是 小根堆
		auto comp1 = [](const Tweet*a, const Tweet*b) { return a->time < b->time; };//弹出最大值，不知道按什么排序，所以需要写排序函数
		priority_queue< Tweet*, vector<Tweet*>, decltype(comp1)> pq1(comp1);

		//合并K个有序链表，不是把全部数据压入pq，而是比较链表头部，比较完之后弹出最值元素，压入弹出元素的下一个元素
		//非常巧妙的设计   
		for (auto followeeId : userMap[userId]->followed)//在该用户关注的用户里面遍历
		{
			if (userMap.count(followeeId) == 0)
				userMap[followeeId] = new user(followeeId);//先创建个 ，统一在head处判断
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
			if (top->next)	pq.push(top->next);//先判断是否有内容
		}
		return ans;
	}
};

int main(void)
{
	Twitter *twitter = new Twitter();

	// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
	twitter->postTweet(1, 5);

	// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
	twitter->getNewsFeed(1);

	// 用户1关注了用户2.
	twitter->follow(1, 2);

	// 用户2发送了一个新推文 (推文id = 6).
	twitter->postTweet(2, 6);

	// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
	// 推文id6应当在推文id5之前，因为它是在5之后发送的.
	twitter->getNewsFeed(1);

	// 用户1取消关注了用户2.
	twitter->unfollow(1, 2);

	// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
	// 因为用户1已经不再关注用户2.
	twitter->getNewsFeed(1);

	return 0;
}