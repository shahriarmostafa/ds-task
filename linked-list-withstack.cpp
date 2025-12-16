#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insertLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}


int searchList(int target) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == target) {
            cout << "Element found at index: " << index << endl;
            return index; 
        }
        temp = temp->next;
        index++;
    }
    return -1; 
}

void insertAfter(int before, int value) {
    Node* temp = head;
    while (temp->data != before) {
        temp = temp->next;
    }
    Node* newNode = new Node;
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
}

int deleteFirst() {
    if (head == NULL) {
        return -1;
    }
    Node* temp = head;
    int deletedValue = temp->data;
    head = head->next;
    delete temp;
    return deletedValue;
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << "\t\t" << temp->data << endl;
        temp = temp->next;
    }
}


void push(int value) {
    insertFirst(value);
    cout << "\n\tElement inserted successfully.";
}

int pop() {
    if (head == NULL) {
        cout << "\tUnderflow!!! Stack is Empty...";
        return -1;
    }
    return deleteFirst();
}

int topp() {
    if (head == NULL) {
        cout << "\tStack is Empty...";
        return -1;
    }
    return head->data;
}

bool isStackEmpty() {
    return (head == NULL);
}

int stackSize() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}


int main() {
    int option, value;
    cout << "C++ program to implement Stack using Linked List\n";

    do {
        cout << "\n\n 1.Push (Insert First)";
        cout << "\n 2.Pop (Delete First)";
        cout << "\n 3.Display Stack (Print List)";
        cout << "\n 4.Display Current Stack Size";
        cout << "\n 5.Display Top Element";
        cout << "\n 6.Exit";
        cout << "\n Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "\n Enter element to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    cout << "\n \tPopped element is: " << value << endl;
                break;
            case 3:
                printList();
                break;
            case 4:
                cout << " \n\tCurrently number of elements: " << stackSize();
                break;
            case 5:
                value = topp();
                if (value != -1)
                    cout << "\n\tCurrent top element is " << value;
                break;
            case 6:
                return 0;
            default:
                cout << "\n Invalid Choice!";
        }
    } while (option != 6);

    return 0;
}