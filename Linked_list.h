#include <stddef.h>

typedef struct Node
{
    void *data;
    size_t elem_size;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int size;

} LinkedList;

void list_init(LinkedList *);
int list_push_front(LinkedList *, void *, size_t );
int list_push_back(LinkedList *, void *, size_t );
int list_pop_front(LinkedList *, void *);
int list_pop_back(LinkedList *, void *);
int list_is_empty(LinkedList *);
void list_free(LinkedList *);
Node *list_find(LinkedList *, void *);
int list_insert_after(LinkedList *, int , void *, size_t);
int list_delete_after(LinkedList *, int);
int list_delete_value(LinkedList *, void *);
int list_insert_at(LinkedList *, int , void *, size_t);
int list_print(LinkedList *, void (*)(void *));