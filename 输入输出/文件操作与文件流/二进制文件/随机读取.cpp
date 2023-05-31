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
		cerr<<"open error��\n";
		abort();
	}
	
	for(int i=0;i<4;++i)
		iofile.write((char *)&stud[i],sizeof stud[i]);//д�뵽�ļ���
	
 	//�Ⱥ��ȡ���0��2��ѧ�����ݣ������stud1[0]��std1[2]��
	for(int i=0;i<4;i+=2)
	{
		iofile.seekg(i*sizeof stud[i],ios::beg);//�������ļ����ļ��Ŀ�ʼλ���ƶ�����i�����ݿ�ͷ
		//��ȡ���ݷŵ�stud1[i]�� 
		iofile.read((char *)&stud1[i],sizeof stud1[i]); 
		cout<<stud1[i].name<<","<<stud1[i].age<<","<<stud1[i].sex<<endl; 
	} 
	cout<<endl;
	
	//�޸ĵڶ���ѧ��
	strcpy(stud[2].name,"Jenny");stud[2].age=18;stud[2].sex='F';
	
	iofile.seekp(2*sizeof stud[0],ios::beg);//����ļ�ָ�붨λ��2��ѧ�����ݿ�ͷ
	iofile.write((char *)&stud[2],sizeof stud[2]);//�ϴ�����
	iofile.seekg(0,ios::beg); //����ָ�����Ϊ�ʼ 
	for(int i=0;i<4;++i)
	{
		iofile.read((char *)&stud1[i],sizeof stud1[i]);
		cout<<stud1[i].name<<","<<stud1[i].age<<","<<stud1[i].sex<<endl;
	}
	iofile.close();//�ر���������ļ� 
	
	return 0;
}
