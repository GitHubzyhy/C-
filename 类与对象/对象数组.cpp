#include<iostream>
#include<Windows.h>
#include<assert.h>
#include<string>

using namespace std;

HANDLE aa=GetStdHandle(STD_OUTPUT_HANDLE);//�������������е�ʱ���ֱ�۷����� !!
int ii=0;//�����ȫ�ֱ��� 

class student
{
public:
	student()=default;//Ĭ�Ϲ��� 
	student(istream &input);//���캯�� 
	student(const int id,const string &name,const int grade):ID(id),name(name),grade(grade){} //���캯����ʼ���б� 
	int Grade();//��ȡ�ɼ��ĺ��� Ϊ������׼�� 
	void show(int i);//��ʾ 
	~student()//�������� ���Բ�д��Ԫ��Ҫ���˵� 
	{
	cout<<"ִ��������"<<endl; 
	}
private:
		int ID=0;//ѧ�� 
		string name="0";//���� 
		int grade=0;//�ɼ� 
};

student::student(istream &input)//���캯���Ķ��� 
{
	
	cout<<"\t\t\t��"<<ii+1<<"������Ĵ�����"<<endl;
	ii++; //ȫ�ֱ������Ӽ�¼�ڼ�������Ĵ��� 
	cout<<"����ѧ�ţ�";
	input>>ID;//&����input��������input���� 
	cout<<"����ѧ��������";
	input>>name;
	cout<<"����ѧ���ĳɼ���";
	input>>grade; 
	cout<<endl;
}

int student::Grade()//����ѧ���ĳɼ� ��Ϊ����������׼������ 
{
		return grade;
}

void student::show(int i) 
{
		SetConsoleTextAttribute(aa, 7);
		
		cout<<"\t\t\t��"<<i+1<<"������ľ��������"<<endl;
		cout<<"ѧ�ţ�"<<ID<<endl;
		cout<<"����ѧ��������"<<name<<endl;
		
		SetConsoleTextAttribute(aa,15 | 8 | 128 | 64);//��� 
		
		cout<<"����ѧ���ĳɼ���"<<grade;
		SetConsoleTextAttribute(aa, 7);//��� 
		cout<<endl;
}
int main(void)
{
    student a[6]={student(cin),student(cin),student(cin),student(cin),student(cin)};/*����6���������鲢����
	��istreaam���й��� */
    student *p=new(nothrow)  student[6];//��̬����student��Ķ������� 
    assert(p!=nullptr);//�������ʧ��ֹͣ���� 
    system("cls");
	
	for(int i=0;i<=4;i++) //ǰ�����ֵ����̬�����Ķ������� 
	{
    *(p+i)=a[i];//����ĸ�ֵ 
    (p+i)->show(i);//��ֵһ����ʾһ����������Ϣ 
	}
	
	for(int i=0;i<=4;i++)//ð������ 
 	for(int j=0;j<=4-i;j++)
 	{
 		if((p+j)->Grade()>(p+j+1)->Grade())//���ճɼ����� 
 		{
 			*(p+5)=*(p+j);//��һ����̬������6���������飬��6����*(p+5)���������Ǵ�0��ʼ�������ǿյ�������t 
 			*(p+j)=*(p+j+1);
 			*(p+j+1)=*(p+5);
		 }
	 }
	 
	cout<<"\t\t\t�����"<<endl<<endl; 
	for(int i=0;i<=4;i++) 
	{
    (p+i)->show(i);//һ������������Ƿ�����ɹ� 
	}
	
	delete []p;//���˶��٣�Ҫ����ȥ 
	p=nullptr;//����������һ�𡢡�������32ҳ�н��� 
}
