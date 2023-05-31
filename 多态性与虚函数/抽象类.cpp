#include<iostream>
#include<string>

using namespace std;

//有用的类只有 	aircraft， airliner bomber pilot（其他的类都是类似操作可以不用看） 
class aircraft//定义的抽象类 
{
public:		
	aircraft()=default; //显示调用默认构造函数 
	aircraft(int w,int v,const string &n):weight(w),velocity(v),nickname(n){}//构造函数的初始化列表！ 
	virtual void show();//展示函数声明 
	virtual void refuel();//加燃油函数申明 
    virtual void fly()=0;//飞行纯虚函数的声明 
	virtual ~aircraft();//虚析构函数申明 

protected:
	int weight;//重量 
	int velocity;//速度  
	string nickname;//代号 
};

void aircraft::show()//展示函数类外定义 
{
		cout<<"飞机的重量："<<weight<<"吨"<<endl;
		cout<<"飞机的速度:"<< velocity<<" km/min"<<endl;
		cout<<"飞机的代号："<< nickname<<endl;
}

void  aircraft::refuel()//加燃油函数类外定义 
{
	cout<<"飞机已经加满油！"<<endl;	
} 

aircraft::~aircraft() //虚析构函数类外的定义 
{
		cout<<"执行aircraft的析构函数！"<<endl;
} 

//民行客机 
class airliner:public aircraft//继承 aircraft类 
{
public:
	airliner()=default;//显示调用默认构造函数 
	airliner(int w,int v,const string &n,int p):aircraft(w,v,n), passengers(p){}//构造函数的初始化列表！ 
	virtual void show()override;//展示函数声明 
	virtual void refuel()override;//加燃油函数申明 
	virtual void fly()override;//飞行纯虚函数的声明 
	virtual ~airliner();//虚析构函数申明 
protected:
	int passengers;//载客量		
};

void airliner::show()//展示函数类外定义
{
		aircraft::show();
		cout<<"载容量为："<< passengers<<endl;
}
void airliner::refuel()//加燃油函数类外定义 
{
		cout<<"airliner refueled"<<endl;
}	
void airliner::fly()//飞行函数类外定义 
{
		cout<<"airliner flying"<<endl;
}
airliner::~airliner()//虚析构函数类外的定义 
{
		cout<<"执行airliner的析构函数！"<<endl;
}

//歼击机 
class fighter:public aircraft
{
public:
	fighter()=default;//显示调用默认构造函数 
	fighter(int w,int v,const string &n,int b):aircraft(w,v,n),bomb(b){}//构造函数的初始化列表！
	virtual void show()override;//展示函数声明 
	virtual void refuel()override;//加燃油函数申明 
	virtual void fly()override;//飞行纯虚函数的声明 
	virtual ~fighter()override; //虚析构函数申明 
protected:
	int bomb;//载弹量 
};

void fighter::show()//展示函数的类外定义 
{
		aircraft::show();
		cout<<"载弹量为："<<bomb<<endl;
}

void fighter::refuel()//加燃油函数类外定义 
{
		cout<<"加歼击机的燃油"<<endl;
}	

void fighter::fly()//飞行函数类外定义 
{
		cout<<"歼击机的飞行"<<endl;
}

fighter::~fighter()//虚析构函数类外的定义 
{
	cout<<"fighter的析构函数执行！"<<endl;
}

//轰炸机 
class bomber:public aircraft
{
public:
	bomber()=default;
	bomber(int w,int v,const string &n,int b):aircraft(w,v,n),bomb(b){}
	virtual void show()override;//展示函数声明 
	virtual void refuel()override;///加燃油函数申明 
	virtual void fly()override;//飞行纯虚函数的声明 
	virtual ~bomber()override;//虚析构函数申明
	protected:
	int bomb;//载弹量 
};

void  bomber::show()
{
		aircraft::show();
		cout<<"载弹量为："<<bomb<<endl;
}

void bomber::refuel()
{
		cout<<"加轰炸机的燃油"<<endl;
}
	
void bomber::fly()
{
		cout<<"轰炸机的飞行"<<endl;
}

bomber::~bomber()
{
		cout<<"bomber 的析构函数执行"<<endl;
}

//直升机 
class helicopter:public aircraft
{
public:
	helicopter()=default;//默认构造 
	helicopter(int w,int v,const string &n,int b): aircraft(w,v,n),bomb1(b){}//构造函数的初始化列表 
	virtual void show();//展示函数 
	virtual void refuel()override;//加燃油函数申明 
	virtual void fly()override;//飞行纯虚函数的声明 
	virtual ~helicopter()override ;///虚析构函数申明 
	protected:
	int bomb1;//直升机的载弹量	
};

void helicopter::show()
{
		aircraft::show();
		cout<<"直升机的子弹数量是："<<bomb1<<endl;
}

void helicopter::refuel()
{
		cout<<"加直升机的燃油"<<endl;
}
	
void helicopter::fly()
{
		cout<<"直升机的飞行"<<endl;
}

helicopter::~helicopter()
{
		cout<<"执行helicopter的析构函数"<<endl; 
} 

class hotAirBalloon:public aircraft//热气球 
{
public:
	hotAirBalloon()=default;//热气球的默认构造函数的显示调用 
	hotAirBalloon(int w,int v,const string &n,double f): aircraft(w,v,n),fuel(f){}//构造函数的初始化列表  
		virtual void show();//展示函数 
	virtual void refuel()override;//加燃油函数申明 
	virtual void fly()override;//飞行纯虚函数的声明 
	~hotAirBalloon();
protected:
		double fuel;//热气球的油量 
};

void hotAirBalloon::show()
{
		aircraft::show();
		cout<<"热气球的燃油是："<<fuel<<endl;
}

void hotAirBalloon::refuel()
{
		cout<<"加热气球的燃油"<<endl;
}
	
void hotAirBalloon::fly()
{
		cout<<"热气球的飞行"<<endl;
}

hotAirBalloon::~hotAirBalloon()
{
	cout<<"hotAirBalloon的析构执行！"<<endl;
}

//这是一个单独的类 
class pilot
{
public:
	pilot()=default;
	pilot(const string &n):name(n){}//构造函数的初始化列表！ 
	void refuelAircraft(aircraft *p);//给飞机加油 （形参是aircraft的指针） 
	void dirveAircraft(aircraft *p);//驾驶飞机 （形参是aircraft的指针） 
	void show(aircraft *p);//展示 （形参是aircraft的指针）

protected:
	string name;//定义的飞行员名字 
};

void pilot::refuelAircraft(aircraft *p)
{
	p->refuel();
	cout<<"给飞机加油"<<endl;
}

void pilot::dirveAircraft(aircraft *p)
{
	p->fly();
	cout<<"驾驶飞机"<<endl;
}

void pilot::show(aircraft *p)
{
	p->show();
	cout<<"name:"<<name<<endl;
}

int main(void)
{	
	aircraft *A380=new airliner(100,50,"A380",20);//创建了一个A380名字aircraft类的指针用airliner类进行初始化	
	A380->show();//依次指向airliner类中的三个函数 
	A380->refuel(); 
	A380->fly();//注意指向的是airliner类中的fly函数 
		cout<<endl;
	
	//创建两个aircraft对象 但用 bomber类进行初始化 
	aircraft *H6K=new(nothrow) bomber(200,50,"H6K",600);//轰6K
	aircraft *WZ10=new(nothrow) bomber(250,60,"WZ10",500);;//武直10
	
	//来一个王牌飞行员，给H6K加油（加的是轰炸机特殊燃油），并且按照H6K的特点飞行（第一个对象操作如下） 
	pilot Jack("飞行员Jack");
	Jack.refuelAircraft(H6K);//加轰炸机燃油（传入H6K的地址） 
	Jack.show(H6K);//（传入H6K的地址） 
	Jack.dirveAircraft(H6K);//轰炸机实弹飞行（（传入H6K的地址）） 
		cout<<endl;
		
		
	//第二个对象进行类似的操作！！	
	//给WZ10加油（加的是基类提供的通用燃油），按照WZ10的特点飞行
	Jack.refuelAircraft(WZ10);//加通用型燃油
	Jack.show(WZ10);
	Jack.dirveAircraft(WZ10);//直升机盘旋*/

	return 0; 
}
 
