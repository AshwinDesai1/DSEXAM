#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *Right;
};
struct TreeNode * Insert(struct TreeNode *root, int ele)
{
    struct TreeNode *n, *curr,*Prev;
    Prev=NULL;
    curr = root;
    n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    n->data = ele;
    n->left=NULL;
    n->Right=NULL;
    if (root == NULL)
    {
       root=n;
    }
    else
    {
        while (curr != NULL)
        {
            Prev=curr;
            if (curr->data <= ele)
            {
                curr = curr->Right;
            }
            else
            {
                curr = curr->left;
            }
        }
        
        if(Prev->data>ele)
        {
            Prev->left=n;
        }
        else{
            Prev->Right=n;
        }
    }
    return root;
}
void inorder(struct TreeNode *root)
{
    // struct TreeNode *curr;
    // curr = root;
    if(root!=NULL)
    {
        printf("%d ", root->data);
        inorder(root->left);
        inorder(root->Right);
    }
}
int main()
{
    struct TreeNode *root = NULL;
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
            printf("\nEnter ele:");
            scanf("%d", &ele);
            root=Insert(root, ele);
            break;
        case 2:
            inorder(root);
            break;
        default:
            break;
        }
    }
    return 0;
}
