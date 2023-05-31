#include<iostream>
#include<string>

using namespace std;

//���õ���ֻ�� 	aircraft�� airliner bomber pilot���������඼�����Ʋ������Բ��ÿ��� 
class aircraft//����ĳ����� 
{
public:		
	aircraft()=default; //��ʾ����Ĭ�Ϲ��캯�� 
	aircraft(int w,int v,const string &n):weight(w),velocity(v),nickname(n){}//���캯���ĳ�ʼ���б� 
	virtual void show();//չʾ�������� 
	virtual void refuel();//��ȼ�ͺ������� 
    virtual void fly()=0;//���д��麯�������� 
	virtual ~aircraft();//�������������� 

protected:
	int weight;//���� 
	int velocity;//�ٶ�  
	string nickname;//���� 
};

void aircraft::show()//չʾ�������ⶨ�� 
{
		cout<<"�ɻ���������"<<weight<<"��"<<endl;
		cout<<"�ɻ����ٶ�:"<< velocity<<" km/min"<<endl;
		cout<<"�ɻ��Ĵ��ţ�"<< nickname<<endl;
}

void  aircraft::refuel()//��ȼ�ͺ������ⶨ�� 
{
	cout<<"�ɻ��Ѿ������ͣ�"<<endl;	
} 

aircraft::~aircraft() //��������������Ķ��� 
{
		cout<<"ִ��aircraft������������"<<endl;
} 

//���пͻ� 
class airliner:public aircraft//�̳� aircraft�� 
{
public:
	airliner()=default;//��ʾ����Ĭ�Ϲ��캯�� 
	airliner(int w,int v,const string &n,int p):aircraft(w,v,n), passengers(p){}//���캯���ĳ�ʼ���б� 
	virtual void show()override;//չʾ�������� 
	virtual void refuel()override;//��ȼ�ͺ������� 
	virtual void fly()override;//���д��麯�������� 
	virtual ~airliner();//�������������� 
protected:
	int passengers;//�ؿ���		
};

void airliner::show()//չʾ�������ⶨ��
{
		aircraft::show();
		cout<<"������Ϊ��"<< passengers<<endl;
}
void airliner::refuel()//��ȼ�ͺ������ⶨ�� 
{
		cout<<"airliner refueled"<<endl;
}	
void airliner::fly()//���к������ⶨ�� 
{
		cout<<"airliner flying"<<endl;
}
airliner::~airliner()//��������������Ķ��� 
{
		cout<<"ִ��airliner������������"<<endl;
}

//�߻��� 
class fighter:public aircraft
{
public:
	fighter()=default;//��ʾ����Ĭ�Ϲ��캯�� 
	fighter(int w,int v,const string &n,int b):aircraft(w,v,n),bomb(b){}//���캯���ĳ�ʼ���б�
	virtual void show()override;//չʾ�������� 
	virtual void refuel()override;//��ȼ�ͺ������� 
	virtual void fly()override;//���д��麯�������� 
	virtual ~fighter()override; //�������������� 
protected:
	int bomb;//�ص��� 
};

void fighter::show()//չʾ���������ⶨ�� 
{
		aircraft::show();
		cout<<"�ص���Ϊ��"<<bomb<<endl;
}

void fighter::refuel()//��ȼ�ͺ������ⶨ�� 
{
		cout<<"�Ӽ߻�����ȼ��"<<endl;
}	

void fighter::fly()//���к������ⶨ�� 
{
		cout<<"�߻����ķ���"<<endl;
}

fighter::~fighter()//��������������Ķ��� 
{
	cout<<"fighter����������ִ�У�"<<endl;
}

//��ը�� 
class bomber:public aircraft
{
public:
	bomber()=default;
	bomber(int w,int v,const string &n,int b):aircraft(w,v,n),bomb(b){}
	virtual void show()override;//չʾ�������� 
	virtual void refuel()override;///��ȼ�ͺ������� 
	virtual void fly()override;//���д��麯�������� 
	virtual ~bomber()override;//��������������
	protected:
	int bomb;//�ص��� 
};

void  bomber::show()
{
		aircraft::show();
		cout<<"�ص���Ϊ��"<<bomb<<endl;
}

void bomber::refuel()
{
		cout<<"�Ӻ�ը����ȼ��"<<endl;
}
	
void bomber::fly()
{
		cout<<"��ը���ķ���"<<endl;
}

bomber::~bomber()
{
		cout<<"bomber ����������ִ��"<<endl;
}

//ֱ���� 
class helicopter:public aircraft
{
public:
	helicopter()=default;//Ĭ�Ϲ��� 
	helicopter(int w,int v,const string &n,int b): aircraft(w,v,n),bomb1(b){}//���캯���ĳ�ʼ���б� 
	virtual void show();//չʾ���� 
	virtual void refuel()override;//��ȼ�ͺ������� 
	virtual void fly()override;//���д��麯�������� 
	virtual ~helicopter()override ;///�������������� 
	protected:
	int bomb1;//ֱ�������ص���	
};

void helicopter::show()
{
		aircraft::show();
		cout<<"ֱ�������ӵ������ǣ�"<<bomb1<<endl;
}

void helicopter::refuel()
{
		cout<<"��ֱ������ȼ��"<<endl;
}
	
void helicopter::fly()
{
		cout<<"ֱ�����ķ���"<<endl;
}

helicopter::~helicopter()
{
		cout<<"ִ��helicopter����������"<<endl; 
} 

class hotAirBalloon:public aircraft//������ 
{
public:
	hotAirBalloon()=default;//�������Ĭ�Ϲ��캯������ʾ���� 
	hotAirBalloon(int w,int v,const string &n,double f): aircraft(w,v,n),fuel(f){}//���캯���ĳ�ʼ���б�  
		virtual void show();//չʾ���� 
	virtual void refuel()override;//��ȼ�ͺ������� 
	virtual void fly()override;//���д��麯�������� 
	~hotAirBalloon();
protected:
		double fuel;//����������� 
};

void hotAirBalloon::show()
{
		aircraft::show();
		cout<<"�������ȼ���ǣ�"<<fuel<<endl;
}

void hotAirBalloon::refuel()
{
		cout<<"���������ȼ��"<<endl;
}
	
void hotAirBalloon::fly()
{
		cout<<"������ķ���"<<endl;
}

hotAirBalloon::~hotAirBalloon()
{
	cout<<"hotAirBalloon������ִ�У�"<<endl;
}

//����һ���������� 
class pilot
{
public:
	pilot()=default;
	pilot(const string &n):name(n){}//���캯���ĳ�ʼ���б� 
	void refuelAircraft(aircraft *p);//���ɻ����� ���β���aircraft��ָ�룩 
	void dirveAircraft(aircraft *p);//��ʻ�ɻ� ���β���aircraft��ָ�룩 
	void show(aircraft *p);//չʾ ���β���aircraft��ָ�룩

protected:
	string name;//����ķ���Ա���� 
};

void pilot::refuelAircraft(aircraft *p)
{
	p->refuel();
	cout<<"���ɻ�����"<<endl;
}

void pilot::dirveAircraft(aircraft *p)
{
	p->fly();
	cout<<"��ʻ�ɻ�"<<endl;
}

void pilot::show(aircraft *p)
{
	p->show();
	cout<<"name:"<<name<<endl;
}

int main(void)
{	
	aircraft *A380=new airliner(100,50,"A380",20);//������һ��A380����aircraft���ָ����airliner����г�ʼ��	
	A380->show();//����ָ��airliner���е��������� 
	A380->refuel(); 
	A380->fly();//ע��ָ�����airliner���е�fly���� 
		cout<<endl;
	
	//��������aircraft���� ���� bomber����г�ʼ�� 
	aircraft *H6K=new(nothrow) bomber(200,50,"H6K",600);//��6K
	aircraft *WZ10=new(nothrow) bomber(250,60,"WZ10",500);;//��ֱ10
	
	//��һ�����Ʒ���Ա����H6K���ͣ��ӵ��Ǻ�ը������ȼ�ͣ������Ұ���H6K���ص���У���һ������������£� 
	pilot Jack("����ԱJack");
	Jack.refuelAircraft(H6K);//�Ӻ�ը��ȼ�ͣ�����H6K�ĵ�ַ�� 
	Jack.show(H6K);//������H6K�ĵ�ַ�� 
	Jack.dirveAircraft(H6K);//��ը��ʵ�����У�������H6K�ĵ�ַ���� 
		cout<<endl;
		
		
	//�ڶ�������������ƵĲ�������	
	//��WZ10���ͣ��ӵ��ǻ����ṩ��ͨ��ȼ�ͣ�������WZ10���ص����
	Jack.refuelAircraft(WZ10);//��ͨ����ȼ��
	Jack.show(WZ10);
	Jack.dirveAircraft(WZ10);//ֱ��������*/

	return 0; 
}
 
