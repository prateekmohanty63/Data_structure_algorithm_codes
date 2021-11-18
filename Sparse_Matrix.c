#include<stdio.h>
#include<stdlib.h>


struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int n;
    int m;
    int num;
    struct Element *ele;

};

void create(struct Sparse *s)
{
    printf("ENTER THE DIMESIONS: ");
    scanf("%d %d",&s->n,&s->m);
    printf("NUMBER OF NON ZERO ELEMENTS: ");
    scanf("%d",&s->num);
    s->ele=(struct Element *)malloc(s->num*sizeof(struct Element));
    printf("ENTER NON ZERO ELEMENTS: ");
    for(int i=0;i<s->num;i++)
    {
        scanf("%d %d %d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }


}

struct Sparse * add(struct Sparse *s,struct Sparse *e)
{
     struct Sparse *r;
     int i=j=k=0;

     sum=(struct Sparse *)malloc(sizeof(struct Sparse));
     sum->ele=(struct Element *)malloc((s1->num + s2->num)*sizeof(struct Element));

     while(i<s1->num && j<s2->num)
     {
         if(s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++]=s1->ele[i++].i;
         else if(s2->ele[j].i < s1->ele[i].i)
            sum->ele[k++]=s2->ele[j++].i;

         else{
            if(s1->ele[i].j < s2->ele[j].j)
            sum->ele[k++]=s1->ele[i++].j;
         else if(s2->ele[j].j < s1->ele[i].j)
            sum->ele[k++]=s2->ele[j++].j;
         else
         {
             sum->ele[k]=s1->ele[i];
             sum->ele[k++]=s1->ele[i++].x+s2->ele[j++].x;
         }
         }
     }

     for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
     for(;j<s2->num;j++)sum->ele[k++]=s2->ele[k];
     sum->m=s1->m;
     sum->n=s2->n;
     sum->num=k;

}

void Display(struct Sparse s)
{
    int k=0;
    for(int i=0;i<s.n;i++)
    {
        for(int j=0;j<s.m;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
            {
                printf("%d ",s.ele[k++].x);
            }
            else
                printf("0 ");
        }
          printf("\n");
    }
}

int main()
{
      struct Sparse s;

      create(&s);
      Display(s);
}
