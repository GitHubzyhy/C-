#include<iostream>
#include<Windows.h>
#include<assert.h>
#include<string>

using namespace std;

HANDLE aa=GetStdHandle(STD_OUTPUT_HANDLE);//当看不见，运行的时候更直观反正别看 !!
int ii=0;//定义的全局变量 

class student
{
public:
	student()=default;//默认构造 
	student(istream &input);//构造函数 
	student(const int id,const string &name,const int grade):ID(id),name(name),grade(grade){} //构造函数初始化列表 
	int Grade();//获取成绩的函数 为排序做准备 
	void show(int i);//显示 
	~student()//析构函数 可以不写但元旦要求了的 
	{
	cout<<"执行析构！"<<endl; 
	}
private:
		int ID=0;//学号 
		string name="0";//名字 
		int grade=0;//成绩 
};

student::student(istream &input)//构造函数的定义 
{
	
	cout<<"\t\t\t第"<<ii+1<<"个对象的创建！"<<endl;
	ii++; //全局变量增加记录第几个对象的创建 
	cout<<"输入学号：";
	input>>ID;//&后是input，所以用input输入 
	cout<<"输入学生姓名：";
	input>>name;
	cout<<"输入学生的成绩：";
	input>>grade; 
	cout<<endl;
}

int student::Grade()//返回学生的成绩 （为后面排序做准备！） 
{
		return grade;
}

void student::show(int i) 
{
		SetConsoleTextAttribute(aa, 7);
		
		cout<<"\t\t\t第"<<i+1<<"个对象的具体情况！"<<endl;
		cout<<"学号："<<ID<<endl;
		cout<<"输入学生姓名："<<name<<endl;
		
		SetConsoleTextAttribute(aa,15 | 8 | 128 | 64);//别管 
		
		cout<<"输入学生的成绩："<<grade;
		SetConsoleTextAttribute(aa, 7);//别管 
		cout<<endl;
}
int main(void)
{
    student a[6]={student(cin),student(cin),student(cin),student(cin),student(cin)};/*创建6个对象数组并调用
	用istreaam进行构造 */
    student *p=new(nothrow)  student[6];//动态创建student类的对象数组 
    assert(p!=nullptr);//如果分配失败停止运行 
    system("cls");
	
	for(int i=0;i<=4;i++) //前五个赋值给动态创建的对象数组 
	{
    *(p+i)=a[i];//对象的赋值 
    (p+i)->show(i);//赋值一个显示一个的所有信息 
	}
	
	for(int i=0;i<=4;i++)//冒泡排序 
 	for(int j=0;j<=4-i;j++)
 	{
 		if((p+j)->Grade()>(p+j+1)->Grade())//按照成绩排序 
 		{
 			*(p+5)=*(p+j);//；一共动态创建了6个对象数组，第6个（*(p+5)）【数组是从0开始计数】是空的拿来当t 
 			*(p+j)=*(p+j+1);
 			*(p+j+1)=*(p+5);
		 }
	 }
	 
	cout<<"\t\t\t排序后"<<endl<<endl; 
	for(int i=0;i<=4;i++) 
	{
    (p+i)->show(i);//一个个做输出看是否排序成功 
	}
	
	delete []p;//借了多少，要还回去 
	p=nullptr;//这俩必须在一起、、、书上32页有解释 
}
