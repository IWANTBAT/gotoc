//#include <iostream>
//using namespace std;
//int add(int x, int y){
//	return x + y;
//}
//int main()
//{
//	int a, b;
//	cout<< "Enter a,b\n";
//	cin>>a>>b;
//	int c = add(a, b);
//	cout << "a+b=" << c << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A{
//private:int a;
//public :
//	A(int i)
//	{
//		a = i;
//	}
//	int f1(){
//		return a + a;
//	}
//	int f2(){
//		return a*a;
//	}
//
//};
//
//int main(){
//	A x(5);
//	cout << x.f1() << endl;
//	cout << x.f2()<< endl;
//	return 0;
//}

#include<iostream>
using namespace std;
static int a = 5;
int  main()
{
	static int b;
	double d;
	char ch = 'h';
	cout << a << ',' << b << ',' << d << ',' << ch << endl;
	a = 10;
	b = 20;
	d = 30.5;
	ch = 'm';
	cout << a << ',' << b << ',' << d << ',' << ch << endl;
	cout << &a << endl;
	return 0;
}

