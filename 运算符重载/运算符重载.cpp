#include<iostream>
using namespace std;

class Complex
{
public:
	Complex()=default;
	Complex(int Real,int Img):real(Real),img(Img){}
	~Complex()=default; 
	Complex operator-(const Complex a);//减法
	Complex operator/(const Complex a);//除法
	
	friend ostream& operator<<(ostream &out,Complex &t);//重载流插入运算符 （友元） 
	friend istream& operator>>(istream &input,Complex &t);//重载流提取运算符 （友元）
	friend Complex operator+(const Complex a,const Complex b);//重载+ 
	friend Complex operator*(const Complex a,const Complex b);//重载*
	friend Complex& operator--(Complex &p);//重载前置-- 
	Complex operator++(int);//重载后置++ 
	
	Complex(double x);//转换构造函数 
private:	
	double real;//定义的实部
	double img;//定义的虚部 
};
Complex  Complex::operator-(Complex a) 
{
	Complex r;//定义的临时对象 
	r.real=real-a.real; 
	r.img=img-a.img;
	return r;
}
Complex Complex::operator/(Complex a)
{
	Complex r;
	r.real=real*a.real-img*a.img;//（a*c）-（b*d）
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
	cout<<"请你输入real(实数)"<<endl; 
	input>>t.real;
	cout<<"请你输入img(虚部)"<<endl; 
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

Complex  Complex::operator++(int)//后置++ （int）是区别前置和后置的 
{
	Complex temp(*this);
	real++;
	img++;
	return temp; //因为是后置所以返回之前的（c++将这样的对象作为右值处理，使其不能用在赋值运算符的左侧） 
}
Complex& operator--(Complex &p)//前置-- 
{
	p.real--;
	p.img--;
	return p;
}
Complex::Complex(double x)//转换构造函数 
{
	real=x;
	img=0;
}

int main(void)
{
	Complex a,b(1,2),c(2,2),d,t;
	cout<<"b的结果是"<<endl;
	cout<<b<<endl;
	cout<<"c的结果是"<<endl;
	cout<<c<<endl; 
	 
	  
	cout<<"输入复数a"<<endl;
	cin>>a;
	cout<<a;
	d=b+c;//验证+的重载是否正确 
	cout<<"b+c的结果是"<<endl;
	cout<<d;
	
	d=b*c;//验证*的重载运算符是否正确 
	cout<<"b*c的结果是"<<endl;
	cout<<d;
	
	d=b-c;//验证-的重载运算符是否正确 
	cout<<"b-c的结果是"<<endl;
	cout<<d;
	
	d=b/c;//验证/的重载运算符是否正确 （（a*c）-（b*d）） 
	cout<<"b/c的结果是"<<endl;
	cout<<d;
	
	//测试后置自增 
	t=a++;
	cout<<"a++的结果是"<<endl;
	cout<<a;//a已经是自增的结果 
	cout<<"t";
	cout<<t;//t则是a自增前的结果因为是后置自增
	 
	//测试前置自减 
	t=--b;
	cout<<"--b的结果是"<<endl;
	cout<<b;//b和t的值是相同的 
	cout<<"t";
	cout<<t;
	
	//测试转换构造函数
	int r=2;
	t=b+r;//类对象=类对象+整形类对象 
//因为+法的重载运算符是Complex operator+(Complex a, Complex b)参数表里面没有int型的参数
//系统会调用转换构造函数comlex（r）处理为t=operator+(b,comlex（r）) 
    cout<<"此时b为"<<b<<endl;//之前的操作对b做过自减操作所以显示现在的b为多少 
	cout<<"t=b+r（2）的答案是"<<t; 
}
