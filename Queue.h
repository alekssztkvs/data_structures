
typedef struct Queue
{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;


void queue_init(Queue *, int );
int enqueue(Queue *, int );
int dequeue(Queue *, int *);
int queue_is_empty(Queue *);
int queue_is_full(Queue *);
void queue_free(Queue *);
