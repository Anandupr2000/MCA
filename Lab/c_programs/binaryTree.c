#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int no_of_nodes = 0;
struct Node
{
    int data;
    struct Node *rchild;
    struct Node *lchild;
} * Parent, *delNodeParent;


////// don't write this fn in record

// int entries[50];
// void showArray()
// {
//     printf("\nEntered datas are => ");
//     for (int i = 0; i < no_of_nodes; i++)
//     {
//         printf("%d ", entries[i]);
//     }
// }
struct Node *findMin(struct Node *root)
{
    struct Node *temp = root;

    //travesing tree to leftmost element
    while (temp->lchild != NULL)
    {
        // assign node to parent node of deleting node which is used in case 3 of delete fn
        delNodeParent =temp; 

        temp = temp->lchild;
    }
    return temp;
}
struct Node *findMax(struct Node *root)
{
    struct Node *temp = Parent;

    //travesing tree to rightmost element
    while (temp->rchild != NULL)
    {
        temp = temp->rchild;
    }
    return temp;
}

int preorder(struct Node *root)
{
    struct Node *temp = root;
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        printf(" %d ", temp->data);
        preorder(temp->lchild);
        preorder(temp->rchild);
    }
}
int inorder(struct Node *root)
{
    struct Node *temp = root;
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        inorder(temp->lchild);
        printf(" %d ", temp->data);
        inorder(temp->rchild);
    }
}
int postorder(struct Node *root)
{
    struct Node *temp = root;
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        // since its tree and the pattern is repeatative, we use recursion for traversing
        postorder(temp->lchild);
        postorder(temp->rchild);
        printf(" %d ", temp->data);
    }
}
void display(struct Node *node, int level)
{
    if (node != NULL)
    {
        display(node->rchild, level + 1);
        printf("\n");
        for (int i = 0; i < level; i++)
        {
            printf("    ");
        }
        printf("%d", node->data);
        display(node->lchild, level + 1);
    }
}
struct Node *insert(struct Node *root, int item) /*Insert a node*/
{
    if (root == NULL)
    {
        struct Node *node = malloc(sizeof(struct Node));
        node->data = item;
        node->lchild = node->rchild = NULL;

        if (no_of_nodes == 0)
            Parent = node;

        no_of_nodes++;
        return node; /*return new node if tree is empty*/
    }
    if (item < root->data)
        root->lchild = insert(root->lchild, item);
    else
        root->rchild = insert(root->rchild, item);
    return root;
}

struct Node *search(int element)
{
    struct Node *root = Parent;

    int i = 0;
    bool found = false;

    // traversing to leaf node
    while (root != NULL)
    { // will exit when nxt node has no child
        
        if (element == root->data)
        {
            found = true;
            break;
        }
        delNodeParent = root; //saving current node as parent of next node for using deletion operation

        // deciding which node to traverse next
        if (element < root->data)
        {
            root = root->lchild; // to left subtree
        }
        else
        {
            root = root->rchild; // to right subtree
        }
        i++; // incrementing level
    }


    if (found)
    {
        printf("\n%d found at level %d\n", element, i);
        return root; // returning parent of node
    }
    else
    {
        printf("\n%d not found\n", element);
        return NULL;
    }
}

struct Node* delete(struct Node* root, int key)
{
    // base case
    if (root == NULL){
        no_of_nodes--;
        if(no_of_nodes==0){
            Parent=NULL;
        }
        return root;
    }
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->lchild = delete(root->lchild, key);
 
    // If the key to be deleted
    // is greater than or equal to the root's
    // key, then it lies in right subtree
    else if (key >= root->data)
        root->rchild = delete(root->rchild, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted

    // node with only one child or no child
    if (root->lchild == NULL) {
        struct Node* temp = root->rchild;
        free(root);
        return temp;
    }
    else if (root->rchild == NULL) {
        struct Node* temp = root->lchild;
        free(root);
        return temp;
    }

    // node with two children:
    // Get the inorder successor
    // (smallest in the right subtree)
    struct Node* temp = findMin(root->rchild);

    // Copy the inorder
    // successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->rchild = delete(root->rchild, temp->data);
    return root;
}

void main()
{
    int menuInput = 1, element;
    while (menuInput != 0)
    {
        printf("\n*********** Menu ***********");
        printf("\n1 - Enter element");
        printf("\n2 - Delete element");
        printf("\n3 - Search element ");
        printf("\n4 - Display tree ");
        printf("\n5 - Find maximum");
        printf("\n6 - Find minimum");
        printf("\n7 - Preorder traversal");
        printf("\n8 - Inorder traversal");
        printf("\n9 - Postorder traversal");
        // printf("\n10 - Show order of elements entered"); // to show order of elements entered
        printf("\n0 - Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &menuInput);
        switch (menuInput)
        {
            case 0:
                break;
            case 1:
            {
                printf("\nEnter element : ");
                scanf("%d", &element);
                // insert(element);
                insert(Parent, element);
                break;
            }
            case 2:
            {
                if(Parent==NULL){
                    printf("\nNo tree found");
                    break;
                }
                int element;
                printf("\nEnter element to delete : ");
                scanf("%d", &element);
                if(search(element)==NULL){
                    printf("\n%d not found", element);
                }
                else{
                    delete (Parent,element);
                }
                break;
            }
            case 3:
            {
                int element;
                printf("\nEnter element to be searched : ");
                scanf("%d", &element);
                search(element);
                break;
            }
            case 4:
            {
                printf("\nParent (at left) to children (at right)");
                display(Parent, 0);
                break;
            }
            case 5:
            {
                struct Node *temp = findMax(Parent);
                printf("\n%d is maximum", temp->data);
                break;
            }
            case 6:
            {
                // findMin(Parent);
                struct Node *temp = findMin(Parent);
                printf("\n%d is minimum", temp->data);
                break;
            }
            case 7:
            {
                preorder(Parent);
                break;
            }
            case 8:
            {
                inorder(Parent);
                break;
            }
            case 9:
            {
                postorder(Parent);
                break;
            }
            // this is a test case to showcase inserted values
            // case 10:
            // {
            //     showArray();
            //     break;
            // }
            default: printf("\n**** Enter any valid input provided in menu ****");
        }
    }
}
