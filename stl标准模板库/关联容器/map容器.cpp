#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

int main()
{
	/*在一个map中，
	key_type此容器类型的关键字类型
	mapped_type每个关键字关联的类型，只适用于map 
	value_type对于set就是key_type元素是键值对，每个元素都是一个pair对象
	，我们不能改变一个元素的const关键字*/
	// set中的关键字也是const,不能修改 
	vector<int>ivec={2,4,6,8,9,5};
	set<int>set1;//构造一个空集合
	set1.insert(ivec.begin(),ivec.end());
	/*只有当元素的关键字不在里面才可以插入，
    insert(value_type对象)	插入后返回一个pair，包含一个迭代器指向具体关键字的元素
	以及一个之时插入是否成功的bool值
	insert(b,e),insert(il),insert(p,v)*/
	
	string str="hellow";
	map<string,int>words;
	words.insert({str,1});
	words.insert(make_pair(str,1));
	words.insert(pair<string,int>(str,1));
	words.insert(map<string,int>::value_type(str,1));//构造一个pair类型，并构造该类型的一个新对象 

   void text();
   text();
   return 0;
}
void text()
{
	//统计单词在插入中出现次数的一种繁琐写法
	map<string,int>words;
	string word;
	while(cin>>word)
	{
		//插入一个元素，关键字等于word，值为1
		auto ret=words.insert(make_pair(word,1));
		if(!ret.second)//返回的bool值为0表示插入失败
		++ret.first->second;//递增计数器 
		cout<<"单词重复有"<<ret.first->second<<endl;
	} 

}
