#include<iostream>
#include<vector>
#include<list>//˫������ 

using namespace std;

int main()
{
	vector<int> v1{1,2,3,4};
	if(!v1.empty())//��Ϊ�յ�ʱ��
	{
		v1.front()=11;//.front()���ص�������
		auto &v=v1.front();
		v=1024; 
	} 
	for(vector<int>::iterator i=v1.begin();i!=v1.end();i++)
	cout<<*i<<" ";
	cout.put('\n');
	vector<string> v2;
	try{
			cout<<v2.at(0);//�±�Խ���׳��쳣 
	}
	catch(...)
	{
		cout<<"out_of_rang";
	}
//�����ѭ��ɾ��һ��list����������Ԫ�� 
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
