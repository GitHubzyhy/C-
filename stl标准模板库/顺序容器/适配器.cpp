#include<stack>//栈适配器
#include<queue>//队列适配器 
#include<iostream>
#include<cstring>
#include<vector>//动态数组 
using namespace std; 
struct Node
{
	char szName[20];//人名
	int priority;//优先级 
	Node(int nri,char *pszName)
	{
		strcpy(szName,pszName);		
		priority=nri;
	} 
};
// 写仿函数
class NodeCmp
{
	public:
	//重写operator()方法,注意这里重写的方法，operator()(参数1，....)
	bool operator()(const Node &na,const Node &nb)
	{
		if(na.priority!=nb.priority)
		return na.priority<=nb.priority;
		else
		return strcmp(na.szName,nb.szName)>0;//优先级相等的情况下用名字比较 
	} 
	
}; 
void text(); 
int main()
{
	/*每个适配器都定义了两个构造函数，一个是默认构造函数
	构造一个空对象，一个是接受一个容器的构造函数复制该容器来初始化适配器 */
	stack<string,vector<string>>str_stk1;//显示指定适配器在vector上面实现
	stack<string,vector<string>>str_stk2(str_stk1);//初始的时候临时保存str_stk1的副本
	/*stack可以使用除array，forward_list之外的任何二容器类型来构造stack
	  queue 只能建立在list和deque上面
	  priority_queue 只能建立在vector 和 deque之上 
	*/ 
	stack<int,vector<int>>str_stk3;
	for(int i=0;i<8;i++)
	str_stk3.push(i);//全部压栈
	while(!str_stk3.empty())
	{
		int value=str_stk3.top();//返回top元素
		cout<<value<<" ";
		 str_stk3.pop();//删除元素 
	}	
	/*str_stk3.push(i)是错误的，不能直接使用，必须使用stack自己的push操作*/	
	cout<<endl;
	text();
	return 0;
}

void printNode(Node na)//打印节点
{
	cout<<na.priority<<" "<<na.szName<<endl;
} 
void text()
{
	//优先级队列默认是使用vector作容器，底层数据结构为堆 
	// 对于优先级队列，如果是自定义数据都要重载<运算符，不重载编译器无法比较，1：成员函数2：友元函数 
	priority_queue<Node,vector<Node>,NodeCmp> a;
	a.push(Node(5,"小谭"));
	a.push(Node(2,"小留"));
	a.push(Node(3,"小王"));
	a.push(Node(1,"小套"));
	//对头的两个人出队
	printNode(a.top());
	a.pop();
    printNode(a.top());
    a.pop();
    cout<<"再进入三个人"<<endl;
    a.push(Node(2,"小留2"));
	a.push(Node(2,"小王2"));
	a.push(Node(3,"小王3"));
	while(!a.empty())
	{
		printNode(a.top());
		a.pop();
	}
}
