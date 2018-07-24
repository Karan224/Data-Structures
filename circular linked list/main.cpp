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
class circular_list
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
    circular_list cl;
    cout<<"1. Insert at the beginning"<<endl;
    cout<<"2. Insert at the end "<<endl;
    cout<<"3. Delete from the beginning"<<endl;
    cout<<"4. Delete from the end "<<endl;
    cout<<"5. Display the elements "<<endl;
    cout<<"6. To exit"<<endl;
    cout<<"enter the choice"<<endl;
    cin>>n;
    while(1)
    {
        switch(n)
        {
        case 1:
            cl.insertbeg();
            cout<<endl;
            break;
        case 2:
            cl.insertend();
            cout<<endl;
            break;
        case 3:
            cl.deletebeg();
            break;
        case 4:
            cl.deleteend();
            break;
        case 5:
            cl.display();
            break;
        case 6:
            exit(1);
        default:
            cout<<"Wrong Choice ";
        }
        cout<<"enter the choice";
        cin>>n;
    }
    return 0;
}
void circular_list::insertbeg()
 {
     int value;
     cout<<"Enter the value u want to enter "<<endl;
     cin>>value;
     struct list *ptr,*temp;
     ptr = new list;
     if(start==NULL)
     {
         ptr->info = value;
         start = ptr;
         ptr->next= start;
     }
     else
        {
            ptr->info = value;
            ptr->next= start;
            temp = start;
            while(temp->next != start)
            {
                temp = temp->next;
            }
            temp->next =ptr;
            start = ptr;
        }
 }
 void circular_list::insertend()
 {
     int value;
     cout<<"Enter the value you want to insert "<<endl;
     cin>> value;
     struct list *ptr,*temp;
     ptr = new list;
     if(start == NULL)
     {
         ptr->info = value;
         start = ptr;
         ptr->next = start;
     }
     else
        {
            ptr->info=value;
            temp= start;
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            temp->next =ptr;
            ptr->next = start;

        }
 }
 void circular_list::deletebeg()
 {
     struct list *temp,*temp1;
     if(start == NULL)
     {
         cout<<"list is empty";
     }
     else if(start->next == start)
     {
         temp = start;
         start = NULL;
         delete temp;
     }
     else
     {
         temp = start;
         temp1 = start;
         while(temp->next != start)
         {
             temp = temp->next;
         }
         start = temp1->next;
         temp->next = start;
         delete temp1;
     }

 }
 void circular_list::deleteend()
 {
     struct list *temp,*temp1;
     if(start == NULL)
     {
         cout<<"overflow";
     }
     else if(start->next == start)
     {
         temp = start;
         start = NULL;
         delete temp;
     }
     else
        {
            temp= start;
            while(temp->next != start)
            {
                temp1= temp;
                temp= temp->next;
            }
            temp1->next = start;
            delete temp;

        }
 }

 void circular_list::display()
 {
     struct list *temp;
     temp= start;
     while (temp->next!= start)
     {
         cout<<temp->info<<"\t";
         temp=temp->next;
     }
     cout<<temp->info;

 }
