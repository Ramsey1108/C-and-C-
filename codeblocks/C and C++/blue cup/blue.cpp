#include<stdio.h>
#include <iostream>
#include <math.h>
using namespace std;



int main()
{
    int g=0;
    int a;
    cin>>a;
    //����λ��
    int number=a;
    int ans=0;
    int b=0;
    for(ans;a>0;ans++)
    {
        b=a/10;
        a=b;
    }
    //��Ҫ�������źͷֳɶ��ٶ�
    int count=int(ans / 3);
    int m=count;
    int count2=ans % 3;
    int c[count]={0};//���ô��Ƭ�ε���������

    c[0]=number / pow(1000,count);//��һ��
    int t[ans]={0};
    int w[count+1]={0};

  while(number>0)//�Ӻ���ǰ��λȡ��
  {

      t[g]=number % 10;

      number=number / 10;
      g++;

  }


//��λΪһ�δ�ӡ
w[0]=c[0];
for(int i=1;i<count+1;i++)
{

    w[i]=t[3*m-1]*100+t[3*m-2]*10+t[3*m-3]*1;
    m--;

}
  for(int i=0;i<count;i++)
{
    if(w[i]==0)
    {
        cout<<"";
    }
    else
        {
            cout<<w[i];
            cout<<",";
        }


}
cout<<w[count];




    return 0;


}
