#include<iostream>
#include<string.h>
using namespace std;

template<typename T>
T myMax(T x,T y)
{
	cout<<"this is a template function! max is: ";
	return x>y?x:y;
}

const char * myMax(const char *x,const char *y)//���ص���ͨ����
{
	cout<<"this is the overload function with char*,char*!max is: ";
	return strcmp(x,y)>0?x:y;
} 

int main()
{
	char *s1="Beijing 2008",*s2="Welcome to Beijing!";
	cout<<myMax(2,3)<<endl;//���ú���ģ�壬T��intȡ�� 
	cout<<myMax(2.02,3.03)<<endl;//���ú���ģ�壬T��doubleȡ�� 
	cout<<myMax(s1,s2)<<endl;

	return 0;
}
