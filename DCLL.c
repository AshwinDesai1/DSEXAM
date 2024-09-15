#include <stdio.h>
#include <stdlib.h>
struct student
{
    int data;
    //    char name[20];
    struct student *next;
    struct student *prev;
};

struct student *insertDCL(struct student *head, int ele)
{
    struct student *neww, *Curr, *Previous;

    neww = (struct student *)malloc(sizeof(struct student));
    neww->data = ele;
    if (head == NULL)
    {
        neww->next = neww;
        neww->prev = neww;
        head = neww;
    }
    Previous = NULL;
    Curr = head;

    while (Curr->data < ele && Curr->next != head)
    {
        Previous = Curr;
        Curr = Curr->next;
    }
    if (Previous == NULL && ele <= Curr->data)
    {
        neww->next = Curr;
        neww->prev = Curr->prev;
        neww->prev->next = neww;
        Curr->prev = neww;
        head = neww;
    }
    else
    {
        if (ele > Curr->data)
        {
            neww->prev = Curr;
            neww->next = Curr->next;
            Curr->next->prev = neww;
            Curr->next = neww;
        }
        else
        {
            neww->next = Curr;
            neww->prev = Previous;
            Previous->next = neww;
            Curr->prev = neww;
        }
    }
    return head;
}
void display(struct student *head)
{
    struct student *tr;
    tr = head;
    if (tr == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        printf("\n");
        while (tr->next != head)
        {
            printf("%d  ", tr->data);
            tr = tr->next;
        }
        printf("%d  ", tr->data);
    }
}
int main()
{

    struct student *head = NULL;

    int ele, c;

    while (1)
    {
        printf("\n1:insert");
        printf("\n2:Display");
        // printf("\n3:display");
        // printf("\n4:exit");
        printf("\nEnter your choice:");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("\nEnter id:");
            scanf("%d", &ele);
            head = insertDCL(head, ele);
            break;
        case 2:
            display(head);
            break;
        default:
            break;
        }
    }
    return 0;
}
