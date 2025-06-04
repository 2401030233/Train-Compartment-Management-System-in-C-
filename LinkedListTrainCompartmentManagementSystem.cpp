# include <iostream>
using namespace std;
struct Node
{
    Node *prev;
    int data;
    Node *next;
} *head, *rear;
class TrainManager
{
public:
    void attachCompartment (int d);
    void detachByPosition (int pos);
    void displayForward ();
    void displayBackward ();
    void deleteFirst ();
    void deleteLast ();
};
void TrainManager::attachCompartment (int d)
{
    Node *temp=new Node ();
    temp->data=d;
    temp->next=nullptr;
    temp->prev=nullptr;
    if (head==nullptr)
    {
        head=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
    cout<<"\nAdded new Compartment no. "<<d<<" at end\n";
}
void TrainManager::deleteFirst ()
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        int d=head->data;
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nRemoved head coach with compartment No. "<<d<<endl;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=nullptr;
        int d=temp->data;
        delete temp;
        temp=nullptr;
        cout<<"\nRemoved first coach with compartment No. "<<d<<endl;
    }
}
void TrainManager::deleteLast ()
{
    if (head==nullptr)
    {
        cout<<"\nList is empty!\nNothing to delete\n";
    }
    else if (head->next==nullptr)
    {
        int d=head->data;
        delete head;
        head=nullptr;
        rear=nullptr;
        cout<<"\nRemoved head coach with compartment No. "<<d<<endl;
    }
    else
    {
        Node *temp=rear;
        rear=rear->prev;
        int d=temp->data;
        rear->next=nullptr;
        delete temp;
        temp=nullptr;
        cout<<"\nRemoved last coach with compartment No. "<<d<<endl;
    }
}
void TrainManager::detachByPosition (int pos)
{
    if (pos<=0)
    {
        cout<<"\nERROR : Invalid position entered by user!\n";
    }
    else
    {
        if (pos==1)
        {
            deleteFirst ();
        }
        else
        {
            Node *temp1=head, *n=head->next, *p=head;
            int num=0;
            while (temp1!=nullptr)
            {
                num++;
                temp1=temp1->next;
            }
            if (pos>1 && pos<num)
            {
                Node *temp=head;
                int i=1;
                while (i<pos-1)
                {
                    p=n;
                    n=n->next;
                    i++;
                }
                temp=p->next;
                int d=temp->data;
                p->next=temp->next;
                delete temp;
                temp=nullptr;
                cout<<"\nRemoved compartment No. "<<d<<" from the train\n";
            }
            else if (pos==num)
            {
                deleteLast ();
            }
            else
            {
                cout<<"\nERROR : Position out of range!\n";
            }
        }
    }
}
void TrainManager::displayForward ()
{
    Node *temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
void TrainManager::displayBackward ()
{
    Node *temp=rear;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" -> ";
        temp=temp->prev;
    }
    cout<<"NULL\n";
}
void displayMenu ()
{
    cout<<"\nMenu :-\n";
    cout<<"\n1.Attach compartment\t2.Detach compartment by position\n3.Display Forward\t4.Display Backward\t5.Exit\n";
    cout<<"\nInput choice : ";
}
int main (void)
{
    int ch, pos, d;
    TrainManager t;
    do
    {
        displayMenu ();
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nInput compartment No. : ";
            cin>>d;
            t.attachCompartment (d);
            break;
        case 2:
            cout<<"\nInput position of compartment to be detached : ";
            cin>>pos;
            t.detachByPosition (pos);
            break;
        case 3:
            cout<<"\nForward : ";
            t.displayForward ();
            break;
        case 4:
            cout<<"\nBackward : ";
            t.displayBackward ();
            break;
        case 5:
            cout<<"\n======[Exiting the program...]======\n";
            exit (0);
            break;
        default:
            cout<<"\nInput valid choice!\n";
        }
    }
    while (ch!=5);
    return 0;
}
