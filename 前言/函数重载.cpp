#include<iostream>

using namespace std;//Ҫ��������ʵ�� 

class stu
{
public:
	stu()=default; 
	stu(const int ,const int );//ʵ���˺������� 
	stu(const int,const int,const int); 
	stu(const double ,const double);

private:
	int s=0;
	double h=0;		
};

stu::stu(const int x,const int y)//����const��Ϊ�β�ʹ�����ȫ 
{
	this->s=x+y;
	cout<<"�����������"<<s<<endl;
}

stu::stu(const double x,const double y)
{
	this->h=x+y;
	cout<<"�������������"<<h<<endl;
}

stu::stu(const int x,const int y,const int z)
{
	this->s=x+y+z;
	cout<<"�������������"<<s<<endl;
}

int main(void)
{	
	int x,y,z;
	double aa,bb;
	
	cout<<"������������������ӣ�(�س�������һ��)"<<endl;
	cin>>x>>y;
	stu a(x,y);
	
	cout<<"��������������������ӣ�(�س�������һ��)"<<endl;
    cin>>aa>>bb;
    stu b(aa,bb);
	
	cout<<"������������������ӣ�(�س�������һ��)"<<endl;
	cin>>x>>y>>z;
	stu c(x,y,z);
	
	return 0;
}
