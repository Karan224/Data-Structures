#include <iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
char a[50],temp;
int top = -1;
void push(char t)
{
    top++;
    a[top]= t;
}
char pop()
{
    char t;
    t= a[top];
    top--;
    return t;
}

int main()
{
    string s;
    getline(cin,s);
    int num = s.length();
    if(s[0]==')'||s[0]=='}'||s[0]==']')
    {
        cout<<"unbalanced";
        exit(0);
    }
    else if(num<=1)
    {
     cout<<"unbalanced";
        exit(0);
    }
    for(int i =0;i<num;i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                push(s[i]);
            }
            else if(s[i]==')'||s[i]=='}'||s[i]==']')
            {
                switch(s[i])
                {
                    case ')':
                           temp = pop();
                           if(temp == '{'||temp =='[')
                           {
                               cout<<"Unbalanced";
                               exit(0);
                           }
                           else
                           {
                               break;
                           }
                    case '}':
                           temp = pop();
                           if(temp == '('||temp =='[')
                           {
                               cout<<"Unbalanced";
                               exit(0);
                           }
                           else
                           {
                               break;
                           }
                    case ']':
                           temp = pop();
                           if(temp == '{'||temp =='{')
                           {
                               cout<<"Unbalanced";
                               exit(0);
                           }
                           else
                           {
                               break;
                           }

                }
            }
    }
    cout<<"balanced";
    return 0;
}
