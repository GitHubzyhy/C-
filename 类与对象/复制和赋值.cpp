#include<iostream>
#include<Windows.h>//不用加只是为了讲解好看 
#include<assert.h>
#include<string.h>
#include<string>

using namespace std;

HANDLE aa=GetStdHandle(STD_OUTPUT_HANDLE);//当看不见，运行的时候更直观反正别看 !!

class airCondition
{
public:
	 airCondition()=default; //默认构造 
	 airCondition(const char *str,const string &colorr,const string powerr,const bool Switchh,const int temperaturee) 
	{//有参数的构造函数（由主函数传入数据 
		brand=new(nothrow) char[strlen(str)+1];//动态分配内存 
		//assert(brand!=nullptr);//如果分配失败系统结束运行 
		strcpy(brand,str);//形参复制给类中的数据成员 
		this->color=colorr;//同 可以不用this指针，用了提高代码的可读性 
		this->power=powerr;//同
		this->Switch=Switchh;//同
		this->temperature=temperaturee;//同
	}
	airCondition(const airCondition &);//复制构造函数 的声明 
	airCondition& operator=(const airCondition &);//复制赋值函数 的声明
	void up()//调高温度 
	{
		if(Switch!=0)//如果开关是开着的 
		{
			if(temperature<30)//16°C到30°C之间 
			temperature++;//温度加加 
		}
	 } 

	void down()//降低温度 
	{
	 	if(Switch!=0)//如果开关是开着的
		{
			if(temperature>16)
			temperature--;
		}
	}
	 
	int Temperature()//目的是返回一个 temperature，为后续的操作做准备 
	{
		return temperature;
	}
	
	void change()//控制开关！ 
	{
		Switch=!Switch;//开关设置的bool类型只有true（1）和faulse（0） 
	}
	
	void show()
	{
		if(Switch==true)//如果开关是开着的 
		{//做输出 
			cout<<"开关状态 Switch: "<<"开启状态" <<endl;
			cout<<"品牌 brand:"<<brand<<endl<<"颜色 color:"<<color<<endl<<"功率 power"<<power<<endl
			<<"温度 temperature:"<<temperature<<"度"<<endl;
		}
		else//如果没开则显示 
			cout<<"请先开空调"<<endl;
	}
	
	~airCondition()//析构函数（数据成员中有指针成员必须写析构函数） 
	{//就是一个~加上类的名字 
		delete []brand;//做销毁动态内存的操作 
		brand=nullptr;//把这俩理解为一个整体缺一不可 
	}

private:
	char *brand;//品牌 
	string color="白色";//颜色 
	string power="2匹";//功率 
	bool Switch;//开关状态 
	int temperature=25;//设定温度 
};

airCondition::airCondition(const airCondition &p)//复制构造函数 
{
	brand=new(nothrow) char[strlen(p.brand)+1];//动态分配内存
	//assert(brand!=nullptr);//与前面的构造函数类似唯一的区别就是参数是（一个对象的引用） 
	strcpy(brand,p.brand);
	this->color=p.color;
	this->power=p.power;
	this->Switch=p.Switch;
	this->temperature=p.temperature;
}

airCondition& airCondition::operator=(const airCondition &p) 
{
	if(&p!=this)//检查是不是自身赋值（建议最好加上） 
	{
	    brand=new(nothrow) char[strlen(p.brand)+1];//重点！！动态分配内存 
		//assert(brand!=nullptr);//与前面的构造函数类似唯一的区别就是参数是（一个对象的引用） 和 operator=
		strcpy(brand,p.brand);
		this->color=p.color;
		this->power=p.power;
		this->Switch=p.Switch;
		this->temperature=p.temperature;
	}
	return *this;
}

int main(void)
{
	airCondition a("格力","白色","2匹",false,25);//调用构造函数进行初始化 
	a.show();//显示此时的状态 
	cout<<"\t\t\t\t\t执行打开空调后的操作\n"; 
	system("pause");//停顿做打开空调 	
	cout<<"打开空调！"<<endl;
	a.change();//打开开关 
	a.show();
	cout<<endl;
	cout<<"进行降温操作！"<<endl;
	while(a.Temperature()!=20)//如果温度不是等于20度做while循环 
	{
		if(a.Temperature()<20)//情况一小于20度做升温 
		a.up();
		else if(a.Temperature()>20)//情况一大于20度做降温温 
		a.down();
	}
	 	a.show();//显示操作完毕的最终结果

		SetConsoleTextAttribute(aa,15|8|128|641);//当看不见，运行的时候更直观反正别看 
		  	
		  	
	//操作一实现 复制
	cout<<endl<<"复制构造函数创建的对象！"<<endl;
	airCondition b(a);
	b.show();
	//操作二实现 复制赋值
	cout<<endl<<"复制赋值函数创建的对象！"<<endl;
	airCondition c;
	c=b;
	c.show();
	
	
	SetConsoleTextAttribute(aa,7);//当看不见，运行的时候更直观反正别看  
	
	/*两个的区别是
	(1)对象的赋值是在两个对象都已经创建的基础上进行的；
	而对象的复制则在用一个已有对象复制一个新对象时进行的。
	(2)它们两个所对应调用的函数不同，对象的赋值系统调用的是重载赋值运算符的函数；
	而对象的复制系统调用的是复制构造函数。
	*/
}
