#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


int len=0;//������ֵ�λ��
double ReverseOrder=0;//������������
int LastNumber=0;//�粻�Ǿ�����ٴ���ȥ
int Palindrome(int a)
{

    int number=a;//����������ʱ�������洫����������
    int number1=a;
    while(number>0)
    {
        number=number/10;
        len++;

    }

    int NumberDigits[len]= {0}; //����һ�������λʮλ��λ������;
    for(int i=0; i<len; i++) //����ӵ�һλ��ʼ�ֱ𱣴��λʮλ��
    {
        NumberDigits[i]=a%10;
        a=a/10;
    }
    //��λȡ��Ȼ������������
    {
        int i=0;
        while(len>0)
        {

            ReverseOrder=ReverseOrder+ double(NumberDigits[i]*pow(10,len-1));

            i++;
            len--;
        }

    }

//��ʱ�Ѿ��������Զ�������ֺ������������ˣ����ڿ�ʼ�ж�
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
