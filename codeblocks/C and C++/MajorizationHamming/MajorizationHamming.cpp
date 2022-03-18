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


int Number(char * num)//计算初始值有多少位
{
    int n=0;
    char * a=new char[10];
    a=num;
    n=strlen(a);
    return n;


}
int RedundantBit(char* num)//计算冗余位
{
    int m= Number(num);
    double r=0;//需要的冗余位
    while(pow(2,r) < m + r +1 )
    {
        r++;
    }
    return r;

}

//把char的全部转给Int的数组里面去

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
int *HammingCode( char * num)//加了冗余码后的
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
    for(int i=sum; i>=0; i--)//先占位冗余位为2
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

//搞错了要逆序输出
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
    //测试是否占位成功
//     cout<<"测试占位"<<endl;
//    for(int i=0; i<all; i++)
//        cout<<hanming[i]<<"  ";
//    cout<<endl;

//测试成功！
 //-------------------
    return hanming;//返回占位以后的函数





}
void Output(char* num)//输出函数
{
    int all=Number(num)+RedundantBit(num);
    int* q=HammingCode(num);
    for(int i=0; i<all; i++)
        cout<<q[i]<<"  ";
    cout<<endl;
}
void Coding(char* num)
{
    int count1=0;//统计分组位置1的个数
    int count2=0;
    int count3=0;
    int count4=0;
    int* q=HammingCode(num);//先把指针传递过来
    int all=Number(num)+RedundantBit(num);

    //统计二进制最后一位是1的位置
    for(int i=all-1; i>=0; i=i-2)
    {
        if(q[i]==1)
            count1++;

    }

    //统计二进制倒数第二位是1的位置
    for(int i=0; i<=all; i++)
    {
        if(i>>1 &1==1 &&q[all-i]==1)
            count2++;

    }
    //统计二进制倒数第三位是1的位置
    for(int i=0; i<=all; i++)
    {
        if(i>>2 &1==1 &&q[all-i]==1)
            count3++;

    }
    //统计二进制倒数第四位是1的位置
    for(int i=0; i<=all; i++)
    {
        if(i>>3 &1==1 &&q[all-i]==1)
            count4++;

    }
//      cout<<"统计1号编码是1的个数:"<<count1<<endl;
//    cout<<"统计2号编码是1的个数:"<<count2<<endl;
//
//    cout<<"统计3号编码是1的个数:"<<count3<<endl;
//
//    cout<<"统计4号编码是1的个数:"<<count4<<endl;
//开始更改校验码1
    if(count1%2==0)
        q[all-1]=0;
    else
        q[all-1]=1;
//开始更改校验码2

    if(count2%2==0)
        q[all-2]=0;
    else
        q[all-2]=1;
//开始更改校验码3

    if(count3%2==0)
        q[all-4]=0;
    else
        q[all-4]=1;
    //开始更改校验码4

    if(count4%2==0)
        q[all-8]=0;
    else
        q[all-8]=1;
    //更改完输出
    for(int i=0; i<all; i++)
        cout<<q[i]<<"  ";
    cout<<endl;

}
//-----------------------------------------------------------------------------------------------------------------
//纠错
int ErrorCorrection(char* error)//纠错
{

    int sum=Number(error);
    int count1=0;//统计分组位置1的个数
    int count2=0;
    int count3=0;
    int count4=0;
    int* q=new int[sum];//先把指针传递过来
    for(int i=0; i<sum; i++)
    {
        q[i]=int(error[i])-48;
    }
    int begin = 0;
    int end = sum - 1;
//    while (begin < end)//开始逐个分开
//    {
//        int tmp = q[begin];
//        q[begin] = q[end];
//        q[end] = tmp;
//        begin++;
//        end--;
//    }
    cout<<"测试"<<endl;
    for(int i=0; i<sum; i++)
    {
        cout<<q[i]<<" ";
    }

//统计二进制最后一位是1的位置
    for(int i=sum-1; i>=0; i=i-2)
    {
        if(q[i]==1)
            count1++;

    }



    //统计二进制倒数第二位是1的位置
    for(int i=0; i<=sum; i++)
    {
        if(i>>1 &1==1 &&q[sum-i]==1)
            count2++;

    }
    //统计二进制倒数第三位是1的位置
    for(int i=0; i<=sum; i++)
    {
        if(i>>2 &1==1 &&q[sum-i]==1)
            count3++;

    }
    //统计二进制倒数第四位是1的位置
    for(int i=0; i<=sum; i++)
    {
        if(i>>3 &1==1 &&q[sum-i]==1)
            count4++;

    }

//    cout<<"统计1号编码是1的个数:"<<count1<<endl;
//    cout<<"统计2号编码是1的个数:"<<count2<<endl;
//
//    cout<<"统计3号编码是1的个数:"<<count3<<endl;
//
//    cout<<"统计4号编码是1的个数:"<<count4<<endl;





    int index[3]= {0};
    //先按有错的来
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



    //先判断有没有错
    if(count4%2==0 && count3%2==0 && count2%2==0 &&count1%2==0)
        cout<<"此次数据传输无错误"<<endl;
    else
    {

        cout<<"此次传输数据有错误"<<endl;
        cout<<"错误的二进制代码是：";
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
 cout<<"测试：有错误的二进制代码转换成十进制是："<<Binary<<endl;

    }


    cout<<"PS:(最右边开始才是一号位)";


    return 0;
}
//----------------------------------------------------------------
//int ConvertToBinary(int *Original)//转换成二进制
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
    cout<<"纠错"<<endl;
    char * error=new char[20];
    cin>>error;
    ErrorCorrection(error);

    return 0;
}
