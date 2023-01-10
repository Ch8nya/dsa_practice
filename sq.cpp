#include<iostream>
using namespace std;
class SLL
{
public:
struct Node
{
int data;
Node * next;
} ;
Node * Top;
Node *rear;
Node *front;
SLL()
{
Top=nullptr;
rear=nullptr;
front = nullptr;
}
void Push();
void Pop();
void display_stack();
int stack_empty();
void enqueue();
void dequeue();
void display_queue();
int queue_empty();
};
int main()
{
SLL s1,q1;
int choice,stchoice,qchoice;
cout<<"***********************WELCOME************************"<<endl;
a:
do
{
cout<<"\nMENU\n1.STACK operations\n2.QUEUE operations\n3.EXIT"<<endl;
cout<<"Enter your choice: ";
cin>>choice;
switch(choice)
{
case 1:
b:
do
{
cout<<"\n1.Insert in stack\n2.Delete from stack\n3.Display stack content\n4.EXIT"<<endl;
cout<<"Enter your choice: ";
cin>>stchoice;
switch(stchoice)
{
case 1:
s1.Push();
break;
case 2:
s1.Pop();
break;
case 3:
s1.display_stack();
break;
case 4:
goto a;
break;
default:
cout<<"Enter valid choice!!!"<<endl;
goto b;
}
}while(stchoice<5);
break;
case 2:
c:
do
{
cout<<"\n1.Insert in Queue\n2.Delete from Queue\n3.Display Queue content\n4.EXIT"<<endl;
cout<<"Enter your choice: ";
cin>>qchoice;
switch(qchoice)
{
case 1:
q1.enqueue();
break;
case 2:
q1.dequeue();
break;
case 3:
q1.display_queue();
break;
case 4:
goto a;
break;
default:
cout<<"Enter valid choice!!!"<<endl;
goto c;
}
}while(stchoice<5);
break;
case 3:
cout<<"THANKYOU !!!"<<endl;
return 0;
}
}while(choice<4);
return 0;
}
int SLL :: stack_empty()
{
int flag=0;
if(Top==nullptr)
{
flag=1;
}
return flag;
}
void SLL :: Push()
{
Node *nn = new Node;
cout<<"Enter the data: ";
cin>>nn->data;
if(Top==nullptr)
{
Top=nn;
cout<<"\nPushed in stack successfully.\n";
}
else
{
nn->next=nullptr;
nn->next=Top;
Top=nn;
cout<<"\nPushed in stack successfully.\n";
}
}
void SLL :: Pop()
{
int flag;
flag=stack_empty();
if(flag==1)
{
 cout<<"\nThe stack is empty . No elements can be deleted.";
}
else
{
Node * temp;
temp=Top;
Top=Top-> next;
delete temp;
cout<<"\nDeleted the Top element successfully.";
}
}
void SLL :: display_stack()
{
Node *cn;
cn=Top;
cout<<"-----------------------------------------------------"<<endl;
while(cn!=nullptr)
{
cout<<cn->data<<"\n";
cn=cn->next;
}
cout<<"-----------------------------------------------------"<<endl;
}
int SLL :: queue_empty()
{
int flag=0;
if(rear==nullptr && front == nullptr)
{
flag=1;
}
return flag;
}
void SLL :: enqueue()
{
 Node *cn,*nn;
nn = new Node;
cout<<"\nEnter the data: ";
cin>>nn->data;
nn->next=nullptr;
 cn=front;
if(front==nullptr)
{
front =nn;
rear=nn;
}
else
{
rear->next=nn;
rear =nn;
}
  cout<<"\nStored in the Queue Successfully. ";
}
void SLL :: dequeue()
{
int flag;
flag=queue_empty();
if(flag==1)
{
cout<<"\nThe Queue is empty.Nothing to delete."<<endl;
}
else{
Node * temp;
temp=front;
front=front->next;
delete temp;
cout<<"\nDeleted Successfully.";
}
}
void SLL :: display_queue()
{
Node * cn;
cn=front;
cout<<"-----------------------------------------------------"<<endl;
while(cn!=nullptr)
{
cout<<cn->data<<endl;
cn=cn->next;
}
cout<<"-----------------------------------------------------"<<endl;
}
