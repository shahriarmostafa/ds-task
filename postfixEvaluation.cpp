#include<iostream>
#include<cctype>
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

int evaluatePostfix(string expr);

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

int evaluatePostfix(string expr)
{
    stack_initialize();
    for(int i = 0; i < (int)expr.length(); i++)
    {
        char c = expr[i];
        if(c == ' ') continue;

        if(isdigit(c))
        {
            push(c - '0'); // single digit
        }
        else
        {
            int op2 = pop();
            int op1 = pop();
            int res = 0;
            switch(c)
            {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
            }
            push(res);
        }
    }
    return topp();
}

int main()
{
    string post;
    cout << "Enter postfix expression (single digits): ";
    getline(cin, post);

    int ans = evaluatePostfix(post);
    cout << "Result = " << ans << endl;

    return 0;
}
