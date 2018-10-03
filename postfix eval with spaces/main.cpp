#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

string postfix;
string temp;
int a[50],l,num1,num2;
int top = -1;
char gettype(char s)
{
    switch(s)
    {
        case '+':
            return 'o';
            break;
        case '-':
            return 'o';
            break;
        case '*':
            return 'o';
            break;
        case '/':
            return 'o';
            break;
        case '^':
            return 'o';
            break;
        default:
            return 'z';
    }

}
void push(int item)
{
    top=top+1;
    a[top] = item;

}
int pop()
{
    int item;
    item = a[top];
    top -- ;
    return item;
}
void evaluate(char t,int num1,int num2)
{
    int num3;
    switch(t)
    {
    case '+':
        num3 = num2+num1;
        break;
    case '-':
        num3 = num2-num1;
        break;
    case '*':
        num3 = num2*num1;
        break;
    case '/':
        num3 = num2/num1;
        break;
    case '^':
        num3 = pow(num2,num1);
        break;
    }
    push(num3);
}
int main()
{
    getline(cin,postfix);
    cout<<postfix;
    postfix[l] = ')';
    for(int i = 0;postfix[i]!=')';i++)
    {
        if(postfix[i]==' '||postfix[i]=='\t')
        {
            continue;
        }
        switch(gettype(postfix[i]))
        {
        case 'o':
            num1 = pop();
            num2 = pop();
            evaluate(postfix[i],num1,num2);
            break;
        case 'z':
            int item=0,temp1=0;
            while(postfix[i]!=' ')
            {
                temp1 =0;
                item *=10;
                temp1 = postfix[i]-'0';
                item = item + temp1;
                i++;

            }
            push(item);
            break;
        }


    }
    cout<<a[top];
    return 0;
}
