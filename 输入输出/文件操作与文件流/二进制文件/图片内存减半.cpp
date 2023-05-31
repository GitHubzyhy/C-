#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char* readimage(const char* filename, int &size)//图片文件名，图片的大小
{
	char* img = nullptr;
	ifstream ifs(filename, ios::in | ios::binary);//以二进制方式打开filename文件 

	if (ifs)//如果文件打开成功 
	{
    ifs.seekg(0, ios::end);//调节读写指针到相对文件结尾位置
	size = ifs.tellg();//返回文件指针当前的位置（赋值给size目的是后面分配内存空间） 
	ifs.seekg(0, ios::beg);//相对于文件开始位置
	img = new(nothrow) char[size];
	ifs.read(img, size);//从文件中读（size个字节）到img
	ifs.close();
	}

	return img;//文件打开成功则返回分配的内存空间，否则返回nullptr 
}

void writeimage(const char* filename, char* image, int size)
{
	ofstream ofs(filename, ios::out | ios::binary);

	if (ofs)
	{
		ofs.write(image, size);//从ofs所关联的磁盘空间写入size个字节
		ofs.close();
	}

}

int main(void)
{
	char *img = nullptr;
	int size = 0;
	img= readimage("in.jpeg", size);//文件打开成功则返回分配的内存空间，否则返回nullptr
	cout<<"图片的size大小："<<size<<endl;
	
	size=size>>1;//右移操作让数据减半，显示的图片也只有一半 
    cout<<"图片的size一半为："<<size<<endl;
	if (img)//当img不为nullptr的时候
	{
		writeimage("out.jpeg", img, size);//将in.jpeg写到out.jpeg 
		delete[] img;
		img=nullptr;
	}
	
	return 0; 
}
