#include<iostream>

using namespace std;//Ҫ�󽻻�����������λ�ã����ã�

int main(void)
{
	int x,y;
	cout<<"���������������������ûس�������һ����"<<endl;	
	
	cin>>x>>y;
	void change(int& ,int&);

	change(x,y);
	cout<<"�������λ����"<<endl<<x<<endl<<y<<endl; 
} 

void change(int &x,int&y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
