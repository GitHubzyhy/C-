#include<iostream>

using namespace std;

template<typename T>
class ManyFriend
{
	T item;
public:
	ManyFriend(const T &i):item(i){}
	template<typename C,typename D>//类模板内部声明模板 
	friend void show(C &,D &);//非约束友元函数 
};

template<typename C,typename D>
void show(C &c,D &d)
{
	cout<<c.item<<","<<d.item<<endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.5);
	
	cout<<"hfi1,hfi2: ";
	show(hfi1,hfi2);
	cout<<"hfdb,hfi2: ";
	show(hfdb,hfi2);

	return 0;
}
