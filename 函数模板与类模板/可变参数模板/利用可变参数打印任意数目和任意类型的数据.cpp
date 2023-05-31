#include<iostream>

using namespace std;

//用来终止递归并处理包中最后一个元素 
template<typename T>
void print(const T &t){cout<<t<<endl;}//打印最后一个实参

//包中除最后一个元素外的其他元素都会调用这个版本的print 
template<typename T,typename ...Args>
void print(const T &t,const Args&...rest)
{
	cout<<t<<" ";//打印第一个实参 
	print(rest...);//递归调用，打印其他实参 
}
 
int main()
{
	print("string1",2,3.14f,"string2",42);
	cout<<endl; 
	return 0;
}
