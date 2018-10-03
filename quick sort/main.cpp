#include <iostream>

using namespace std;
void quicksort(int [],int,int);
int parts(int [],int,int);

int main()
{
    int a[50],i,j=0,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,j,n-1);
    for(i =0;i<n;i++)
        cout<<a[i]<<"   ";
    return 0;
}
void quicksort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j= parts(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
    }
}
int parts(int a[],int l,int h)
{
    int p,i,j,temp;
    p =a[l];
    i=l;
    j=h;
    while(i<=j)
    {
        while(a[i]<=p)
            i++;
        while(a[j]>p)
            j--;
        if(i<j)
        {
            temp = a[i];
            a[i] =a[j];
            a[j]=temp;
        }
    }
        a[l]=a[j];
        a[j]=p;
        return j;

}
