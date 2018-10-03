#include <iostream>
using namespace std;

struct list 
{
	int info;
	struct list *next;
};
struct list *top = NULL;
class stack
{
	public:
		void push();
		void pop();
		void traverse();
};
int main() 
{
	stack st;
	int n;
	while(1)
	{
		cout<<"1. Insert the element"<<endl;
		cout<<"2. Delete the element"<<endl;
		cout<<"3. Display the stack"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>n;
		switch(n)
		{
			case 1:
				st.push();
				break;
			case 2:
				st.pop();
				break;
			case 3:
				st.traverse();
				break;
			default:
				exit(0);
					
		}
				
	}
	return 0;
}
void stack::push()
{
	int num;
	cout<<"Enter the number you want to insert"<<endl;
	cin>>num;
	struct list *ptr;
	ptr= new list;
	if(top==NULL)
	{
		ptr->info=num;
		ptr->next=NULL;
		top=ptr;
		
	}
	else
	{
		ptr->info=num;
		ptr->next=top;
		top = ptr;
	}
}
void stack::pop()
{
	struct list *temp;
	if(top == NULL)
	{
		cout<<"Underflow"<<endl;
	}
	else
	{
		temp= top;
		top= temp->next;
		delete temp;
	}
}
void stack::traverse()
{
	struct list *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->info<<endl;
		temp= temp->next;
	}
}
