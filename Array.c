#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

void Append(struct Array *arr,int x)
{
   if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    if(index>=0 && index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}

void Delete(int index,struct Array *arr)
{
    int x=0;
    int i;

    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

int BinarySearch(struct Array arr, int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }

    return -1;

}

int RBinSearch(int a[],int l,int h,int key)
{
    int mid;

    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h,key);
    }
    return -1;
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A>arr.A[i+1])
            return 0;
    }

    return 1;
}

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else
 arr3->A[k++]=arr2->A[j++];
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 arr3->length=arr1->length+arr2->length;
 arr3->size=10;

 return arr3;
}


struct Array* Union(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else if(arr2->A[j]<arr1->A[i])
 arr3->A[k++]=arr2->A[j++];

 else{
    arr3->A[k++]=arr1->A[i++];
    j++;
 }
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
arr3->length=k;
 arr3->size=10;

 return arr3;
}



struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array ));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 i++;
 else if(arr2->A[j]<arr1->A[i])
 j++;

 else if(arr2->A[j]==arr1->A[i]){
    arr3->A[k++]=arr1->A[i++];
    j++;
 }
 }

arr3->length=k;
 arr3->size=10;

 return arr3;
}


struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array ));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 {
  arr3->A[k++]=arr1->A[i++];
 }
 else if(arr2->A[j]<arr1->A[i])
 j++;

 else{
       i++;
       j++;
 }

 for(;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];

arr3->length=k;
 arr3->size=10;

 return arr3;
}



int main()
{
    struct Array arr={{2,3,4,5,6},10,5};
    struct Array arr1={{18,27,4,7,5},10,5};
    struct Array *arr3;
    struct Array *arr4;
    struct Array *arr5,*arr6;
    arr3=Merge(&arr,&arr1);


    arr4=Union(&arr,&arr1);
    arr5=Intersection(&arr,&arr1);
    arr6=Difference(&arr,&arr1);

    Append(&arr,10);
    Display(arr);
    Insert(&arr,2,10);
    Delete(2,&arr);
    Display(arr);

    printf("%d\n",BinarySearch(arr,5));
    printf("%d\n",isSorted(arr));
    Display(*arr3);
    Display(*arr4);
    Display(*arr5);
    Display(*arr6);

    return 0;
}
