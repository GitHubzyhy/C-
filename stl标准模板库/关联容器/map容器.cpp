#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

int main()
{
	/*��һ��map�У�
	key_type���������͵Ĺؼ�������
	mapped_typeÿ���ؼ��ֹ��������ͣ�ֻ������map 
	value_type����set����key_typeԪ���Ǽ�ֵ�ԣ�ÿ��Ԫ�ض���һ��pair����
	�����ǲ��ܸı�һ��Ԫ�ص�const�ؼ���*/
	// set�еĹؼ���Ҳ��const,�����޸� 
	vector<int>ivec={2,4,6,8,9,5};
	set<int>set1;//����һ���ռ���
	set1.insert(ivec.begin(),ivec.end());
	/*ֻ�е�Ԫ�صĹؼ��ֲ�������ſ��Բ��룬
    insert(value_type����)	����󷵻�һ��pair������һ��������ָ�����ؼ��ֵ�Ԫ��
	�Լ�һ��֮ʱ�����Ƿ�ɹ���boolֵ
	insert(b,e),insert(il),insert(p,v)*/
	
	string str="hellow";
	map<string,int>words;
	words.insert({str,1});
	words.insert(make_pair(str,1));
	words.insert(pair<string,int>(str,1));
	words.insert(map<string,int>::value_type(str,1));//����һ��pair���ͣ�����������͵�һ���¶��� 

   void text();
   text();
   return 0;
}
void text()
{
	//ͳ�Ƶ����ڲ����г��ִ�����һ�ַ���д��
	map<string,int>words;
	string word;
	while(cin>>word)
	{
		//����һ��Ԫ�أ��ؼ��ֵ���word��ֵΪ1
		auto ret=words.insert(make_pair(word,1));
		if(!ret.second)//���ص�boolֵΪ0��ʾ����ʧ��
		++ret.first->second;//���������� 
		cout<<"�����ظ���"<<ret.first->second<<endl;
	} 

}
