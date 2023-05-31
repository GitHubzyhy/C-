#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>

using namespace std;

void text1()//输入迭代器
{
	/*输入迭代器只用于顺序访问，只能用于单遍扫描法，解引用运算符只会出现在赋值运算符的右侧  
	当创建了一个流迭代器时候，必须指定  将要读写的类型必须定义了输入运算符，当创建了一个istream_iterator时可以
	将它绑在一个流上，当默认初始化的时候，就创建了一个可以当作尾后值使用的迭代器 
	*/
	vector<int>vec1;
	istream_iterator<int>in_iter(cin);//绑定到一个流上,从cin读取int 
	istream_iterator<int>eof;//istream的尾后迭代器 
//输入	
	while(in_iter!=eof)//一旦关联的流遇到文件尾或遇到I/O错误，迭代器的值就与尾后迭代器相等 
	vec1.push_back(*in_iter++);//后置递增运算符读取流，返回迭代器的旧值，解引用迭代器，获得从流读取的前一个值 
//输出 
	for(auto result:vec1)
	cout<<result<<" ";
//	
//	vector<int>vec2(in_iter,eof);//从迭代器范围构造vec 
//	for(auto result:vec2)
//	cout<<result<<" ";
}
int main()
{
	//使用算法操作流迭代器 
//	istream_iterator<int>in(cin),eof;
//	cout<<accumulate(in,eof,0)<<endl;
	text1();
	
}
