
struct Stack
{
    int N;  /// max size
    char *word;
    int top;   /// index of most recent spelled char
};

struct Stack* box(int n)
{
    struct Stack* T=(struct Stack*)malloc(sizeof(struct Stack));
    T->N=n;
    T->top=-1;
    T->word=(char*)malloc(T->N*sizeof(char));

    return T;

};

int isFull(struct Stack* T)
{
    if(T->top==T->N-1)
        return 1;
        return 0;
}

int isEmpty(struct Stack* T)
{
    if(T->top==-1)
        return 1;
    return 0;
}
void push(struct Stack *T,char ch)
{
    if(isFull(T))
        return 1;
    T->word[++T->N]=ch;
    printf("%c pushed into the stack\n",ch);
}

char pop(struct Stack* T)
{
    if(isEmpty(T))
        return 0;
    return T->word[T->top--];

}

int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    return 1;
}

int pre(char x)
{
    if(x=='+' || x=='-')
        return  1;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='^')
        return 3;
    else if(x=='(' || x==')')
        return 4;
    return 0;
}
char *peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->word[stack->top];
}

char * convert(char *infix)
{
      struct Stack* stack=box(100);
      char *postfix=(char *)malloc(strlen(infix)*sizeof(char)+1);
      int i=0,j=0;

      while(infix[i]!='\0')
      {
          if(isOperand(infix[i]))
            postfix[j++]=infix[i];
          else{
             if(pre(infix[i])>pre(peek(stack)))
                push(stack,infix[i++]);
             else
                postfix[j++]=pop(stack);
          }
      }
      while(isEmpty(stack))
      {
          postfix[j++]=pop(stack);
      }
      postfix[j]='\0';

      return postfix;
}


int main()
{
    char a[100];
    scanf("%s",&a);
    char b[100];
    printf("%s",convert(a));
}
