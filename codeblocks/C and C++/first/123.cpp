#include<stdio.h>
#include <iostream>

using namespace std;

int main()
{
//    int num;
//    scanf("%d", &num);
//    int b=num;
//    b=b>>(3-1)&1;
//    cout<<b;
//    return 0;
    //��10��1010���ĵ���λ��


    for(int i=0;i<16;i++)
        {
            if(i>>3 &1==1)
                cout<<i<<endl;
        }
}
