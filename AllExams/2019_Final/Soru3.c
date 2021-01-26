#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct n{

    int data;
    struct n * left;
    struct n * right;
    struct n * middle;
}node;

node *root=NULL;

node *insert(node *tree, int val) {

    if (tree==NULL) {
      
        tree = (node *)malloc(sizeof(node));
        tree->left = NULL;
        tree->right = NULL;
        tree->data = val;

        return tree;
    }

    else if (val < tree->data) { //left node
        tree->left = insert(tree->left, val);
    } else if (val > tree->data && val < tree->data * tree->data) { //middle node
        tree->middle = insert(tree->middle, val);
    } else if (val > tree->data * tree->data) { // right node
        tree->right = insert(tree->right, val);
    }

    return tree;

}

node *search(node **tree, int val) {
    if (!(*tree)) {
        return NULL;
    }
    if (val < (*tree)->data) // left node
    {
        search(&((*tree)->left), val);
    } else if (val > (*tree)->data && val < ((*tree)->data * (*tree)->data)) { // middle node
        search(&((*tree)->middle), val);
    } else if (val > ((*tree)->data * (*tree)->data)) { // right node
        search(&((*tree)->right), val);
    } else if (val == (*tree)->data) {
        return *tree; // return search node
    }
}

node *findMax(node *tree) {
    if (tree == NULL) return NULL;
    if (tree->right == NULL) // right ve middle null ise kendini döndür
        if (tree->middle == NULL) return tree;

    if (tree->right == NULL) //right null ve middle null değilse middle ı recursive fonsiyona gönder
        if (tree->middle != NULL) return findMax(tree->middle);

    return findMax(tree->right);   //son case right a git
}

node *findMin(node *tree) {
    node *current = tree;

    while (current->left != NULL)
        current = current->left;

    return current;
}
node *deleteNode(node *tree, int key);

void rebuild(node *tree, node *base) {
//    tst *temp = baseRoot;
    //base case
    int data = findMax(base)->data;
    if (tree->right == NULL || (base->data) * ((base->data)) < data) {
        tree->right = NULL;
        return;
    }
    deleteNode(base->right, data);
    insert(root, data);
    if (tree->right->left == NULL && tree->right->middle == NULL && tree->right->right == NULL) {
        data = findMax(base)->data;
        deleteNode(base->right, data);
        insert(root, data);
        tree->right = NULL;
        return;
    }
    rebuild(tree, base);
}

node *deleteNode(node *tree, int key) {

    if (tree == NULL) return tree;  //base case
    node *temp;
    //left side case
    if (key < tree->data)
        tree->left = deleteNode(tree->left, key);

        //middle side case
    else if (key > tree->data && (key < (tree->data * tree->data)))
        tree->middle = deleteNode(tree->middle, key);

        //right side case
    else if (key > (tree->data * tree->data))
        tree->right = deleteNode(tree->right, key);

        //if the same tree's key
    else {
        if (tree->left && tree->middle) {
            temp = findMin(tree->middle);
            tree->data = temp->data;
            tree->middle = deleteNode(tree->middle, tree->data);
            rebuild(tree->right, tree->right);
        } else if (tree->left && tree->right) {
            temp = findMax(tree->left);
            tree->data = temp->data;
            tree->left = deleteNode(tree->left, tree->data);
        } else {
            temp = tree;
            if (tree->left != NULL)
                tree = tree->left;
            else if (tree->right != NULL)
                tree = tree->right;
            else if (tree->middle != NULL)
                tree = tree->middle;
            else if (tree->middle == NULL && tree->left == NULL && tree->right == NULL)
                tree = NULL;
            free(temp);
        }
    }
    return tree;
}


void traversal(node *tree) {
    if (tree == NULL){ 

    	return;
    }
    printf("%d--", tree->data);
    traversal(tree->left);
    traversal(tree->middle);
    traversal(tree->right);

}

int main() {
    
	root = insert(root,10);
	root = insert(root,85);
	root = insert(root,30);
	root = insert(root,7);
	root = insert(root,31);
	root = insert(root,15);
	root = insert(root,40);
	root = insert(root,63);
	root = insert(root,1);
	root = insert(root,15);


	traversal(root);


}
