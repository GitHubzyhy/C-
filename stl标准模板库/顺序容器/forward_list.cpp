#include<iostream>
#include<forward_list>//前向链表
#include<algorithm> 
using namespace std;
void print(int i)
{
	cout<<i<<" ";
}
int main()
{
	//insert erase操作都是在迭代器之后进行操作的d 
	forward_list<int> list1,list2{2,3,4,5,6};
	auto prev=list1.before_begin();//返回指向链表首元素之前不存在元素的的迭代器，这个迭代器不能解引用
	list1.insert_after(prev,1); //迭代器所指向位置之后插入 
	list1.insert_after(list1.begin(),list2.begin(),list2.end()); 
	for_each(list1.begin(),list1.end(),print);
	return 0;
}
