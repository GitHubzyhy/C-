#include<iostream>

using namespace std;

int main()
{
	cout<<"12345678970"<<endl;
	cout<<"Default width is: "<<cout.width()<<endl;//返回当前输出数据时的宽度
	
	int i=1234;
	cout<<i<<endl;
	cout.width(12);
	cout<<i<<endl;
	
	cout<<"Default fill is: "<<cout.fill()<<endl;//默认填充字符为空格符
	cout.width(12);
	cout.fill('*'); 
	cout.setf(ios::left);//按照输出左对齐
	cout<<i<<endl; 
	
	cout<<"Default precision is:"<<cout.precision()<<endl;//默认精度为6
	float j=12.3456789;
	cout<<j<<endl;
	cout.width(12);
	cout.setf(ios::right);//右对齐
	cout.precision(5);//设置精度为5 
	cout<<j<<endl; 
	
	return 0;
}
