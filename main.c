#include <stdio.h>
#include "Queue.h"

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
    return 0;
}