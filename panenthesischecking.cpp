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

// extra helpers
bool arePair(char openB, char closeB);
bool isBalanced(string expr);

// ========== stack functions ==========
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

// ========== parentheses checking ==========
bool arePair(char openB, char closeB)
{
    if(openB == '(' && closeB == ')') return true;
    if(openB == '{' && closeB == '}') return true;
    if(openB == '[' && closeB == ']') return true;
    return false;
}

bool isBalanced(string expr)
{
    stack_initialize();
    for(int i = 0; i < (int)expr.length(); i++)
    {
        char ch = expr[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(isStackEmpty()) return false;
            char topChar = (char)pop();
            if(!arePair(topChar, ch)) return false;
        }
    }
    return isStackEmpty();
}

int main()
{
    string exp;
    cout << "Enter expression: ";
    getline(cin, exp);

    if(isBalanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
