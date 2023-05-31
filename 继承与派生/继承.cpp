#include<iostream>
#include<string>

using namespace std;

class Country
{
public:
	Country()=default;
	Country(const string name,const string capital,const int population)
	:Country_name(name),Country_capital(capital),Country_population(population){}//构造函数的初始化列表 
	Country(istream &input):Country()//委托函数，让后面测试更具有灵活性 
	{
	cout<<"输入国名"<<endl;
	input>>Country_name;
	 cout<<"输入首都"<<endl;
	 input>>Country_capital;
	cout<<"输入人口"<<endl;
   input>> Country_population;
    }	
    void show()
    {
    	cout<<"国名为："<< Country_name<<endl;
    	cout<<"首都为："<<Country_capital<<endl;
    	cout<<"国家的人口为"<< Country_population<<"亿"<<endl; 
	}
private:
	string Country_name;
	string Country_capital;
	int Country_population;
};

class Countryy:public Country
{
public:
	using Country::Country; //调用基类的构造函数 
    
	Countryy(const string name,const string capital,const int population,string provice_namee,int provice_populationn)
	:Country(name,capital,population),provice_name(provice_namee),provice_population(provice_populationn){}
	Countryy(istream &input):Country(input)
	{
	cout<<"输入省会城市的名字"<<endl;
	input>>provice_name;
	cout<<"输入省会城市的人口"<<endl;
   input>> provice_population;
    }
	
	void show()
	{
     	Country::show();
		cout<<"省会城市的名字为："<< provice_name<<endl;
		cout<<"国家的人口为"<<provice_population<<"千万"<<endl; 
	}	
private:
	string provice_name;
	int provice_population;
};

int main(void)
{
		Countryy a("中国","北京",14,"重庆",2);  
		a.show();
		cout<<endl<<endl;
		Countryy aa(cin); 
		cout<<endl<<endl;
		aa.show();
		
		return 0; 
}
