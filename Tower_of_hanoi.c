#include<stdio.h>

void TOH(int n,int a,int b,int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("Move blocks from %d tower to %d tower\n",a,c);
        TOH(n-1,b,a,c);
    }

}

int main()
{
    TOH(4,1,2,3);
}
