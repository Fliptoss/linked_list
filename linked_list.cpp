#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
};

void display(Node *head)
{
  Node *p;
  if(head == NULL)
  {
    cout<<"List is empty...";
    return;
  }
  p = head;
  cout<<"List is : ";
  while(p!= NULL)
  {
    cout<<p->data<<" ";
    p = p->next;
  }
} 

Node *addatbeg(Node *head, int num)
{
  Node *temp;
  temp = new Node;
  temp -> data = num;
  temp->next = head;
  head = temp;
  return head;
}

void addatend(Node *head, int num)
{
  Node *temp, *p;
  temp = new Node;
  temp -> data = num;
  p = head;
  while(p->next!=NULL)
  {
     p = p->next;
  }
  p->next=temp;
  temp->next=NULL;
}

Node *del(Node *head, int num)
{
  Node *temp, *p;
  if(head == NULL)
  {
    cout<<"List is empty.\n";
  }
  if(head->data == num)
  {
      temp = head;
      head=head->next;
      free(temp);
      return head;
  }

//in any position
  p = head;
  while(p->next!=NULL)
  {
    if(p->next->data==num)
    {
      temp = p->next;
      p=p->next;
      free(temp);
      return  head;
    }
    p = p->next;
  }
  cout<<"Number not present in the list..\n";
  return head;
}

void search(Node *head, int num)
{
  Node *p;
  int pos = 1;
  while(p!=NULL)
  {
    if(p->data==num)
    {
      cout<<num<<" found at position \n"<<pos;
      return;
    }
    p=p->next;
    pos++;
  }
  cout<<num<<" not found in the list\n";
}

void count(Node *head)
{ 
   int count =0;
   Node *p;
   p = head;

   while(p!=NULL)
   {
      p = p->next;
      count++;
   }
   cout<<"Number of nodes are: "<<count;
}

void addafter(Node *head, int num, int num2)
{
   Node *temp, *p;
   p=head;
   while(p!=NULL)
   {
     if(p->data==num2){
         temp = new Node;
         temp->data=num;
         temp->next=p->next;
         p->next=temp;
         return; 
     } 
     p=p->next;
   }
   cout<<num2<<"not found in the list.\n";
}

Node *addbefore(Node *head, int num, int num2)
{
  Node *temp, *p;
  if(head->data==num2)
  {
     temp = new Node;
     temp -> data = num;
     temp->next = head;
     head = temp;
     return head;
  }

  p=head;
  while(p->next!=NULL)
  {
       if(p->next->data==num2)
       {
         temp = new Node;
         temp->data=num;
         temp->next = p->next;
         p->next=temp;
         return head;
       }
       p=p->next;
  }
  cout<<num2<<" not found in the list.\n";
  return head;
}


int main() {

  Node *head = NULL;
  int choice, num, num2;

  while(1)
  {
    cout<<"\n1.Display\n";
    cout<<"2.Add node to empty list/ add at beginning.\n";
    cout<<"3.Add node at the end.\n";
    cout<<"4.Delete from list.\n";
    cout<<"5.Search.\n";
    cout<<"6.Count number of nodes.\n";
    cout<<"7.Add after node.\n";
    cout<<"8.Add before node.\n";
    cout<<"9.Exit.\n\n";

    cin>>choice;
    switch(choice){
      case 1:
        display(head);
        break;
      case 2:
        cout<<"Enter the number to be inserted: ";
        cin>>num;
        head = addatbeg(head, num);
        break;
      case 3:
        cout<<"Enter a number to be inserted: ";
        cin>>num;
        addatend(head, num);
        break;
      case 4:
        cout<<"Enter the number to be deleted.\n";
        cin>>num;
        head = del(head, num);
        break;
      case 5:
        cout<<"Enter the number to search.\n";
        cin>>num;
        search(head, num);
        break;
      case 6:
        count(head);
        break;
      case 7:
        cout<<"Enter a number to insert.\n";
        cin>>num;
        cout<<"Enter the number after which to insert.\n";
        cin>>num2;
        addafter(head,num,num2);
        break;
      case 8:
        cout<<"Enter a number to insert.\n";
        cin>>num;
        cout<<"Enter the number before which to insert.\n";
        cin>>num2;
        head = addbefore(head,num,num2);
        break;
      case 9:
        exit(1);
    }
  }
 
}
