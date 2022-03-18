

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
	if(Fibonacci(n)%2==0)
        cout<<0;
    else
        cout<<1;
	cout<<endl;
    return 0;
}
