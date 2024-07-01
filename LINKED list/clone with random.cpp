class Solution
{
    private:
    void insertAtTail(Node* &head,Node* &tail,int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        unordered_map<Node*,Node*> randomMap;
        Node*head1=head;
        Node*head2=cloneHead;
        while(head1!=NULL){
            randomMap[head1]=head2;
            head1=head1->next;
            head2=head2->next;
        }
        head1=head;
        head2=cloneHead;
        while(head1!=NULL){
            head2->arb=randomMap[head1->arb];
            head2=head2->next;
            head1=head1->next;
        }
        return cloneHead;
    }

};

//without map
