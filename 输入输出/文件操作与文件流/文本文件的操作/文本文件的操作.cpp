#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

int main()
{
	fstream outfile("1.txt",ios::out);//�����ļ������󣬴򿪴����ļ�1.txt
	if(!outfile)
	{
		cerr<<"����û��Ȩ�ޣ����ߴ��̷����������ߴ����л����ȡ�\n"<<endl;
		cerr<<"��������˳�����...\n"<<endl;
		getch();
		abort();
	} 
	
	outfile<<"Hellow\n";
	outfile<<"zyh\n";
	outfile.close();
	
	ifstream infile("1.txt",ios::in);
	if(!infile)
	{
		cerr<<"����û��Ȩ�ޣ����ߴ��̷����������ߴ����л����ȡ�\n"<<endl;
		cerr<<"��������˳�����...\n"<<endl;
		getch();
		abort();
	} 
	
	char s[100];
	while(!infile.eof())
	{
		infile.getline(s,sizeof s);
		cout<<s<<endl;
	} 
	infile.close();//�ر��ļ� 
	
	return 0;
}
