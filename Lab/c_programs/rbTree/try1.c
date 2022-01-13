#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int no_of_nodes=0;
struct Node
{
    int data;
    char color;
    struct Node *parent;
    struct Node *rchild;
    struct Node *lchild;
}*p = NULL,*delNodeParent = NULL;

// fn for searching tree
struct Node *search(int element)
{
    struct Node *root = p, *nodeSearched;

    int i = 0;
    bool found = false;

    // traversing to leaf node
    while (root != NULL)
    { // will exit when nxt node has no child
        
        if (element == root->data)
        {
            printf("\n%d is element found",root->data);
            found = true;
            nodeSearched =  root;
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
        // if(root== NULL) return root;
    }


    if (found)
    {
        printf("\n%d found at level %d\n", element, i);
        return nodeSearched; // returning node
    }
    else
    {
        printf("\n%d not found\n", element);
        return NULL;
    }
}

// used for left skewed tree
void leftToRightRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;
    // struct Node *grandParent , *P = root->parent;
    if(root->parent==NULL) printf("\nparent is null");
    printf("\n%d is value at parent",P->data);
    // grandParent = P->parent;
    // printf("\n%d is value at grandParent",(P->parent)->data);
    // int newLChildvalue = root->data;
    // int newGvalue = P->data;
    // int newRChildvalue = grandParent->data;
    
    // // moving parent node to left
    // grandParent->lchild = root;
    // grandParent->rchild = P;
    // root->parent = grandParent;
    // P->data = grandParent->data;
    // grandParent->data = newGvalue; 

    // printf("\n converting parent node to leaf node");
    // // converting parent node to leaf node
    // P->rchild = P->lchild = NULL;
    if(grandParent->parent == NULL) // if grandparent's parent is root
    {
        printf("\ntree starting found");
        p = P; // setting root as parent
        p->rchild = grandParent;
        grandParent->rchild = grandParent->lchild = NULL;
        grandParent->parent = P;
    }
    else{
        printf("\n %d is not tree starting",grandParent->data);
        struct Node *temp = grandParent->parent;
        P->rchild = grandParent;
        grandParent->rchild = grandParent->lchild = NULL;
            // if (item < root->data)

        if(P->data < temp->data)    temp->lchild = P;
        else    temp->rchild = P;
    }
}

// used for tree with left child then right child
void leftToLeftRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;
    // restructuring tree to left skewed
    root->parent = grandParent;
    grandParent->lchild = root;

    root->lchild = P;
    P->parent = root;
    P->rchild = NULL;
}
// used for tree with right child then left child
void rightToRightRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;
    // restructuring tree to right skewed
    root->parent = grandParent;
    grandParent->rchild = root;

    root->rchild = P;
    P->parent = root;
    P->lchild = NULL;
}

// used for right skewed tree
void rightToLeftRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;

    if(grandParent->parent == NULL) // if grandparent's parent is root
    {
        printf("\ntree starting found");
        p = P; // setting root as parent
        p->lchild = grandParent;
        grandParent->rchild = grandParent->lchild = NULL;
        grandParent->parent = P;
        P->parent = NULL;
    }
    else{
        printf("\n %d is not tree starting",grandParent->data);
        struct Node *temp = grandParent->parent;
        P->parent = temp;
        P->lchild = grandParent;
        grandParent->rchild = grandParent->lchild = NULL;
        grandParent->parent = P;
            // if (item < root->data)

        if(P->data < temp->data)    temp->lchild = P;
        else    temp->rchild = P;
    }
}

// fn for adding and removing nullnodes
void nullize(struct Node *root,bool addNullNode){
    if(addNullNode){
        if(root!=NULL){
            // null black nodes
            struct Node *nullNode = malloc(sizeof(struct Node));
            nullNode->color = 'b';
            root->rchild = root->lchild = nullNode;
            return;
        }
    }
    else{

    }
}
/*Inserting a node*/
struct Node *insert(struct Node *root, int item) 
{
    struct Node *temp;
    if (root == NULL)
    {
        // struct Node *node = malloc(sizeof(struct Node));
        struct Node *nullNode = malloc(sizeof(struct Node));
        nullNode->color = 'b';
        root->rchild = root->lchild = nullNode;

        if (no_of_nodes == 0){
            struct Node *node = malloc(sizeof(struct Node));
            p = node;
            node->color = 'b';
            node->parent = NULL;
            node->data = item;
            node->rchild = node->lchild = nullNode;
            return node; /*return new node if tree is empty and further insert recursion will not occur*/
        }
        else root->color = 'r';
        
        // node->data = item;
        root->data = item;

        no_of_nodes++;
    }
    // printf("\n%d is parent",root->data);
    if (item < root->data)
    {
        temp = insert(root->lchild, item);
        root->lchild = temp;
        temp->parent = root;
    }
    else
    {
        temp = insert(root->rchild, item);
        root->rchild = temp;
        temp->parent = root;
    }
    return root;
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
        // if(node->parent != NULL) printf("p-%d ", (node->parent)->data);
        if(node->data) printf("%d",node->data);
        printf(" %c",node->color);
        // printf("v-%d ", node->data);
        // if(node->lchild != NULL) printf("l-%d ", (node->lchild)->data);
        // if(node->rchild != NULL) printf("r-%d", (node->rchild)->data);
        // printf(" d-%d l-%d r-%d", node->data,(node->lchild)->data,(node->rchild)->data);
        display(node->lchild, level + 1);
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

// validate fn for adjusting tree height
void validateTree(struct Node* root){
    if (root->parent != NULL && (root->parent)->parent != NULL)
    {
        struct Node *grandParent = ((root->parent)->parent), *P = root->parent;
        // if subtree is right skewed (containing only nodes with right child) and uncle is null
        if(root->data >= P->data && P->data >= grandParent->data  && grandParent->lchild==NULL){
            printf("right skewed");
            rightToLeftRotate(root);
        }
        // if subtree is left skewed (containing only nodes with left child) and uncle is null
        if(root->data < P->data && P->data < grandParent->data && grandParent->rchild==NULL){
            printf("left skewed");
            leftToRightRotate(root);
        }
        // if root is right child and parent is left child and uncle is null
        if(root->data >= P->data && P->data < grandParent->data && grandParent->rchild==NULL){
            printf("\nroot is right child and parent is left child");
            // making subtree with leaf root right skewed
            rightToRightRotate(root);
            printf("\nrightToRightRotate successfull");
            // rotating left to decrease height
            validateTree(root->rchild); // after rightToRightRotate() root's parent will be its child
        }
        // if root is left child and parent is right child and uncle is null
        if(root->data < P->data && P->data >= grandParent->data && grandParent->lchild==NULL){
            printf("\nroot is left child and parent is right child");
            // making subtree with leaf root left skewed
            leftToLeftRotate(root);
            printf("\nleftToLeftRotate successfull");
            // rotating left to decrease height
            validateTree(root->lchild); // after leftToLeftRotate() root's parent will be its child
        }
    }
}

// void displayParents(int element){
//     struct Node *root = p;
//     while(root!= NULL){
//             printf(" %d", root->data);
//             if(root->data < element){
//                 if((root->rchild)->data ==element) break;
//                 root = root->rchild;
//             }
//             else{
//                 if((root->lchild)->data==element) break;
//                 root = root->lchild;
//             }
//         // if(root->data==element) break;
//         }
//     printf("\nTraversing back to root : ");
//     // if(root==NULL) printf("\nroot is NULL");
//     // root = root->parent;
//     while(root!= NULL)
//     {
//         printf(" %d", root->data);
//         root = root->parent;
//     }
// }
void main()
{
    system("clear");
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
        printf("\n7 - Inorder traversal");
        printf("\n8 - Left to Right Rotate");
        // printf("\n9 - show parents");
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
                insert(p, element);
                validateTree(search(element));
                break;
            }
            case 2:
            {
                // if(p==NULL){
                //     printf("\nNo tree found");
                //     break;
                // }
                // int element;
                // printf("\nEnter element to delete : ");
                // scanf("%d", &element);
                // if(search(element)==NULL){
                //     printf("\n%d not found", element);
                // }
                // else{
                //     delete (element);
                // }
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
                display(p, 0);
                break;
            }
            case 5:
            {
                // struct Node *temp = findMax(p);
                // printf("\n%d is maximum", temp->data);
                break;
            }
            case 6:
            {
                // findMin(Parent);
                // struct Node *temp = findMin(p);
                // printf("\n%d is minimum", temp->data);
                break;
            }
            case 7:
            {
                inorder(p);
                break;
            }
            case 8:{
                int value;
                printf("\nEnter leaf element : ");
                scanf("%d", &value);
                struct Node *node = search(value);
                printf("\nvalue of node is %d",node->data);
                rightToRightRotate(node);
                break;
            }
            // case 9:{
            //     int element;
            //     printf("\nEnter element : ");
            //     scanf("%d", &element);
            //     displayParents(element);
            //     break;
            // }
            default: printf("\n**** Enter any valid input provided in menu ****\n");
        }
    }
}