#include <stdio.h>
#include <string.h>
#define max 5

void insert(int Nq[], int Pq[], int *f, int *r, int *fp, int *rp)
{
    int ele;
    printf("\nEnter element : ");
    scanf("%d", &ele);
    if (ele <= 60)
    {
        if (*f == max - 1)
        {
            printf("\nNormal Queue is full");
        }
        else
        {
            if (*f == -1 && *r == -1)
            {
                *f = *r = 0;
                printf("\n%d inserted at %d ", ele, *r);
            }
            else
            {
                *r++;
                Nq[*r] = ele;
                printf("\n%d inserted at %d ", ele, *r);
            }
        }
    }
    else
    {
        if (*fp == max - 1)
        {
            printf("\nPriority Queue is full");
        }
        else
        {
            if (*fp == -1 && *rp == -1)
            {
                *f = *r = 0;
                printf("\n%d inserted at %d ", ele, *r);
            }
            else
            {
                (*r)++;
                Nq[*r] = ele;
                printf("\n%d inserted at %d ", ele, *r);
            }
        }
    }
}
int main()
{
    int Nq[max];
    int Pq[max];
    int f = -1, r = -1, fp = -1, rp = -1;
    int *fnp = &f, *rnp = &r, *fpp = &fp, *rpp = &rp;

    while (1)
    {
        insert(Nq, Pq, fnp, rnp, fpp, rpp);
        break;
    }
    return 0;
}