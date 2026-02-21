#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void queue_init(Queue *q, int capacity)
{
    q->data = malloc(sizeof(int) * capacity);
    q-> front = 0;
    q-> rear = 0;
    q->size = 0;
    q->capacity = capacity;
    
}

int enqueue(Queue *q, int value)
{
    if(queue_is_full(q))
    {
        printf("Queue if full\n");
        return 0;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;

    (q->size)++;
    return 1;
}

int dequeue(Queue *q, int *out)
{
    if (queue_is_empty(q))
    {
        printf("Queue is empty\n");
        return 0;
    }
    
    *out = q->data[(q->front)];
    q->front = (q->front+1) % q->capacity;
    (q->size)--;
    return 1;
    
}

int queue_is_full(Queue *q)
{
    return q->size == q->capacity;
}
int queue_is_empty(Queue *q)
{
    return q->size == 0;
}

void free_queue(Queue *q)
{
    free(q->data);
}