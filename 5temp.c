#include <stdio.h>
#include <ctype.h>

#define maxst 10

int prec(char c)
{
    // Set precedence levels
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '(')
        return 0; // '(' should not affect precedence
    return -1; // For ')' and any other invalid character

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
    if (*top < 0)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("%c ", Stack[*top]);
        (*top)--;
    }
}

void converter(char Stack[], char In[], int *top)
{
    int i = 0;

    while (In[i] != '\0')
    {
        // If the character is an operator
        if (In[i] == '*' || In[i] == '/' || In[i] == '+' || In[i] == '-')
        {
            while (*top >= 0 && prec(Stack[*top]) >= prec(In[i]))
            {
                pop(Stack, top);
            }
            push(Stack, In[i], top);
        }
        // If the character is '('
        else if (In[i] == '(')
        {
            push(Stack, In[i], top);
        }
        // If the character is ')'
        else if (In[i] == ')')
        {
            while (*top >= 0 && Stack[*top] != '(')
            {
                pop(Stack, top);
            }
            if (*top >= 0 && Stack[*top] == '(')
            {
                (*top)--; // Pop the '(' from the stack
            }
            else
            {
                printf("\nMismatched parentheses");
                return;
            }
        }
        // If the character is an operand
        else
        {
            printf("%c ", In[i]);
        }
        i++;
    }

    // Pop all the operators left in the stack
    while (*top >= 0)
    {
        if (Stack[*top] == '(')
        {
            printf("\nMismatched parentheses");
            return;
        }
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
