#include <stdio.h>

#include<conio.h>

#include <stdlib.h>

#define M 3

typedef struct _node {

int n; /*n < M No. of keys in node will always less than order of B tree*/

int keys[M - 1];

struct _node *p[M]; /* (n+1 pointers will be in use) */

} node;

node *root = NULL;

typedef enum KeyStatus { Duplicate, SearchFailure, Success, InsertIt, LessKeys,

} KeyStatus;

void insert(int key);

void display(node *root, int);

void DelNode(int x);
int maxDepth(node *root);

KeyStatus ins(node *r, int x, int* y, node** u);

int searchPos(int x, int *key_arr, int n);

KeyStatus del(node *r, int x);

void eatline(void);

void inorder(node *ptr);

int main() {

clrscr();

int key;

int choice;

printf("Creation of B tree for M=%d\n", M);

while (1) {

printf("1.Insert\n2.Delete\n3.depth\n4.Display\n5.Quit\nEnter your choice: ");

scanf("%d", &choice); eatline();

switch (choice) {

case 1:

printf("Enter the key: ");

scanf("%d", &key); eatline();

insert(key);

break;

case 2:

printf("Enter the key : ");

scanf("%d", &key); eatline();

DelNode(key);

break;

case 3:

Printf(" Height of tree %d", maxDepth (node));

break;

case 4:

printf("Btree is :\n");

display(root, 0);

break;

case 5:

exit(1);

default:

printf("Wrong choice\n");

break;

}}

return 0;

}

void insert(int key) {

node *newnode;

int upKey;

KeyStatus value;

value = ins(root, key, &upKey, &newnode);

if (value == Duplicate)

printf("Key already available\n");

if (value == InsertIt) {

node *uproot = root;

root = (node*)malloc(sizeof(node));

root->n = 1;

root->keys[0] = upKey;

root->p[0] = uproot;

root->p[1] = newnode;

}}

KeyStatus ins(node *ptr, int key, int *upKey, node **newnode) {

node *newPtr, *lastPtr;

int pos, i, n, splitPos;

int newKey, lastKey;

KeyStatus value;

if (ptr == NULL) {

*newnode = NULL;

*upKey = key;

return InsertIt;

}

n = ptr->n;

pos = searchPos(key, ptr->keys, n);

if (pos < n && key == ptr->keys[pos])

return Duplicate;

value = ins(ptr->p[pos], key, &newKey, &newPtr);

if (value != InsertIt)

return value;

/*If keys in node is less than M-1 where M is order of B tree*/

if (n < M - 1) {

pos = searchPos(newKey, ptr->keys, n);

/*Shifting the key and pointer right for inserting the new key*/

for (i = n; i>pos; i--) {

ptr->keys[i] = ptr->keys[i - 1];

ptr->p[i + 1] = ptr->p[i];

}

/*Key is inserted at exact location*/

ptr->keys[pos] = newKey;

ptr->p[pos + 1] = newPtr;

++ptr->n; /*incrementing the number of keys in node*/

return Success;

}

/*If keys in nodes are maximum and position of node to be inserted is last*/

if (pos == M - 1) {

lastKey = newKey;

lastPtr = newPtr;

}

else { /*If keys in node are maximum and position of node to be inserted is not last*/

lastKey = ptr->keys[M - 2];

lastPtr = ptr->p[M - 1];

for (i = M - 2; i>pos; i--) {

ptr->keys[i] = ptr->keys[i - 1];

ptr->p[i + 1] = ptr->p[i];

}

ptr->keys[pos] = newKey;

ptr->p[pos + 1] = newPtr;

}

splitPos = (M - 1) / 2;

(*upKey) = ptr->keys[splitPos];

(*newnode) = (node*)malloc(sizeof(node));/*Right node after split*/

ptr->n = splitPos; /*No. of keys for left splitted node*/

(*newnode)->n = M - 1 - splitPos;/*No. of keys for right splitted node*/

for (i = 0; i < (*newnode)->n; i++) {

(*newnode)->p[i] = ptr->p[i + splitPos + 1];

if (i < (*newnode)->n - 1)

(*newnode)->keys[i] = ptr->keys[i + splitPos + 1];

else

(*newnode)->keys[i] = lastKey;

}

(*newnode)->p[(*newnode)->n] = lastPtr;

return InsertIt;

}
int maxDepth(struct node *n)
{

    if (n == NULL)

        return -1;

    else {

        /* compute the depth of each subtree */
        
        int lDepth = maxDepth(n->left);

        int rDepth = maxDepth(n->right);
 

        /* use the larger one */

        if (lDepth > rDepth)

            return (lDepth + 1);

        else

            return (rDepth + 1);

    }
}

void display(node *ptr, int blanks) {

if (ptr) {

int i;

for (i = 1; i <= blanks; i++)

printf(" ");

for (i = 0; i < ptr->n; i++)

printf("%d ", ptr->keys[i]);

printf("\n");

for (i = 0; i <= ptr->n; i++)

display(ptr->p[i], blanks + 10);

}}

}