#include <stdio.h>
#define maxst 10

int prec(char c)
{
    int p;
    if (c == '*' || c == '/')
    {
        p = 2;
    }
    else if (c == '+' || c == '-')
    {
        p = 1;
    }
    else if (c == '(' || c == ')')
    {
        p = 0;
    }
    return p;
}
void push(char Stack[], char c, int *top)
{
    if (*top == maxst - 1)
    {
        printf("\nStack Full");
    }
    else
    {
        (*top)++;
        Stack[*top] = c;
    }
}
void pop(char Stack[], int *top)
{
    int rele;
    if (*top < 0)
    {
        printf("Underflow");
    }
    else
    {
        printf("%c ", Stack[*top]);
        *top--;
    }
}
void converter(char Stack[], char In[], int *top)
{
    int i = 0;

    while (In[i] != '\0')
    {
        if (In[i] == '*' || In[i] == '/' || In[i] == '+', In[i] == '-')
        {

            while (prec(In[i]) <= prec(Stack[*top]) && *top >= 0)
            {
                pop(Stack, top);
            }
            push(Stack, In[i], top);
        }

        else if (In[i] == '(')
        {
            push(Stack, In[i], top);
        }
        else if (In[i] == ')')
        {
            while (Stack[*top] != '('&& Stack[*top]>=0)
            {
                pop(Stack, top);
            }
            if(*top>=0 && Stack[*top]=='(')
            {
                *top--;
            }
        }

        else
        {
            printf("%c ", In[i]);
        }
        i++;
    }
    while (*top >= 0)
    {
        pop(Stack, top);
    }
}
int main()
{
    char In[20], Stack[maxst];
    int t = -1, *top = &t;
    printf("\nEnter infix : ");
    scanf("%s", In);
    converter(Stack, In, top);
    return 0;
}