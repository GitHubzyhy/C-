#include<iostream>
#include<string>
using namespace std;
class Employee//基类 
{
public:
	Employee()=default;
	Employee(const string &Name,int Age,const string &Sex,const string &Address
,const string &Telephone):name(Name),
age(Age),sex(Sex),address(Address),telephone(Telephone){}//构造函数的初始化列表

Employee(istream &input):Employee()//委托函数方便后面的调试 
{
	cout<<"输入name："<<endl;
	input>>name;
	cout<<"输入age: "<<endl;
	input>>age;
	cout<<"输入sex: "<<endl;
	input>>sex;
	cout<<"输入address:"<<endl;
	input>>address;
	cout<<"输入telephone: "<<endl;
	input>>telephone;
}
	~Employee()=default;
protected:
	string name;//姓名 
	int age;//年龄 
	string sex;//性别 
	string address;//地址 
	string telephone;//电话	
};

class Teacher:virtual public Employee
{
public:
	Teacher()=default;//显示调用构造函数 
	Teacher(const string &Name,int Age,const string &Sex,const string &Address
	,const string &Telephone,const string &Title):Employee(Name, Age,Sex,Address,Telephone),title(Title){}//构造函数的初始化列表
	
	Teacher(istream &input):Employee(input)//委托函数方便后面的调试 
	{
		cout<<"输入title: "<<endl;
		input>>title;
	}
	~Teacher()=default; 
protected:
	string title;//职称 (此类特有） 
};

class Cardre: virtual public Employee
{
public:
	Cardre()=default;
	Cardre(const string &Name,int Age,const string &Sex,const string &Address
	,const string &Telephone,const string &Post):Employee(Name, Age,Sex,Address,Telephone),post(Post){}//构造函数的初始化列表
	
	Cardre(istream &input):Employee(input)//委托函数方便后面的调试 
	{
		cout<<"输入post: "<<endl;
		input>>post;
	}
	~Cardre()=default;
protected:
	string post;//职务(此类特有）
};

class Teacher_Cardre:public Teacher,public Cardre//公用继承两个基类 
{
public:
	Teacher_Cardre()=default;
	Teacher_Cardre(const string &Name,int Age,const string &Sex,const string &Address
	,const string &Telephone,const string &Title,const string &Post,int Wage):Employee(Name,Age,Sex,Address,Telephone),Teacher(Name, Age,Sex,Address,Telephone,Title),
	Cardre(Name, Age,Sex,Address,Telephone,Post),wage(Wage){}//构造函数的初始化列表
	
	Teacher_Cardre(istream &input):Employee(input),Teacher(input),Cardre(input)//委托函数方便后面的调试 
	{
		cout<<"输入wage: "<<endl;
		input>>wage;
	}

	void show()
	{
		cout<<"name: "<<name<<endl;
		cout<<"age: "<<age<<endl;
		cout<<"sex: "<<sex<<endl;
		cout<<"address: "<<address<<endl;
		cout<<"telephone: "<<telephone<<endl;
		cout<<"title: "<<title<<endl;
		cout<<"post: "<<post<<endl;
		cout<<"wage: "<<wage<<endl<<endl;
	}
	~Teacher_Cardre()=default;
protected:
	int wage;	
};

int main(void)
{
     	Teacher_Cardre a("张三",35,"男","重庆永川","1234561111","教授","院长",8000);
	 	a.show();
        Teacher_Cardre b(cin);	
	    b.show();
	
		return 0; 
}
