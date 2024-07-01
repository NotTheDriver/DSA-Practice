#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    //destructor
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"space freed of data "<<value<<endl;
    }

};
void insertAtHead(Node* &head,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        //tail=temp;
    }
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
        //head=temp;
    }
    Node* temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertAtPosition(Node* &head, Node* &tail, int position, int value){
    //when position is 1
    if(position==1){
        insertAtHead(head,value);
        return;
    }
    else{
        //any other position
        Node* temp=head;
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            insertAtTail(tail,value);
            return;
        }
        Node* newNode=new Node(value);
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
        newNode->prev=temp;
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleteNode(int position, Node* &head){
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //for any other position
        Node* current=head;
        Node* prev=NULL;
        int count=1;
        while(count<position){
            prev=current;
            current=current->next;
            count++;
        }
        current->prev=NULL;
        prev->next=current->next;
        current->next->prev=prev;
        current->next=NULL;
        delete current;
    }
}

int main(){
    Node* node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    print(head);
    insertAtHead(head,33);
    print(head);
    print(tail);
    insertAtTail(tail,20);
    print(head);
    print(tail);
    insertAtTail(tail,27);
    print(head);
    print(tail);
    insertAtPosition(head,tail,3,100);
    print(head);
    print(tail);
    deleteNode(3,head);
    print(head);
    print(tail);
    return 0;
}