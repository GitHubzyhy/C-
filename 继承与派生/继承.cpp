#include<iostream>
#include<string>

using namespace std;

class Country
{
public:
	Country()=default;
	Country(const string name,const string capital,const int population)
	:Country_name(name),Country_capital(capital),Country_population(population){}//���캯���ĳ�ʼ���б� 
	Country(istream &input):Country()//ί�к������ú�����Ը���������� 
	{
	cout<<"�������"<<endl;
	input>>Country_name;
	 cout<<"�����׶�"<<endl;
	 input>>Country_capital;
	cout<<"�����˿�"<<endl;
   input>> Country_population;
    }	
    void show()
    {
    	cout<<"����Ϊ��"<< Country_name<<endl;
    	cout<<"�׶�Ϊ��"<<Country_capital<<endl;
    	cout<<"���ҵ��˿�Ϊ"<< Country_population<<"��"<<endl; 
	}
private:
	string Country_name;
	string Country_capital;
	int Country_population;
};

class Countryy:public Country
{
public:
	using Country::Country; //���û���Ĺ��캯�� 
    
	Countryy(const string name,const string capital,const int population,string provice_namee,int provice_populationn)
	:Country(name,capital,population),provice_name(provice_namee),provice_population(provice_populationn){}
	Countryy(istream &input):Country(input)
	{
	cout<<"����ʡ����е�����"<<endl;
	input>>provice_name;
	cout<<"����ʡ����е��˿�"<<endl;
   input>> provice_population;
    }
	
	void show()
	{
     	Country::show();
		cout<<"ʡ����е�����Ϊ��"<< provice_name<<endl;
		cout<<"���ҵ��˿�Ϊ"<<provice_population<<"ǧ��"<<endl; 
	}	
private:
	string provice_name;
	int provice_population;
};

int main(void)
{
		Countryy a("�й�","����",14,"����",2);  
		a.show();
		cout<<endl<<endl;
		Countryy aa(cin); 
		cout<<endl<<endl;
		aa.show();
		
		return 0; 
}
