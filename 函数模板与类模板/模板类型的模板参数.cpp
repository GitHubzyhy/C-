#include<iostream>

using namespace std;

template<typename T,size_t size>
class Array
{
	T data[size];
	size_t count;//����Ԫ�صĸ��� 
public:
	Array(){count=0;}//���캯�� 
	void pushBack(const T &t)//������ĩβ����Ԫ��t
	{
		if(count<size) data[count++]=t;
	} 
	
	void popBack()//ɾ����������һ��Ԫ��
	{
		if(count>0) --count;
	} 
	
	T* begin(){return data;}//����������׵�ַ
	T* end(){return data+count;}//������������һ��Ԫ�صĵ�ַ 
};

template<typename T,size_t size,template<typename,size_t>class Seq>//Seq����ģ�����͵Ĳ��� 
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
	Container<int,10,Array>container;//ʹ��Array����ʵ���������seq����Array 
	container.append(1);
	container.append(2);
	
	int *p=container.begin();
	while(p!=container.end())
	{
		cout<<*p++<<endl;
	}
	
	return 0;
}
