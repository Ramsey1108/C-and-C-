// 斐波那契数列.cpp: 主项目文件。


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
    cout<<"请输入你需要的斐波那契的前n项"<<endl;
	cout<<"请输入n的数值（n>0）";
	cin>>n;
	Fibonacci(n);
	for(int i=1;i<=n;i++)
		cout<<Fibonacci(i)<<"  ";
	cout<<endl;
    return 0;
}
