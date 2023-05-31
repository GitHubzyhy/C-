#include<iostream>

using namespace std;

const int SSize=10;

template<typename T>
class Stack
{
	T data[SSize];//ջԪ�����飬�̶���СΪSSize
	int top; 
public:
	Stack(){top=0;}
	void push(T e);//��ջ
	T pop();//��ջ
	bool stackEmpty(){return top==0;} //�ж�ջ�Ƿ�Ϊ�� 
	bool stackFull(){return top==SSize;}//�ж�ջ�Ƿ����� 
};

template<typename T>//push���������ⶨ��
void Stack<T>::push(T e)
{
	if(top==SSize)
	{
		cout<<"Stack is Full! Dont't push data!\n";
		return ;
	}
	data[top++]=e;//û��������ջ 
} 

template<typename T>
inline T Stack<T>::pop()//���ⶨ�壬ֻ��Ϊ���ú���
{
	if(top==0)
	{
		cout<<"Stack is Empty!,Don't pop data!\n";
		return 0;
	}
	top--;
	return data[top];
} 

int main()
{
	Stack<int> s;
	for(int i=1;i<=5;++i)
	s.push(i);
	
	while(!s.stackEmpty())
	{
		cout<<s.pop()<<" ";
	}
	return 0;
}
