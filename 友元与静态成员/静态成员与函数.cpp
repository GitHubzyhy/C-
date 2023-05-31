#include<iostream>
#include<string>

using namespace std;

class Score
{
public:
	Score()=default;//默认构造函数 
	Score(const string n,const string s,int i,int g):name(n),sex(s),id(i){grade+=g,num++;}//同学的数量++ 
	Score(istream &input)
	{
		int grade1=0;//定义了一个局部变量 
		cout<<"第"<<num+1<<"个对象的创建"<<endl; 
		cout<<"输入name:";
		input>>name;
		cout<<"输入性别:";
		input>>sex;
		cout<<"输入成绩:";
		input>>grade1; 
		grade+=grade1;
		cout<<endl;
		num++;//同学的数量++ 
}

void show1()
{
	cout<<"name: "<<name<<endl;
	cout<<"sex: "<<sex<<endl;
	cout<<"grade: "<<grade<<endl;
} 

static double show()///静态成员函数 （作用：操作静态成员） 
{
	return grade/num;//计算的是平均成绩 
} 

 ~Score();
 static double grade;//计算总分数（静态成员在整个类中只有一个副本！！！属于类不属于对象，所有对象一起维护这个成员） 
 static double num;//静态数据成员（学生人数）目的：方便后续输出知道计算了几个对象 

private:
	string name;//名字
	string sex;//，性别 
	int id;//学生的身份证号码 
};

Score::~Score()
{
 	cout<<"Score析构函数执行！"<<endl; 
}

double Score::grade=0;//静态数据成员初始化（只能在类外进行初始化：这是要求） 
double Score::num=0;//静态数据成员初始化 

int main(void)
{
	Score a1("名字","男",2111,10);
	a1.show1(); 
	cout<<endl;
	cout<<"第"<<Score::num<<"个同学的平均分数是："<<a1.show()<<endl;
	
	//用户自己进行输入操作 
	Score a2[3]={Score(cin),Score(cin),Score(cin)};
	cout<<"第"<<Score::num<<"个同学的平均分: "<<a2[2].show()<<endl;
	 
	return 0; 
}
