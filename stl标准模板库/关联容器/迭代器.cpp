#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>

using namespace std;

void text1()//���������
{
	/*���������ֻ����˳����ʣ�ֻ�����ڵ���ɨ�跨�������������ֻ������ڸ�ֵ��������Ҳ�  
	��������һ����������ʱ�򣬱���ָ��  ��Ҫ��д�����ͱ��붨�����������������������һ��istream_iteratorʱ����
	��������һ�����ϣ���Ĭ�ϳ�ʼ����ʱ�򣬾ʹ�����һ�����Ե���β��ֵʹ�õĵ����� 
	*/
	vector<int>vec1;
	istream_iterator<int>in_iter(cin);//�󶨵�һ������,��cin��ȡint 
	istream_iterator<int>eof;//istream��β������� 
//����	
	while(in_iter!=eof)//һ���������������ļ�β������I/O���󣬵�������ֵ����β���������� 
	vec1.push_back(*in_iter++);//���õ����������ȡ�������ص������ľ�ֵ�������õ���������ô�����ȡ��ǰһ��ֵ 
//��� 
	for(auto result:vec1)
	cout<<result<<" ";
//	
//	vector<int>vec2(in_iter,eof);//�ӵ�������Χ����vec 
//	for(auto result:vec2)
//	cout<<result<<" ";
}
int main()
{
	//ʹ���㷨������������ 
//	istream_iterator<int>in(cin),eof;
//	cout<<accumulate(in,eof,0)<<endl;
	text1();
	
}
