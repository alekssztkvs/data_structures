

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList_int
{
    Node *head;
    int size;
} LinkedList_int;

void list_init(LinkedList_int *);
int list_push_front(LinkedList_int *, int );
int list_push_back(LinkedList_int *, int );
int list_pop_front(LinkedList_int *, int *);
int list_pop_back(LinkedList_int *, int *);
int list_is_empty(LinkedList_int *);
void list_free(LinkedList_int *);
Node *list_find(LinkedList_int *, int value);
int list_insert_after(LinkedList_int *, int , int);