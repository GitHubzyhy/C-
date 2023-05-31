#include<iostream>

using namespace std;

template<typename T>
class HasFriend
{
	T item;
	static int ct;
public:
	HasFriend(const T &i):item(i){ct++;}//每一次调用构造 函数静态成员就++
	~HasFriend(){ct--;}
	
	friend void counts();//是类模板所有实例化的友元 是一个普通友元函数
	//带模板类参数的友元函数，必须指明实例化
	friend void reports(HasFriend<T> &); 
}; 

template<typename T>
int HasFriend<T>::ct=0;//模板类中的静态成员类外初始化 

void counts()//普通友元函数 
{
	cout<<"int count: "<<HasFriend<int>::ct<<";";
	cout<<"double count: "<<HasFriend<double>::ct<<endl;
}

void reports(HasFriend<int> &hf){cout<<"HasFriend<int>: "<<hf.item<<endl;}
void reports(HasFriend<double> &hf){cout<<"HasFriend<double>: "<<hf.item<<endl;} 

int main()
{
	cout<<"No object declared\n";
	counts();
	
	HasFriend<int>hfi1(10);
	cout<<"After hfil declared: ";
	counts();
	
	HasFriend<int>hfi2(20);
	cout<<"After hfi2 declared: ";
	counts();
	
	HasFriend<double> hfdb(10.5);
	cout<<"After hfdb declared: ";
	counts();
	
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);
	
	return 0;
	return 0;
}
