#include<iostream>
#include<iterator>
#include<vector>//动态数组 
#include<list>//list采用的是双向迭代器，不支持随机访问 
using namespace std;
void text()//去奇求偶数 
{
	vector<int>v1={0,1,2,3,4,5,6,7,8,9};
	ostream_iterator<int> out(cout,",");//输出流迭代器 
 	vector<int>::iterator ite=v1.begin();
 	while(ite!=v1.end())//不能指向返回尾后迭代器 
 	{
	if(*ite%2)
	{
		ite=v1.insert(ite,*ite);//插入迭代器之前,插入后返回插入的第一个元素的迭代器
		ite+=2;//跳过插入的值和原来的值 
	} 	
	else
	ite=v1.erase(ite);//删除偶数元素返回删除后元素的迭代器 
	}
	copy(v1.begin(),v1.end(),out);//利用copy函数输出 
}
int main()
{
	int stuff[]={1,3,5,7,9};
	int more[]={2,4,6,8,2,4};
	ostream_iterator<int>out(cout," ");//输出流迭代器 
	list<int>onelist(5,2);//申明一个双向链表onelist,含有5个2 
	list<int>twolist;
	twolist.insert(twolist.begin(),stuff,stuff+5);
	list<int>threelist(twolist);//与twolist一样的元素
	threelist.insert(threelist.begin(),more,more+6);
 
	copy(onelist.begin(),onelist.end(),out);
		cout<<"-->onelist"<<endl;

	copy(twolist.begin(),twolist.end(),out);
		cout<<"-->twolist"<<endl; 
	
	copy(threelist.begin(),threelist.end(),out);
	    cout<<"-->threelist"<<endl; 
	
	threelist.remove(2);//删除所有元素为2的
	copy(threelist.begin(),threelist.end(),out);
	    cout<<"-->threelist删除2后的"<<endl;
	
	threelist.splice(threelist.begin(),onelist);//移动插入
	copy(threelist.begin(),threelist.end(),out);
	    cout<<"-->threelist|onelist移动插入后的"<<endl;
	
	cout<<"验证splice后onelist已经为空"<<endl;
	copy(onelist.begin(),onelist.end(),out);
		cout<<"-->onelist"<<endl;
		
	threelist.unique();//相同的元素被压缩为单个元素
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist压缩后的"<<endl; 
		
	threelist.sort();//进行排序
	threelist.unique();//分组后继续进行压缩 
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist排序继续压缩后的"<<endl; 
		
	twolist.sort();//让twolist排序
	threelist.merge(twolist);//链表合并前已经排序，合并后twolist被清空
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist合并twolist后"<<endl; 
		
	copy(twolist.begin(),twolist.end(),out);
		cout<<"-->twolist验证被清空"<<endl; 
	threelist.reverse();//链表逆序
	
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist合并twolist后"<<endl; 
		
	text();		
	return 0;
}
