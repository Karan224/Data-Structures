#include <iostream>

using namespace std;


struct node
{
    int data;
    node *left;
    node *right;
};
struct node *root = NULL;
void insert1(int n)
{
    node *p,*temp,*prev;
    p = new node;
    p ->left = NULL;
    p->right = NULL;
    p->data = n;
    if(root== NULL)
    {
        root = p;
    }
    else
    {
        temp = root;
        while(temp!=NULL)
        {
            prev = temp;
            if(n<temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp= temp->right;
            }
        }
        if(n>prev->data)
        {
            prev->right = p;
        }
        else
        {
            prev->left = p;
        }

    }

}
void ddelete(int del)
{
    struct node *temp,*prev;
    if (root == NULL)
    {

        cout<<"NO element to delete";
    }
    else
    {
        temp = root;
        while((del!=temp->data)&&temp!=NULL)
        {
            prev = temp;
            if(del > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if(del!= temp->data && temp == NULL)
        {

            cout<<"NOT FOUND";
        }
        if(temp->left == NULL&& temp->right== NULL)
        {
            if(temp== root)
            {
                root = NULL;
                return;
            }
            if(del > prev->data)
            {
                prev->right=NULL;
            }
            else
            {
                prev->left = NULL;
            }
        }
        else if (temp->left != NULL && temp->right!= NULL)
        {
            struct node *base;
            int x;
            base = temp;
            temp = temp->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            x= temp->data;
            ddelete(x);
            base->data = x;
        }
        else
        {
            if(temp== root)
            {
                if(temp->left!= NULL)
                {
                    root = temp->left;
                }
                else
                {
                    root = temp->right;
                }
            }
            else
            {
                if(temp->data < prev->data)
                {
                    if(temp->left!=NULL)
                    {
                        prev->left = temp->left;
                        temp->left = NULL;
                        delete temp;
                    }
                    else
                    {
                        prev ->left = temp->right;
                        temp->right = NULL;
                        delete temp;
                    }
                }
                else
                {
                    if(temp->left!=NULL)
                    {
                        prev->right = temp->left;
                        temp->left = NULL;
                        delete temp;
                    }
                    else
                    {
                        prev ->right = temp->right;
                        temp->right = NULL;
                        delete temp;
                    }
                }
            }
        }
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
    }
}
int height(struct node *root)
{
    int c1=0,c2=0;
    struct node *temp;
    temp= root;
    while(temp!= NULL)
    {
        temp=temp->left;
        c1++;
    }
    temp = root;
    while(temp!= NULL)
    {
        temp = temp->right;
        c2++;
    }
    if(c1>c2)
        return c1;
    else
        return c2;
}
int main()
{
   int num,n,del;
   cout<<"enter the no of elements u want to insert";
   cin>>num;
   for(int i = 0;i<num;i++)
   {
       cout<<"enter the element";
       cin>>n;
       insert1(n);
   }
   inorder(root);
   int h = height(root);
   cout<<"height of the tree is: ";
   cout<<h<<endl;
   cout<<"enter the element you want to delete";
   cin>>del;
   ddelete(del);
   inorder(root);
   return 0;
}
