#include <stdio.h>
#include "Queue.h"
#include "Linked_list_int.h"
#include "Stack.h"

int main(void)
{
    Queue q;
    int capacity = 3;
    queue_init(&q, capacity);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    int qu;
    for(int i = 0; i < capacity+1; i++)
        printf("%d\t", q.data[i]);
    putchar('\n');
    printf("queue now: %d\n", dequeue(&q, &qu));

    LinkedList_int list;
    list_init(&list);
    list_push_front(&list, 5);
    list_push_front(&list, 4);
    list_push_front(&list, 3);
    list_push_back(&list, 12);
    list_push_back(&list, 14);
    list_push_front(&list , 6);
    int check;
    list_pop_back(&list, &check);

    for (Node *p = list.head; p!=NULL; p = p->next)
        printf("%d\t", p->data);
    
    printf("|deleted: %d\n", check);
    putchar('\n');
    list_pop_front(&list, &check);
    list_insert_after(&list, 2, 99);
    for (Node *p = list.head; p!=NULL; p = p->next)
        printf("%d\t", p->data);
    printf("|deleted: %d\n", check);

    return 0;
}