#include<iostream>
using namespace std;
#define MAXSIZE 10;

int s[MAXSIZE];
int top;

void push(int value);
int pop();
int topp();
bool isStackEmpty();
bool isStackFull();
void display_stack();
int stackSize();



void push(int value)
{
    if(isStackFull()){
        cout<<"\t Overflow!!! Stack is Full ...";
    }
    else
    {
      s[top]=value;
      top++;
    }
}

int pop()
{
    int x;
    if(isStackEmpty())
    {
       cout<<"\tUnderflow!!! Stack is Empty...";
    }
    else{
        top--;
        x=s[top] ;
        return x;
    }

}

bool isStackEmpty()
{
    return (top==0);
}

bool isStackFull()
{
    return (top>=MAXSIZE);
}

int stackSize()
{
    return top;
}

void display_stack()
{
    for(int i=top-1;i>=0;i--){
        cout<< "\t\t"<<s[i] <<endl;
    }
}
int topp()
{
    if(isStackEmpty()){
        cout<<"\tStack is Empty...";
    }
    else{
        return s[top-1];
    }
}
void stack_initialize()
{
    top=0;
}
int main(){
    int option,n, value;
    stack_initialize();
    cout<<"C++ program to implement stack operations\n";
    do{
        cout<<"\n\n 1.Push an element in stack";
        cout<<"\n 2.Pop an element from stack";
        cout<<"\n 3.Display stack";
        cout<<"\n 4.Display current stack size ";
        cout<<"\n 5.Display top element ";
        cout<<"\n 6.Exit";
        cout<<"\n Enter your choice: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"\n Insert an element in stack : ";
            cin>>n;
            push(n);
            break;
        case 2:
            value = pop();
            if(value)
            cout<<"\n \tPopped element is: "<<value<<endl;
            break;
        case 3:
            display_stack();
            break;
        case 4:
            value=stackSize();
            cout<<" \n\tCurrently number of element in stack is "<<value;
            break;
        case 5:
            value=topp();
            if(value)
                cout<<"\n\tCurrent top element is "<<value;
            break;
        case 6:
            return 0;
        }

    }
    while(option<=6);

    return 0;
}



//---------------------------------------------------------------------------------
#include<iostream>
using namespace std;
#define MAXSIZE 10;

int q[MAXSIZE];
int front, rear;
front = -1; rear= -1;

void enqueue(int value);
int DeQueue();
bool isEmpty();
bool isFull();
void ShowQueue();
int frontElement();

void EnQueue(int value)
{
    if(isFull()){
        cout<<"Overflow!!! Queue is Full ...";
    }
    else
    {
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        rear++;
        q[rear] = value;
    }
}

int DeQueue()
{
    int x;
    if(isEmpty())
    {
       cout<<"Underflow!!! Queue is Empty...";
    }
    else{
        x = q[front];
        front++;
        if(front > rear) {
            front = rear = -1;
        }
        return x;
    }
}

bool isEmpty()
{
    return (front == -1);
}

bool isFull()
{
    return (rear >= MAXSIZE - 1);
}


void ShowQueue()
{
    for(int i = front; i <= rear; i++){
        cout<< q[i] << endl;
    }
}

int FrontValue()
{
    if(isEmpty()){
        cout<<"Queue is Empty...";
    }
    else{
        return q[front];
    }
}

//-----------------------------------------------------------------------

#include<iostream>
using namespace std;
#define MAXSIZE 10;

int q[MAXSIZE];
int front = -1, rear = -1;

void EnQueue(int value)
{
    if((rear + 1) % MAXSIZE == front)
        cout << "Overflow!!! Queue is Full ...";
    else
    {
        if(front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAXSIZE;
        }
        q[rear] = value;
    }
}

int DeQueue()
{
    int x;
    if(front == -1)
    {
        cout << "Underflow! Queue is Empty...";
        return -1;
    }
    else
    {
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAXSIZE;
        }
        return x;
    }
}

bool isEmpty()
{
    return (front == -1 && rear == -1);
}

bool isFull()
{
    return ((rear + 1) % MAXSIZE == front);
}

void ShowQueue()
{
    if(isEmpty())
        cout << "Queue is Empty";
    else
    {
        int i = front;
        while(i != rear)
        {
            cout << q[i] << endl;
            i = (i + 1) % MAXSIZE;
        }
        cout << q[rear] << endl;
    }
}

int FrontValue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty...";
    }
    else{
        return q[front];
    }
}


