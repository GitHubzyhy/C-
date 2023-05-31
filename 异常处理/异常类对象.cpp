#include<iostream>
using namespace std;

enum//枚举 
{
	EXCEPTION_1=1,EXCEPTION_2=2,EXCEPTION_3=3
};

class CppException
{
public:
	CppException()=default;
	CppException(int nReason):reason(nReason){}	
	~CppException(){}
	void Reason(){cout<<"Exception: "<<reason<<endl;}
private:
	int reason;		
};

void Trigger()//触发异常
{
	if(EXCEPTION_2>EXCEPTION_1)//一旦满足条件执行以下操作
	{
			CppException *p=new(nothrow) CppException(5);//异常类对象指针 
			throw p;//进行抛出操作 
	} 

}
 
int main(void)
{
	try//检查 
	{
		Trigger();///函数内部抛出	 
	}
	catch(CppException *e)//捕捉 
	{
		e->Reason();
		delete[] e;//释放指针 
		e=nullptr; 
	}
	
	return 0; 
} 
