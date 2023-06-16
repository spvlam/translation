#include <stdio.h>
#include <string.h>
#include <ctype.h>
// push, pop, top, isEmpty

char arr[100];
int n = 0;
void push(char s)
{
    arr[n] = s;
    n += 1;
}
int isEmpty()
{
    return n == 0;
}
char pop()
{
    if (isEmpty())
    {
        return 'c';
    }
    else
    {
        n -= 1;
        return arr[n];
    }
}
char top()
{
    if (isEmpty())
    {
        return 'c';
    }
    else
    {
        return arr[n - 1];
    }
}
int checkOperator(char s)
{
    return s == '+' || s == '-' || s == '*' || s == '/' || s == '^';
}
int priority(char s)
{
    if (s == '+' || s == '-')
        return 1;
    if (s == '*' || s == '/')
        return 2;
    if (s == '^')
        return 3;
}
int Donothavequote()
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{' || arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            return 0;
        }
    }
    return 1;
}
int checkParensisOpen(char s)
{
    if(s=='(' || s=='['|| s=='{') return 1;
    return 0;
}

int main()
{
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            printf("%c", s[i]);
        }
        else
        {
            if (checkOperator(s[i]))
            {
                if (isEmpty())
                {
                    push(s[i]);
                    continue;
                }
                else if ((priority(s[i]) < priority(top())) && Donothavequote())
                {
                    while (!isEmpty())
                    {
                        printf("%c", pop());
                    }
                }
                push(s[i]);
            }
            else
            {
                if (checkParensisOpen(s[i]))
                {
                    char fi = pop();

                    while (!isEmpty())
                    {
                        printf("%c", pop());
                    }
                    push(fi);
                    push(s[i]);
                }
                else
                {
                    while (top() != '(' || top() != '[' || top() != '{')
                    {
                        printf("%c", pop());
                    }
                    if (top() == '(' || top() == '[' || top() == '{')
                    {
                        pop();
                    }
                }
            }
        }
    }
    while (!isEmpty())
    {
        printf("%c", pop());
    }
}