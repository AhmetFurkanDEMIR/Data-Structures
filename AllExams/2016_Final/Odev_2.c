#include <stdio.h> 
#include <stdlib.h> 

typedef struct Node{
	int top; 
	int capacity; 
	int *array; 
}node; 

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

int isEmpty(node* stack){ 
	return stack->top == -1 ; 
} 

char peek(node* stack){ 

	return stack->array[stack->top]; 
} 

char pop(node* stack){ 

	if (!isEmpty(stack)){
		return stack->array[stack->top--] ; 
	}
}

void push(node* stack, char op){ 

	stack->array[++stack->top] = op; 
} 


int isOperand(char ch){ 

	return (ch >= '0' && ch <= '9');

}

int Valence(char ch){ 

	if(ch=='+' || ch=='-'){
		return 1;
	}

	else if(ch=='*' || ch=='/'){
		return 2;
	}

	else if(ch=='^'){
		return 3;
	}

	else{
		return -1;
	}

} 
 
char *InfixtoPostfix(char *exp){ 

	int i, k; 
	int capacity = strlena(exp);

	node *stack = (node*)malloc(sizeof(node));
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity *sizeof(int)); 

	for (i = 0, k = -1; exp[i]; ++i){ 
 
		if (isOperand(exp[i])){
			exp[++k] = exp[i]; 
		}

		else if (exp[i] == '('){
			push(stack, exp[i]); 
		}
		
		else if (exp[i] == ')'){ 

			while (!isEmpty(stack) && peek(stack) != '('){
				exp[++k] = pop(stack); 
			}

			if (!isEmpty(stack) && peek(stack) != '('){
				return '\0';	 
			}

			else{
				pop(stack); 
			}
		}

		else{ 

			while(!isEmpty(stack) && Valence(exp[i]) <= Valence(peek(stack))){
				exp[++k] = pop(stack); 
			}

			push(stack, exp[i]); 
		} 

	} 

	while (!isEmpty(stack)){ 
		exp[++k] = pop(stack );
	} 

	exp[++k] = '\0'; 
	return exp;
} 

int Postfix(char *exp){  

	int i;
    int capacity = strlena(exp);

	node* stack = (node*)malloc(sizeof(node));
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

	char exp[] = "3-(4+5*4)/6";
	char *expp;

	for(i=0;exp[i]!='\0';i++){
		*(expp+i) = exp[i];
	}
	*(expp+i) = '\0';

	char *expa = InfixtoPostfix(exp);

	result = Postfix(expa);

	printf(" Infix : %s \n Postfix : %s \n Result = %d \n",expp, exp, result);

	return 0; 
} 
