#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insertFirst(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int before, int value) {
    Node* temp = head;

    while (temp->data != before) {
        temp = temp->next;
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFirst() {
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteLast() {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    head = NULL;
    delete temp;
}

void deleteAfter(int before) {
    Node* temp = head;
    while (temp->data != before) {
        temp = temp->next;
    }
    Node* node = temp->next;    
    temp->next = node->next;
    node->next->prev = temp;
    delete node;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-";
        temp = temp->next;
    }
}



