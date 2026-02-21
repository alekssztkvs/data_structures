
typedef struct Stack
{
    void *data;
    size_t elem_size;
    int top;
    int capacity;
} Stack;

void stack_init(Stack *, int , size_t );
int stack_push(Stack *, void *);
int stack_pop(Stack *, void *);
int stack_peek(Stack *, void *);
int stack_is_empty(const Stack *);
int stack_is_full(const Stack *);