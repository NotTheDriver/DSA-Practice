#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
class Solution
{
    private:
    void insertAtTail(struct Node* &ansHead, struct Node* &ansTail, int val){
        Node* temp=new Node(val);
        if(ansHead==NULL){
            ansHead=temp;
            ansTail=temp;
            return;
        }
        else{
            ansTail->next=temp;
            ansTail=temp;
        }
    }
    struct Node* reverse(struct Node* &head){
        if(head==NULL){
            return head;
        }
        else{
            Node*curr=head;
            Node*next=NULL;
            Node*prev=NULL;
            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
    }
    struct Node* add(struct Node* first, struct Node* second){
        int carry=0;
        Node* ansHead=NULL;
        Node *ansTail=NULL;
        while(first!=NULL || second!=NULL || carry!=0){
            int val1=0;
            if(first!=NULL){
                val1=first->data;
            }
            int val2=0;
            if(second!=NULL){
                val2=second->data;
            }
            int sum=carry+val1+val2;
            int digit=sum%10;
            insertAtTail(ansHead,ansTail,digit);
            carry=sum/10;
            if(first!=NULL)
                first=first->next;
            if(second!=NULL)  
                second=second->next;
        }
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        Node* sum=add(first,second);
        sum=reverse(sum);
        return sum;
    }
};

int main(){
    return 0;
}