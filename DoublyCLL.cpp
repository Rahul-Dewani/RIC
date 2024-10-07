#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyCircularLL{
private:
    Node* head;

public:
    DoublyCircularLL() : head(nullptr) {}

   
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

 
    void insertAtEnd(int value) {
        Node* newNode = createNode(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void insertAtBegin(int value) {
        Node* newNode = createNode(value);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(int value) {
        if (!head) return;

        Node* current = head;
        Node* prevNode = nullptr;
        if (current->data == value && current->next == head) {
            delete current;
            head = nullptr;
            return;
        }

        do {
            if (current->data == value) {
                if (current == head) {
                    Node* last = head->prev;
                    head = head->next;
                    head->prev = last;
                    last->next = head;
                    delete current;
                } else {
                    prevNode->next = current->next;
                    current->next->prev = prevNode;
                    delete current;
                }
                return;
            }
            prevNode = current;
            current = current->next;
        } while (current != head);
    }

    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularLL list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "List after inserting elements at the end: ";
    list.display();

    list.insertAtBegin(5);
    cout << "List after inserting element at the beginning: ";
    list.display();

    list.deleteNode(20);
    cout << "List after deleting 20: ";
    list.display();

    return 0;
}
