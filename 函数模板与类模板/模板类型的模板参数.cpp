#include<iostream>

using namespace std;

template<typename T,size_t size>
class Array
{
	T data[size];
	size_t count;//数组元素的个数 
public:
	Array(){count=0;}//构造函数 
	void pushBack(const T &t)//在数组末尾插入元素t
	{
		if(count<size) data[count++]=t;
	} 
	
	void popBack()//删除数组的最后一个元素
	{
		if(count>0) --count;
	} 
	
	T* begin(){return data;}//返回数组的首地址
	T* end(){return data+count;}//返回数组的最后一个元素的地址 
};

template<typename T,size_t size,template<typename,size_t>class Seq>//Seq是类模板类型的参数 
class Container
{
	Seq<T,size>seq;
public:
	void append(const T &t) 
	{
		seq.pushBack(t);	
	}
	
	T* begin(){return seq.begin();}
	T* end() {return seq.end();}
}; 

int main()
{
	Container<int,10,Array>container;//使用Array将其实例化，因此seq代表Array 
	container.append(1);
	container.append(2);
	
	int *p=container.begin();
	while(p!=container.end())
	{
		cout<<*p++<<endl;
	}
	
	return 0;
}
