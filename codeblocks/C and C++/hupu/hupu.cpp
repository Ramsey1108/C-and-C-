#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


int len=0;//存放数字的位数
double ReverseOrder=0;//存放逆序的数字
int LastNumber=0;//如不是就相加再传过去
int Palindrome(int a)
{

    int number=a;//找两个个临时变量保存传过来的数字
    int number1=a;
    while(number>0)
    {
        number=number/10;
        len++;

    }

    int NumberDigits[len]= {0}; //创建一个保存个位十位百位的数组;
    for(int i=0; i<len; i++) //数组从第一位开始分别保存个位十位等
    {
        NumberDigits[i]=a%10;
        a=a/10;
    }
    //逐位取出然后求逆序数字
    {
        int i=0;
        while(len>0)
        {

            ReverseOrder=ReverseOrder+ double(NumberDigits[i]*pow(10,len-1));

            i++;
            len--;
        }

    }

//此时已经求出来他远来的数字和逆序后的数字了，现在开始判断
//    if(number1==ReverseOrder)
//    {
//        //cout<<number1<<"  is a Palindrome"<<endl;
//        return 1;
//
//    }
//    else
//    {
//        LastNumber=number1+ReverseOrder;
//
//
//        return LastNumber;
//    }
return ReverseOrder;
}
int main()
{
    int n,f=1;
    cin>>n;
    while(f)
    {
        if(Palindrome(n)==n)
            f=0;
        else
        {
             n+=Palindrome(n);
            cout<<Palindrome(n);
        }

    }



}
