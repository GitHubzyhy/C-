#include<iostream>
#include<forward_list>//ǰ������
#include<algorithm> 
using namespace std;
void print(int i)
{
	cout<<i<<" ";
}
int main()
{
	//insert erase���������ڵ�����֮����в�����d 
	forward_list<int> list1,list2{2,3,4,5,6};
	auto prev=list1.before_begin();//����ָ��������Ԫ��֮ǰ������Ԫ�صĵĵ�������������������ܽ�����
	list1.insert_after(prev,1); //��������ָ��λ��֮����� 
	list1.insert_after(list1.begin(),list2.begin(),list2.end()); 
	for_each(list1.begin(),list1.end(),print);
	return 0;
}
