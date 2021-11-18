#include<iostream>
#include "only_tree.c"

using namespace std;

int nodecount(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=nodecount(p->rchild);
        y=nodecount(p->lchild);

        return x+y+1;
    }
    return 0;
}

int two_child_count(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=two_child_count(p->lchild);
        y=two_child_count(p->rchild);

        if(p->lchild && p->rchild)
            return x+y+1;
        else
            return x+y;
    }
    return 0;

}

int height(Node *p)
{
    int x,y;

    if(p!=NULL)
    {
        x=uncount(p->lchild);
        y=uncount(p->rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}


int main()
{
    Treecreate();
    cout<<nodecount(root)<<" ";
    cout<<two_child_count(root)<<" ";
    cout<<height(root);


}
