#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

int main()
{
	fstream outfile("1.txt",ios::out);//定义文件流对象，打开磁盘文件1.txt
	if(!outfile)
	{
		cerr<<"可能没有权限，或者磁盘分区满，或者磁盘有坏道等。\n"<<endl;
		cerr<<"按任意键退出程序...\n"<<endl;
		getch();
		abort();
	} 
	
	outfile<<"Hellow\n";
	outfile<<"zyh\n";
	outfile.close();
	
	ifstream infile("1.txt",ios::in);
	if(!infile)
	{
		cerr<<"可能没有权限，或者磁盘分区满，或者磁盘有坏道等。\n"<<endl;
		cerr<<"按任意键退出程序...\n"<<endl;
		getch();
		abort();
	} 
	
	char s[100];
	while(!infile.eof())
	{
		infile.getline(s,sizeof s);
		cout<<s<<endl;
	} 
	infile.close();//关闭文件 
	
	return 0;
}
