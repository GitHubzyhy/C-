#include<iostream>
#include<vector>
using namespace std;
class base
{
	public:
		base(int id,string name):id(id),name(name){}
	    void show()
	    {
			cout<<id<<" "<<name<<endl;
		}
//	private:
		int id;
		string name;
};
int main()
{
	int word;

	vector<int>v1;//vector��String��֧��push_front(),pop_front() 
	vector<base>v2;
	for(int i=0;i<5;i++)
	v1.push_back(i);
	v1.insert(v1.begin(),5,1);
	vector<int>::iterator pos=v1.begin();
	
	while(cin>>word)//������push_fron() 
	pos=v1.insert(pos,word);
	for(auto &e:v1)
	cout<<e<<" ";
	cout.put('\n');
	v2.emplace_back(1,"1");//���������ݸ�Ԫ�����͵Ĺ��캯����emplace��Աʹ����Щ����������������ڴ�ռ���ֱ�ӹ���Ԫ�� 
	v2.emplace(v2.begin(),2,"2");//�����ڲ��� 
	for(auto i=v2.begin();i!=v2.end();i++)
    i->show();
	return 0;
}
