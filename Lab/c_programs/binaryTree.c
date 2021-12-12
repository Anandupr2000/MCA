#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int no_of_nodes = 0;
int entries[50];
struct Node
{
    int data;
    // struct Node *parent;
    struct Node *rchild;
    struct Node *lchild;
} * Parent, *delNodeParent;

void showArray()
{
    printf("\nEntered datas are => ");
    for (int i = 0; i < no_of_nodes; i++)
    {
        printf("%d ", entries[i]);
    }
}
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
        printf("\nIteration no => %d", i);
        printf("\ndata found => %d", root->data);
        
        if (element == root->data)
        {
            found = true;
            break;
        }
        delNodeParent = root; //saving current node as parent of next node
        printf("\nparent of data => %d", delNodeParent->data);

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
void delete (int element)
{
    printf("\nInside delete fn");
    // finding node to be deleted 
    struct Node *delNode = search(element); 

    // for no element searched found
    if(delNode==NULL){
        printf("\nDeletion failed, since there is no %d in tree.",element);
        return;
    }

    //case 1 : leaf node
    if (delNode->lchild == NULL && delNode->rchild == NULL)
    {
        printf("\nNode is leaf");
        free(delNode);
        printf("%d is parent of %d",delNodeParent->data,element);
        if (element < delNodeParent->data)
            delNodeParent->lchild = NULL;
        else
            delNodeParent->rchild = NULL;
    }

    //case 2 : node with 1 child

    //for deleting node with left child
    else if (delNode->lchild != NULL && delNode->rchild == NULL)
    {
        // node to be deleted is left child of its parent and node itself doesn't have any left child
        printf("\nNode has one child");

        if(delNode==Parent)
            Parent = delNode->lchild;
        else if (element < delNodeParent->data)
            delNodeParent->lchild = delNode->lchild;
        else    
            delNodeParent->rchild = delNode->lchild;

        free(delNode);

        no_of_nodes--;
    }
    // for deleting node with right child
    else if (delNode->lchild == NULL && delNode->rchild != NULL)
    {
        // node to be deleted is left child of its parent and node itself doesn't have any left child
        printf("\nNode has one child");

        if(delNode==Parent) // if deleting node with one child is parent
                Parent = delNode->rchild;
        // deleting other nodes with one child
        else if (element < delNodeParent->data)
            delNodeParent->lchild = delNode->rchild;
        else
            delNodeParent->rchild = delNode->rchild;

        free(delNode);

        no_of_nodes--;
    }

    // case3 : node with 2 children
    else if (delNode->lchild != NULL && delNode->rchild != NULL)
    {
        //finding min in right subtree to replace it's value with deleting node's value
        struct Node *child = findMin(delNode->rchild);
        
        printf("\n%d is the value to replaced to %d",child->data,delNode->data);
    
        // saving existing address of right and left children
        struct Node *l =  delNode->lchild;
        struct Node *r =  delNode->rchild;
        
        //replacing value of delNode with its child's values
        *delNode = *child; 
        
        // restoring previous address of right and left children
        delNode->lchild = l; 
        delNode->rchild = r;
        
        // find parent of min node in right subtree and assign it to NULL
        delNodeParent->lchild = NULL;
        free(child);
    }
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
        printf("\n5 - Show order of elements entered"); // to show order of elements entered
        printf("\n6 - Find maximum");
        printf("\n7 - Find minimum");
        printf("\n8 - Preorder traversal");
        printf("\n9 - Inorder traversal");
        printf("\n10 - Postorder traversal");
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
            int element;
            printf("\nEnter element to delete : ");
            scanf("%d", &element);
            delete (element);
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
            display(Parent, 0);
            break;
        }
        case 5:
        {
            showArray();
            break;
        }
        case 6:
        {
            struct Node *temp = findMax(Parent);
            printf("\n%d is maximum", temp->data);
            break;
        }
        case 7:
        {
            // findMin(Parent);
            printf("\nEnter element : ");
            scanf("%d", &element);
            struct Node *temp = findMin(search(element));
            printf("\n%d is minimum", temp->data);
            break;
        }
        case 8:
        {
            preorder(Parent);
            break;
        }
        case 9:
        {
            inorder(Parent);
            break;
        }
        case 10:
        {
            postorder(Parent);
            break;
        }
        }
    }
}
