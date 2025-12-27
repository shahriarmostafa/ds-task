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

int precedence(char op);
bool isOperator(char c);
string infixToPostfix(string expr);

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

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string expr)
{
    stack_initialize();
    string result = "";

    for(int i = 0; i < (int)expr.length(); i++)
    {
        char c = expr[i];
        if(c == ' ') continue;

        if(isalnum(c))
        {
            result += c;
        }
        else if(c == '(')
        {
            push(c);
        }
        else if(c == ')')
        {
            while(!isStackEmpty() && (char)topp() != '(')
            {
                result += (char)pop();
            }
            pop(); // remove '('
        }
        else if(isOperator(c))
        {
            while(!isStackEmpty() && (char)topp() != '(' &&
                  precedence((char)topp()) >= precedence(c))
            {
                result += (char)pop();
            }
            push(c);
        }
    }

    while(!isStackEmpty())
    {
        result += (char)pop();
    }

    return result;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string post = infixToPostfix(infix);
    cout << "Postfix: " << post << endl;

    return 0;
}
