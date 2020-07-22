#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<utility>
#include<unordered_map>
using namespace std;

class Window 
{
public:
	//1未加载 2显示 3隐藏 4对象池
	int status;						//四种状态
	bool top;
	Window():status(1),top(false){}

	stack<Window*> sshow;//显示的栈
	stack<Window*> shint;
	virtual bool show() = 0;
	virtual void close() {}
 

};
class NormalWindow :public Window
{
public:
	bool show()
	{
		status = 2;
		sshow.push(this);
		return true;
	}
};
class FullWindow :public Window 
{
	bool show()
	{
		status = 2;
		while (sshow.size())
		{
			Window* temp = sshow.top();
			temp->status = 3;
			shint.push(temp);
		}	
		return true;
	}
	void close()
	{
		status = 4;
		while (shint.size())
		{
			Window* temp = shint.top();
			temp->status = 2;
			sshow.push(temp);
		}
	}

};
class PopWindow :public Window
{
public:
	PopWindow(){}
	bool show()
	{
		if (top == true) return false;
		top = true;
		return true;
	}
};
class Windowmanager
{
public:
	void addWindow(pair<string, Window*> pii)//id 和 类型
	{
		m_window.insert(pii);
	}
	Window* getWindow(string windowId)
	{
		return m_window[windowId];
	}
	bool check(string windowId)
	{
		return m_window[windowId]->sshow.top() == m_window[windowId];
	}
	bool show(string windowId)
	{
		return m_window[windowId]->show();
	}
private:
	unordered_map<string, Window*> m_window;
};
int main(void)
{
	int cnt = 0, m = 0;
	cin >> cnt >> m;
	string windowId;
	string windowType;
	Windowmanager wm;
	for (int i = 0; i < cnt; i++)
	{
		cin >> windowId;
		cin >> windowType;
		if (windowType == "NormalWindow")		
			wm.addWindow({ windowId, new NormalWindow() });
		
		else if (windowType == "FullWindow")		
			wm.addWindow({ windowId, new FullWindow() });
		
		else if (windowType == "PopmalWindow")		
			wm.addWindow({ windowId, new PopWindow() });
	}

	int mcnt = 0;
	cnt >> mcnt;
	string winOperator;
	for (int i = 0; i < mcnt; i++)
	{
		cin >> winOperator;
		cin >> windowId;
		if (winOperator == "show")
		{
			if (wm.show(windowId)) cout << windowId << endl;
			else cout << "Invalid operation" << endl;
		}
		else if (winOperator == "check")
		{
			if(wm.check(windowId))	cout << windowId << endl;
			else cout << "FALSE" << endl;
		}
	}	
}