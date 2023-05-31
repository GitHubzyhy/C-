#include<iostream>
using namespace std;

class Complex
{
public:
	Complex()=default;
	Complex(int Real,int Img):real(Real),img(Img){}
	~Complex()=default; 
	Complex operator-(const Complex a);//����
	Complex operator/(const Complex a);//����
	
	friend ostream& operator<<(ostream &out,Complex &t);//��������������� ����Ԫ�� 
	friend istream& operator>>(istream &input,Complex &t);//��������ȡ����� ����Ԫ��
	friend Complex operator+(const Complex a,const Complex b);//����+ 
	friend Complex operator*(const Complex a,const Complex b);//����*
	friend Complex& operator--(Complex &p);//����ǰ��-- 
	Complex operator++(int);//���غ���++ 
	
	Complex(double x);//ת�����캯�� 
private:	
	double real;//�����ʵ��
	double img;//������鲿 
};
Complex  Complex::operator-(Complex a) 
{
	Complex r;//�������ʱ���� 
	r.real=real-a.real; 
	r.img=img-a.img;
	return r;
}
Complex Complex::operator/(Complex a)
{
	Complex r;
	r.real=real*a.real-img*a.img;//��a*c��-��b*d��
	r.img= img*a.real+real*a.img;
	return r;
}
ostream& operator<<(ostream &out,Complex &t) 
{
	out<<"("<<t.real<<","<<t.img<<")"<<endl;
	return out;
}
istream& operator>>(istream &input,Complex &t) 
{
	cout<<"��������real(ʵ��)"<<endl; 
	input>>t.real;
	cout<<"��������img(�鲿)"<<endl; 
	input>>t.img;
	return input;
}
Complex operator+(Complex a, Complex b)
{
	Complex r;
	r.real=a.real+b.real;
	r.img=a.img+b.img;
	return r;
}
Complex operator*(Complex a, Complex b)
{
	Complex r;
	r.real=a.real*b.real;
	r.img=a.img*b.img;
	return r;
}

Complex  Complex::operator++(int)//����++ ��int��������ǰ�úͺ��õ� 
{
	Complex temp(*this);
	real++;
	img++;
	return temp; //��Ϊ�Ǻ������Է���֮ǰ�ģ�c++�������Ķ�����Ϊ��ֵ����ʹ�䲻�����ڸ�ֵ���������ࣩ 
}
Complex& operator--(Complex &p)//ǰ��-- 
{
	p.real--;
	p.img--;
	return p;
}
Complex::Complex(double x)//ת�����캯�� 
{
	real=x;
	img=0;
}

int main(void)
{
	Complex a,b(1,2),c(2,2),d,t;
	cout<<"b�Ľ����"<<endl;
	cout<<b<<endl;
	cout<<"c�Ľ����"<<endl;
	cout<<c<<endl; 
	 
	  
	cout<<"���븴��a"<<endl;
	cin>>a;
	cout<<a;
	d=b+c;//��֤+�������Ƿ���ȷ 
	cout<<"b+c�Ľ����"<<endl;
	cout<<d;
	
	d=b*c;//��֤*������������Ƿ���ȷ 
	cout<<"b*c�Ľ����"<<endl;
	cout<<d;
	
	d=b-c;//��֤-������������Ƿ���ȷ 
	cout<<"b-c�Ľ����"<<endl;
	cout<<d;
	
	d=b/c;//��֤/������������Ƿ���ȷ ����a*c��-��b*d���� 
	cout<<"b/c�Ľ����"<<endl;
	cout<<d;
	
	//���Ժ������� 
	t=a++;
	cout<<"a++�Ľ����"<<endl;
	cout<<a;//a�Ѿ��������Ľ�� 
	cout<<"t";
	cout<<t;//t����a����ǰ�Ľ����Ϊ�Ǻ�������
	 
	//����ǰ���Լ� 
	t=--b;
	cout<<"--b�Ľ����"<<endl;
	cout<<b;//b��t��ֵ����ͬ�� 
	cout<<"t";
	cout<<t;
	
	//����ת�����캯��
	int r=2;
	t=b+r;//�����=�����+��������� 
//��Ϊ+���������������Complex operator+(Complex a, Complex b)����������û��int�͵Ĳ���
//ϵͳ�����ת�����캯��comlex��r������Ϊt=operator+(b,comlex��r��) 
    cout<<"��ʱbΪ"<<b<<endl;//֮ǰ�Ĳ�����b�����Լ�����������ʾ���ڵ�bΪ���� 
	cout<<"t=b+r��2���Ĵ���"<<t; 
}
