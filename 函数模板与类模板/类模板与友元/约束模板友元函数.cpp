#include<iostream>

using namespace std;

template<typename T>  void counts();//��������ģ��
template<typename T>  void report(T &);

template<typename TT>
class HasFriendT
{
	TT item;
	static int ct;
public:
	HasFriendT(const TT &i):item(i){ct++;}
	~HasFriendT(){ct--;}
	friend void counts<TT>();//ָ��ʵ����
	friend void report<>(HasFriendT<TT> &);//<>Ϊ������Ϊ���ԴӺ��������ƶϳ�ģ�����Ͳ��� 
}; 

template<typename T>
int HasFriendT<T>::ct=0;//ģ���о�̬��Ա�������ʼ��

template<typename T>
void counts()
{
	cout<<"template size: "<<sizeof(HasFriendT<T>)<<";";
	cout<<"template counts(): "<<HasFriendT<T>::ct<<endl;//���ĳ�����͵�ʵ�����µľ�̬��Ա 
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
