#include <iostream>
#include<math.h>
#include<string.h>
using namespace std;

char postfix[50];
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
    cin>>postfix;
    l = strlen(postfix);
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
            int item;
            item = postfix[i]-'0';
            push(item);
            break;
        }

    }
    cout<<a[top];
    return 0;
}
