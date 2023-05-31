#include<stack>//ջ������
#include<queue>//���������� 
#include<iostream>
#include<cstring>
#include<vector>//��̬���� 
using namespace std; 
struct Node
{
	char szName[20];//����
	int priority;//���ȼ� 
	Node(int nri,char *pszName)
	{
		strcpy(szName,pszName);		
		priority=nri;
	} 
};
// д�º���
class NodeCmp
{
	public:
	//��дoperator()����,ע��������д�ķ�����operator()(����1��....)
	bool operator()(const Node &na,const Node &nb)
	{
		if(na.priority!=nb.priority)
		return na.priority<=nb.priority;
		else
		return strcmp(na.szName,nb.szName)>0;//���ȼ���ȵ�����������ֱȽ� 
	} 
	
}; 
void text(); 
int main()
{
	/*ÿ�����������������������캯����һ����Ĭ�Ϲ��캯��
	����һ���ն���һ���ǽ���һ�������Ĺ��캯�����Ƹ���������ʼ�������� */
	stack<string,vector<string>>str_stk1;//��ʾָ����������vector����ʵ��
	stack<string,vector<string>>str_stk2(str_stk1);//��ʼ��ʱ����ʱ����str_stk1�ĸ���
	/*stack����ʹ�ó�array��forward_list֮����κζ���������������stack
	  queue ֻ�ܽ�����list��deque����
	  priority_queue ֻ�ܽ�����vector �� deque֮�� 
	*/ 
	stack<int,vector<int>>str_stk3;
	for(int i=0;i<8;i++)
	str_stk3.push(i);//ȫ��ѹջ
	while(!str_stk3.empty())
	{
		int value=str_stk3.top();//����topԪ��
		cout<<value<<" ";
		 str_stk3.pop();//ɾ��Ԫ�� 
	}	
	/*str_stk3.push(i)�Ǵ���ģ�����ֱ��ʹ�ã�����ʹ��stack�Լ���push����*/	
	cout<<endl;
	text();
	return 0;
}

void printNode(Node na)//��ӡ�ڵ�
{
	cout<<na.priority<<" "<<na.szName<<endl;
} 
void text()
{
	//���ȼ�����Ĭ����ʹ��vector���������ײ����ݽṹΪ�� 
	// �������ȼ����У�������Զ������ݶ�Ҫ����<������������ر������޷��Ƚϣ�1����Ա����2����Ԫ���� 
	priority_queue<Node,vector<Node>,NodeCmp> a;
	a.push(Node(5,"С̷"));
	a.push(Node(2,"С��"));
	a.push(Node(3,"С��"));
	a.push(Node(1,"С��"));
	//��ͷ�������˳���
	printNode(a.top());
	a.pop();
    printNode(a.top());
    a.pop();
    cout<<"�ٽ���������"<<endl;
    a.push(Node(2,"С��2"));
	a.push(Node(2,"С��2"));
	a.push(Node(3,"С��3"));
	while(!a.empty())
	{
		printNode(a.top());
		a.pop();
	}
}
