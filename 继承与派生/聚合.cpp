#include<iostream>
#include<string>
using namespace std;
class Employee//基类 
{
public:
	Employee()=default;
	Employee(const string &Name,int Id,int Grade):name(Name),id(Id),grade(Grade){}//构造函数的初始化列表
	Employee(istream &input):Employee()//委托函数方便后面的调试 
	{
		cout<<"输入name："<<endl;
		input>>name;
		cout<<"输入id: "<<endl;
		input>>id;
	}
	~Employee()=default;
protected:
	string name;//姓名 
	int id=0;//编号 
	int grade=1;//级别
	double salary=0;//工资 
};
//经理的类 
class Manager:virtual public Employee
{
public:
	Manager()=default;//显示调用默认构造函数 
	Manager(const string &Name,int Id,int Grade):Employee(Name,Id,Grade){}//经理的构造 
	Manager(istream &input):Employee(input){}
	void show()
	{
		if(grade==4)//如果级别是4 
		{
			cout<<"name: "<<name<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"grade: "<<grade<<endl;
			salary=8000;//经理固定工资 
	     	cout<<"经理的工资为："<<salary<<"元"<<endl; 
		} 
	}
	~Manager()=default; 
};
//建立的日期类(与技术人员是一个板块的，这一板块可以先不看） -------------------------------- ---------------------------------------------
class date
{
	public:
	date(int Hour):hour(Hour){}
	~date()=default;
	protected:
	int hour;
	
};

//技术人员的类 
class Technician: virtual public Employee
{
public:
	Technician()=default;
	Technician(const string &Name,int Id,int Grade,int H):Employee(Name,Id,Grade),Date(H){salary=100*H;}
	using Employee::Employee;
	
	void show()
	{
		if(grade==3)
		{
			cout<<"name: "<<name<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"grade: "<<grade<<endl;
		cout<<"技术人员的工资"<<salary<<"元"<<endl;
		}
	    
	}
	~Technician()=default;
protected:
	date Date;//定义的子对象书上196页相似代码 
};
//------------------------------------------------------------------------------------------
class Salesman:virtual public Employee //销售员 
{
public:
	Salesman()=default;
	Salesman(const string &Name,int Id,int Grade,int Value):Employee(Name,Id,Grade),value(Value){}
	Salesman(istream &input):Employee(input)
	{
		if(grade==1)//如果初始级别为1 
		{
			cout<<"输入销售额(value)："<<endl;
	        input>>value;
		}
	}
	void show()
	{
		if(grade==1)
		{
			salary+=value*0.04;//销售额0.04的提成
			cout<<"name: "<<name<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"grade: "<<grade<<endl;
			cout<<"value(销售额): "<<value<<endl; 
			cout<<"销售员的工资是：一个月"<<salary<<"元"<<endl; 
		}
		
	}
	~ Salesman()=default;
protected:
	int value=0;	
};
class Salesmanager:public Manager,public Salesman//销售经理 
{
public:
	Salesmanager()=default;
	Salesmanager(const string &Name,int Id,int Grade,int Value):Employee(Name,Id,Grade),
	Manager(Name,Id,Grade),Salesman(Name,Id,Grade,Value){}
	Salesmanager(istream &input):Employee(input),Manager(input),Salesman(input){}
	void up_or_down()
	{
		int n;
		cout<<"输入升职的次数（只有级别1.3.4）"<<endl;
		cin>>n;
		while(n==1)
		{
			cout<<"只有级别1.3.4"<<endl;
			cin>>n;
		 } 
		 for(int i=0;i<=n-1;i++)
		grade++;//升职
	 } 
	void show()
	{
		if(grade==1)
		{
			Salesman::show();
		}
		else if(grade==3)
		{
			cout<<"name: "<<name<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"grade: "<<grade<<endl;
			cout<<"value(销售额):"<<value<<endl;
			salary+=value*0.05+5000;//基础工资加上销售额0.05的提成 
			cout<<"销售经理的工资是："<<salary<<"元"<<endl; 
		}
		else if(grade==4)
		{
			Manager::show();
		}
	}
	~Salesmanager()=default; 
protected:
	int valuee=0;
};

int main(void)
{
//第一个对象  级别1： 销售员，级别3：技术人员或者销售经理，级别4：经理 
	
	Salesmanager a("name",21110504,1,100);//名字，工号，级别，销售总额（要求全部初始人员级别是1） 
	a.show();
	a.up_or_down();//降职操作 （级别是4级别只能降级） 
	a.show();

//第二个对象	   
	Salesmanager b(cin);
	b.show();
	cout<<endl; 
	b.up_or_down();
	b.show();
	   
/*     ------>继承的意思 
基类-----> 经理（4级别）【日期类和技术人员先别看】
                       ||---------->销售经理（3级别） 
基类----->销售员（1级别） 

在主函数中定义销售经理的对象，实现降职或者升值操作，然后输出信息 
注意 级别1： 销售员，级别3：技术人员或者销售经理，级别4：经理  


*/	   
	   
	   
	   
	   
	   
	   
	   
	   
}
