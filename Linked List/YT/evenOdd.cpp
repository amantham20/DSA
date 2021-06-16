#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);
    if(head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp=temp->next;
    }
    temp->next=n;
    
}

void insertAtHead(Node* &head, int val) {
    Node * n = new Node(val);
    n->next = head;
    head = n;
}

void evenAfterOdd(Node* &head) {
    Node* odd = head;
    Node* even = head->next;
    Node* evenstart = even;
    
    while(odd->next != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;

    }
    odd->next = evenstart;
    if(odd->next!=NULL) {
        even->next = NULL;
    }
}

void Display(Node* head) {  
    Node * temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL" << endl;
}


int main() {
    Node* head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    Display(head);
    evenAfterOdd(head);
    Display(head);

}