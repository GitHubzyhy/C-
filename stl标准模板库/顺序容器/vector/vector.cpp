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

	vector<int>v1;//vector和String不支持push_front(),pop_front() 
	vector<base>v2;
	for(int i=0;i<5;i++)
	v1.push_back(i);
	v1.insert(v1.begin(),5,1);
	vector<int>::iterator pos=v1.begin();
	
	while(cin>>word)//类似与push_fron() 
	pos=v1.insert(pos,word);
	for(auto &e:v1)
	cout<<e<<" ";
	cout.put('\n');
	v2.emplace_back(1,"1");//将参数传递给元素类型的构造函数，emplace成员使用这些参数在容器管理的内存空间中直接构造元素 
	v2.emplace(v2.begin(),2,"2");//类似于插入 
	for(auto i=v2.begin();i!=v2.end();i++)
    i->show();
	return 0;
}
