#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
	int top; 
	int capacity; 
	int *array; 
}Stack; 

int isdigita(char a){

	if(a>='0' && a<='9'){
		return 1;
	}

	else{
		return 0;
	}

}

int strlena(char *a){

	int i=0;
	
	for(i=0;*(a+i)!='\0';i++){

	}
	return i;
}

int isEmpty(Stack* stack){ 
	return stack->top == -1 ; 
} 


char pop(Stack* stack){ 

	if (!isEmpty(stack)){
		return stack->array[stack->top--] ; 
	}
}

void push(Stack* stack, char op){ 

	stack->array[++stack->top] = op; 
} 

int Postfix(char *exp){  

	int i;
    int capacity = strlena(exp);

	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity *sizeof(int));  
  
    for (i = 0; exp[i]; ++i){  
 
        if (isdigita(exp[i])){
            push(stack, exp[i] - '0');  
        }

        else{

            int val1 = pop(stack);  
            int val2 = pop(stack);

            if(exp[i]=='+'){
            	push(stack, val2 + val1);
            }

            else if(exp[i]=='-'){
            	push(stack, val2 - val1);
            }

            else if(exp[i]=='*'){
            	push(stack, val2 * val1);
            }

            else if(exp[i]=='/'){
            	push(stack, val2/val1);
            }

        }  
    }  
    return pop(stack);  
}  

int main(){ 

	int result, i;

	char exp[] = "3454*+6/-";
	char *expp;

	for(i=0;exp[i]!='\0';i++){
		*(expp+i) = exp[i];
	}
	*(expp+i) = '\0';

	result = Postfix(exp);

	printf(" Postfix : %s \n Result = %d \n", exp, result);

	return 0; 
} 
