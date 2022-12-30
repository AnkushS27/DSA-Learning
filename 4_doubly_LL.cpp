#include<iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    Node(int dt){
        this->prev = NULL;
        this->data = dt;
        this->next = NULL;
    }
};

void insertAtBeginning(Node* &head, Node* &tail, int dt){
    if(head == NULL){
        Node* temp = new Node(dt);
        head = temp;
        tail = temp;
    } else{
        Node* temp = new Node(dt);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd(Node* &head, Node* &tail, int dt){
    if(tail == NULL){
        Node* temp = new Node(dt);
        head = temp;
        tail = temp;
    } else{
        Node* temp = new Node(dt);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    cout<<endl;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    
    return len;
}

void insertAtPosition(Node* &head, Node* &tail, int dt, int position){
    if(position == 1){
        insertAtBeginning(head, tail, dt);
        return;
    }

    Node* temp = head;
    int cnt=1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtEnd(head, tail, dt);
        return;
    }

    Node* nodeToInsert = new Node(dt);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void printNodeData(Node* head){
    Node* temp = head;

    cout<<endl;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    // Node* newNode = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    insertAtBeginning(head, tail, 6);

    cout<<"Length: "<<getLength(head);
    printNodeData(head);
    cout<<"\nHead: "<<head->data<<"\ntail: "<<tail->data<<"\n------x------x-----";

    insertAtEnd(head, tail, 8);

    cout<<"Length: "<<getLength(head);
    printNodeData(head);
    cout<<"\nHead: "<<head->data<<"\ntail: "<<tail->data<<"\n------x------x-----";

    insertAtPosition(head, tail, 2, 2);
    cout<<"Length: "<<getLength(head);
    printNodeData(head);
    cout<<"\nHead: "<<head->data<<"\ntail: "<<tail->data<<"\n------x------x-----";

    insertAtPosition(head, tail, 11, 1);
    cout<<"Length: "<<getLength(head);
    printNodeData(head);
    cout<<"\nHead: "<<head->data<<"\ntail: "<<tail->data<<"\n------x------x-----";

    insertAtPosition(head, tail, 15, 5);
    cout<<"Length: "<<getLength(head);
    printNodeData(head);
    cout<<"\nHead: "<<head->data<<"\ntail: "<<tail->data<<"\n------x------x-----";

    return 0;
}