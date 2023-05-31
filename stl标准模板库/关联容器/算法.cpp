#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{ 
	using ve=vector<int>;//取的别名 
	//一般情况下，STL算法不直接操控容器，而是遍历有两个迭代器指定的一个元素范围来进行操作
	ve a1={1,2,3,4,5};
	int val=3;
	auto result=find(a1.begin(),a1.end(),val);// find返回第一个等于给定值元素的迭代器，如果没有找到
	cout<<*result<<endl;                                          //返回第二个参数表示搜索失败

 //指针像内置数组上的迭代器一样，我们可以用find在数组中查找值 
 	int ia[]={27,210,12,47,109};
	int vall=47;
	int *result2=find(begin(ia),end(ia),vall);//使用标准库的begin和end函数获取指向ia中首元素和尾元素之后的指针 
	cout<<*result2<<endl; 
	
	//还可以在序列的子范围中查找，只需要将指向子范围首元素和尾元素之后的位置的迭代器(指针)传递个find()
	auto result3=find(ia+1,ia+4,vall);
	cout<<*result3<<endl; 
	
}
