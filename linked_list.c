#include "Linked_list_int.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_init(LinkedList *list)
{
    list->size = 0;
    list -> head = NULL;
}
int list_push_front(LinkedList *list, void *value, size_t size )
{
    Node *n = malloc(sizeof(*n));
    if (!n) return 0;

    n->data = malloc(size);
    if (!n->data) { free(n); return 0; }

    memcpy(n->data, value, size);
    n->elem_size = size;
    n->next = list->head;
    list->head = n;
    list->size++;

    return 1;
}
int list_push_back(LinkedList *list, void *value, size_t size )
{
    Node *n = (Node *)malloc(sizeof(*n));
    if(!n) return 0;
    n->data = malloc(size);
    if(!n->data)
    {
        free(n);
        return 0;
    }

    memcpy(n->data, value, size);
    n->elem_size = size;

    n->next = NULL;

    if(list->head == NULL)
        list->head = n;
    else
    {
        Node *curr = list->head;
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = n;
    }
    list ->size++;
    return 1;
}

int list_pop_back(LinkedList *list, void *out)
{
    if(list->head == NULL)
        return 0;

    Node *curr = list->head;
    Node *prev = NULL;
    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    if (out != NULL)
        memcpy(out, curr->data, curr->elem_size);
    free(curr->data);
    free(curr);
    if(prev)
        prev->next = NULL;
    else
        list->head = NULL;
    
    list->size--;
    return 1;
}

int list_pop_front(LinkedList *list, void *out)
{
    if(list->head == NULL)
        return 0;
    
    Node *temp = list->head;
    if(out != NULL)
        memcpy(out, temp->data, temp->elem_size);
    list->head = temp->next;
    free(temp->data);
    free(temp);
    list->size--;
    
    return 1;
}

int list_is_empty(LinkedList *list)
{
    return list->head == NULL;
}
void list_free(LinkedList *list)
{
    Node *curr = list->head;
    Node *temp;

    if(curr == NULL)
        return;
    while(curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp->data);
        free(temp);  
    }
    list->head = NULL;
    list->size = 0;

}

Node *list_find(LinkedList *list, void  *value)
{
    Node *p = list->head;

    if (value == NULL)
        return NULL;
    
    while(p != NULL)
    {
        if (memcmp(p->data, value, p->elem_size)==0)
            return p;
        p = p->next;
    }
    return NULL;
}

int list_insert_after(LinkedList *list, int pos, void *value, size_t size)
{
    if (list->head == NULL)
        return 0;
    Node *curr = list->head;

    int count = 1;
    while (curr != NULL && count < pos)
    {
        curr = curr->next;
        count++;
    }
    if (curr == NULL)
        return 0;

    Node *n = (Node *)malloc(sizeof(*n)); //after pos is found
    if (!n) return 0;

    n->data = malloc(size);
    if (!n->data) { free(n); return 0; }
    memcpy(n->data, value, size);
    n->elem_size = size;

    n->next = curr->next;
    curr->next = n;
    list->size++;

    return 1;

}

int list_insert_at(LinkedList *list, int pos, void *value, size_t size)
{
    if (pos < 1)
        return 0;

    if (pos == 1)
        return list_push_front(list, value, size);

    Node *curr = list->head;
    Node *prev = NULL;
    int count = 1;

    while (curr != NULL && count < pos)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (count != pos)
        return 0;

    Node *n = malloc(sizeof(*n));
    if (!n) return 0;

    n->data = malloc(size);
    if (!n->data) { free(n); return 0; }
    memcpy(n->data, value, size);
    n->elem_size = size;

    n->next = curr;
    prev->next = n;

    list->size++;
    return 1;
}

int list_delete_after(LinkedList *list, int pos)
{
    if(list->head == NULL)
        return 0;

    Node *curr = list->head;
    int count = 1;
    
    while (curr != NULL && count < pos)
    {
        curr = curr->next;
        count++;
    }
    if (curr == NULL || curr->next == NULL)
        return 0;

    Node *temp = curr->next;
    curr->next = temp->next;
    free(temp->data);
    free(temp);
   
    list->size--;

    return 1;

}

int list_delete_value(LinkedList *list, void *value)
{
    if (list->head == NULL)
        return 0;
    Node *curr = list->head;
    Node *prev = NULL;

    while(curr != NULL && (memcmp(curr->data,value, curr->elem_size)) != 0)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        return 0; // not found

    if (prev == NULL)
        list->head=curr->next;
    else
        prev->next = curr->next;

    free(curr->data);
    free(curr);
    list->size--;

    return 1;

}