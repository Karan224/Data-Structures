#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void create();
void insertion();
void deletion();
void display();
int arr[50],m,n,i,j,k;

int main()
{
    while(1)
    {
        cout<<"1. Create an array"<<endl;
        cout<<"2. Insert at any position in the array"<<endl;
        cout<<"3. Deletion of element from any position"<<endl;
        cout<<"4. Display the array"<<endl;
        cout<<"Enter your choice "<<endl;
        cin>>n;
        switch(n)
        {
        case 1:
            create();
            break;
        case 2:
            insertion();
            break;
        case 3:
            deletion();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
void create()
{
    cout<<"Enter the no of elements in your array "<<endl;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>arr[i];
    }
}
void insertion()
{
    int ele,pos;
    cout<<"Enter the element you want to insert"<<endl;
    cin>>ele;
    cout<<"Enter the position at where you want to insert"<<endl;
    cin>>pos;
    for (i=m-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=ele;
    m=m+1;

}
void deletion()
{
    int pos;
    cout<<"Enter the position fron where you want to delete the element"<<endl;
    cin>>pos;
    for(i= pos;i<m;i++)
    {
        arr[i-1]=arr[i];
    }
    m=m-1;
}
void display()
{
    cout<<"Elements in array are:"<<endl;
    for(i=0;i<m;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
