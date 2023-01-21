/* C Program to find the height of a Tree */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* left, *right;
};

/*
 * Function to create new nodes
 */

struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;

    return(newnode);
}

/*
 * Function to ascertain the height of a Tree
 */

int heightoftree(struct node* root)
{
    int max;

    if (root!=NULL)
    {
        /*Finding the height of left subtree.*/
        int leftsubtree = heightoftree(root->left);
        /*Finding the height of right subtree.*/
        int rightsubtree = heightoftree(root->right);
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}

/*
 * Main Function
 */

int main()
{
   /* Creating first Tree.*/

    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);

    /* Sample Tree 1- Balanced Tree


                    25
                  /    \
                 27     19
                / \     / \
              17  91   13 55


    */
    printf("Height of the first Tree is\t%d\n",heightoftree(newnode));

    /* Creating second Tree.*/

    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);

    /* Sample Tree 2-   Right Skewed Tree (Unbalanced).

                    1
                     \
                      2
                       \
                        3
                         \
                          4
                           \
                            5
    */

    printf("\nHeight of the second Tree is\t%d\n",heightoftree(node));

    /*Creating third Tree. */

    struct node *root = createnode(15);

    /* Sample Tree 3-  Tree having just one root node.

                   15

    */

    printf("\nHeight of the third Tree is\t%d",heightoftree(root));

    return 0;
}
