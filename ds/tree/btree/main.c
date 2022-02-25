#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

void insert(node **rootp, int d)
{
    if (*rootp == NULL)
    {
        *rootp = malloc(sizeof *rootp);
        (*rootp)->left = NULL;
        (*rootp)->right = NULL;
        (*rootp)->data = d;
        return;
    }

    if (d >= (*rootp)->data)
    {
        insert(&(*rootp)->right, d);
    }
    else
    {
        insert(&(*rootp)->left, d);
    }
}

void before_print(node *root)
{
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    before_print(root->left);
    before_print(root->right);
}

void after_print(node *root)
{
    if (root == NULL)
        return;
    
    after_print(root->left);
    after_print(root->right);
    printf("%d ", root->data);
}

void mid_print(node *root)
{
    if (root == NULL)
        return;
    
    mid_print(root->left);
    printf("%d ", root->data);
    mid_print(root->right);
}

void destroy(node *root)
{
    if (root == NULL)
        return;
    
    destroy(root->left);
    destroy(root->right);
    free(root);
}

static int amount_of(node *root)
{
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL)
        return 1;

    return 1 + amount_of(root->left) + amount_of(root->right);
}

// make the tree, which root is @root, balance.
// return the balanced tree's root.
node *make_balance(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return root;

    int left_amount = amount_of(root->left);
    int right_amount = amount_of(root->right);

    if (abs(left_amount - right_amount) <= 1)
    {
        root->left = make_balance(root->left);
        root->right = make_balance(root->right);

        return root;
    }

    node *new_root = NULL, *tmp = NULL;

    if (left_amount > right_amount)
    {
        new_root = root->left;
        root->left = NULL; //important!
        tmp = new_root;
        while(tmp->right != NULL)
            tmp = tmp->right;
        tmp->right = root;
    }
    else
    {
        new_root = root->right;
        root->right = NULL; //important!
        tmp = new_root;
        while (tmp->left != NULL)
            tmp = tmp->left;
        tmp->left = root;
    }
    
    return make_balance(new_root);
}

int main()
{
    node *root = NULL;
    int arr[] = {1, 2, 7, 4, 6, 3, 8, 5};
    for (int i = 0; i < sizeof(arr) / sizeof *arr; i++)
    {
        insert(&root, arr[i]);
    }

    before_print(root);
    printf("\n");

    root = make_balance(root);

    before_print(root);
    printf("\n");

    destroy(root);
    return 0;
}
