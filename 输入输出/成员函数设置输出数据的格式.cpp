#include<iostream>

using namespace std;

int main()
{
	cout<<"12345678970"<<endl;
	cout<<"Default width is: "<<cout.width()<<endl;//���ص�ǰ�������ʱ�Ŀ��
	
	int i=1234;
	cout<<i<<endl;
	cout.width(12);
	cout<<i<<endl;
	
	cout<<"Default fill is: "<<cout.fill()<<endl;//Ĭ������ַ�Ϊ�ո��
	cout.width(12);
	cout.fill('*'); 
	cout.setf(ios::left);//������������
	cout<<i<<endl; 
	
	cout<<"Default precision is:"<<cout.precision()<<endl;//Ĭ�Ͼ���Ϊ6
	float j=12.3456789;
	cout<<j<<endl;
	cout.width(12);
	cout.setf(ios::right);//�Ҷ���
	cout.precision(5);//���þ���Ϊ5 
	cout<<j<<endl; 
	
	return 0;
}
