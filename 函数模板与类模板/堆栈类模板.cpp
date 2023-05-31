#include<iostream>

using namespace std;

const int SSize=10;

template<typename T>
class Stack
{
	T data[SSize];//栈元素数组，固定大小为SSize
	int top; 
public:
	Stack(){top=0;}
	void push(T e);//入栈
	T pop();//出栈
	bool stackEmpty(){return top==0;} //判断栈是否为空 
	bool stackFull(){return top==SSize;}//判断栈是否以满 
};

template<typename T>//push函数的类外定义
void Stack<T>::push(T e)
{
	if(top==SSize)
	{
		cout<<"Stack is Full! Dont't push data!\n";
		return ;
	}
	data[top++]=e;//没有满就入栈 
} 

template<typename T>
inline T Stack<T>::pop()//类外定义，只当为内置函数
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
