#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBeginning(Node* &head, int dt){
    Node* temp = new Node(dt);
    
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &tail, int dt){
    Node* temp = new Node(dt);
    
    tail->next = temp; 
    tail = tail->next;
}

void insertAtPosition(Node* &head, Node*&tail, int position, int dt){
    if(position == 1){
        insertAtBeginning(head, dt);
        return;
    }
    Node* temp = head;

    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    
    if(temp->next == NULL){
        insertAtEnd(tail, dt);
    } else{
        Node* temp2 = new Node(dt);
        temp2->next = temp->next;
        temp->next = temp2;
    }
}

void deleteNode(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void printNodeData(Node* &head) {
    Node* temp = head;
    
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main()
{
    Node* newNode = new Node(7);
    
    Node* head = newNode;
    Node* tail = newNode;
    
    insertAtBeginning(head, 5);
    
    insertAtEnd(tail, 1);
    insertAtBeginning(head, 6);
    
    insertAtPosition(head, tail, 5, 15);
    printNodeData(head);
    cout<<endl;
    deleteNode(head, 5);
    printNodeData(head);


    return 0;
}