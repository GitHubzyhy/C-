#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	fstream infile,outfile;//�����ļ�������
	char ch,str[]="Hello world";
	
	outfile.open("ff.dat",ios::out);
	if(!outfile)
	{
		cerr<<"open error!\n"<<endl;	
		abort();//������ֹ��ǰ����(�����쳣�ĳ������ֹ) 
	}	
	
	for(int i=0;i<=(int)strlen(str);++i)
		outfile.put(str[i]);
	outfile.close();
	
	infile.open("ff.dat",ios::in);
	if(!infile)
	{
		cerr<<"open error!\n"<<endl;	
		abort();//������ֹ��ǰ����(�����쳣�ĳ������ֹ) 
	}
	
	while(infile.get(ch))
		cout<<ch;
	cout<<endl;
	infile.close();	
	
	return 0;
}
