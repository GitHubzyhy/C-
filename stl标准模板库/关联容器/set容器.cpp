#include<iostream>
#include<set>//只需要指明关键字的类型,所有元素插入后自动排序 
#include<vector>//动态数组 

using namespace std;

int main()
{
	//容器multimap和multiset关键字可以不唯一，set，map不能插入重复的值 
	vector<int>v1;
	for(int i=1;i<=20;i++)
	{
		v1.push_back(i);v1.push_back(i);
	}
	set<int>iset(v1.begin(),v1.end());//从一个值范围初始化容器。
 
	multiset<int>miset(v1.begin(),v1.end()) ;
	cout<<"vector is num: "<<v1.size()<<endl;
	cout<<"set is num: "<<iset.size()<<endl;
	cout<<"multise is num: "<<miset.size()<<endl;
	//-------------------------------------------------------------------
	void text();
	text();
	return 0;
} 
class base//自定义的数据类型 
{
public:
       int isbn;
	   base(int isbn):isbn(isbn){};//初始化列表
	   base()=default;	
	   friend bool operator<(const base &a1,const base &a2);//第二种方式定义的友元函数重载<运算符 
};

//第二种方式 
bool operator<(const base &a1,const base &a2)
{
	return a1.isbn>a2.isbn;//降序排序 
}
bool compareIsbn(const base &a1,const base &a2)
{
 	return a1.isbn<a2.isbn;//升序排序 
}
 //第三种方式 用仿函数的形式
struct Node
{
 	bool operator()(const base &a1,const base &a2)
 	{
	 	return a1.isbn<a2.isbn;
	 }
}; 

void text()
{
	/*对于内置数据类型默认使用<比较两个关键字,否则必须
	显示指定关键字比较方法	默认是升序相当于set<int,less<int>>
	对于自定类型数据 1.必须重载<运算符，
	                 2.或者单独提供比较函数 */  
	set<base,decltype(compareIsbn)*>bookstore1(compareIsbn);//比较函数 
		/*使用decltype指出自定义操作的类型，当用它来获取一个函数指针的时候
		必须加上* 来指出我们使用一个给定函数类型的指针，compareIsbn初始化对象
		表示向这个对象添加数据的时候按照compareIsbn为这些元素排序*/
	set<base>bookstore2;//重载<运算符 倒叙 
	set<base,Node>bookstore3;//定义的仿函数 正序 

	for(int i=9;i>=1;i--)
	{
			bookstore1.insert(bookstore1.begin(),i); 
			bookstore2.insert(bookstore2.begin(),i);
			bookstore3.insert(bookstore3.begin(),i);
	}
	
	for(auto i=bookstore1.begin();i!=bookstore1.end();i++)
	cout<<i->isbn<<" ";
 	cout.put('\n');
 	
 	for(auto i=bookstore2.begin();i!=bookstore2.end();i++)
 	cout<<i->isbn<<" ";
 	cout.put('\n');
 	
 	for(auto i=bookstore3.begin();i!=bookstore3.end();i++)
	cout<<i->isbn<<" ";
	 
}
