#include <iostream>

using namespace std;
int n,m,i,j,k,cost[100][100],visited[100],visit[100],qu[100],front,rare,v;
int main()
{
    cout<<"no of vertices";
    cin>>n;
    cout<<"enter no of edges";
    cin>>m;
    cout<<"edges";
    for(k=0;k<m;k++)
    {
        cin>>i>>j;
        cost[i][j]=1;
    }
    cout<<"enter initial vertex";
    cin>>v;
    cout<<endl<<"intial vertex is"<<endl;
    cout<<v;
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=1;j<=n;j++)
        {
            if(cost[v][j]!=0&&visited[j]!=1&&visit[j]!=1)
            {
                visit[j]=1;
                qu[rare++]=j;
            }
        }
        v=qu[front++];
        cout<<v<<" ";
        k++;
    }
    return 0;
}
