#include<iostream>

using namespace std;

class circle
{
public:
	circle()=default;
	double rr()
	{
		cout<<"��������뾶r"<<endl;
		cin>>r;
		return r;
	 } 
	 double Girth()
	 {
	 	girth=2*r*3.1415926;//�����ܳ� 
	 	cout<<"�ܳ��ǣ�"<<girth<<endl;
	 	return girth;
	 }
	 double Area()
	 {
	 	area=3.1415926*r*r;//������� 
	 	cout<<"����ǣ�"<<area<<endl;
	 	return area; 
	 }
private:
    double r=0;//�뾶 
    double area=0;//��� 
    double girth=0;//�ܳ� 
};
int main(void)
{
	circle a;
	a.rr();
	a.Girth();
	a.Area();
	return 0; 
}
