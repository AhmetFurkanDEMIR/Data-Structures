#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct stack{

    char* data[100];
    int size;

}stack;


int operate(char** op1, char** op2, char operator, char* buff){

    int operand1 = atoi(*op1);
    int operand2 = atoi(*op2);

    if(operator == '+')
    {
        sprintf(buff, "%d", operand1 + operand2);
        char ans[50];
        sprintf(ans, "%d", operand1 + operand2);
        return (int) strlen(ans);
    }
    else if(operator == '*')
    {
        sprintf(buff, "%d", operand1 * operand2);
        char ans[50];
        sprintf(ans, "%d", operand1 + operand2);
        return (int) strlen(ans);
    }
    else if(operator == '/')
    {
        sprintf(buff, "%d", operand1 / operand2);
        char ans[50];
        sprintf(ans, "%d", operand1 + operand2);
        return (int) strlen(ans);
    }
    else if(operator == '-')
    {
        sprintf(buff, "%d", operand1 - operand2);
        char ans[50];
        sprintf(ans, "%d", operand1 + operand2);
        return (int) strlen(ans);
    }

    return 0;
}

int operator_importance(char* op1, char* op2)
{
    if ((*op1 == '*' || *op1 == '/') && (*op2 == '+' || *op2 == '-'))
        return 1;
    if ((*op1 == '*' || *op1 == '/') && (*op2 == '*' || *op2 == '/'))
        return 1;
    return 0;
}

void stack_init(struct stack* stack)
{
    stack->size = 0;
}

void push(struct stack* stack, char* data)
{


    stack->size++;
    stack->data[stack->size] = data;


}

char* pop(struct stack* stack)
{

    char* val = stack->data[stack->size];
    stack->size--;
    return val;
}

char* peek(struct stack* stack)
{
    return stack->data[stack->size];
}

int main()
{
    stack value_stack;
    stack_init(&value_stack);

    stack operator_stack;
    stack_init(&operator_stack);

    char buffer[50];
    printf("Please enter an expression:\n");
    fgets(buffer, 50, stdin);

    for(int i = 0; i < strlen(buffer); i++)
    {
        char token = buffer[i];

        if(token == ' ')
            continue;

        if(token >= '0' && token <= '9')
        {
            char* num = malloc(50);
            int len = 0;
            while(buffer[i] >= '0' && buffer[i] <= '9')
            {
                i++;
                len++;
            }
            memcpy(num, &buffer[i - len], len + 1);
            *(num + len) = '\0';
            i--;
            push(&value_stack, num);
        }
        else if(token == '(')
        {
            push(&operator_stack, &buffer[i]);
        }
        else if(token == ')')
        {
            while(*peek(&operator_stack) != '(')
            {
                char operator = *pop(&operator_stack);
                char* operand2 = pop(&value_stack);
                char* operand1 = pop(&value_stack);

                char* result = malloc(50);
                operate(&operand1, &operand2, operator, result);
                push(&value_stack, result);
            }
            pop(&operator_stack);
        }
        else if(token == '+' || token == '-' || token == '*' ||token == '/')
        {
            while(operator_stack.size > 0 && operator_importance(peek(&operator_stack), &token) > 0)
            {
                char operator = *pop(&operator_stack);
                char* operand2 = pop(&value_stack);
                char* operand1 = pop(&value_stack);

                char* result = malloc(50);
                operate(&operand1, &operand2, operator, result);
                push(&value_stack, result);
            }
            push(&operator_stack, &buffer[i]);
        }
    }

    while(operator_stack.size > 0)
    {
        char operator = *pop(&operator_stack);
        char* operand2 = pop(&value_stack);
        char* operand1 = pop(&value_stack);

        char* result = malloc(50);
        operate(&operand1, &operand2, operator, result);
        free(operand2);
        free(operand1);
        push(&value_stack, result);
    }

    char* answer = pop(&value_stack);
    printf("Answer: %s", answer);

    free(answer);

    return 0;
}
