#include<iostream>

using namespace std;//要求交换两个整数的位置（引用）

int main(void)
{
	int x,y;
	cout<<"请你输入两个整数！（用回车输入下一个）"<<endl;	
	
	cin>>x>>y;
	void change(int& ,int&);

	change(x,y);
	cout<<"交换后的位置是"<<endl<<x<<endl<<y<<endl; 
} 

void change(int &x,int&y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
