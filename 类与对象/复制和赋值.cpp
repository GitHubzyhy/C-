#include<iostream>
#include<Windows.h>//���ü�ֻ��Ϊ�˽���ÿ� 
#include<assert.h>
#include<string.h>
#include<string>

using namespace std;

HANDLE aa=GetStdHandle(STD_OUTPUT_HANDLE);//�������������е�ʱ���ֱ�۷����� !!

class airCondition
{
public:
	 airCondition()=default; //Ĭ�Ϲ��� 
	 airCondition(const char *str,const string &colorr,const string powerr,const bool Switchh,const int temperaturee) 
	{//�в����Ĺ��캯�������������������� 
		brand=new(nothrow) char[strlen(str)+1];//��̬�����ڴ� 
		//assert(brand!=nullptr);//�������ʧ��ϵͳ�������� 
		strcpy(brand,str);//�βθ��Ƹ����е����ݳ�Ա 
		this->color=colorr;//ͬ ���Բ���thisָ�룬������ߴ���Ŀɶ��� 
		this->power=powerr;//ͬ
		this->Switch=Switchh;//ͬ
		this->temperature=temperaturee;//ͬ
	}
	airCondition(const airCondition &);//���ƹ��캯�� ������ 
	airCondition& operator=(const airCondition &);//���Ƹ�ֵ���� ������
	void up()//�����¶� 
	{
		if(Switch!=0)//��������ǿ��ŵ� 
		{
			if(temperature<30)//16��C��30��C֮�� 
			temperature++;//�¶ȼӼ� 
		}
	 } 

	void down()//�����¶� 
	{
	 	if(Switch!=0)//��������ǿ��ŵ�
		{
			if(temperature>16)
			temperature--;
		}
	}
	 
	int Temperature()//Ŀ���Ƿ���һ�� temperature��Ϊ�����Ĳ�����׼�� 
	{
		return temperature;
	}
	
	void change()//���ƿ��أ� 
	{
		Switch=!Switch;//�������õ�bool����ֻ��true��1����faulse��0�� 
	}
	
	void show()
	{
		if(Switch==true)//��������ǿ��ŵ� 
		{//����� 
			cout<<"����״̬ Switch: "<<"����״̬" <<endl;
			cout<<"Ʒ�� brand:"<<brand<<endl<<"��ɫ color:"<<color<<endl<<"���� power"<<power<<endl
			<<"�¶� temperature:"<<temperature<<"��"<<endl;
		}
		else//���û������ʾ 
			cout<<"���ȿ��յ�"<<endl;
	}
	
	~airCondition()//�������������ݳ�Ա����ָ���Ա����д���������� 
	{//����һ��~����������� 
		delete []brand;//�����ٶ�̬�ڴ�Ĳ��� 
		brand=nullptr;//���������Ϊһ������ȱһ���� 
	}

private:
	char *brand;//Ʒ�� 
	string color="��ɫ";//��ɫ 
	string power="2ƥ";//���� 
	bool Switch;//����״̬ 
	int temperature=25;//�趨�¶� 
};

airCondition::airCondition(const airCondition &p)//���ƹ��캯�� 
{
	brand=new(nothrow) char[strlen(p.brand)+1];//��̬�����ڴ�
	//assert(brand!=nullptr);//��ǰ��Ĺ��캯������Ψһ��������ǲ����ǣ�һ����������ã� 
	strcpy(brand,p.brand);
	this->color=p.color;
	this->power=p.power;
	this->Switch=p.Switch;
	this->temperature=p.temperature;
}

airCondition& airCondition::operator=(const airCondition &p) 
{
	if(&p!=this)//����ǲ�������ֵ��������ü��ϣ� 
	{
	    brand=new(nothrow) char[strlen(p.brand)+1];//�ص㣡����̬�����ڴ� 
		//assert(brand!=nullptr);//��ǰ��Ĺ��캯������Ψһ��������ǲ����ǣ�һ����������ã� �� operator=
		strcpy(brand,p.brand);
		this->color=p.color;
		this->power=p.power;
		this->Switch=p.Switch;
		this->temperature=p.temperature;
	}
	return *this;
}

int main(void)
{
	airCondition a("����","��ɫ","2ƥ",false,25);//���ù��캯�����г�ʼ�� 
	a.show();//��ʾ��ʱ��״̬ 
	cout<<"\t\t\t\t\tִ�д򿪿յ���Ĳ���\n"; 
	system("pause");//ͣ�����򿪿յ� 	
	cout<<"�򿪿յ���"<<endl;
	a.change();//�򿪿��� 
	a.show();
	cout<<endl;
	cout<<"���н��²�����"<<endl;
	while(a.Temperature()!=20)//����¶Ȳ��ǵ���20����whileѭ�� 
	{
		if(a.Temperature()<20)//���һС��20�������� 
		a.up();
		else if(a.Temperature()>20)//���һ����20���������� 
		a.down();
	}
	 	a.show();//��ʾ������ϵ����ս��

		SetConsoleTextAttribute(aa,15|8|128|641);//�������������е�ʱ���ֱ�۷����� 
		  	
		  	
	//����һʵ�� ����
	cout<<endl<<"���ƹ��캯�������Ķ���"<<endl;
	airCondition b(a);
	b.show();
	//������ʵ�� ���Ƹ�ֵ
	cout<<endl<<"���Ƹ�ֵ���������Ķ���"<<endl;
	airCondition c;
	c=b;
	c.show();
	
	
	SetConsoleTextAttribute(aa,7);//�������������е�ʱ���ֱ�۷�����  
	
	/*������������
	(1)����ĸ�ֵ�������������Ѿ������Ļ����Ͻ��еģ�
	������ĸ���������һ�����ж�����һ���¶���ʱ���еġ�
	(2)������������Ӧ���õĺ�����ͬ������ĸ�ֵϵͳ���õ������ظ�ֵ������ĺ�����
	������ĸ���ϵͳ���õ��Ǹ��ƹ��캯����
	*/
}
