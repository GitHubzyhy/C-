#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{ 
	using ve=vector<int>;//ȡ�ı��� 
	//һ������£�STL�㷨��ֱ�Ӳٿ����������Ǳ���������������ָ����һ��Ԫ�ط�Χ�����в���
	ve a1={1,2,3,4,5};
	int val=3;
	auto result=find(a1.begin(),a1.end(),val);// find���ص�һ�����ڸ���ֵԪ�صĵ����������û���ҵ�
	cout<<*result<<endl;                                          //���صڶ���������ʾ����ʧ��

 //ָ�������������ϵĵ�����һ�������ǿ�����find�������в���ֵ 
 	int ia[]={27,210,12,47,109};
	int vall=47;
	int *result2=find(begin(ia),end(ia),vall);//ʹ�ñ�׼���begin��end������ȡָ��ia����Ԫ�غ�βԪ��֮���ָ�� 
	cout<<*result2<<endl; 
	
	//�����������е��ӷ�Χ�в��ң�ֻ��Ҫ��ָ���ӷ�Χ��Ԫ�غ�βԪ��֮���λ�õĵ�����(ָ��)���ݸ�find()
	auto result3=find(ia+1,ia+4,vall);
	cout<<*result3<<endl; 
	
}
