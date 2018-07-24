#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct list
{
    int info;
    struct list *next;
};
struct list *start =NULL;
class linked_list
{
public:
    void insertbeg();
    void display();
    void insertend();
    void deletebeg();
    void deleteend();
    void reversee();

};

int main()
{
    int n;
    linked_list li;
    cout<<"1. Insert at the beginning"<<endl;
    cout<<"2. Display the elements "<<endl;
    cout<<"3. Insert at the end "<<endl;
    cout<<"4. Delete from the beginning"<<endl;
    cout<<"5. Delete from the end "<<endl;
    cout<<"6. Reverse the linked list"<<endl;
    cout<<"7. To exit"<<endl;
    cout<<"enter the choice"<<endl;
    cin>>n;
    while(1)
    {
        switch(n)
        {
        case 1:
            li.insertbeg();
            cout<<endl;
            break;
        case 2:
            li.display();
            cout<<endl;
            break;
        case 3:
            li.insertend();
            cout<<endl;
            break;
        case 4:
            li.deletebeg();
            cout<<endl;
            break;
        case 5:
            li.deleteend();
            cout<<endl;
            break;
        case 6:
            li.reversee();
            break;
        case 7:
            exit(1);
            break;
        default:
            cout<<"wrong choice";
        }
        cout<<"enter the choice"<<endl;
        cin>>n;
    }
    return 0;
}
void linked_list::insertbeg()
{
    int value;
    cout<<"enter the element you want to enter"<<endl;
    cin>>value;
    struct list *ptr;
    ptr = new list;
    if(start==NULL)
        start=ptr;
        ptr->info=value;
        ptr->next=NULL;
    }
    else
        {
            ptr->info=value;
    {
            ptr->next=start;
            start=ptr;
        }
}
void linked_list::display()
{
    struct list *temp;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        temp= start;
        while(temp!= NULL)
        {
            cout<<temp->info<<"\t";
            temp=temp->next;
        }
    }
}
void linked_list::insertend()
{
    int value;
    cout<<"enter the value u want to enter "<<endl;
    cin>>value;
    struct list *ptr,*temp;
    ptr = new list;
    if(start==NULL)
    {
        ptr->info=value;
        ptr->next=NULL;
        start=ptr;
    }
    else
        {
            ptr->info=value;
            ptr->next=NULL;
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
        }
}
void linked_list ::deletebeg()
{
struct list *temp;
temp=start;
if(start == NULL)
{
    cout<<"Underflow";
}
else
{
    start=temp->next;
    delete temp;
}
}
void linked_list :: deleteend()
{
    struct list *temp,*temp1;
    if(start == NULL)
    {
        cout<<"underflow";
    }
    else if(start->next==NULL)
    {
        temp=start;
        start=NULL;
        delete temp;
    }
    else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next=NULL;
            delete temp;
        }
}
void linked_list :: reversee()
{
    struct list *temp1,*temp2,*temp3;
    if(start==NULL)
    {
        cout<<"List is empty";
    }
    else if(start->next == NULL)
    {
        cout<<"There is only single element in the linked list";
    }
    else
        {
            temp1=start;
            temp3=NULL;
            while( temp1!= NULL)
            {
                temp2 =temp1->next;
                temp1->next =temp3;
                temp3=temp1;
                temp1=temp2;
            }
            start=temp3;
        }



}
