#include<iostream>
using namespace std;


//int globalVar = 1;//main函数之前初始化，在哪都能用，作用域是全局
//static int staticGlobalVar = 1;//与上一个全局变量的链接属性不一样
////第一个全文件可用，第二个在当前文件可见
//void Test1()
//{
//	static int staticVar = 1;//运行到这再初始化，作用域是再Test函数中
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
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}
////40 5 4 4 4 4或者8(没说32位机还是64位机)
//int main()
//{
//
//	return 0;
//}

//int main()
//{
//	//C函数
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)*10);
//
//	free(p1);
//	free(p3);
//	//C++操作数
//	//int* p2 = new int;
//	int* p2 = new int(10);//申请一个int4个字节空间，初始化成10
//	int* p4 = new int[10];//申请10个int的40个字节空间
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

//有了malloc和free，new和delete意义何在
//1、对于上面内置类型，效果一样
//2、对于自定义类型，效果不一样--->malloc只申请空间，new申请空间+构造函数初始化
//free只释放空间，delete析构+释放空间
int main()
{
	A* p1 = (A*)malloc(sizeof(A));//只是申请空间
	A* p4 = new A;//申请空间+构造函数初始化
	free(p1);//释放空间
	delete p4;//析构函数+释放空间
	return 0;
}