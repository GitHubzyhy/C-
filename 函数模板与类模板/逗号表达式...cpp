#include<iostream>

using namespace std;

template<typename T>
void print(T t){cout<<t<<endl;}

template<typename ...Args>//模板类型参数 
void expand(Args ...args)//函数模板参数 
{//arr数组都所有元素都为0 
	int arr[]={(print(args),0)...};//用初始化列表来初始化一个变长的数组 
}

int main()
{
	expand(1,2,3,4); 
	return 0;
}
