#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(void)
{
	queue<int> q;///////////////////////不能把队列定义到循环外面呀 数据冲突了 改树的时候咋没意识到！！！！！！！
	vector<int> ans;
	int testCnt = 0;
	cin >> testCnt;//测试次数
	for (int i = 0; i < testCnt; i++)
	{
		int opCnt = 0;
		cin >> opCnt;
		for (int j = 0; j < opCnt; j++)
		{
			string operaType;
			int num = 0;
			cin >> operaType;
			if (operaType == "PUSH")
			{
				cin >> num;
				q.push(num);
			}
			else if (operaType == "TOP")
			{
				if (q.size()) ans.push_back(q.front());
				else ans.push_back(-1);
			}
			else if (operaType == "POP")
			{
				if (q.empty()) ans.push_back(-1);
				else q.pop();
			}
			else if (operaType == "SIZE")
			{
				ans.push_back(q.size());
			}
			else if (operaType == "CLEAR")
			{
				while (q.size())
					q.pop();
			}
		}
	}
	for (int i : ans)
	{
		cout << i << endl;
	}
	return 0;
}


//牛客的正确答案
#include <iostream>(5488)
#include <string>
#include <string.h>(5856)
#include <queue>
using namespace std;
int main(){    
	string cmd;    
	int t,q;    
	int val;   
	cin>>t;    
	while(t--)
	{        
		queue<int> que;        
		cin>>q;        
		while(q--)
		{            
			cin>>cmd;            
			if(cmd == "PUSH"){                
				cin>>val;                
				que.push(val);            
			}else if(cmd=="POP"){                
				if(que.empty()){                    
					cout<<-1<<endl;                
				}else{                    
					que.pop();                
				}            
			}else if(cmd=="TOP"){                
				if(que.empty()){                    
					cout<<-1<<endl;                
				}else{                    
					cout<<que.front()<<endl;                
				}            
			}else if(cmd=="SIZE"){                
				cout<<que.size()<<endl;            
			}else if(cmd=="CLEAR"){                
				while(!que.empty()){                    
					que.pop();                
				}            
			}        
		}    
	}    
	return 0;}