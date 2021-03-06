// 1. infix to postfix
// 2. infix to prefix
// 3. infix implementation
// 4. postfix to infix
// 5. postfix to prefix
// 6. postfix impletation
// 7. prefix to infix
// 8. prefix to postfix
// 9. prefix implementation
// 10. simple que
// 11. doulby que
// 12. circular que
// 13. Write Menu Driven Program to implement push (), pop (), Peep () , display ( ) and Change Operation.
// 14. singly link list
// 15. doulby link list
// 16. circular singly
// 17. circular doulby

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max size - 1
#define empty -1
#define size 25

int infixtoPostfix(char *expression);

int pop(char *stack, int *top)
{
    char operator;
    if ((*top) != empty)
    {
        operator= stack[(*top)];
        stack[(*top)] = '\0'; /*segment fault here on secound loop*/
        (*top)--;
    }
    else
    {
        printf("top is empty %d", *top);
        return 0;
    }
    return operator;
}

int priority(char operator)
{
    if (operator== '(')
    {
        return 6;
    }
    else if (operator== '^' || operator== '$')
    {
        return 5;
    }
    else if (operator== '/' || operator== '*')
    {
        return 4;
    }
    else if (operator== '+' || operator== '-')
    {
        return 3;
    }
    return 0;
}
/*push use to push data in output var also*/

int push(char *stack, int *top, char arg)
{
    if (*top != max)
    {
        (*top)++;
        stack[*top] = arg;
        return 1;
    }
    printf("given array is full! can't push more data");
    return 0;
}

int string_reverse(char *str)
{
    int i = 0;
    int j = strlen(str) - 1;

    for (i = 0; i != j / 2; i++)
    {
        str[i] = str[i] + str[j - i];
        str[j - i] = str[i] - str[j - i];
        str[i] = str[i] - str[j - i];
    }
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }

    return 0;
}
// infix to prefix
int infixtoprefix(char *expression)
{
    int index;
    string_reverse(expression);
    infixtoPostfix(expression);
    string_reverse(expression);
    return 0;
}
// infix to POSTFIX
int infixtoPostfix(char *expression)
{

    char output[size];
    char stack[size];

    unsigned short int counter = 0;

    unsigned short int stack_priority_value;
    unsigned short int expression_priority_value;

    int top = -1;

    int loop = 0;
    int index = 0;

    /*1. Scan the infix expression from left to right.*/
    for (loop = 0; expression[loop] != '\0'; loop++)
    {
        /*scanned character is an operand*/
        if (isalnum(expression[loop]))
        {
            output[index] = expression[loop];
            index++;
            continue;
        }

        stack_priority_value = priority(stack[top]);
        expression_priority_value = priority(expression[loop]);
        if (top == empty || stack_priority_value < expression_priority_value || stack[top] == '(')
        {
            push(stack, &top, expression[loop]);
        }
        /*pop all the operators from the stack which are greater than or equal priority*/
        else if (expression[loop] == ')')
        {
            while (stack[top] != '(')
            {
                output[index++] = pop(stack, &top);
            }
            pop(stack, &top);
        }
        else if (stack_priority_value >= expression_priority_value)
        {
            while (priority(stack[top]) >= expression_priority_value)
            { /*if top == -1 pop return 0 !*/
                output[index++] = pop(stack, &top);
            }
            push(stack, &top, expression[loop]);
        }
    }

    while (top != empty)
    {
        output[index] = pop(stack, &top);
        index++;
    }

    for (counter = 0; index != counter; counter++)
    {
        expression[counter] = output[counter];
    }

    expression[counter] = '\0';

    return 0;
}
int stringHandler()
{

    return 0;
}

// postfix to infix
int postInfix(char *expression)
{

    return 0;
}

int main()
{
    char expression[size];
    int choice;

    printf("\n:1 Infix to PreFix.\n:2 Infix to PostFix \n:3 Postfix to infix(Not Working)\n");
    scanf("%d", &choice);
    scanf("%s", expression);
    switch (choice)
    {
    case 1:
        fflush(stdin);
        infixtoprefix(expression);
        printf("%s\n", expression);
        break;
    case 2:
        infixtoPostfix(expression);
        printf("%s\n", expression);
        break;
    default:
        printf("Really It's not an option!!");
        break;
    }

    return 0;
}