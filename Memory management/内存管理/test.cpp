#include<iostream>
using namespace std;


//int globalVar = 1;//main����֮ǰ��ʼ�������Ķ����ã���������ȫ��
//static int staticGlobalVar = 1;//����һ��ȫ�ֱ������������Բ�һ��
////��һ��ȫ�ļ����ã��ڶ����ڵ�ǰ�ļ��ɼ�
//void Test1()
//{
//	static int staticVar = 1;//���е����ٳ�ʼ��������������Test������
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//
//void Test2()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)��
//	free(p3);
//}
////40 5 4 4 4 4����8(û˵32λ������64λ��)
//int main()
//{
//
//	return 0;
//}

//int main()
//{
//	//C����
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)*10);
//
//	free(p1);
//	free(p3);
//	//C++������
//	//int* p2 = new int;
//	int* p2 = new int(10);//����һ��int4���ֽڿռ䣬��ʼ����10
//	int* p4 = new int[10];//����10��int��40���ֽڿռ�
//
//	delete p2;
//	delete []p4;
//
//	return 0;
//}


class A
{
public:
	A()
	{
		_a = 10;
	}
private:
	int _a;
};

//����malloc��free��new��delete�������
//1�����������������ͣ�Ч��һ��
//2�������Զ������ͣ�Ч����һ��--->mallocֻ����ռ䣬new����ռ�+���캯����ʼ��
//freeֻ�ͷſռ䣬delete����+�ͷſռ�
int main()
{
	A* p1 = (A*)malloc(sizeof(A));//ֻ������ռ�
	A* p4 = new A;//����ռ�+���캯����ʼ��
	free(p1);//�ͷſռ�
	delete p4;//��������+�ͷſռ�
	return 0;
}