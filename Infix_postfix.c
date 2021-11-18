#include<stdio.h>


struct Stack
{
    int top;
    int capacity;
    int *arr;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack=(struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->arr=(int*)malloc(stack->capacity*sizeof(int));

    return stack;

};

int isFull(struct Stack* stack)
{
    if (stack->top==stack->capacity-1)
    return 1;

    return -1;
}

int isEmpty(struct Stack* stack)
{
    if(stack->top==-1)
        return 1;
    return -1;
}

void push(struct Stack *stack,int n)
{
    if(isFull(stack))
    {
        printf("Stack is full");
        return ;
    }
    else{
        stack->arr[stack->top++]=n;
    }
}

int pop(struct Stack *stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty, no element to pop");
    }
    return stack->arr[stack->top];
}

int prec(char c){

   if(c=='^'){
    return 3;
   }

   else if(c=='*' || c=='-'){
    return 2;
   }

   else if(c=='+' || c=='-'){
    return 1;
   }

   return -1;
}

void infixtoPostfix(char s[])
{
    struct Stack* stack=createStack(10);
    char res[100];

    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            res+=s[i];
        else if(s[i]=='(')
        {
            push(stack,s[i]);
        }

        else if(s[i]==')'){
            while(!isEmpty(stack) && peek(stack)!='('){
                    res+=peek(stack);
                    pop(stack);
                  }
                  if(!isEmpty(stack)){
                    pop(stack);
                  }
        }
        else{
            while(isEmpty(stack) && prec(stack->top)>prec(s[i]))
            {
                res+=peek(stack);
                pop(stack);
            }
            push(stack,s[i]);
        }
    }
    while(!isEmpty(stack)){
        res+=peek(stack);
        pop(stack);
    }

    for(int i=0;i<strlen(res))
    {
        printf("%c",res[i]);
    }
}

int main()
{

   infixtoPostfix("(a-b/c)*(a/k-l");
}
