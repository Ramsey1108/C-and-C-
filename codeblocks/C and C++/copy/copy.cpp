// 쳲���������.cpp: ����Ŀ�ļ���


#include<stdio.h>
#include <iostream>
using namespace std;
int Fibonacci(int n)
{
	if(n == 1||n ==2)

	{

		return 1;

	}

	else

	{

		return Fibonacci(n-1) + Fibonacci(n-2);

	}
}




int main()
{
	int n;
    cout<<"����������Ҫ��쳲�������ǰn��"<<endl;
	cout<<"������n����ֵ��n>0��";
	cin>>n;
	Fibonacci(n);
	for(int i=1;i<=n;i++)
		cout<<Fibonacci(i)<<"  ";
	cout<<endl;
    return 0;
}
