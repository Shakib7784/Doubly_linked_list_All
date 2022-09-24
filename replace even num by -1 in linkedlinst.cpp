#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node * Next;
    Node (int val)
    {
        value=val;
        Next=NULL;
    }
};
void insert_at_tail(Node *&head,int val)
{
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Node *temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newnode;
    }
}
int length(Node *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        Node *temp=head;
        int i=1;
        while(temp->Next!=NULL)
        {
            i++;
            temp=temp->Next;
        }
        return i;
    }
}
void Display(Node *&head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {

         Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value;
            if(temp->Next!=NULL)
                cout<<"->";
            temp=temp->Next;
        }
        cout<<endl;


    }
}
void replace_Even(Node *head)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            if(temp->value  % 2==0)
            {
                temp->value=-1;
            }
            temp=temp->Next;
        }
    }
}
int main()
{
    Node *head=NULL;
    int n;
    cout<<"how much number do you want to insert?"<<endl;
    cin>>n;
    int i=1;
    while(i<=n)
    {

        int num;
        cin>>num;
         insert_at_tail(head,num);
        i++;
    }
    cout<<"Linked List : "<<endl;
    Display(head);
    cout<<"Linked List After replace : "<<endl;
    replace_Even(head);
    Display(head);

    int len = length (head);
    if(len==-1)
    {
        cout<<"Length is 0"<<endl;
    }
    else
    {
        cout<<"Length is "<<len<<endl;
    }
}
