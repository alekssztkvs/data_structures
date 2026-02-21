#include <stdlib.h>
#include "Stack.h"
#include <string.h>

void stack_init(Stack *s, int capacity, size_t elemsize)
{
    s->elem_size = elemsize;
    s->capacity = capacity;
    s->top = 0;
    s->data = malloc(capacity * elemsize);
    if (!s->data)
        exit(EXIT_FAILURE);
    
}
int stack_push(Stack *s, void *value)
{
    if (stack_is_full(s))
        return 0;
    
    void *target = (char *)s->data + s->top * s->elem_size;
    memcpy(target, value, s->elem_size);

    s->top++;

    return 1;
}

int stack_pop(Stack *s, void *out)
{
    if(stack_is_empty(s))
        return 0;

    s->top--;

    void *source = (char *)s->data + s->top *s->elem_size;
    memcpy(out, source, s->elem_size);

    return 1;
}

int stack_peek(Stack *s, void *out)
{
    if(s->top == 0)
        return 0;
    
    void *target = (char *)s->data + (s->top-1) * s->elem_size;
    memcpy(out, target, s->elem_size);

    return 1;
}


int stack_is_empty(const Stack *s)
{
    return (s->top == 0);
}

int stack_is_full(const Stack *s)
{
    return (s->top == s->capacity);
}

void stack_free(Stack *s)
{
    free(s->data);
}