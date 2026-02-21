#include "Linked_list_int.h"

#include <stdio.h>
#include <stdlib.h>

void list_init(LinkedList_int *list)
{
    list->size = 0;
    list -> head = NULL;

}
int list_push_front(LinkedList_int *list, int value )
{
    Node *n= (Node *)malloc(sizeof(*n));
    n->next = list->head;
    n->data = value;
    list->head = n;
    list->size++;
    return 1;
}
int list_push_back(LinkedList_int *list, int value )
{
    Node *n = (Node *)malloc(sizeof(*n));
    if(!n) return 0;
    n->data = value;
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

int list_pop_back(LinkedList_int *list, int *out)
{
    if(list->head == NULL)
        return 0;

    if (list->head->next == NULL)
    {
        *out = list->head->data;
        free(list->head);
        list->head = NULL;
        list->size--;
        return 1;
    }

    Node *curr = list->head;
    Node *prev = NULL;
    while(curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    *out = curr->data;
    free(curr);
    prev->next = NULL;
    list->size--;
    return 1;
}

int list_pop_front(LinkedList_int *list, int *out)
{
    if(list->head == NULL)
        return 0;
    
    Node *temp = list->head;
    *out = temp->data;
    list->head = temp->next;
    free(temp);
    list->size--;
    
    return 1;
}

int list_is_empty(LinkedList_int *list)
{
    return list->head == NULL;
}
void list_free(LinkedList_int *list)
{
    Node *curr = list->head;
    Node *temp;

    if(curr == NULL)
        return;
    while(curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;

}

Node *list_find(LinkedList_int *list, int value)
{
    Node *p = list->head;
    while(p != NULL)
    {
        if (p->data == value)
            return p;
        p = p->next;
    }
    return NULL;
}

int list_insert_after(LinkedList_int *list, int pos, int value)
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

    n->data = value;
    n->next = curr->next;
    curr->next = n;

    return 1;

}

int list_insert_at(LinkedList_int *list, int pos, int value)
{
    if (list->head == NULL)
        return 0;
    Node *curr = list->head;
    Node *prev;

    int count = 1;
    while (count != pos)
    {
        if (curr == NULL)
            return 0;
        prev = curr;
        curr = curr->next;
        count++;
    }
    Node *n = (Node *)malloc(sizeof(*n)); //after pos is found

    if (curr ->next == NULL)
    {
        list_push_back(list, value);
        return 1;
    }
    n->data = value;
    prev->next = n;
    n->next = curr;
    
    return 1;

}