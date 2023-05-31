#include<iostream>

using namespace std;

//������ֹ�ݹ鲢����������һ��Ԫ�� 
template<typename T>
void print(const T &t){cout<<t<<endl;}//��ӡ���һ��ʵ��

//���г����һ��Ԫ���������Ԫ�ض����������汾��print 
template<typename T,typename ...Args>
void print(const T &t,const Args&...rest)
{
	cout<<t<<" ";//��ӡ��һ��ʵ�� 
	print(rest...);//�ݹ���ã���ӡ����ʵ�� 
}
 
int main()
{
	print("string1",2,3.14f,"string2",42);
	cout<<endl; 
	return 0;
}
