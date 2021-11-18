#include<stdio.h>
#include<stdlib.h>

struct term
{
    int coeff;
    int power;
};

struct poly
{
    int n;
    struct term *terms;
};

void create(struct poly *p)
{
    int i;
    printf("ENTER THE NUMBER OF TERMS: ");
    scanf("%d",&p->n);
    p->terms=(struct term*)malloc(p->n*sizeof(struct term));

    printf("ENTER THE TERMS: ");
    for(int i=0;i<p->n;i++)
    {
        scanf("%d %d",&p->terms[i].coeff,&p->terms[i].power);
    }
}

void display(struct poly p)
{
    for(int i=0;i<p.n;i++)
    {
        printf("%d %d",p.terms[i].coeff,p.terms[i].coeff);
    }
    printf("\n");
}

struct Poly *add(struct poly *p1,struct poly *p2)
{
    struct poly *p3;

    p3=(struct poly *)malloc(sizeof(struct poly));
    p3->terms=(struct term *)malloc((p1->n+p2->n)*sizeof(struct term));

    int i=0;
    int j=0;
    int k=0;

    while(i<p1->n && j<p2->n)
    {
        if(p1->terms[i].coeff>p2->terms[j].coeff)
            p3->terms[k++]=p1->terms[i++];
        else if(p1->terms[i].coeff<p2->terms[j].coeff)
            p3->terms[k++]=p2->terms[j++];
        else
        {
            p3->terms[k].power=p1->terms[i].power;
            p3->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    }

    for(;i<p1->n;i++)
        p3->terms[k++]=p1->terms[i];
    for(;j<p2->n;j++)
        p3->terms[k++]=p2->terms[j];
    p3->n=k;
    return p3;
}

int main()
{
     struct poly p1,p2,*p3;
     create(&p1);
     create(&p2);

    p3=add(&p1,&p2);
    display(*p3);

}












   /* int deg1,deg2;
    printf("ENTER THE DEGREE OF FIRST POLYNOMIAL: \n");
    scanf("%d",&deg1);

    printf("ENTER THE DEGREE OF SECOND POLYNOMIAL: \n");
    scanf("%d",&deg2);



    int coeff1[deg1];
    int power1[deg1];

    int coeff2[deg2];
    int power2[deg2];

    for(int r=0;r<deg1;r++)
    {
        scanf("%d",&coeff1[r]);
        scanf("%d",&power1[r]);
    }

    for(int l=0;l<deg2;l++)
    {
        scanf("%d",&coeff2[l]);
        scanf("%d",&power2[l]);
    }

    int *res_coeff;

    res_coeff=(int *)malloc(deg1*sizeof(int) +deg2*sizeof(int));

    int i=0;
    int j=0;
    int k=0;

    while(i<deg1 && j<deg2)
    {
        if(power1[i]>power2[j])
        {
            res_coeff[k++]=coeff1[i++];
        }
        if(power2[j]>power1[i])
        {
            res_coeff[k++]=coeff2[j++];
        }
        else
        {
            res_coeff[k++]=coeff1[i++]+coeff2[j++];
        }
    }

    for(;i<deg1;i++)
        res_coeff[k++]=coeff1[i];
    for(;j<deg2;j++)
        res_coeff[k++]=coeff2[j];

    for(int i=0;i<k;i++)
       printf("%d ",res_coeff[k]);*/

