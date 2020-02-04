#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
//经典的三次反转方法：实现数组循环右移k位
void Reverse(int* array, int p, int q)
{
	for (; p<q; p++, q--)
	{
		int temp = array[q];
		array[q] = array[p];
		array[p] = temp;
	}
}
 
void RightShift(int* array,int n, int k)
{
	k %= n;
	Reverse(array, 0, n - k - 1);
	Reverse(array, n - k, n - 1);
	Reverse(array, 0, n - 1);
}
 
int main()
{
	int array[6] = { 1,2,3,4,5,6};
	cout << "原数组："<<endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << array[i];
	}
	RightShift(array, 6,2);
	cout << endl;
	cout << "循环移位两位后的数组："<<endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << array[i];
	}
	cout << endl;
	system("pause");
	return 0;
}
