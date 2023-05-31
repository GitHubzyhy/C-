#include<iostream>
using namespace std;
class Acoount
{
public:
		Acoount()=default;//默认构造函数 
		Acoount(istream &input);//实现获取账号操作声明 [1]//可以直接定义一个输入函数不用这个 
		int Deposit(const int & balance);//实现存款功能 [2]
		int Withdrawl();//实现取款操作[3]
		void inquire()//余额查询 [4]
		{
			cout<<"余额为:"<<Balance<<endl;
		}
private:
		int Account=17001;//该类账号 
		int Balance=5000;//该类余额 
};

Acoount::Acoount(istream &input)//输入构造函数 
{
	cout<<"请你输入账号：";
	input>>Account; 
	cout<<"请你输入余额：";
	input>>Balance;
	system("cls");
	cout<<"当前账户："<<Account<<endl;
	cout<<"当前余额："<< Balance<<endl;
}

int Acoount::Deposit(const int & balance)
{
	        Balance+=balance;//存款操作 
			 cout<<"存款成功！"<<endl; 
			 cout<<"余额为："<< Balance<<endl;
			 return  Balance;	 
}

int Acoount::Withdrawl()
{
	int balance;
	cout<<"本次取款金额："; 
	cin>> balance;//输入取款的金额 
	while(balance>Balance)//如果余额不足做一个循环 
	{
		cout<<"余额不足，取款失败！"<<endl;
		cout<<"本次取款金额："; 
		cin>> balance;
	}	 
	 Balance-=balance;//取款操作 
	 cout<<"取款成功！"<<endl;
	 return  Balance;		 
}

int main(void)
{
	int  balance;
	cout<<"\t\t\t进行对象1的创建！"<<endl<<endl;
	Acoount a(cin);//调用输入构造函数 
	cout<<"此次存款金额："; 
	cin>> balance;
	a.Deposit(balance);//存款的金额作为主参带入到存款函数里去 
	a.Withdrawl();//调用取款操作 
	a.inquire(); //查询余额（显示余额多少！） 
	
	/*对象2跟对象1相同 
	 思路：
	 创建一个账户（初始化账号，和卡里的余额）然后清屏操作为了
	 好看（system（“cls”），
	 输入存款的金额带入存款函数里，再掉用
	 取款操作*****最后显示最终的余额是多少******/ 
	cout<<"\t\t\t进行对象2的创建！"<<endl<<endl;
	Acoount b(cin);
	cout<<"此次存款金额："; 
	cin>> balance;
	b.Deposit(balance);
	b.Withdrawl();
	b.inquire(); 
}
