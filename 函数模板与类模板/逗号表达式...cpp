#include<iostream>

using namespace std;

template<typename T>
void print(T t){cout<<t<<endl;}

template<typename ...Args>//ģ�����Ͳ��� 
void expand(Args ...args)//����ģ����� 
{//arr���鶼����Ԫ�ض�Ϊ0 
	int arr[]={(print(args),0)...};//�ó�ʼ���б�����ʼ��һ���䳤������ 
}

int main()
{
	expand(1,2,3,4); 
	return 0;
}
