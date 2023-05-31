#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char* readimage(const char* filename, int &size)//ͼƬ�ļ�����ͼƬ�Ĵ�С
{
	char* img = nullptr;
	ifstream ifs(filename, ios::in | ios::binary);//�Զ����Ʒ�ʽ��filename�ļ� 

	if (ifs)//����ļ��򿪳ɹ� 
	{
    ifs.seekg(0, ios::end);//���ڶ�дָ�뵽����ļ���βλ��
	size = ifs.tellg();//�����ļ�ָ�뵱ǰ��λ�ã���ֵ��sizeĿ���Ǻ�������ڴ�ռ䣩 
	ifs.seekg(0, ios::beg);//������ļ���ʼλ��
	img = new(nothrow) char[size];
	ifs.read(img, size);//���ļ��ж���size���ֽڣ���img
	ifs.close();
	}

	return img;//�ļ��򿪳ɹ��򷵻ط�����ڴ�ռ䣬���򷵻�nullptr 
}

void writeimage(const char* filename, char* image, int size)
{
	ofstream ofs(filename, ios::out | ios::binary);

	if (ofs)
	{
		ofs.write(image, size);//��ofs�������Ĵ��̿ռ�д��size���ֽ�
		ofs.close();
	}

}

int main(void)
{
	char *img = nullptr;
	int size = 0;
	img= readimage("in.jpeg", size);//�ļ��򿪳ɹ��򷵻ط�����ڴ�ռ䣬���򷵻�nullptr
	cout<<"ͼƬ��size��С��"<<size<<endl;
	
	size=size>>1;//���Ʋ��������ݼ��룬��ʾ��ͼƬҲֻ��һ�� 
    cout<<"ͼƬ��sizeһ��Ϊ��"<<size<<endl;
	if (img)//��img��Ϊnullptr��ʱ��
	{
		writeimage("out.jpeg", img, size);//��in.jpegд��out.jpeg 
		delete[] img;
		img=nullptr;
	}
	
	return 0; 
}
