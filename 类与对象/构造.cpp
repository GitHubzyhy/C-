#include<iostream>
using namespace std;
class Acoount
{
public:
		Acoount()=default;//Ĭ�Ϲ��캯�� 
		Acoount(istream &input);//ʵ�ֻ�ȡ�˺Ų������� [1]//����ֱ�Ӷ���һ�����뺯��������� 
		int Deposit(const int & balance);//ʵ�ִ��� [2]
		int Withdrawl();//ʵ��ȡ�����[3]
		void inquire()//����ѯ [4]
		{
			cout<<"���Ϊ:"<<Balance<<endl;
		}
private:
		int Account=17001;//�����˺� 
		int Balance=5000;//������� 
};

Acoount::Acoount(istream &input)//���빹�캯�� 
{
	cout<<"���������˺ţ�";
	input>>Account; 
	cout<<"����������";
	input>>Balance;
	system("cls");
	cout<<"��ǰ�˻���"<<Account<<endl;
	cout<<"��ǰ��"<< Balance<<endl;
}

int Acoount::Deposit(const int & balance)
{
	        Balance+=balance;//������ 
			 cout<<"���ɹ���"<<endl; 
			 cout<<"���Ϊ��"<< Balance<<endl;
			 return  Balance;	 
}

int Acoount::Withdrawl()
{
	int balance;
	cout<<"����ȡ���"; 
	cin>> balance;//����ȡ��Ľ�� 
	while(balance>Balance)//���������һ��ѭ�� 
	{
		cout<<"���㣬ȡ��ʧ�ܣ�"<<endl;
		cout<<"����ȡ���"; 
		cin>> balance;
	}	 
	 Balance-=balance;//ȡ����� 
	 cout<<"ȡ��ɹ���"<<endl;
	 return  Balance;		 
}

int main(void)
{
	int  balance;
	cout<<"\t\t\t���ж���1�Ĵ�����"<<endl<<endl;
	Acoount a(cin);//�������빹�캯�� 
	cout<<"�˴δ���"; 
	cin>> balance;
	a.Deposit(balance);//���Ľ����Ϊ���δ��뵽������ȥ 
	a.Withdrawl();//����ȡ����� 
	a.inquire(); //��ѯ����ʾ�����٣��� 
	
	/*����2������1��ͬ 
	 ˼·��
	 ����һ���˻�����ʼ���˺ţ��Ϳ������Ȼ����������Ϊ��
	 �ÿ���system����cls������
	 ������Ľ����������ٵ���
	 ȡ�����*****�����ʾ���յ�����Ƕ���******/ 
	cout<<"\t\t\t���ж���2�Ĵ�����"<<endl<<endl;
	Acoount b(cin);
	cout<<"�˴δ���"; 
	cin>> balance;
	b.Deposit(balance);
	b.Withdrawl();
	b.inquire(); 
}
