#include<iostream>
#include<iomanip>//格式控制符包含的头文件 

using namespace std;

int main()
{
	int a=161;
	cout<<"dec:"<<dec<<a<<endl;//十进制输出
	cout<<"hex:"<<hex<<a<<endl;//以十六进制输出
	cout<<"oct:"<<setbase(8)<<a<<endl;//以八进制输出
	
	char *pt="Hello world";
	cout<<setw(16)<<pt<<endl;//设置域宽为16
	cout<<setfill('*')<<setw(16)<<pt<<endl;
	
	double k=12.3456789;
	cout<<setiosflags(ios::scientific)<<setprecision(8);//按照指数形式输出，8位小数
	cout<<"k: "<<k<<endl;
	cout<<"k: "<<setprecision(4)<<k<<endl;//改为4位小数
	cout<<"k: "<<setiosflags(ios::fixed)<<k<<endl;//改为小数形式输出 
	 
	return 0;
}
