#include<iostream>

using namespace std;

class Date;//向前引用声明 
class Clock
{
public:
	Clock(int,int,int);//构造函数的原型申明
    void show(Date &);//是这个类的成员函数 
private:
	int hour,minute,second; 
};

class Date
{//默认访问限定符为private 
	int year,month,day; 
public:
	Date(int ,int ,int);
	friend void Clock::show(Date &);//申明show函数为Date类的友元函数	
};

int main()
{
	Date d(2018,8,1);
	Clock t(8,10,15);
	t.show(d);
	
	return 0;
}

Clock::Clock(int h,int m,int s)
{
	this->hour=h,this->minute=m,this->second=s;
} 

Date::Date(int y,int m,int d)
{
	this->year=y,this->month=m,this->day=d;
}

void Clock:: show(Date &d)
{
	cout<<d.year<<"年 "<<d.month<<"月 "<<d.day<<"日"<<endl;
	cout<<hour<<": "<<minute<<": "<<second<<endl;
}
