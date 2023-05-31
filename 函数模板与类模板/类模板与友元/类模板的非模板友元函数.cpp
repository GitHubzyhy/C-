#include<iostream>

using namespace std;

template<typename T>
class HasFriend
{
	T item;
	static int ct;
public:
	HasFriend(const T &i):item(i){ct++;}//ÿһ�ε��ù��� ������̬��Ա��++
	~HasFriend(){ct--;}
	
	friend void counts();//����ģ������ʵ��������Ԫ ��һ����ͨ��Ԫ����
	//��ģ�����������Ԫ����������ָ��ʵ����
	friend void reports(HasFriend<T> &); 
}; 

template<typename T>
int HasFriend<T>::ct=0;//ģ�����еľ�̬��Ա�����ʼ�� 

void counts()//��ͨ��Ԫ���� 
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
