#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


int Number(int num)//�����ʼֵ�ж���λ
{
    int Count=0;
    while(num>0)
    {
        // num=num%10;
        num=num/10;
        Count++;
    }
    return Count;

}

int *ReverseOrder(int num)
{
    int sum=Number(num);
    int *test=new int[sum];
    for(int i=0; i<sum; i++)
    {
        test[i]=num%10;
        num=num/10;
    }

    return test;

}
int RedundantBit(int num)//��������λ
{
    int m= Number(num);
    double r=0;//��Ҫ������λ
    while(pow(2,r) < m + r +1 )
    {
        r++;
    }
    return r;

}
int *HammingCode( int num)//������������
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
    return hanming;//����ռλ�Ժ�ĺ���

}
void Output(int num)//�������
{
    int all=Number(num)+RedundantBit(num);
    int* q=HammingCode(num);
    for(int i=0; i<all; i++)
        cout<<q[i]<<"  ";
    cout<<endl;
}
void Coding(int num)
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

int ErrorCorrection(int error)//����
{

    int sum=Number(error);
    int count1=0;//ͳ�Ʒ���λ��1�ĸ���
    int count2=0;
    int count3=0;
    int count4=0;
    int* q=new int[sum];//�Ȱ�ָ�봫�ݹ���
    for(int i=0; i<sum; i++)
    {
        q[i]=error%10;
        error=error/10;
    }
    int begin = 0;
    int end = sum - 1;
    while (begin < end)//��ʼ����ֿ�
    {
        int tmp = q[begin];
        q[begin] = q[end];
        q[end] = tmp;
        begin++;
        end--;
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
        for(int i=0; i<=3;i++)
            cout<<index[i]<<" ";

    }
    cout<<endl;
    cout<<"PS:�Լ�ת���ɶ����ơ�����";








}
int main()
{
    int a;
    cin>>a;

cout<<"����"<<endl;
    Coding(a);
    int b;
    cout<<"����"<<endl;
    cin>>b;//���ʮλ ����int���ȶ�ʧ
    ErrorCorrection(b);
    return 0;
}
