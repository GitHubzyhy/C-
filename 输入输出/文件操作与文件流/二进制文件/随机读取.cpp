#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

struct Person
{
	char name[20];
	int age;
	char sex;
}; 

int main()
{
	Person stud[4]={"Jack",18,'M',"John",19,'M',"Mary",17,'F',"Mike",18,'M'},stud1[4];
	fstream iofile("student.dat",ios::in|ios::out|ios::binary);
	if(!iofile)
	{
		cerr<<"open error！\n";
		abort();
	}
	
	for(int i=0;i<4;++i)
		iofile.write((char *)&stud[i],sizeof stud[i]);//写入到文件中
	
 	//先后读取序号0，2的学生数据，存放在stud1[0]和std1[2]中
	for(int i=0;i<4;i+=2)
	{
		iofile.seekg(i*sizeof stud[i],ios::beg);//将输入文件从文件的开始位置移动到第i个数据开头
		//读取数据放到stud1[i]中 
		iofile.read((char *)&stud1[i],sizeof stud1[i]); 
		cout<<stud1[i].name<<","<<stud1[i].age<<","<<stud1[i].sex<<endl; 
	} 
	cout<<endl;
	
	//修改第二个学生
	strcpy(stud[2].name,"Jenny");stud[2].age=18;stud[2].sex='F';
	
	iofile.seekp(2*sizeof stud[0],ios::beg);//输出文件指针定位第2个学生数据开头
	iofile.write((char *)&stud[2],sizeof stud[2]);//上传更新
	iofile.seekg(0,ios::beg); //输入指针调整为最开始 
	for(int i=0;i<4;++i)
	{
		iofile.read((char *)&stud1[i],sizeof stud1[i]);
		cout<<stud1[i].name<<","<<stud1[i].age<<","<<stud1[i].sex<<endl;
	}
	iofile.close();//关闭输入输出文件 
	
	return 0;
}
