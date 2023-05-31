#include<iostream>

using namespace std;

template<typename T>  void counts();//声明函数模板
template<typename T>  void report(T &);

template<typename TT>
class HasFriendT
{
	TT item;
	static int ct;
public:
	HasFriendT(const TT &i):item(i){ct++;}
	~HasFriendT(){ct--;}
	friend void counts<TT>();//指明实例化
	friend void report<>(HasFriendT<TT> &);//<>为空是因为可以从函数参数推断出模板类型参数 
}; 

template<typename T>
int HasFriendT<T>::ct=0;//模板中静态成员的类外初始化

template<typename T>
void counts()
{
	cout<<"template size: "<<sizeof(HasFriendT<T>)<<";";
	cout<<"template counts(): "<<HasFriendT<T>::ct<<endl;//输出某个类型的实例化下的静态成员 
} 

template<typename T>
void report(T &hf){cout<<hf.item<<endl;} 

int main()
{
	counts<int>();
	
	HasFriendT<int>hfi1(10);
	HasFriendT<int>hfi2(20);
	HasFriendT<double>hfi3(10.5);
	
	report(hfi1);
	report(hfi2);
	report(hfi3);
	
	cout<<"counts<int>() output:\n";
	counts<int>();
	cout<<"counts<double>() output:\n";
	counts<double>();
	return 0;
}
