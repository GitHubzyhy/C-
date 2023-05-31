#include<iostream>

using namespace std;//要求函数重载实现 

class stu
{
public:
	stu()=default; 
	stu(const int ,const int );//实现了函数重载 
	stu(const int,const int,const int); 
	stu(const double ,const double);

private:
	int s=0;
	double h=0;		
};

stu::stu(const int x,const int y)//利用const作为形参使其更安全 
{
	this->s=x+y;
	cout<<"两个整数相加"<<s<<endl;
}

stu::stu(const double x,const double y)
{
	this->h=x+y;
	cout<<"两个浮点型相加"<<h<<endl;
}

stu::stu(const int x,const int y,const int z)
{
	this->s=x+y+z;
	cout<<"三个个整数相加"<<s<<endl;
}

int main(void)
{	
	int x,y,z;
	double aa,bb;
	
	cout<<"请你输入两个整数相加！(回车输入下一个)"<<endl;
	cin>>x>>y;
	stu a(x,y);
	
	cout<<"请你输入两个浮点型相加！(回车输入下一个)"<<endl;
    cin>>aa>>bb;
    stu b(aa,bb);
	
	cout<<"请你输入三个整型相加！(回车输入下一个)"<<endl;
	cin>>x>>y>>z;
	stu c(x,y,z);
	
	return 0;
}
