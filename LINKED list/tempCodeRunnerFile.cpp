#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    // ~Node(){
    //     int value=this->data;
    //     if(next!=NULL){
    //     delete next;
    //     this->next=NULL;
    // }
    // cout<<"Memory is free "<<value<<endl;
    // }

};
void InsertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtPosition(Node* &head,Node* &tail,int position, int d){
    if(position==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    Node* newNode=new Node(d);
    newNode->next=temp->next;
    temp->next=newNode;
}
void deleteNode(int position, Node* &head){
    if(position==1){
        Node* temp=head;
        head=head->next;
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
        prev->next=current->next;
        current->next=NULL;
        delete current;

    }
}
void recursiveReversal(Node* &head,Node* &curr,Node* &prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node* forward=curr->next;
    recursiveReversal(head,forward,curr);
    curr->next=prev;
} 
Node *reverseLinkedList(Node* &head) 
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    // Write your code here
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
// Node* removeDups(Node* head){
//     if(head==NULL){
//         return NULL;
//     }
//     Node* curr=head;
//     while(curr!=NULL){
//         if((curr->next!=NULL) && curr->data==curr->next->data){
//             cout<<curr->next->data<<" herre "<<endl;
//             Node* next_next=curr->next->next;
//             cout<<next_next->data<<" herre "<<endl;
//             Node* todelete=curr->next;
//             cout<<todelete->data<<" herre "<<endl;
//             delete(todelete);
//             curr->next=next_next;
//         }
//         else{
//             curr=curr->next;
//         }
//     }
//     return head;
// }
Node * uniqueSortedList(Node * &head) {
   	//empty List
    if(head == NULL)
        return NULL;
    
    //non empty list
    Node* curr = head;
    
    while(curr != NULL) {
        
        if( (curr -> next != NULL) && curr -> data == curr -> next -> data) {
            Node* next_next = curr ->next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else //not equal
        {
            curr = curr -> next;
        }   
    }
    
    return head; 
}
int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    // cout<<node1->data<<endl<<node1->next;
    InsertAtHead(head,1);
    print(head);    
    insertAtTail(tail,3);
    print(head);
    insertAtTail(tail,3);
    print(head);
    insertAtPosition(head,tail,5,7);
    print(head);
    insertAtPosition(head,tail,6,8);
    print(head);
    Node*node2=NULL;
    node2=uniqueSortedList(head);
    print(node2);
    return 0;
}