#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
	/*map�����ṩ�±�����������عؼ���Ϊk(�˹ؼ����������ֵ)��Ԫ�أ����k����c�У����
	һ���ؼ���Ϊk��Ԫ�أ�����ֵ��ʼ���������±������õ�mapped_type����
	��������õõ�value_type���� 
	*/
	//ͳ��ÿ�������������г��ֵĴ��������Գ������ʣ�ʹ��set��������Եĵ���
	set<string>exclude={"The","But","And","Or","An","A","the","but","and","or","an","a"};
	map<string,size_t>words;
	string word;
	cout<<"input words\n";
	while(cin>>word)
	{
		//ֻͳ�Ʋ���exclude�еĵ���
		 if(exclude.find(word)==exclude.end())//û���ҵ�
		 ++words[word];//���������� ���ص���(�˹ؼ����������ֵ)���k����c�У����һ���ؼ���Ϊk��Ԫ��
	} 
	
	auto map_it=words.begin();
	while(map_it!=words.end())//�Ƚϵ�ǰ�������Ƿ񵽴�β������ȥ
	{
		cout<<map_it->first<<"  "<<map_it->second<<" ";
		cout<<((map_it->second>1)?"times":"time")<<endl;
		++map_it;//��������� 
	} 
	
//------------------------------------------------------------------------------
void text1();
text1();	
	
	return 0;
}
void text1()
{
	/*c.find(k):        ����һ����������ָ���һ���ؼ���Ϊk��Ԫ�أ��������򷵻�β�������
	  c.count(k):       ���عؼ���Ϊk��Ԫ�ص����������ڲ������ظ��ؼ��ֵ�����������ֵ��Զ��0����1
	  c.lower_bound(k): ����һ����������ָ���һ���ؼ��ֲ�С��k��Ԫ�� 
	  c.upper_bound(k): ����һ����������ָ���һ���ؼ��ִ���k��Ԫ�� 
	  c.equal_range(k): ����һ��������pair����ʾ�ؼ��ֵ���k��Ԫ�صķ��أ���k������
	  ��pair��������Ա��Ϊc.end() 
	�������ظ��ؼ��ֵ������У���ͬ�Ĺؼ��ֵ�Ԫ�ش洢
	�����ڴ洢*/
	 multimap<string,string>authors;// ����
	 authors.insert(multimap<string,string>::value_type(string("author1"),string("book1")));
	 authors.insert(make_pair("author1","book2"));
	 authors.insert({"author1","book3"});
	 authors.insert(pair<string,string>("author1","book4"));
	 string search_item("author1");
	 //��һ�ַ��� 
	 auto entries=authors.count(search_item);//���عؼ���Ϊ search_item������
	 auto iter=authors.find(search_item);//�ҵ���һ������������ڵ�λ��
	 while(entries--)//ͨ����������ѭ�����ٴ� 
	 {
	 	cout<<iter->first<<" "<<iter->second<<endl;
	 	++iter;
	 } 
	 cout.put('\n');
	 
	 //�ڶ��ַ�ʽ����   c.lower_bound(k)  c.upper_bound(k)
	 multimap<string,string>::iterator begin=authors.lower_bound(search_item);
	 multimap<string,string>::iterator end=authors.upper_bound(search_item);// ָ��ƥ��Ԫ�ص���һ��λ��
	 while(begin!=end)
	 {
	 	cout<<begin->first<<" "<<begin->second<<endl;
	 	begin++;
	 } 
	 cout.put('\n');
	 
	 //�����ַ�������    c.equal_range(k)
	 pair<multimap<string,string>::iterator, multimap<string,string>::iterator>position;
	 position=authors.equal_range(search_item);
	 /*��������ڣ���������2��ָ�룬��һ��ָ��ָ����� һ��ƥ���Ԫ�� 
	   �ڶ���ָ��ָ������һ��ƥ���Ԫ�ص���һ��λ�� 
	   ���������� ��pair��������Ա��Ϊc.end() 
*/
		while(position.first!=position.second)//�������ǵ����� 
		{
			cout<<position.first->first<<" "<<position.first->second<<endl;
			position.first++;
		}
} 
