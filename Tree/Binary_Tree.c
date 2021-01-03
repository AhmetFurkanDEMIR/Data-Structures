#include<stdlib.h>
#include<stdio.h>

struct tree_el {
   int val;
   struct tree_el * right, * left;
};

typedef struct tree_el node;
node * curr, * root;
int size = 0;
int left_depth = 0;
int right_depth = 0;
int path[1000];
int ancestorPath[1000];

int find_size(node * tree){
    if(tree->left){
        size++;
        find_size(tree->left);
    }
    if(tree->right){
        size++;
        find_size(tree->right);
    }
    return size + 1;
}

int find_max_depth(node * tree){
	if(tree->left){
		left_depth++;
		find_max_depth(tree->left);
	}
	
	if(tree->right){
		right_depth++;
		find_max_depth(tree->right);
	}
	
	return ((left_depth > right_depth) ? left_depth : right_depth);
}

void print_inorder_traversal(node * tree) {
   if(tree->left) print_inorder_traversal(tree->left);
   printf("%d\n",tree->val);
   if(tree->right) print_inorder_traversal(tree->right);
}

void print_preorder_traversal(node * tree) {
   printf("%d\n",tree->val);
   if(tree->left) {
	print_preorder_traversal(tree->left);
   }
   
   if(tree->right) {
    print_preorder_traversal(tree->right);
   }	
}

void print_postorder_traversal(node * tree) {
   if(tree->left) {
	print_postorder_traversal(tree->left);
   }
   
   if(tree->right) {
	print_postorder_traversal(tree->right);
   } 
   
   printf("%d\n",tree->val);
}

int find_max(node *root)
{
	int leftVal, rightVal, rootVal, MAX = 0;	
	if(root != NULL)
	{
		rootVal = root->val;
		leftVal = find_max(root->left);
		rightVal = find_max(root->right);
		if(leftVal > rightVal) MAX = leftVal;
		else MAX = rightVal;
		if(rootVal > MAX)
		MAX = rootVal;
	}
	return MAX;
}

int insert(node ** tree, node * item) {
	if(!(*tree)) {
	  *tree = item;
	  return 0;
	}
	if(item->val<(*tree)->val){
		insert(&(*tree)->left, item);
	}	  
	else if(item->val>(*tree)->val){
		insert(&(*tree)->right, item);
	}	  
	return 0;
}

void create_binary_search_tree(){

	int number = 0, counter = 0, how_many_elements = 0; 
	printf("Enter how many elements: \n");
	scanf("%d", &how_many_elements);

	for(counter = 1; counter <= how_many_elements; counter++) {
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		scanf("%d", &number);
		curr->val = number;
		insert(&root, curr);
	}
	printf("\nThe binary search tree is: \n");
	print_inorder_traversal(root);
}

void find_element(node * tree, int value){
	if(tree->val == value)
    {
        printf("\nMatch found \n");
    }
    else if(tree->val < value)
    {
        if(tree->right)
        {
            find_element(tree->right, value);
        }
        else
        {
            printf("Match not found \n");
        }
    }
    else if(tree->val > value)
    {
        if(tree->left)
        {
            find_element(tree->left, value);
        }
        else
        {
            printf("Match not found \n");
        }
    }	
}


int main(){

   int action_key = 0, search_element;

   create_binary_search_tree();

   do{
    printf("\n1: Find max\n2: Pre Order Traversal\n3: Post Order Traversal\n4: Get Size\n5: Search Element\n\n");
    scanf("%d", &action_key);

	switch(action_key){

		case 1:
			printf("\nThe maximum value in the tree is:");
			printf("%d\n", find_max(root));
			break;

		case 2:
		    printf("\nPre Order Traversal of the binary tree\n");
			print_preorder_traversal(root);
			break;

		case 3:
			printf("\nPost Order Traversal of the binary tree\n");
			print_postorder_traversal(root);
			break;

		case 4:
			printf("\nThe size of the binary tree is: ");
			printf("%d\n", find_size(root));
			break;	

		case 5:
		    printf("\nEnter the element to be searched: ");
			scanf("%d", &search_element);
			find_element(root, search_element);
			break;

		default:
			break;			
	}
   } while(action_key <= 15);

   return 0;
} 