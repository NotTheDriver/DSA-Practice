#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"space freed of data "<<value<<endl;
    }
};
void insert(Node* &tail,int element, int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }
    else{
        Node* current=tail;
        while(current->data!=element){
            current=current->next;
        }
        Node* temp=new Node(d);
        temp->next=current->next;
        current->next=temp;
}}
void print(Node* tail){
    Node* temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
    cout<<endl;
}
bool loopDetect(Node* head){
    if(head==NULL){
        return false;
    }
    map<Node*,int> visited;
    Node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}
//using Floyds cycle detection
Node* floydCycle(Node* &head){
    if(head==NULL){
        return 0;
    }
    Node* slow=head;
    Node* fast=head;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            cout<<"Loop at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}
Node* getStartNode(Node*head){
    if(head==NULL){
        return head;
    }
    Node* intersection=floydCycle(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
    
}
void removeLoop(Node* head){
    if(head==NULL){
        return;
    }
    Node* startofLoop=getStartNode(head);
    Node* temp=startofLoop;
    while(temp->next!=startofLoop){
        temp=temp->next;
    }
    temp->next=NULL;

}
// Node* floydCycle(Node* &head){
//     if(head==NULL){
//         return 0;
//     }
//     Node* slow=head;
//     Node* fast=head;
//     while(slow!=NULL && fast!=NULL){
//         fast=fast->next;
//         if(fast!=NULL){
//             fast=fast->next;
//         }
//         slow=slow->next;
//         if(slow==fast){
//             return slow;
//         }
//     }
//     return NULL;
// }
// Node* getStartNode(Node*head){
//     if(head==NULL){
//         return head;
//     }
//     Node* intersection=floydCycle(head);
//     if(intersection==NULL){
//         return NULL;
//     }
//     Node* slow=head;
//     while(slow!=intersection){
//         slow=slow->next;
//         intersection=intersection->next;
//     }
//     return slow;
    
// }
// Node *removeLoop(Node *head)
// {
//     // Write your code here.
//     if(head==NULL){
//         return NULL;
//     }
//     Node* startofLoop=getStartNode(head);
//     if(startofLoop==NULL){
//         return head;
//     }
//     Node* temp=startofLoop;
//     while(temp->next!=startofLoop){
//         temp=temp->next;
//     }
//     temp->next=NULL;
//     return head;

// }

int main(){
    Node* tail=NULL;
    insert(tail,3,5);
    print(tail);
    insert(tail,5,7);
    print(tail);
    insert(tail,7,13);
    print(tail);
    bool loop=floydCycle(tail);
    cout<<loop;
    return 0;

}