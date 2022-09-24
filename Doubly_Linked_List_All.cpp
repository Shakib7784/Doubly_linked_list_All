#include<bits/stdc++.h>
using namespace std;
class DoublyLinkedList
{
public:
    int value;
    DoublyLinkedList *prev;
    DoublyLinkedList *Next;
    DoublyLinkedList(int val)
    {
        value=val;
        prev=NULL;
        Next=NULL;
    }
};
struct Duplicate
{
    int position[1000];
};
void   Insert_at_tail(DoublyLinkedList *&head,int value)
{
    DoublyLinkedList *newnode=new DoublyLinkedList(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        DoublyLinkedList *temp=head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        temp->Next=newnode;
        newnode->prev=temp;
    }
}
void Inset_at_head(DoublyLinkedList *&head, int value)
{
    DoublyLinkedList *newnode= new DoublyLinkedList(value);

    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        DoublyLinkedList *temp=head;
        head=newnode;
        newnode->Next=temp;
        temp->prev=newnode;


    }
}
int length(DoublyLinkedList *&head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        DoublyLinkedList *temp=head;
        int i=1;
        while(temp->Next!=NULL)
        {
            i++;
            temp=temp->Next;
        }
        return i;
    }
}
void Display(DoublyLinkedList *&head)
{
    if(head==NULL)
    {
        cout<<"there is no value"<<endl;
    }
    else
    {
        DoublyLinkedList *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->value<<endl;
            temp=temp->Next;
        }
    }
}
void  DisplayReverse(DoublyLinkedList *& head)
{
    if(head==NULL)
    {
        cout<<"Linked list is null"<<endl;
    }
    else
    {
        DoublyLinkedList *temp =head;
        while(temp->Next!=NULL)
        {
            temp=temp->Next;
        }
        while(temp!=NULL)
        {
            cout<<temp->value<<endl;
            temp=temp->prev;
        }
    }
}
void insertAtSpecificPosition(DoublyLinkedList *&head,int val,int pos)
{
    DoublyLinkedList *newnode=new DoublyLinkedList(val);
    if(head==NULL)
    {
        cout<<"Linked List is NULL"<<endl;
    }
    else
    {
        int len=length(head);
        if(pos<1 || pos>len+1)
        {
            cout<<"position is out of range"<<endl;
        }
        else if(pos==1)
        {
            Inset_at_head(head, val);
        }
        else
        {
            DoublyLinkedList *temp=head;
            int i=1;
            while(i<pos-1)
            {
                temp=temp->Next;
                i++;
            }
            DoublyLinkedList *nextnode=temp->Next;
            temp->Next=newnode;
            newnode->Next=nextnode;
            newnode->prev=temp;
        }
    }
}

int Search_value_in_uniqueList(DoublyLinkedList *&head, int value)
{
     if(head==NULL)
    {
        return -1;
    }
    else
    {
        DoublyLinkedList *temp=head;
        int i=1;
        while(temp->value!=value)
        {
            if(temp->Next==NULL)
            {
                return -1;
            }
            temp=temp->Next;
            i++;
        }
        return i;
    }
}

void Search_value_in_Duplicate_ValuedList(DoublyLinkedList *&head, int value)
{
    if (head == NULL)
    {
        cout<<"Value is not found"<<endl;
    }
    else
    {
        int len = length(head);
        int pos[len+1],k=1;
        DoublyLinkedList *temp=head;
        int c=1;
        while(c<=len)
        {
            if(temp->value==value)
            {
                pos[k]=c;
                k++;
            }
            c++;
            temp=temp->Next;
        }
        pos[0]=k;
        cout<<"Positions of searched value are: ";
        for(int i=1;i<k;i++)
        {
            cout<<pos[i];
            if(i<k-1)
                cout<<",";
        }
        cout<<endl;
        if(k==1)
        {
            cout<<"Value is not found"<<endl;
        }
    }
}

Duplicate Search_value_in_Duplicate_ValuedList_Return(DoublyLinkedList *&head, int value)
{
    DoublyLinkedList *temp=head;
    int len=length(head);
    Duplicate D;
    int k=1,c=1;
    while(c<=len)
    {
        if(temp->value==value)
        {
            D.position[k]=c;
            k++;
        }
        c++;
        temp=temp->Next;
    }
    D.position[0]=k;
    return D;
}
void Insert_after_before_ofA_Specific_Value(DoublyLinkedList *&head,int spv,int value)
{
    int pos = Search_value_in_uniqueList(head,spv);
    if(pos==-1)
    {
        cout<<"Value is not found"<<endl;
    }
    else
    {
        insertAtSpecificPosition(head,value,pos+1);
    }
}
void Insert_after_before_ofA_Specific_Value_Duplicate_LinkedList(DoublyLinkedList *&head,int TargetValue,int value)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {
        Duplicate s;
        s=Search_value_in_Duplicate_ValuedList_Return(head,TargetValue);
        int lenn = s.position[0];
        cout<<lenn;
        int i=1;
        while(i<lenn)
        {
            insertAtSpecificPosition(head,value,s.position[i]+1);
            i++;
            s.position[i]=s.position[i]+(i-1);
        }

    }
}


void Delete_from_head(DoublyLinkedList *&head)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {
        DoublyLinkedList *temp = head;
        head=head->Next;
        delete(temp);

    }
}
void Delete_from_tail(DoublyLinkedList *&head)
{
    if(head==NULL)
    {
        cout<<"Linked List is empty"<<endl;
    }
    else
    {
        DoublyLinkedList *temp=head;
        if(temp->Next==NULL)
        {
            Delete_from_head(head);
        }
        else
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        DoublyLinkedList *hold = temp->Next;
        temp->Next=NULL;
        delete(hold);

    }
    }
}
void Delete_from_specific_Position(DoublyLinkedList *&head, int pos)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        int len= length(head);
        if(pos<1||pos>len)
        {
            cout<<"position is out of range"<<endl;
        }
        else if(pos==1)
        {
            Delete_from_head(head);
        }
        else if(pos==len)
        {
            Delete_from_tail(head);
        }
        else
        {
            DoublyLinkedList *temp=head;
            int c=1;
            while(c<pos-1)
            {
                temp=temp->Next;
                c++;
            }
            DoublyLinkedList *tobedeleted=temp->Next;
            DoublyLinkedList * store= temp->Next->Next;
            temp->Next=store;
            store->prev=temp;
            delete(tobedeleted);
        }
    }
}

void Delete_value_from_AUnique_Doubly_LinkedList(DoublyLinkedList *&head, int val)
{
    int pos=Search_value_in_uniqueList(head,val);
    if(pos==-1)
    {
        cout<<"Value is not found"<<endl;
    }
    else
    {
        Delete_from_specific_Position(head,pos);
    }
}
void Delete_value_from_ADuplicate_Doubly_LinkedList(DoublyLinkedList *&head, int val)
{
    Duplicate s;
    s= Search_value_in_Duplicate_ValuedList_Return(head,val);
    int len=s.position[0];
    int c=1;
    DoublyLinkedList *temp=head;
    while(c<=len)
    {
        Delete_from_specific_Position(head,s.position[c]);
        c++;
        s.position[c]=s.position[c]-(c-1);
    }
}
int main()
{
    DoublyLinkedList *head=NULL;
    cout<<"Give your choice"<<endl;
    cout<<"Choice 0: Exist"<<endl;
    cout<<"Choice 1: Insert value at tail"<<endl;
    cout<<"Choice 2: Insert value at head"<<endl;
     cout<<"Choice 3: Reversed Linked List"<<endl;
    cout<<"Choice 4: Insert at specific position"<<endl;
    cout<<"Choice 5: Search by value from unique List"<<endl;
     cout<<"Choice 6: Search by value from Duplicate List"<<endl;
     cout<<"Choice 7: Inset after or before of a specific position"<<endl;
     cout<<"Choice 8:  Insert after before ofA Specific Value Duplicate LinkedList"<<endl;
     cout<<"Choice 9:  Delete from head"<<endl;
      cout<<"Choice 10:  Delete from tail"<<endl;
    cout<<"Choice 11:  Delete from a specific position"<<endl;
    cout<<"Choice 12:  Delete by value from unique list"<<endl;
    cout<<"Choice 13:  Delete by value from Duplicate list"<<endl;





     int choice;
    cin>>choice;
    while(choice!=0)
    {
        int value,position,len,sv;
        Duplicate dd;

        switch(choice)
        {
             case 1:
                cout<<"Insert Value: "<<endl;
                cin>>value;
                Insert_at_tail(head,value);
                break;

                case 2:
                cout<<"Insert Value: "<<endl;
                cin>>value;
                Inset_at_head(head,value);
               break;

                case 3:
                    cout<<"Reverse Linked LIst"<<endl;
                    DisplayReverse(head);
                    break;

                case 4:
                    cout<<"Insert Position : ";
                    cin>>position;
                     cout<<"Insert Value: "<<endl;
                        cin>>value;
                        insertAtSpecificPosition(head,value,position);
                        break;
                case 5:
                     cout<<"Insert Value which you want to search "<<endl;
                        cin>>value;
                        position = Search_value_in_uniqueList(head,value);
                        if(position==-1)
                            cout<<"Value not found"<<endl;
                        else
                            cout<<"value is at position "<<position<<endl;
                        break;

                        case 6:
                        cout<<"Insert Value which you want to search "<<endl;
                        cin>>value;
                        dd = Search_value_in_Duplicate_ValuedList_Return(head,value);
                         len = dd.position[0];
                                if(len==1)
                         {
                             cout<<"Value is not found"<<endl;
                         }
                         else
                         {
                             cout<<"Positions of searched value are ";
                             for(int i=1;i<len;i++)
                             {
                                 cout<<dd.position[i];
                                 if(i<len-1)
                                    cout<<",";
                             }
                             cout<<endl;

                         }
                        break;

                        case 7:
                            cout<<"enter searched value"<<endl;
                            cin>>sv;
                            cout<<"enter the value which do you wan to insert"<<endl;
                            cin>>value;
                            Insert_after_before_ofA_Specific_Value(head,sv,value);
                        break;

                        case 8:
                            cout<<"enter searched value"<<endl;
                            cin>>sv;
                            cout<<"enter the value which do you wan to insert"<<endl;
                            cin>>value;
                            Insert_after_before_ofA_Specific_Value_Duplicate_LinkedList(head,sv,value);
                             cout<<"Linked List: "<<endl;
                            Display(head);
                            break;

                        case 9:
                            Delete_from_head(head);
                            cout<<"Linked List: "<<endl;
                            Display(head);
                            break;
                        case 10:
                            Delete_from_tail(head);
                            cout<<"Linked List: "<<endl;
                            Display(head);
                            break;

                        case 11:
                            cout<<"enter position"<<endl;
                            cin>>position;
                            Delete_from_specific_Position(head,position);
                             cout<<"Linked List: "<<endl;
                            Display(head);
                            break;
                           case 12:
                               cout<<"Insert Value: "<<endl;
                                cin>>value;
                            Delete_value_from_AUnique_Doubly_LinkedList(head, value);
                            cout<<"Linked List: "<<endl;
                            Display(head);
                            break;

                            case 13:
                               cout<<"Insert Value: "<<endl;
                                cin>>value;
                                Delete_value_from_ADuplicate_Doubly_LinkedList(head,value);
                            cout<<"Linked List: "<<endl;
                            Display(head);
                            break;

                default:
                break;
        }

        cout<<"Next Choice"<<endl;
        cin>>choice;
    }

    cout<<"Linked List: "<<endl;
    Display(head);
    cout<<"Length is: "<<endl;
    int len=length(head);
    if(len==-1)
    {
        cout<<"Length is 0 "<<endl;
    }
    else
    {
        cout<<len<<endl;
    }
}
