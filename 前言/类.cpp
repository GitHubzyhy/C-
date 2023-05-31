#include<iostream>

using namespace std;

class circle
{
public:
	circle()=default;
	double rr()
	{
		cout<<"请你输入半径r"<<endl;
		cin>>r;
		return r;
	 } 
	 double Girth()
	 {
	 	girth=2*r*3.1415926;//计算周长 
	 	cout<<"周长是："<<girth<<endl;
	 	return girth;
	 }
	 double Area()
	 {
	 	area=3.1415926*r*r;//计算面积 
	 	cout<<"面积是："<<area<<endl;
	 	return area; 
	 }
private:
    double r=0;//半径 
    double area=0;//面积 
    double girth=0;//周长 
};
int main(void)
{
	circle a;
	a.rr();
	a.Girth();
	a.Area();
	return 0; 
}
