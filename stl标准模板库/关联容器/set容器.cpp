#include<iostream>
#include<set>//ֻ��Ҫָ���ؼ��ֵ�����,����Ԫ�ز�����Զ����� 
#include<vector>//��̬���� 

using namespace std;

int main()
{
	//����multimap��multiset�ؼ��ֿ��Բ�Ψһ��set��map���ܲ����ظ���ֵ 
	vector<int>v1;
	for(int i=1;i<=20;i++)
	{
		v1.push_back(i);v1.push_back(i);
	}
	set<int>iset(v1.begin(),v1.end());//��һ��ֵ��Χ��ʼ��������
 
	multiset<int>miset(v1.begin(),v1.end()) ;
	cout<<"vector is num: "<<v1.size()<<endl;
	cout<<"set is num: "<<iset.size()<<endl;
	cout<<"multise is num: "<<miset.size()<<endl;
	//-------------------------------------------------------------------
	void text();
	text();
	return 0;
} 
class base//�Զ������������ 
{
public:
       int isbn;
	   base(int isbn):isbn(isbn){};//��ʼ���б�
	   base()=default;	
	   friend bool operator<(const base &a1,const base &a2);//�ڶ��ַ�ʽ�������Ԫ��������<����� 
};

//�ڶ��ַ�ʽ 
bool operator<(const base &a1,const base &a2)
{
	return a1.isbn>a2.isbn;//�������� 
}
bool compareIsbn(const base &a1,const base &a2)
{
 	return a1.isbn<a2.isbn;//�������� 
}
 //�����ַ�ʽ �÷º�������ʽ
struct Node
{
 	bool operator()(const base &a1,const base &a2)
 	{
	 	return a1.isbn<a2.isbn;
	 }
}; 

void text()
{
	/*����������������Ĭ��ʹ��<�Ƚ������ؼ���,�������
	��ʾָ���ؼ��ֱȽϷ���	Ĭ���������൱��set<int,less<int>>
	�����Զ��������� 1.��������<�������
	                 2.���ߵ����ṩ�ȽϺ��� */  
	set<base,decltype(compareIsbn)*>bookstore1(compareIsbn);//�ȽϺ��� 
		/*ʹ��decltypeָ���Զ�����������ͣ�����������ȡһ������ָ���ʱ��
		�������* ��ָ������ʹ��һ�������������͵�ָ�룬compareIsbn��ʼ������
		��ʾ���������������ݵ�ʱ����compareIsbnΪ��ЩԪ������*/
	set<base>bookstore2;//����<����� ���� 
	set<base,Node>bookstore3;//����ķº��� ���� 

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
