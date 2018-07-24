#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct list
{
    int info;
    struct list *prev,*next;
};
struct list *start = NULL;
struct list *endd=NULL;

class doubly_list
{
    public:
    void insertbeg();
    void insertend();
    void deletebeg();
    void deleteend();
    void display();
};
int main()
{
    int n;
    doubly_list dl;
    cout<<"1. Insert at the beginning"<<endl;
    cout<<"2. Insert at the end "<<endl;
    cout<<"3. Delete from the beginning"<<endl;
    cout<<"4. Delete from the end "<<endl;
    cout<<"5. Display the elements "<<endl;
    cout<<"6. To exit"<<endl;

    cout<<"Enter the choice ";
    cin>>n;
    while(1)
    {
        switch(n)
        {
        case 1:
            dl.insertbeg();
            cout<<endl;
            break;
        case 2:

            dl.insertend();
            cout<<endl;
            break;
        case 3:
            dl.deletebeg();
            cout<<endl;
            break;
        case 4:
            dl.deleteend();
            cout<<endl;
            break;
        case 5:
            dl.display();
            break;
        case 6:
            exit(1);
        default:
            cout<<"Wrong Choice";

        }
        cout<<"enter the choice "<<endl;
        cin>>n;
        cout<<endl;
    }
    return 0;
}
void doubly_list::insertbeg()
{
    int value;
    struct list *ptr;
    ptr = new list;
    cout<<"Enter the number you want to insert"<<endl;
    cin>>value;
    if(start == NULL)
    {
        ptr->info=value;
        ptr->prev=NULL;
        ptr->next=NULL;
        start=ptr;
        endd=ptr;
    }
    else
        {
            ptr->info=value;
            ptr->next=start;
            start->prev=ptr;
            start = ptr;
            start->prev =NULL;
        }
}
void doubly_list::insertend()
{
    int value;
    struct list *ptr;
    ptr = new list;
    cout<<"Enter the number you want to insert"<<endl;
    cin>>value;
    if(endd==NULL)
    {
        ptr->info=value;
        ptr->prev=NULL;
        ptr->next=NULL;
        start=ptr;
        endd=ptr;
    }
    else
    {
        ptr->info =value;
        endd->next = ptr;
        ptr->next= NULL;
        ptr->prev= endd;
        endd=ptr;
    }
}
void doubly_list::display()
{
    struct list *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<temp->info<<endl;
}
void doubly_list::deletebeg()
{
    struct list *temp;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else if(start == endd)
    {
        temp= start;
        start = NULL;
        endd = NULL;
        delete temp;
    }
    else
        {
            temp = start;
            start=temp->next;
            start->prev=NULL;
            delete temp;

        }
}
void doubly_list::deleteend()
{
    struct list *temp;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else if(start == endd)
    {
        temp= start;
        start = NULL;
        endd = NULL;
        delete temp;
    }
    else
        {
            temp = start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            endd=temp->prev;
            temp->prev->next=NULL;
            delete temp;
        }
}
