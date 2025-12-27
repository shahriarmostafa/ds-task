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

int evaluatePostfix(string line);

void push(int value)
{
    if (isStackFull())
    {
        cout << "\tOverflow!!! Stack is Full ...\n";
    }
    else
    {
        s[top] = value;
        top++;
    }
}

int pop()
{
    if (isStackEmpty())
    {
        cout << "\tUnderflow!!! Stack is Empty...\n";
        return -1;
    }
    else
    {
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
    for (int i = top - 1; i >= 0; i--)
    {
        cout << "\t\t" << s[i] << endl;
    }
}

int topp()
{
    if (isStackEmpty())
    {
        cout << "\tStack is Empty...\n";
        return -1;
    }
    else
    {
        return s[top - 1];
    }
}

void stack_initialize()
{
    top = 0;
}

int evaluatePostfix(string line)
{
    stack_initialize();
    for (int i = 0; i < line.length(); i++)
    {
        char ch = line[i];
        if (ch == ' ') continue;
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int number1 = pop();
            int number2 = pop();
            int result= 0;
            switch (ch)
            {
                case '+': result= number1 + number2; break;
                case '-': result= number1 - number2; break;
                case '*': result= number1 * number2; break;
                case '/': 
                    if (number2 != 0) {
                        result= number1 / number2; 
                    }
                    break;
                default: 
                    cout << "Invalid operator\n";
                    return -1;
            }
            push(result);
        }
        else
        {
            cout << "Invalid character in expression: " << ch << endl;
            return -1;
        }
    }
    return topp();
}

int main()
{
    string post;
    cout << "Enter postfix: ";
    cin >> post;
    int ans = evaluatePostfix(post);
    cout << "Result = " << ans << endl;
    return 0;
}
