#include<iostream>
#include<iterator>
#include<vector>//��̬���� 
#include<list>//list���õ���˫�����������֧��������� 
using namespace std;
void text()//ȥ����ż�� 
{
	vector<int>v1={0,1,2,3,4,5,6,7,8,9};
	ostream_iterator<int> out(cout,",");//����������� 
 	vector<int>::iterator ite=v1.begin();
 	while(ite!=v1.end())//����ָ�򷵻�β������� 
 	{
	if(*ite%2)
	{
		ite=v1.insert(ite,*ite);//���������֮ǰ,����󷵻ز���ĵ�һ��Ԫ�صĵ�����
		ite+=2;//���������ֵ��ԭ����ֵ 
	} 	
	else
	ite=v1.erase(ite);//ɾ��ż��Ԫ�ط���ɾ����Ԫ�صĵ����� 
	}
	copy(v1.begin(),v1.end(),out);//����copy������� 
}
int main()
{
	int stuff[]={1,3,5,7,9};
	int more[]={2,4,6,8,2,4};
	ostream_iterator<int>out(cout," ");//����������� 
	list<int>onelist(5,2);//����һ��˫������onelist,����5��2 
	list<int>twolist;
	twolist.insert(twolist.begin(),stuff,stuff+5);
	list<int>threelist(twolist);//��twolistһ����Ԫ��
	threelist.insert(threelist.begin(),more,more+6);
 
	copy(onelist.begin(),onelist.end(),out);
		cout<<"-->onelist"<<endl;

	copy(twolist.begin(),twolist.end(),out);
		cout<<"-->twolist"<<endl; 
	
	copy(threelist.begin(),threelist.end(),out);
	    cout<<"-->threelist"<<endl; 
	
	threelist.remove(2);//ɾ������Ԫ��Ϊ2��
	copy(threelist.begin(),threelist.end(),out);
	    cout<<"-->threelistɾ��2���"<<endl;
	
	threelist.splice(threelist.begin(),onelist);//�ƶ�����
	copy(threelist.begin(),threelist.end(),out);
	    cout<<"-->threelist|onelist�ƶ�������"<<endl;
	
	cout<<"��֤splice��onelist�Ѿ�Ϊ��"<<endl;
	copy(onelist.begin(),onelist.end(),out);
		cout<<"-->onelist"<<endl;
		
	threelist.unique();//��ͬ��Ԫ�ر�ѹ��Ϊ����Ԫ��
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelistѹ�����"<<endl; 
		
	threelist.sort();//��������
	threelist.unique();//������������ѹ�� 
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist�������ѹ�����"<<endl; 
		
	twolist.sort();//��twolist����
	threelist.merge(twolist);//����ϲ�ǰ�Ѿ����򣬺ϲ���twolist�����
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist�ϲ�twolist��"<<endl; 
		
	copy(twolist.begin(),twolist.end(),out);
		cout<<"-->twolist��֤�����"<<endl; 
	threelist.reverse();//��������
	
	copy(threelist.begin(),threelist.end(),out);
		cout<<"-->threelist�ϲ�twolist��"<<endl; 
		
	text();		
	return 0;
}
