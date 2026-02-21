#include "Stack_actions.h"
#include "Safe_input.h"
#include <stdio.h>

void stacks()
{
    Stack s;
    int s_size = 50;
    stack_init(&s, s_size, sizeof(int));
    MenuOption_stack stack_menu[] = {
    {"Push", stack_push_action},
    {"Pop", stack_pop_action},
    {"Peek", stack_peek_action},
    {"Check if full", stack_check_full},
    {"Check if empty", stack_check_empty}
    };
    stack_menu_loop("Stack", stack_menu, 5, &s);
    stack_free(&s);
}

void stack_menu_loop(const char *title, MenuOption_stack options[], int options_count, Stack *s)
{
    int choice = 0;

    while(1) 
    {
        printf("\n===%s===\n", title);
        for (int i = 0; i < options_count; i++)
            printf("%d : %s\n", i+1, options[i].text);
        printf("0: Back / Exit\n");

        printf("Your choice:");
        if(!safe_int_input(&choice))
            continue;
        if (choice == 0)
            break;
        if (choice < 1 || choice > options_count)
        {
            printf("Incorrect choice, try again.\n");
            continue;
        }
        options[choice-1].func(s);
    }
}


void stack_push_action(Stack *s) {
    int num;
    printf("Enter integer to push: ");
    safe_int_input(&num);
    if(stack_push(s, &num))
        printf("%d pushed.\n", num);
    else
        printf("Stack is full.\n");
}

void stack_pop_action(Stack *s) {
    int num;
    if(stack_pop(s, &num))
        printf("%d popped.\n", num);
    else
        printf("Stack is empty.\n");
}

void stack_peek_action(Stack *s) {
    int num;
    if(stack_peek(s, &num))
        printf("Top element: %d\n", num);
    else
        printf("Stack is empty.\n");
}

void stack_check_full(Stack *s) {
    if (stack_is_full(s))
        printf("Stack is full\n");
    else
        printf("Stack isn't full\n");
}

void stack_check_empty(Stack *s) {
    if (stack_is_empty(s))
        printf("Stack is empty\n");
    else
        printf("Stack isn't empty\n");
}