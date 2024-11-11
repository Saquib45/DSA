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
    cout<<"enter the data:";
    cin>>data;
    head=NULL;
    node* tail=NULL;
    while(data!=-1){
        if(head==NULL){
            head=new node(data);
            tail=head;
        }
        else{
            node* newnode=new node(data);
            tail->next=newnode;
            tail=tail->next;
        }
        cout<<"enter the data:";
        cin>>data;
    }
    return head;
}

node* roatedList(node* head,int k){
    if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        int len = 1;
        node* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        if (k > len) {
            k = k % len;
            if (k == 0) {
                return head;
            }
        }
        if (k <= len) {
            k = len - k;
            if (k == 0) {
                return head;
            }
        }

        int count = 1;
        node* curr = head;
        while (count < k && curr != NULL) {
            curr = curr->next;
            count++;
        }

        node* temp = curr->next;
        curr->next = NULL;
        tail->next = head;
        return temp;
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
    cout<<"linked list is:";
    print(head);
    int k;
    cout<<endl<<"enter the number of rotation:";
    cin>>k;
    node* roated=roatedList(head,k);
    print(roated);
    return 0;
}