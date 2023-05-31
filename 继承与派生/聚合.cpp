#include<iostream>
#include<string>
using namespace std;
class Employee//���� 
{
public:
	Employee()=default;
	Employee(const string &Name,int Id,int Grade):name(Name),id(Id),grade(Grade){}//���캯���ĳ�ʼ���б�
	Employee(istream &input):Employee()//ί�к����������ĵ��� 
	{
		cout<<"����name��"<<endl;
		input>>name;
		cout<<"����id: "<<endl;
		input>>id;
	}
	~Employee()=default;
protected:
	string name;//���� 
	int id=0;//��� 
	int grade=1;//����
	double salary=0;//���� 
};
//������� 
class Manager:virtual public Employee
{
public:
	Manager()=default;//��ʾ����Ĭ�Ϲ��캯�� 
	Manager(const string &Name,int Id,int Grade):Employee(Name,Id,Grade){}//����Ĺ��� 
	Manager(istream &input):Employee(input){}
	void show()
	{
		if(grade==4)//���������4 
		{
			cout<<"name: "<<name<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"grade: "<<grade<<endl;
			salary=8000;//����̶����� 
	     	cout<<"����Ĺ���Ϊ��"<<salary<<"Ԫ"<<endl; 
		} 
	}
	~Manager()=default; 
};
//������������(�뼼����Ա��һ�����ģ���һ�������Ȳ����� -------------------------------- ---------------------------------------------
class date
{
	public:
	date(int Hour):hour(Hour){}
	~date()=default;
	protected:
	int hour;
	
};

//������Ա���� 
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
		cout<<"������Ա�Ĺ���"<<salary<<"Ԫ"<<endl;
		}
	    
	}
	~Technician()=default;
protected:
	date Date;//������Ӷ�������196ҳ���ƴ��� 
};
//------------------------------------------------------------------------------------------
class Salesman:virtual public Employee //����Ա 
{
public:
	Salesman()=default;
	Salesman(const string &Name,int Id,int Grade,int Value):Employee(Name,Id,Grade),value(Value){}
	Salesman(istream &input):Employee(input)
	{
		if(grade==1)//�����ʼ����Ϊ1 
		{
			cout<<"�������۶�(value)��"<<endl;
	        input>>value;
		}
	}
	void show()
	{
		if(grade==1)
		{
			salary+=value*0.04;//���۶�0.04�����
			cout<<"name: "<<name<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"grade: "<<grade<<endl;
			cout<<"value(���۶�): "<<value<<endl; 
			cout<<"����Ա�Ĺ����ǣ�һ����"<<salary<<"Ԫ"<<endl; 
		}
		
	}
	~ Salesman()=default;
protected:
	int value=0;	
};
class Salesmanager:public Manager,public Salesman//���۾��� 
{
public:
	Salesmanager()=default;
	Salesmanager(const string &Name,int Id,int Grade,int Value):Employee(Name,Id,Grade),
	Manager(Name,Id,Grade),Salesman(Name,Id,Grade,Value){}
	Salesmanager(istream &input):Employee(input),Manager(input),Salesman(input){}
	void up_or_down()
	{
		int n;
		cout<<"������ְ�Ĵ�����ֻ�м���1.3.4��"<<endl;
		cin>>n;
		while(n==1)
		{
			cout<<"ֻ�м���1.3.4"<<endl;
			cin>>n;
		 } 
		 for(int i=0;i<=n-1;i++)
		grade++;//��ְ
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
			cout<<"value(���۶�):"<<value<<endl;
			salary+=value*0.05+5000;//�������ʼ������۶�0.05����� 
			cout<<"���۾���Ĺ����ǣ�"<<salary<<"Ԫ"<<endl; 
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
//��һ������  ����1�� ����Ա������3��������Ա�������۾�������4������ 
	
	Salesmanager a("name",21110504,1,100);//���֣����ţ����������ܶҪ��ȫ����ʼ��Ա������1�� 
	a.show();
	a.up_or_down();//��ְ���� ��������4����ֻ�ܽ����� 
	a.show();

//�ڶ�������	   
	Salesmanager b(cin);
	b.show();
	cout<<endl; 
	b.up_or_down();
	b.show();
	   
/*     ------>�̳е���˼ 
����-----> ����4���𣩡�������ͼ�����Ա�ȱ𿴡�
                       ||---------->���۾���3���� 
����----->����Ա��1���� 

���������ж������۾���Ķ���ʵ�ֽ�ְ������ֵ������Ȼ�������Ϣ 
ע�� ����1�� ����Ա������3��������Ա�������۾�������4������  


*/	   
	   
	   
	   
	   
	   
	   
	   
	   
}
