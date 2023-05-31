#include<iostream>
#include<string>
using namespace std;
class Employee//���� 
{
public:
	Employee()=default;
	Employee(const string &Name,int Age,const string &Sex,const string &Address
,const string &Telephone):name(Name),
age(Age),sex(Sex),address(Address),telephone(Telephone){}//���캯���ĳ�ʼ���б�

Employee(istream &input):Employee()//ί�к����������ĵ��� 
{
	cout<<"����name��"<<endl;
	input>>name;
	cout<<"����age: "<<endl;
	input>>age;
	cout<<"����sex: "<<endl;
	input>>sex;
	cout<<"����address:"<<endl;
	input>>address;
	cout<<"����telephone: "<<endl;
	input>>telephone;
}
	~Employee()=default;
protected:
	string name;//���� 
	int age;//���� 
	string sex;//�Ա� 
	string address;//��ַ 
	string telephone;//�绰	
};

class Teacher:virtual public Employee
{
public:
	Teacher()=default;//��ʾ���ù��캯�� 
	Teacher(const string &Name,int Age,const string &Sex,const string &Address
	,const string &Telephone,const string &Title):Employee(Name, Age,Sex,Address,Telephone),title(Title){}//���캯���ĳ�ʼ���б�
	
	Teacher(istream &input):Employee(input)//ί�к����������ĵ��� 
	{
		cout<<"����title: "<<endl;
		input>>title;
	}
	~Teacher()=default; 
protected:
	string title;//ְ�� (�������У� 
};

class Cardre: virtual public Employee
{
public:
	Cardre()=default;
	Cardre(const string &Name,int Age,const string &Sex,const string &Address
	,const string &Telephone,const string &Post):Employee(Name, Age,Sex,Address,Telephone),post(Post){}//���캯���ĳ�ʼ���б�
	
	Cardre(istream &input):Employee(input)//ί�к����������ĵ��� 
	{
		cout<<"����post: "<<endl;
		input>>post;
	}
	~Cardre()=default;
protected:
	string post;//ְ��(�������У�
};

class Teacher_Cardre:public Teacher,public Cardre//���ü̳��������� 
{
public:
	Teacher_Cardre()=default;
	Teacher_Cardre(const string &Name,int Age,const string &Sex,const string &Address
	,const string &Telephone,const string &Title,const string &Post,int Wage):Employee(Name,Age,Sex,Address,Telephone),Teacher(Name, Age,Sex,Address,Telephone,Title),
	Cardre(Name, Age,Sex,Address,Telephone,Post),wage(Wage){}//���캯���ĳ�ʼ���б�
	
	Teacher_Cardre(istream &input):Employee(input),Teacher(input),Cardre(input)//ί�к����������ĵ��� 
	{
		cout<<"����wage: "<<endl;
		input>>wage;
	}

	void show()
	{
		cout<<"name: "<<name<<endl;
		cout<<"age: "<<age<<endl;
		cout<<"sex: "<<sex<<endl;
		cout<<"address: "<<address<<endl;
		cout<<"telephone: "<<telephone<<endl;
		cout<<"title: "<<title<<endl;
		cout<<"post: "<<post<<endl;
		cout<<"wage: "<<wage<<endl<<endl;
	}
	~Teacher_Cardre()=default;
protected:
	int wage;	
};

int main(void)
{
     	Teacher_Cardre a("����",35,"��","��������","1234561111","����","Ժ��",8000);
	 	a.show();
        Teacher_Cardre b(cin);	
	    b.show();
	
		return 0; 
}
