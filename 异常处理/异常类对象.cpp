#include<iostream>
using namespace std;

enum//ö�� 
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

void Trigger()//�����쳣
{
	if(EXCEPTION_2>EXCEPTION_1)//һ����������ִ�����²���
	{
			CppException *p=new(nothrow) CppException(5);//�쳣�����ָ�� 
			throw p;//�����׳����� 
	} 

}
 
int main(void)
{
	try//��� 
	{
		Trigger();///�����ڲ��׳�	 
	}
	catch(CppException *e)//��׽ 
	{
		e->Reason();
		delete[] e;//�ͷ�ָ�� 
		e=nullptr; 
	}
	
	return 0; 
} 
