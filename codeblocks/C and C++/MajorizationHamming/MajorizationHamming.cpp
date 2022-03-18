#include<stdio.h>
#include <iostream>
#include <math.h>
#include<string.h>
#include <stdlib.h>
using namespace std;
// char * a=new char[10];
//  cin>>a;
////  cout<<strlen(a);
//for(int i=0;i<strlen(a);i++)
//    cout<<int(a[i])-48<<endl;


int Number(char * num)//�����ʼֵ�ж���λ
{
    int n=0;
    char * a=new char[10];
    a=num;
    n=strlen(a);
    return n;


}
int RedundantBit(char* num)//��������λ
{
    int m= Number(num);
    double r=0;//��Ҫ������λ
    while(pow(2,r) < m + r +1 )
    {
        r++;
    }
    return r;

}

//��char��ȫ��ת��Int����������ȥ

int *ReverseOrder(char* num)
{
    int sum=Number(num);
    int *test=new int[sum];
    for(int i=0; i<sum; i++)
    {
        test[i]=int(num[i])-48;
    }

    //-------------------
      int begin = 0;
    int end = sum - 1;
    while (begin < end)
    {
        int tmp = test[begin];
        test[begin] = test[end];
        test[end] = tmp;
        begin++;
    }
         //-------------------
    return test;

}
int *HammingCode( char * num)//������������
{
    int n=Number(num);
    int *TestCopy=ReverseOrder( num);
    int sum=Number(num)+RedundantBit(num);
    int all=sum;
    int *hanming =new int[sum];
    for(int i=0; i<sum; i++)
    {
        hanming[i] = 0;


    }
    for(int i=sum; i>=0; i--)//��ռλ����λΪ2
    {

        if (((i) & (i-1))== 0  )
            hanming[i-1]=2;
        else
        {
//            hanming[i-1]=num%10;
//            num=num/10;
            hanming[i-1]=TestCopy[n-1];
            n--;

        }

    }

//�����Ҫ�������
 //-------------------
    int begin = 0;
    int end = sum - 1;
    while (begin < end)
    {
        int tmp = hanming[begin];
        hanming[begin] = hanming[end];
        hanming[end] = tmp;
        begin++;
        end--;
    }
     //-------------------
     //-------------------
    //�����Ƿ�ռλ�ɹ�
//     cout<<"����ռλ"<<endl;
//    for(int i=0; i<all; i++)
//        cout<<hanming[i]<<"  ";
//    cout<<endl;

//���Գɹ���
 //-------------------
    return hanming;//����ռλ�Ժ�ĺ���





}
void Output(char* num)//�������
{
    int all=Number(num)+RedundantBit(num);
    int* q=HammingCode(num);
    for(int i=0; i<all; i++)
        cout<<q[i]<<"  ";
    cout<<endl;
}
void Coding(char* num)
{
    int count1=0;//ͳ�Ʒ���λ��1�ĸ���
    int count2=0;
    int count3=0;
    int count4=0;
    int* q=HammingCode(num);//�Ȱ�ָ�봫�ݹ���
    int all=Number(num)+RedundantBit(num);

    //ͳ�ƶ��������һλ��1��λ��
    for(int i=all-1; i>=0; i=i-2)
    {
        if(q[i]==1)
            count1++;

    }

    //ͳ�ƶ����Ƶ����ڶ�λ��1��λ��
    for(int i=0; i<=all; i++)
    {
        if(i>>1 &1==1 &&q[all-i]==1)
            count2++;

    }
    //ͳ�ƶ����Ƶ�������λ��1��λ��
    for(int i=0; i<=all; i++)
    {
        if(i>>2 &1==1 &&q[all-i]==1)
            count3++;

    }
    //ͳ�ƶ����Ƶ�������λ��1��λ��
    for(int i=0; i<=all; i++)
    {
        if(i>>3 &1==1 &&q[all-i]==1)
            count4++;

    }
//      cout<<"ͳ��1�ű�����1�ĸ���:"<<count1<<endl;
//    cout<<"ͳ��2�ű�����1�ĸ���:"<<count2<<endl;
//
//    cout<<"ͳ��3�ű�����1�ĸ���:"<<count3<<endl;
//
//    cout<<"ͳ��4�ű�����1�ĸ���:"<<count4<<endl;
//��ʼ����У����1
    if(count1%2==0)
        q[all-1]=0;
    else
        q[all-1]=1;
//��ʼ����У����2

    if(count2%2==0)
        q[all-2]=0;
    else
        q[all-2]=1;
//��ʼ����У����3

    if(count3%2==0)
        q[all-4]=0;
    else
        q[all-4]=1;
    //��ʼ����У����4

    if(count4%2==0)
        q[all-8]=0;
    else
        q[all-8]=1;
    //���������
    for(int i=0; i<all; i++)
        cout<<q[i]<<"  ";
    cout<<endl;

}
//-----------------------------------------------------------------------------------------------------------------
//����
int ErrorCorrection(char* error)//����
{

    int sum=Number(error);
    int count1=0;//ͳ�Ʒ���λ��1�ĸ���
    int count2=0;
    int count3=0;
    int count4=0;
    int* q=new int[sum];//�Ȱ�ָ�봫�ݹ���
    for(int i=0; i<sum; i++)
    {
        q[i]=int(error[i])-48;
    }
    int begin = 0;
    int end = sum - 1;
//    while (begin < end)//��ʼ����ֿ�
//    {
//        int tmp = q[begin];
//        q[begin] = q[end];
//        q[end] = tmp;
//        begin++;
//        end--;
//    }
    cout<<"����"<<endl;
    for(int i=0; i<sum; i++)
    {
        cout<<q[i]<<" ";
    }

//ͳ�ƶ��������һλ��1��λ��
    for(int i=sum-1; i>=0; i=i-2)
    {
        if(q[i]==1)
            count1++;

    }



    //ͳ�ƶ����Ƶ����ڶ�λ��1��λ��
    for(int i=0; i<=sum; i++)
    {
        if(i>>1 &1==1 &&q[sum-i]==1)
            count2++;

    }
    //ͳ�ƶ����Ƶ�������λ��1��λ��
    for(int i=0; i<=sum; i++)
    {
        if(i>>2 &1==1 &&q[sum-i]==1)
            count3++;

    }
    //ͳ�ƶ����Ƶ�������λ��1��λ��
    for(int i=0; i<=sum; i++)
    {
        if(i>>3 &1==1 &&q[sum-i]==1)
            count4++;

    }

//    cout<<"ͳ��1�ű�����1�ĸ���:"<<count1<<endl;
//    cout<<"ͳ��2�ű�����1�ĸ���:"<<count2<<endl;
//
//    cout<<"ͳ��3�ű�����1�ĸ���:"<<count3<<endl;
//
//    cout<<"ͳ��4�ű�����1�ĸ���:"<<count4<<endl;





    int index[3]= {0};
    //�Ȱ��д����
    if(count4%2==0)
        index[0]=0;
    else
        index[0]=1;

    if(count3%2==0)
        index[1]=0;
    else
        index[1]=1;

    if(count2%2==0)
        index[2]=0;
    else
        index[2]=1;

    if(count1%2==0)
        index[3]=0;
    else
        index[3]=1;



    //���ж���û�д�
    if(count4%2==0 && count3%2==0 && count2%2==0 &&count1%2==0)
        cout<<"�˴����ݴ����޴���"<<endl;
    else
    {

        cout<<"�˴δ��������д���"<<endl;
        cout<<"����Ķ����ƴ����ǣ�";
        for(int i=0; i<=3; i++)
        {
             cout<<index[i]<<" ";

        }
         cout<<endl;

         int Binary=0;
         int n=0;
        for(int i=3;i>=0;i--)
        {
            Binary=Binary + index[i]*pow(2,n);
            n++;
        }
 cout<<"���ԣ��д���Ķ����ƴ���ת����ʮ�����ǣ�"<<Binary<<endl;

    }


    cout<<"PS:(���ұ߿�ʼ����һ��λ)";


    return 0;
}
//----------------------------------------------------------------
//int ConvertToBinary(int *Original)//ת���ɶ�����
//{
//        int *Final=
//}

int main()
{
    char * num=new char[10];
    cin>>num;
    cout<<endl;
    HammingCode(num);
    Coding(num);
   // Coding(num);
    cout<<"����"<<endl;
    char * error=new char[20];
    cin>>error;
    ErrorCorrection(error);

    return 0;
}
