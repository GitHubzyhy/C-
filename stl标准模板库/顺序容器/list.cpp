#include<iostream>
#include<vector>
#include<list>//双向链表 

using namespace std;

int main()
{
	vector<int> v1{1,2,3,4};
	if(!v1.empty())//不为空的时候
	{
		v1.front()=11;//.front()返回的是引用
		auto &v=v1.front();
		v=1024; 
	} 
	for(vector<int>::iterator i=v1.begin();i!=v1.end();i++)
	cout<<*i<<" ";
	cout.put('\n');
	vector<string> v2;
	try{
			cout<<v2.at(0);//下标越界抛出异常 
	}
	catch(...)
	{
		cout<<"out_of_rang";
	}
//下面的循环删除一个list中所有奇数元素 
	list<int> lst={0,1,2,3,4,5,6,7};
	list<int>::iterator it=lst.begin();
	while(it!=lst.end())
	{
		if(*it%2)
		it=lst.erase(it);
		else
		it++;
	}
	for(auto i=lst.begin();i!=lst.end();i++)
	cout<<*i<<" ";
	return 0;
}
