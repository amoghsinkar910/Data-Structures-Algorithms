// author: _mayor 
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

void del(Node* loop, Node* head)
{
    Node* p1,*p2;
    p1=loop;
    p2=loop;
    
    int cnt=1;
    while(p1->next!=p2){
        cnt++;
        p1=p1->next;
    }
    
    p1=head,p2=head;
    for(int i=0;i<cnt;i++) p2=p2->next;
    
    while(p2!=p1)
    {
        p1=p1->next;
        p2=p2->next;
    }
    
    while(p2->next!=p1)
    {
        p2=p2->next;
    }
    p2->next=NULL;
}

void detectLoop(Node* head)
{
    Node* f=head,*s=head;
    while(f!=NULL && f->next!=NULL && s!=NULL)
    {
        s=s->next;
        f=f->next->next;
        if(s==f) del(s,head);
    }
}


void removeLoop(Node* head)
{
    detectLoop(head);
}



