#include<iostream>
#include<string>

using namespace std;

class Score
{
public:
	Score()=default;//Ĭ�Ϲ��캯�� 
	Score(const string n,const string s,int i,int g):name(n),sex(s),id(i){grade+=g,num++;}//ͬѧ������++ 
	Score(istream &input)
	{
		int grade1=0;//������һ���ֲ����� 
		cout<<"��"<<num+1<<"������Ĵ���"<<endl; 
		cout<<"����name:";
		input>>name;
		cout<<"�����Ա�:";
		input>>sex;
		cout<<"����ɼ�:";
		input>>grade1; 
		grade+=grade1;
		cout<<endl;
		num++;//ͬѧ������++ 
}

void show1()
{
	cout<<"name: "<<name<<endl;
	cout<<"sex: "<<sex<<endl;
	cout<<"grade: "<<grade<<endl;
} 

static double show()///��̬��Ա���� �����ã�������̬��Ա�� 
{
	return grade/num;//�������ƽ���ɼ� 
} 

 ~Score();
 static double grade;//�����ܷ�������̬��Ա����������ֻ��һ�����������������಻���ڶ������ж���һ��ά�������Ա�� 
 static double num;//��̬���ݳ�Ա��ѧ��������Ŀ�ģ�����������֪�������˼������� 

private:
	string name;//����
	string sex;//���Ա� 
	int id;//ѧ�������֤���� 
};

Score::~Score()
{
 	cout<<"Score��������ִ�У�"<<endl; 
}

double Score::grade=0;//��̬���ݳ�Ա��ʼ����ֻ����������г�ʼ��������Ҫ�� 
double Score::num=0;//��̬���ݳ�Ա��ʼ�� 

int main(void)
{
	Score a1("����","��",2111,10);
	a1.show1(); 
	cout<<endl;
	cout<<"��"<<Score::num<<"��ͬѧ��ƽ�������ǣ�"<<a1.show()<<endl;
	
	//�û��Լ������������ 
	Score a2[3]={Score(cin),Score(cin),Score(cin)};
	cout<<"��"<<Score::num<<"��ͬѧ��ƽ����: "<<a2[2].show()<<endl;
	 
	return 0; 
}
