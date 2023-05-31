#include<iostream>
#include<fstream>

using namespace std;

struct Person
{
	char name[20];
	int age;
	char sex;
}; 

int main()
{
	Person stud[4]={"Jack",18,'M',"John",19,'M',"Mary",17,'F',"Mike",18,'M'},stud_temp[4];

	//写入到文件中 
	ofstream outfile("student.dat",ios::binary);
	if(!outfile)
	{
		cerr<<"open error!\n"<<endl;
		abort();
	}
	
	for(int i=0;i<4;++i)
		outfile.write((char *)&stud[i],sizeof stud[i]);//地址   多少个字节
	outfile.close();
	
	//从文件中读取 
	ifstream infile("student.dat",ios::binary);
	if(!infile)
	{
		cerr<<"open error!\n"<<endl;
		abort();	
	} 
	
	for(int i=0;i<4;++i)
		infile.read((char *)&stud_temp[i],sizeof stud_temp[i]);//读取到内存地址，一次读多少个字节 
	infile.close();
	
	for(int i=0;i<4;++i)
	{
		cout<<"name: "<<stud_temp[i].name<<'\t';
		cout<<"age: "<<stud_temp[i].age<<'\t';
		cout<<"sex: "<<stud_temp[i].sex<<endl;
	} 
	
	return 0;
}
