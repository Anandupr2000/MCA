#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int data;
    char color;
    struct Node *parent;
    struct Node *rchild;
    struct Node *lchild;
}*start = NULL,*delNode = NULL;

// fn for searching tree
struct Node *search(int element)
{
    struct Node *root = start, *nodeSearched;

    int i = 0;
    bool found = false;

    // traversing to leaf node
    while (root != NULL)
    { // will exit when nxt node has no child
        
        if (element == root->data)
        {
            found = true;
            nodeSearched =  root;
            break;
        }

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
    if(P==NULL || grandParent==NULL) {
        printf("\ncannot perform leftToRightRotate");
        return;
    }
    if(grandParent->parent == NULL) // if grandparent's parent is starting of tree
    {
        printf("\ntree starting found");
        start = P; // setting root as parent
        grandParent->lchild = P->rchild = NULL;
        start->rchild = grandParent;
        grandParent->parent = P;
    }
    else{
        printf("\n %d is not tree starting",grandParent->data);
        struct Node *temp = grandParent->parent;
        grandParent->lchild = P->rchild;
        P->rchild = grandParent;

        // if(P->data < temp->data) 
           temp->lchild = P;
        // else    temp->rchild = P;
    }
}

// used for right skewed tree
void rightToLeftRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;

    if(grandParent->parent == NULL) // if grandparent's parent is root
    {
        printf("\ntree starting found");
        start = P; // setting root as parent
        grandParent->rchild = start->lchild;
        start->lchild = grandParent;
        grandParent->parent = P;
        P->parent = NULL;
    }
    else{
        printf("\n %d is not tree starting",grandParent->data);
        struct Node *temp = grandParent->parent;
        P->parent = temp;
        grandParent->rchild = P->lchild ;
        P->lchild = grandParent;
        grandParent->parent = P;
            // if (item < root->data)

        // if(P->data < temp->data)    temp->lchild = P;
        // else
            temp->rchild = P;
    }
}

// used for tree with left child then right child(insertion)
void leftToLeftRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;
    // restructuring tree to left skewed
    root->parent = grandParent;
    grandParent->lchild = root;

    P->rchild = root->lchild;
    root->lchild = P;
    P->parent = root;
    // P->lchild = NULL;
}
// used for tree with right child then left child(insertion)
void rightToRightRotate(struct Node *root){
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent;
    // restructuring tree to right skewed
    root->parent = grandParent;
    grandParent->rchild = root;

    P->lchild = root->rchild;
    root->rchild = P;

    P->parent = root;
}

/*Inserting a node*/
struct Node *insert(struct Node *root, int item) 
{
    struct Node *temp;
    if (root == NULL)
    {
        struct Node *node = malloc(sizeof(struct Node));

        node->data = item;

        if (start == NULL){
            start = node;
            node->color = 'b';
            node->parent = NULL;
        }
        else node->color = 'r';
        return node; /*return new node if tree is empty and further insert recursion will not occur*/
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

struct Node *findMin(struct Node *root)
{
    struct Node *temp = root;

    //travesing tree to leftmost element
    while (temp->lchild != NULL)
    {
        // assign node to parent node of deleting node which is used in case 3 of delete fn
        // delNodeParent =temp; 

        temp = temp->lchild;
    }
    return temp;
}

struct Node* sibiling(struct Node *root){
    if(root!=NULL && root->parent!=NULL){
        if(root->data < (root->parent)->data){
            return (root->parent)->rchild;
        }
        else{
            return (root->parent)->lchild;
        }
    }
    else return NULL;
}

bool isLeaf(struct Node *root){
    if(root->lchild == NULL && root->rchild == NULL)
        return true;
    else return false;
}
bool isBothChildrenBlack(struct Node* node){
    bool blackChildren = (
            (node->lchild==NULL || (node->lchild!=NULL&&(node->lchild)->color=='b'))&&
            (node->rchild==NULL || (node->rchild!=NULL&&(node->rchild)->color=='b'))
        )?true:false;
    
    return blackChildren;
}
void recolor(struct Node *root){
    printf("\nInside recolor fn");
    struct Node *grandParent = ((root->parent)->parent), *P = root->parent , *uncle=sibiling(root->parent);
    if(grandParent!=NULL && grandParent!=start) grandParent->color = 'r';
    if(P!=NULL) P->color = 'b';
    if(uncle!=NULL) uncle->color = 'b';
    printf("\nSucessfull recolor");
}
void swapNodeColor(struct Node *node1,struct Node *node2){
    char temp = node1->color;
    node1->color = node2->color;
    node2->color = temp; 
}
void rotateFix(struct Node *root){
    struct Node *grandParent = root->parent->parent;
    struct Node *P = root->parent;
    if(grandParent!=NULL){
        // if subtree is right skewed
        if(root->data >= P->data && P->data >= grandParent->data){
            printf("right skewed");
            recolor(root);
            rightToLeftRotate(root);
        }
        // if subtree is left skewed (containing only nodes with left child)
        // if(root->data < P->data && P->data < grandParent->data && grandParent->rchild==NULL){
        if(root->data < P->data && P->data < grandParent->data){
            printf("left skewed");
            recolor(root);
            leftToRightRotate(root);
        }
        // if parent is left child and root is right child 
        if(root->data >= P->data && P->data < grandParent->data){
            printf("\nparent is left child and root is right child");
            // making subtree with leaf root left skewed
            // rightToRightRotate(root);
            leftToLeftRotate(root);
            printf("\nleftToLeftRotate successfull");
            // rotating left to decrease height
            // printf("\n%d is right child",(root->rchild)->data);
            rotateFix(root->lchild); // after leftToLeftRotate() root's parent will be its left child
        }
        // if parent is right child and  root is left child
        if(root->data < P->data && P->data >= grandParent->data){
            printf("\nparent is right child and  root is left child");
            // making subtree with leaf root right skewed
            // leftToLeftRotate(root);
            rightToRightRotate(root);
            printf("\nrightToRightRotate successfull");
            // rotating left to decrease height
            rotateFix(root->rchild); // after rightToRightRotate() root's parent will be its right child
}
    }
}
void validateInsertion(struct Node* root){
    printf("\nPerforming validateInsertion");
    // if tree start is red or red-red conflict (root and root's parent is red)
    if((start!=NULL && start->color == 'r') || (root->parent != NULL && root->parent->color == 'r' && root->color=='r'))
    {
        printf("Started");
        // case A if tree starting is red
        if(start->color=='r')
        {
            printf("\nPerforming case A");
            start->color = 'b';
            return;
        }
        if (root->parent != NULL && (root->parent)->parent != NULL)
        {
            struct Node *grandParent = ((root->parent)->parent), *P = root->parent ,*uncle=sibiling(root->parent);
            bool isBlackUncle = true;

            if(uncle!=NULL) isBlackUncle = (uncle->color == 'b')? true:false; 
            // case B red uncle condition
            if(uncle!=NULL && uncle->color=='r'){
                printf("\nPerforming case B");
                printf("\n%d is red node",uncle->data);
                recolor(root);
                validateInsertion(grandParent);
                return;
            }

            // case C
            // if subtree is right skewed (containing only nodes with right child) and uncle is null
            // if(root->data >= P->data && P->data >= grandParent->data  && grandParent->lchild==NULL){
            
            if(uncle==NULL || isBlackUncle)
            {
                printf("\nPerforming case C");
                // print("\n");
                rotateFix(root);
            }
        }
    }
    printf("\nSuccessfull validateInsertion");
}

// fn for ordinary bst deletion
struct Node* delete(struct Node* root, int key)
{
    // base case
    if (root == NULL){
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
    else if (key > root->data)
        root->rchild = delete(root->rchild, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
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

        // Delete the inorder  successor
        root->rchild = delete(root->rchild, temp->data);
    }
    return root;
}
void validateDeletion(struct Node* node){
    struct Node* uncle = sibiling(node->parent);
    struct Node* s = sibiling(node);
    // case1
    if(isLeaf(node) && node->color=='r'){
        printf("\nPerformed case1");
        return;//do nothing
    }
    // case2
    // below are cases for deleting internal node
    // checking tree starting is double black
    if(node->color == 'b' && start->color=='b' && node->parent == start){
        printf("\nPerforming case2");
        if(s->lchild) rotateFix(s->lchild);
        else if(s->rchild) rotateFix(s->rchild);
        // sibiling(sibiling(node))->color = node->color; //preserving original color
        printf("\nPerformed case2");
        return;
    }
    // uncle is black and both its chidren are black
    // else if(uncle == NULL || (uncle!=NULL && uncle->color=='b')){
    //     if(isBothChildrenBlack(uncle)){
    //         if(node->parent!=NULL && node->parent->color=='r') node->parent->color='b';
    //         if(s!=NULL) s->color = 'r';
    //         if(node->parent!=NULL && node->parent->color == 'b') validateDeletion(node->parent);
    //     }
    // }
    // case3
    // sibling is black and both its chidren are black
    if(s == NULL || (s!=NULL && s->color=='b')){
        if(isBothChildrenBlack(s) && node->parent!=NULL){
            if(node->parent->color=='r')
            {
                node->parent->color='b';
                if(s!=NULL) s->color = 'r';
            }
            // checking for double black
            else if(node->parent->color == 'b') validateDeletion(node->parent);
        }
        printf("\nPerformed case3");
    }
    // case4
    // sibling is red
    if(s != NULL && s->color == 'r'){
        swapNodeColor(node->parent,s);
        // sameside rotation
        // node is right child
        if(node==(node->parent)->rchild){
            rightToRightRotate(s); // rotating parent and sibiling towards node
        }
        // node is left child
        else if(node==(node->parent)->lchild){
            leftToLeftRotate(s); // rotating parent and sibiling towards node
        }
        printf("\nPerformed case4");
        validateDeletion(node); // reapplying cases with same node
    }
    
        // case5
        // sibling is black, sibling's child who is far from node is black but near child is red
        // opposite side rotation
        // if node is left child and sibling having red left child
        if(
            (s!=NULL && s->color=='b') &&
            ((s->lchild!=NULL && s->lchild->color=='r')) &&
            (node==(node->parent)->lchild && node->color == 'b')
        )
        {
            printf("\nPerforming case5 red left child");        
            // // exchange the color of sibiling of given node and left child of sibiling
            // swapNodeColor(s,s->lchild);
            // rightToRightRotate(node);// rotating parent and sibiling away from node    
            // printf("\nPerformed case5");        
            // // checking for double black
            // if(node->parent->color=='b') validateDeletion(node);
        }
        // if node is right child and sibling having red right child
        else if(
            (s!=NULL && s->color == 'b') &&
            ((s->lchild!=NULL && s->lchild->color=='r')) &&
            (node==(node->parent)->lchild && node->color == 'b')
        )
        {
            printf("\nPerforming case5 red right child");        
            // // exchange the color of sibiling of given node and right child of sibiling
            // swapNodeColor(s,s->rchild);
            // leftToLeftRotate(node);// rotating parent and sibiling away from node 
            // printf("\nPerformed case5"); 
            // // checking for double black
            // if(node->parent->color=='b') validateDeletion(node);          
        }   
        
        // case6
        // sibling is black, sibling's child who is far from node is red but near child is black
        // node is left child and sibling's red child is right
        if(s!=NULL && (node==node->parent->lchild && (s->rchild!=NULL && s->rchild->color=='r'))){
            struct Node *farthestRedNode = s->rchild;
            swapNodeColor(s,node->parent);
            leftToLeftRotate(s); // rotate towards node
            farthestRedNode->color = 'b';
            printf("\nPerformed case6");
        }
        // node is right child and sibling's red child is left
        else if(s!=NULL && (node==node->parent->rchild && (s->lchild!=NULL && s->lchild->color=='r'))){
            struct Node *farthestRedNode = s->lchild;
            swapNodeColor(s,node->parent);
            leftToLeftRotate(s); // rotate towards node
            farthestRedNode->color = 'b';
            printf("\nPerformed case6");
        }
    
}
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
                insert(start, element);
                validateInsertion(search(element));
                display(start,0);
                break;
            }
            case 2:
            {
                if(start==NULL){
                    printf("\nNo tree found");
                    break;
                }
                int element;
                struct Node *node;
                printf("\nEnter element to delete : ");
                scanf("%d", &element);
                node = search(element);
                if(node==NULL){
                    printf("\n%d not found", element);
                }
                else{
                    delNode = malloc(sizeof(struct Node));
                    *delNode = *node;
                    // delNode->data = node->data;
                    // delNode->color = node->color;
                    // delNode->rchild = node->rchild;
                    // delNode->lchild = node->lchild;
                    // delNode->parent = node->parent;

                    delete (start,element);
                    validateDeletion(delNode);
                    display(start,0);
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
                display(start, 0);
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
                // inorder(p);
                break;
            }
            case 8:{
                int value;
                printf("\nEnter leaf element : ");
                scanf("%d", &value);
                struct Node *node = search(value);
                printf("\nvalue of node is %d",node->data);
                if (node!=NULL) rotateFix(node);
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