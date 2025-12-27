#include<iostream>
using namespace std;
#define MAXSIZE 100

int s[MAXSIZE];
int top;

void push(int value);
int pop();
int topp();
bool isStackEmpty();
bool isStackFull();
void display_stack();
int stackSize();
void stack_initialize();
bool checkParenthesis(string line);

void push(int value)
{
    if(isStackFull()){
        cout<<"\tOverflow!!! Stack is Full ...";
    }
    else
    {
        s[top] = value;
        top++;
    }
}

int pop()
{
    if(isStackEmpty())
    {
        cout<<"\tUnderflow!!! Stack is Empty...";
        return -1;
    }
    else{
        top--;
        return s[top];
    }
}

bool isStackEmpty()
{
    return (top == 0);
}

bool isStackFull()
{
    return (top >= MAXSIZE);
}

int stackSize()
{
    return top;
}

void display_stack()
{
    for(int i = top - 1; i >= 0; i--){
        cout << "\t\t" << s[i] << endl;
    }
}

int topp()
{
    if(isStackEmpty()){
        cout<<"\tStack is Empty...";
        return -1;
    }
    else{
        return s[top - 1];
    }
}

void stack_initialize()
{
    top = 0;
}



bool checkParenthesis(string line)
{
    stack_initialize();
    for(int i = 0; i < line.length(); i++)
    {
        char ch = line[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(isStackEmpty()) return false;
            char topChar = (char)pop();
            if(topChar == '(' && ch == ')') return true;
            if(topChar == '{' && ch == '}') return true;
            if(topChar == '[' && ch == ']') return true;
            return false;
        }
    }
    return isStackEmpty();
}

int main()
{
    string line;
    cout << "Enter a line: ";
    cin>>line;

    if(checkParenthesis(exp))
        cout << "correct\n";
    else
        cout << "Not correct\n";

    return 0;
}
