#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
T myMax(T x,T y)
{
	cout<<"this is a template function! max is: ";
	return x>y?x:y;
}

const char * myMax(const char *x,const char *y)//重载的普通函数
{
	cout<<"this is the overload function with char*,char*!max is: ";
	return strcmp(x,y)>0?x:y;
} 

int main()
{
	char *s1="Beijing 2008",*s2="Welcome to Beijing!";
	cout<<myMax(2,3)<<endl;//调用函数模板，T被int取代 
	cout<<myMax(2.02,3.03)<<endl;//调用函数模板，T被double取代 
	cout<<myMax(s1,s2)<<endl;

	return 0;
}
