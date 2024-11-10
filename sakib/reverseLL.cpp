#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};

node* input(node* head){
    int data;
    cout<<"enter the head data:"<<endl;
    cin>>data;
    head=NULL;
    node* tail=NULL;
    while(data!=-1){
        if(head==NULL){
            head=new node(data);
            tail=head;
        }
        else{
            tail->next=new node(data);
            tail=tail->next;
        }
        cout<<"enter the next data:"<<endl;
        cin>>data;
    }
    return head;
}

node* reverse_recursive(node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node* smallans=reverse_recursive(head->next);
    node* tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallans;
}

node* reverse_iterative(node* head){
    node* curr=head;
    node* prev=NULL;
    while(curr!=NULL){
        node* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
}
void print(node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    node* head=NULL;
    head=input(head);
    node* temp=head;
    cout<<"linked list is:";
    print(temp);

    cout<<endl<<"recursive reverse linked list:";
    node* h1=reverse_recursive(temp);
    print(h1);

    temp=head;
    cout<<endl<<"iterative reverse linked list:";
    node* h2=reverse_iterative(h1);
    print(h2);
}