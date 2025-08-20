/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head)
{   
    node* slow=head;
    node* fast=head;
    while(fast->next && fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


node* merge(node* l1, node* l2)
{   
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    node* dummy=new node(-1);
    node* tail=dummy;
    
    while(l1 && l2)
    {
        if(l1->data<=l2->data)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1)
    {
        tail->next=l1;
    }
    if(l2)
    {
        tail->next=l2;
    }
    return dummy->next;

}
node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* mid=findmid(head);

    node* left=head;
    node* right=mid->next;
    mid->next=NULL;


    left=mergeSort(left);
    right=mergeSort(right);


    node* result=merge(left,right);

    return result;
}
//added comments
/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head)
{   
    node* slow=head;
    node* fast=head;
    while(fast->next && fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


node* merge(node* l1, node* l2)
{   
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    node* dummy=new node(-1);
    node* tail=dummy;
    
    while(l1 && l2)
    {
        if(l1->data<=l2->data)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1)
    {
        tail->next=l1;
    }
    if(l2)
    {
        tail->next=l2;
    }
    return dummy->next;

}
node* mergeSort(node *head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* mid=findmid(head);

    node* left=head;
    node* right=mid->next;
    mid->next=NULL;


    left=mergeSort(left);
    right=mergeSort(right);


    node* result=merge(left,right);

    return result;
}