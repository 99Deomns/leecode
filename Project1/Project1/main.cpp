#include "money.h"
#include <fstream>
using namespace std;


int main() {
	{
		int a, b;
		cout << "how much?\n" << endl;
		cin >> a >> b;
		char aaa[] = "aaa\0";
		char bbb[] = "bbb\0";
		char hhh[] = "hha\0";
		money h1(a, aaa);
		money h2(b, bbb);
		money h;
		
		h = h1 + h2;//str end
		//这里还需要重载=，否则 给h赋值的是一个临时对象完成本句话之后h1+h2的临时对象就会被析构，此时重载h进行深拷贝

		//cout << "LKK   " << h << endl;


		//money copy = h1;
		//change_name(copy);
		//copy.pri();
		//h1.pri();

		cout << "***" << endl;
	}//aaa bbb  end
	
	return 0;
}
/*
#include <iostream>
using namespace std;
class A
{
public:
	A(int _size) : size(_size) { data = new int[size]; } //假如其中有一段动态分配的内存
	int Get_Val() { return *data; }
	int* Get_Val_add() { return data; }
	A() {}
	A(const A& _A) : size(_A.size) { data = new int[size]; } //深拷贝
	~A() { delete[] data; data = NULL; } //析构时释放资源
private:
	int* data;
	int size;
};
int main()
{
	A a(5);
	A b(a);
	cout << a.Get_Val() << endl;
	cout << b.Get_Val() << endl;

	return 0;
}
*/