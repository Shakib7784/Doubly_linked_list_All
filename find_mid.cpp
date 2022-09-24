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

int findMid(Node *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        Node *first=head;
        Node *second=head;
        while(first!=NULL && first->Next!=NULL) // first!=NULL is handaling even number, it will give use mid value (length/2)+1. suppose we have 6 value it will give use
            // mid value 4th position's value. because in even  number mid value can be 2 value.
        {
            first=first->Next->Next;
            second = second->Next;
        }
        return second->value;
    }
}
int main()
{
    Node *head=NULL;
    int choice;
    cout<<"enter your choice"<<endl;
    cout<<"choice 1: insert at tail"<<endl;
    cout<<"choice 2: Find mid"<<endl;
    cin>>choice;

    while(choice!=0)
    {
        int value,result;
        switch(choice)
        {
        case 1:
            cout<<"enter value:"<<endl;
            cin>>value;
            insert_at_tail(head,value);
            break;
        case 2:
             result = findMid(head);
            if(result ==-1)
            {
                cout<<"there is no value"<<endl;
            }
            else
            {
                cout<<"Mid value is : "<<result<<endl;
            }

            break;

        default:
            break;

        }
        cout<<"Next choice"<<endl;
        cin>>choice;
    }
    cout<<"Linked List : "<<endl;
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

