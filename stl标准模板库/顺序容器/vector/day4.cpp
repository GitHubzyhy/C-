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
	sort(num.begin(),num.end());//�����㷨
	for(int i=0;i<num.size();i++)//����������±���� 
	cout<<num[i]<<" "; 
	cout.put('\n');

	//�ڶ����� 
	vector<int>vec1,vec2(10,6),vec3(vec2.begin(),vec2.begin()+3);
	cout<<"���vec1"<<endl;
	for(auto i=vec1.begin();i!=vec1.end();i++)
	cout<<*i<<" ";
	cout.put('\n');
	
		cout<<"���vec2"<<endl;
		for(auto i=vec2.begin();i!=vec2.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
		
		cout<<"���vec3"<<endl;
		for(auto i=vec3.begin();i!=vec3.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
		//������ӺͲ����Ա���� 
		vec1.push_back(2);
		vec1.push_back(4);
		vec1.insert(vec1.begin()+1,5);
		vec1.insert(vec1.begin()+1,vec3.begin(),vec3.end());
		cout<<"���vec1"<<endl;
		for(auto i=vec1.begin();i!=vec1.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
				
				
		//���Ը�ֵ��Ա���� 
		vec2.assign(8,1);	
         cout<<"���vec2"<<endl;
		for(auto i=vec2.begin();i!=vec2.end();i++)
		cout<<*i<<" ";
		cout.put('\n');		
		//�����������Ա����
		cout<<"vec1.front(): "<<vec1.front() <<endl;
		cout<<"vec1.back(): "<<vec1.back()<<endl;
		//�����Ƴ���ɾ��
		vec1.pop_back();
		cout<<"���vec1(pop_back)"<<endl;
		for(auto i=vec1.begin();i!=vec1.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
		
		vec1.erase(vec1.begin()+1,vec1.end()-2);
		cout<<"���vec1"<<endl;
		for(auto i=vec1.begin();i!=vec1.end();i++)
		cout<<*i<<" ";
		cout.put('\n');
						
			//��ʾ����״̬��Ϣ capacity()�����Ӷ��ٸ�Ԫ�ػᵹ���������·����ڴ� 
		cout<<"vec1.capacity(): "<<vec1.capacity()<<endl;
		cout<<"vec1.max_size(): "<<vec1.max_size()<<endl;
		cout<<"vec1.size(): "<<vec1.size()<<endl;
		cout<<"vec1.empty(): "<<vec1.empty()<<endl;
		//���������� 
		cout<<"vec1==vec3: "<<(vec1==vec3)<<endl;//��ȷ���1������ȷ���0 
		cout<<"vec1<=vec3: "<<(vec1<=vec3)<<endl;
	return 0;
}
