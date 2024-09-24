/*13. Write a program to implement tree sort algorithm.*/
#include <stdio.h>
#include <stdlib.h> // For malloc()

struct tree {
    struct tree *left;
    int num;
    struct tree *right;
};

void insert(struct tree **, int);
void inorder(struct tree *);

int main() {
    struct tree *t;
    int arr[10];
    int i;

    printf("\nEnter 10 elements: ");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    t = NULL;
    printf("\nThe elements of the array are:\n");
    for (i = 0; i < 10; i++)
        printf("%d\t", arr[i]);

    for (i = 0; i < 10; i++)
        insert(&t, arr[i]);

    printf("\nThe sorted array is:\n");
    inorder(t);

    return 0;
}

void insert(struct tree **tree_node, int num) {
    if (*tree_node == NULL) {
        *tree_node = (struct tree *)malloc(sizeof(struct tree)); // Corrected malloc
        (*tree_node)->left = NULL;
        (*tree_node)->num = num;
        (*tree_node)->right = NULL;
    } else {
        if (num < (*tree_node)->num)
            insert(&((*tree_node)->left), num);
        else
            insert(&((*tree_node)->right), num);
    }
}

void inorder(struct tree *tree_node) {
    if (tree_node != NULL) {
        inorder(tree_node->left);
        printf("%d\t", tree_node->num);
        inorder(tree_node->right);
    }
}