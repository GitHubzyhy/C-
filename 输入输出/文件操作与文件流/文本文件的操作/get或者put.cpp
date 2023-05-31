#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
	fstream infile,outfile;//定义文件流对象
	char ch,str[]="Hello world";
	
	outfile.open("ff.dat",ios::out);
	if(!outfile)
	{
		cerr<<"open error!\n"<<endl;	
		abort();//用于终止当前进程(对于异常的程序的终止) 
	}	
	
	for(int i=0;i<=(int)strlen(str);++i)
		outfile.put(str[i]);
	outfile.close();
	
	infile.open("ff.dat",ios::in);
	if(!infile)
	{
		cerr<<"open error!\n"<<endl;	
		abort();//用于终止当前进程(对于异常的程序的终止) 
	}
	
	while(infile.get(ch))
		cout<<ch;
	cout<<endl;
	infile.close();	
	
	return 0;
}
