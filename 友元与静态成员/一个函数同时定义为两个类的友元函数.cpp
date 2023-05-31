#include<iostream>

using namespace std;

class Date;//��ǰ�������� 
class Clock
{
public:
	Clock(int,int,int);//���캯����ԭ������
	friend void show(Date &,Clock &);//����show����ΪClock�����Ԫ����  ������ĳ�Ա����
private:
	int hour,minute,second; 
};

class Date
{//Ĭ�Ϸ����޶���Ϊprivate 
	int year,month,day; 
public:
	Date(int ,int ,int);
	friend void show(Date &,Clock &);//����show����ΪDate�����Ԫ����	
};

int main()
{
	Date d(2018,8,1);
	Clock t(8,10,15);
	show(d,t);
	
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

void show(Date &d,Clock &t)
{
	cout<<d.year<<"�� "<<d.month<<"�� "<<d.day<<"��"<<endl;
	cout<<t.hour<<": "<<t.minute<<": "<<t.second<<endl;
}
