#include<iostream>
#include<iomanip>//��ʽ���Ʒ�������ͷ�ļ� 

using namespace std;

int main()
{
	int a=161;
	cout<<"dec:"<<dec<<a<<endl;//ʮ�������
	cout<<"hex:"<<hex<<a<<endl;//��ʮ���������
	cout<<"oct:"<<setbase(8)<<a<<endl;//�԰˽������
	
	char *pt="Hello world";
	cout<<setw(16)<<pt<<endl;//�������Ϊ16
	cout<<setfill('*')<<setw(16)<<pt<<endl;
	
	double k=12.3456789;
	cout<<setiosflags(ios::scientific)<<setprecision(8);//����ָ����ʽ�����8λС��
	cout<<"k: "<<k<<endl;
	cout<<"k: "<<setprecision(4)<<k<<endl;//��Ϊ4λС��
	cout<<"k: "<<setiosflags(ios::fixed)<<k<<endl;//��ΪС����ʽ��� 
	 
	return 0;
}
