#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n{

    char *pStack;
    int size;
    int top;

}stack;


void initializeStack(stack *theStack){

    theStack->pStack = (char*)malloc(2*sizeof(char));
    theStack->size = 2;
    theStack->top = -1;
}


int stackIsEmpty(stack *theStack){

    if (theStack->top < 0){
        return 1;
    }

    else{
        return 0;
    }
}


void push(stack *theStack, char toPush){

    char *tempArray = NULL;
    int top = theStack->top;
    int size = theStack->size;
    int i;

    if (top == size-1){

        tempArray = (char*)malloc((size+2)*sizeof(char));

        for(i = 0; i < size; i++){

            tempArray[i] = theStack->pStack[i];
        }

        free(theStack->pStack);
        theStack->pStack = tempArray;
        theStack->size += 2;
    }

    top++;

    theStack->pStack[top] = toPush;

    theStack->top = top;
}


void pop(stack *theStack){

    int top = theStack->top;

    int isEmpty = stackIsEmpty(theStack);

    if (isEmpty == 1){
        printf("Stack is empty. No values to delete/pop.");
    }


    else{
        theStack->top = top-1;
    }
}

int main(int argc, char **argv){

    stack expressionMarks;

    expressionMarks.pStack = (char*)malloc(2*sizeof(char));
    expressionMarks.size = 2;
    expressionMarks.top = -1;

    char expression[301] = "(){";
    char charTop;
    int isEmpty;
    int wrongSymbol = 0;
    int missingSymbol = 0;
    int stringLength = 0;
    int i;

 
    stringLength = strlen(expression);

    for(i = 0; i < stringLength; i++){

        charTop = expressionMarks.pStack[expressionMarks.top];

        isEmpty = stackIsEmpty(&expressionMarks);

        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[' || expression[i] == '<'){

            push(&expressionMarks, expression[i]);

        }


        else if(expression[i] == ')'){

            if (charTop == '('){

                pop(&expressionMarks);

                continue;
            }

            else if (charTop == '{'){

                printf("}");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '['){

                printf("]");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '<'){

                printf(">");
                wrongSymbol = 1;
                break;
            }

            else if(isEmpty == 1){

                printf("(");
                missingSymbol = 1;
                break;
            }

            else if(isEmpty == 1 && stringLength == 1){

                printf("(");
                missingSymbol = 1;
                break;
            }
        }

        else if(expression[i] == ']'){
            
            if (charTop == '['){

                pop(&expressionMarks);
                continue;
            }

            else if (charTop == '{'){

                printf("}");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '('){

                printf(")");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '<'){

                printf(">");
                wrongSymbol = 1;
                break;
            }

            else if(isEmpty == 1){

                printf("[");
                missingSymbol = 1;
                break;
            }

            else if(isEmpty == 1 && stringLength == 1){

                printf("[");
                missingSymbol = 1;
                break;
            }
        }

        else if(expression[i] == '}'){

            if (charTop == '{'){

                pop(&expressionMarks);
                continue;
            }

            else if (charTop == '('){

                printf(")");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '['){

                printf("]");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '<'){

                printf(">");
                wrongSymbol = 1;
                break;
            }

            else if(isEmpty == 1){

                printf("{");
                missingSymbol = 1;
                break;
            }

            else if(isEmpty == 1 && stringLength == 1){

                printf("{");
                missingSymbol = 1;
                break;
            }
        }

        else if(expression[i] == '>'){

            if (charTop == '<'){

                pop(&expressionMarks);
                continue;
            }

            else if (charTop == '{'){

                printf("}");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '['){

                printf("]");
                wrongSymbol = 1;
                break;
            }

            else if(charTop == '('){

                printf(")");
                wrongSymbol = 1;
                break;
            }

            else if(isEmpty == 1){

                printf("<");
                missingSymbol = 1;
                break;
            }

            else if(isEmpty == 1 && stringLength == 1){

                printf("<");
                missingSymbol = 1;
                break;
            }
        }

    }


    isEmpty = stackIsEmpty(&expressionMarks);
    charTop = expressionMarks.pStack[expressionMarks.top];

    if(isEmpty == 1 && missingSymbol != 1 && expression[0] != 'q'&& expression[0] != 'Q'){

        printf("\nThe expression is balanced");
    }


    else if (isEmpty == 0){

        if (charTop == '(' && wrongSymbol != 1){

            printf(")");
        }

        else if (charTop == '[' && wrongSymbol != 1){

            printf("]");
        }

        else if (charTop == '{' && wrongSymbol != 1){

            printf("}");
        }

        else if(charTop == '<' && wrongSymbol != 1){

            printf(">");
        }

    }

    return 1;

}