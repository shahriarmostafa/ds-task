#include<iostream>
#include<cctype>
using namespace std;

#define MAXSIZE 10

char s[MAXSIZE];
int top;

void push(char value);
char pop();
char topp();
bool isStackEmpty();
bool isStackFull();
void display_stack();
int stackSize();
void stack_initialize();

int precedence(char op);
bool isOperator(char c);
string infixToPostfix(string line);

void push(char value)
{
    if(isStackFull()){
        cout << "\tOverflow!!! Stack is Full ...";
    }
    else
    {
        s[top] = value;
        top++;
    }
}

char pop()
{
    if(isStackEmpty())
    {
        cout << "\tUnderflow!!! Stack is Empty...";
        return -1;
    }
    else {
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

char topp()
{
    if(isStackEmpty()){
        cout << "\tStack is Empty...";
        return -1;
    }
    else {
        return s[top - 1];
    }
}

void stack_initialize()
{
    top = 0;
}

int checkoperator(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string line)
{
    stack_initialize();
    string result = "";

    for(int i = 0; i < line.length(); i++)
    {
        char ch = line[i];
        if(ch == ' ') continue;

        if(isalnum(ch))
        {
            result += ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(topp() != '(')
            {
                result += pop();  
            }
            pop();  
        }
        else if(isOperator(c))
        {
            while(topp() != '(' && checkoperator(topp()) >= checkoperator(ch))
            {
                result += pop(); 
            }
            push(ch);
        }
    }

    while(!isStackEmpty())
    {
        result += pop();
    }

    return result;
}

int main()
{
    string infix;
    cout << "Enter infix: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}
