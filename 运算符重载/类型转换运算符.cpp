#include<iostream>

using namespace std;

class base
{
	int num;
public:
	base(const int &num):num(num){}
	explicit operator int(){return num;}//����ת������ 
};

int main()
{
	base b(5);
	cout<<int(b)+3;
	return 0;
}
