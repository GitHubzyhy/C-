#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
	/*map容器提供下表运算符，返回关键字为k(此关键字相关联的值)的元素，如果k不在c中，添加
	一个关键字为k的元素，对其值初始化，对其下标操作会得到mapped_type对象
	对其解引用得到value_type对象 
	*/
	//统计每个单词在输入中出现的次数，忽略常见单词，使用set保存想忽略的单词
	set<string>exclude={"The","But","And","Or","An","A","the","but","and","or","an","a"};
	map<string,size_t>words;
	string word;
	cout<<"input words\n";
	while(cin>>word)
	{
		//只统计不在exclude中的单词
		 if(exclude.find(word)==exclude.end())//没有找到
		 ++words[word];//递增计数器 返回的是(此关键字相关联的值)如果k不在c中，添加一个关键字为k的元素
	} 
	
	auto map_it=words.begin();
	while(map_it!=words.end())//比较当前迭代器是否到达尾迭代器去
	{
		cout<<map_it->first<<"  "<<map_it->second<<" ";
		cout<<((map_it->second>1)?"times":"time")<<endl;
		++map_it;//迭代器相加 
	} 
	
//------------------------------------------------------------------------------
void text1();
text1();	
	
	return 0;
}
void text1()
{
	/*c.find(k):        返回一个迭代器，指向第一个关键字为k的元素，若不在则返回尾后迭代器
	  c.count(k):       返回关键字为k的元素的数量，对于不允许重复关键字的容器，返回值永远是0或者1
	  c.lower_bound(k): 返回一个迭代器，指向第一个关键字不小于k的元素 
	  c.upper_bound(k): 返回一个迭代器，指向第一个关键字大于k的元素 
	  c.equal_range(k): 返回一个迭代器pair，表示关键字等于k的元素的返回，若k不存在
	  ，pair的两个成员都为c.end() 
	在允许重复关键字的容器中，相同的关键字的元素存储
	是相邻存储*/
	 multimap<string,string>authors;// 作者
	 authors.insert(multimap<string,string>::value_type(string("author1"),string("book1")));
	 authors.insert(make_pair("author1","book2"));
	 authors.insert({"author1","book3"});
	 authors.insert(pair<string,string>("author1","book4"));
	 string search_item("author1");
	 //第一种方法 
	 auto entries=authors.count(search_item);//返回关键字为 search_item的数量
	 auto iter=authors.find(search_item);//找到第一本书迭代器所在的位置
	 while(entries--)//通过数量决定循环多少次 
	 {
	 	cout<<iter->first<<" "<<iter->second<<endl;
	 	++iter;
	 } 
	 cout.put('\n');
	 
	 //第二种方式利用   c.lower_bound(k)  c.upper_bound(k)
	 multimap<string,string>::iterator begin=authors.lower_bound(search_item);
	 multimap<string,string>::iterator end=authors.upper_bound(search_item);// 指向匹配元素的下一个位置
	 while(begin!=end)
	 {
	 	cout<<begin->first<<" "<<begin->second<<endl;
	 	begin++;
	 } 
	 cout.put('\n');
	 
	 //第三种方法利用    c.equal_range(k)
	 pair<multimap<string,string>::iterator, multimap<string,string>::iterator>position;
	 position=authors.equal_range(search_item);
	 /*如果键存在，函数返回2个指针，第一个指针指向键第 一个匹配的元素 
	   第二个指针指向键最后一个匹配的元素的下一个位置 
	   若键不存在 ，pair的两个成员都为c.end() 
*/
		while(position.first!=position.second)//两个都是迭代器 
		{
			cout<<position.first->first<<" "<<position.first->second<<endl;
			position.first++;
		}
} 
