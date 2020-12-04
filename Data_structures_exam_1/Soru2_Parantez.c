#include <stdio.h> 
#include <stdlib.h> 

// stack yapımız
typedef struct node{ 
	char ch; 
	struct node *next; 
}stack; 


// yigina veri ekleme
void push(stack *temp, int new_data) 
{ 

	stack* new_node = (stack*)malloc(sizeof(stack)); 

	new_node->ch = new_data; 

	new_node->next = temp; 

	temp = new_node; 
} 

// yigindan veri cikarma
int pop(stack *temp){ 

	char res; 
	stack *top; 

	top = temp; 
	res = top->ch; 
	temp = top->next; 
	free(top); 
	return res; 

} 


int sonlanma(char ch1, char ch2) 
{ 
	if (ch1 == '(' && ch2 == ')') 
		return 1; 
	else if (ch1 == '{' && ch2 == '}') 
		return 1; 
	else if (ch1 == '[' && ch2 == ']') 
		return 1; 
	else
		return 0; 
} 


int denge_kontrol(char veri[]) 
{ 
	int i = 0; 

	stack *stacka = NULL; 

	while (veri[i]){ 

		if (veri[i] == '{' || veri[i] == '(' || veri[i] == '['){
			push(stacka, veri[i]); 
		}

		if (veri[i] == '}' || veri[i] == ')'|| veri[i] == ']'){ 


			if (stacka == NULL){
				return 0; 
			}

			else if(sonlanma(pop(stacka), veri[i])==0){
				return 0; 
			}
		} 
		i++; 
	} 

	if (stacka == NULL){
		return 1; //dengeli
	}

	else{
		return 0; // dengesiz
	}
} 


int main(){

	char veri[] = "{()}["; 

	if (denge_kontrol(veri)){

		printf("Dengeli parantez \n"); 
	} 
	else{

		printf("Dengesiz parantez \n"); 
	}
	return 0; 
} 

