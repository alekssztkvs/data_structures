#include "Stack.h"

typedef void (*ActionFunc_stack)(Stack *s);


typedef struct MenuOption_stack
{
    const char *text;
    ActionFunc_stack func;
}MenuOption_stack;


void stack_push_action(Stack *);
void stack_pop_action(Stack *);
void stack_peek_action(Stack *);
void stack_menu_loop(const char *title, MenuOption_stack options[], int options_count, Stack *s);
void stack_check_empty(Stack *);
void stack_check_full(Stack *);
void stacks();