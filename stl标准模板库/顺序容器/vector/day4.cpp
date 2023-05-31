#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int>num;
	int element;
	while(cin>>element)
	num.push_back(element);
	sort(num.begin(),num.end());//排序算法
	for(int i=0;i<num.size();i++)//输出，利用下表访问 
	cout<<num[i]<<" "; 
	cout.put('\n');

	//第二部分 
	vector<int>vec1,vec2(10,6),vec3(vec2.begin(),vec2.begin()+3);
	cout<<"输出vec1"<<endl;
	for(auto i=vec1.begin();i!=vec1.end();i++)
	cout<<*i<<" ";
	cout.put('\n');
	
		cout<<"输出vec2"<<endl;
		for(auto i=vec2.begin();i!=vec2.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
		
		cout<<"输出vec3"<<endl;
		for(auto i=vec3.begin();i!=vec3.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
		//测试添加和插入成员函数 
		vec1.push_back(2);
		vec1.push_back(4);
		vec1.insert(vec1.begin()+1,5);
		vec1.insert(vec1.begin()+1,vec3.begin(),vec3.end());
		cout<<"输出vec1"<<endl;
		for(auto i=vec1.begin();i!=vec1.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
				
				
		//测试赋值成员函数 
		vec2.assign(8,1);	
         cout<<"输出vec2"<<endl;
		for(auto i=vec2.begin();i!=vec2.end();i++)
		cout<<*i<<" ";
		cout.put('\n');		
		//测试引用类成员函数
		cout<<"vec1.front(): "<<vec1.front() <<endl;
		cout<<"vec1.back(): "<<vec1.back()<<endl;
		//测试移除和删除
		vec1.pop_back();
		cout<<"输出vec1(pop_back)"<<endl;
		for(auto i=vec1.begin();i!=vec1.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
		
		vec1.erase(vec1.begin()+1,vec1.end()-2);
		cout<<"输出vec1"<<endl;
		for(auto i=vec1.begin();i!=vec1.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
						
			//显示序列状态信息 capacity()最多添加多少个元素会倒置容器重新分配内存 
		cout<<"vec1.capacity(): "<<vec1.capacity()<<endl;
		cout<<"vec1.max_size(): "<<vec1.max_size()<<endl;
		cout<<"vec1.size(): "<<vec1.size()<<endl;
		cout<<"vec1.empty(): "<<vec1.empty()<<endl;
		//容器的运算 
		cout<<"vec1==vec3: "<<(vec1==vec3)<<endl;//相等返回1，不相等返回0 
		cout<<"vec1<=vec3: "<<(vec1<=vec3)<<endl;
	return 0;
}
