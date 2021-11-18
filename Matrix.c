#include<stdio.h>
#include<stdlib.h>


struct Matrix
{
    int *A;
    int n;
};

void set_diagonal(struct Matrix *m,int i,int j,int x)
{
    if(i==j)
        m->A[i]=x;
}

void set_lower_tri_rowm(struct Matrix *m,int i,int j,int x)
{
    if(i>=j)
    m->A[i*(i-1)/2+j-1]=x;

}

void set_lower_tri_colm(struct Matrix *m,int i,int j,int x)
{
    if(i>=j)
    m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;

}


int get(struct Matrix *m,int i,int j)
{
    if(i==j)
        return m->A[i];
    return 0;
}

void get_lower_tri_rowm(struct Matrix *m,int i,int j)
{
    if(i>=j)
        return m->A[i*(i-1)+j-1];
    return 0;
}


void get_lower_tri_colm(struct Matrix *m,int i,int j)
{
    if(i>=j)
        return m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j];
    return 0;
}

/// Diagonal martix
void Display(struct Matrix *m)
{
    for(int i=0;i<m->n;i++)
    {
        for(int j=0;j<m->n;j++)
            if(i==j)
            printf("%d",m->A[i]);
             else
                printf("0");

       printf("\n");
    }

}

void Display_lower_tri_rowm(struct Matrix *m)
{
    for(int i=1;i<=m->n;i++)
    {
        for(int j=0;j<=m->n;j++)
        {
            if(i>=j)
                printf("%d ",m->A[i*(i-1)/2+j-1]);
            else
                printf(0);
        }
    }
}

void Display_lower_tri_colm(struct Matrix *m)
{
    for(int i=1;i<=m->n;i++)
    {
        for(int j=0;j<=m->n;j++)
        {
            if(i>=j)
                printf("%d ",m->n*(j-1)+(j-2)*(j-1)/2+i-j]);
            else
                printf(0);
        }
    }
}

int main()
{

    struct Matrix m;
    printf("ENTER THE DIMESION OF MATRIX: ");
    scanf("%d",&m.n);
    m.A=(int*)malloc(m.n*(m.n+1)/2*sizeof(int));


   /* set(&m,1,1,5);
    set(&m,0,0,6);
    set(&m,2,2,7);
    set(&m,3,3,8);
    set(&m,4,4,9);

    printf("%d",get(&m,0,0));*/

    int x;

    printf("ENTER ALL THE ELEMENTS:  ");

    for(int i=1;i<=m.n;i++)
    {
        for(int j=1;j<=m.n;j++)
        {
            scanf("%d",&x);
            set_lower_tri(&m,i,j,x);
        }
    }
    printf("\n");



    Display_lower_tri(&m);

    return 0;
}
