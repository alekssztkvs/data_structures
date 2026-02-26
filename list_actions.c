#include "Linked_list_actions.h"
#include "Safe_input.h"
#include "callback.h"
#include <stdio.h>

void s_llist()
{
    LinkedList list;
    list_init(&list);
    MenuOption_list list_menu[] = {
        {"Push forward", list_pushf_action},
        {"Push back", list_pushb_action},
        {"Pop front", list_popf_action},
        {"Pop back", list_popb_action},
        {"Check if empty", list_empty_action},
        {"Find", list_find_action},
        {"Insert after x", list_insert_after_action},
        {"Delete after x", list_delete_after_action},
        {"Delete value", list_deleteval_action},
        {"Print list", list_print_action}
    };
    list_menu_loop("Singly linked list", list_menu, 10, &list);
    list_free(&list);

}

void list_menu_loop(const char *title, MenuOption_list options[], int options_count, LinkedList *list)
{
    int choice = 0;

    while(1) 
    {
        printf("\n===%s===\n", title);
        for (int i = 0; i < options_count; i++)
            printf("%d : %s\n", i+1, options[i].text);
        printf("0: Back / Exit\n");

        printf("Your choice:");
        if(!safe_int_input(&choice))
            continue;
        if (choice == 0)
            break;
        if (choice < 1 || choice > options_count)
        {
            printf("Incorrect choice, try again.\n");
            continue;
        }
        options[choice-1].func(list);
        printf("Press enter to continue...");
        getchar();
    }
}

void list_pushf_action(LinkedList *list)
{
    int num;
    printf("Enter integer to push:");
    safe_int_input(&num);
    if(list_push_front(list, &num, sizeof(int)))
        printf("%d pushed to front\n", num);
    else
        printf("%d not pushed\n", num);
}
void list_pushb_action(LinkedList *list)
{
     int num;
    printf("Enter integer to push:");
    safe_int_input(&num);
    if(list_push_back(list, &num, sizeof(int)))
        printf("%d pushed to back\n", num);
    else
        printf("%d not pushed\n", num);
}
void list_popb_action(LinkedList *list)
{
    int out;
    if(list_pop_back(list, &out))
        printf("%d popped from back\n", out);
    else
        printf("List is empty\n");
}
void list_popf_action(LinkedList *list)
{
    int out;
    if(list_pop_front(list, &out))
        printf("%d popped from front\n", out);
    else
        printf("List is empty\n");
}
void list_empty_action(LinkedList *list)
{
    if(list_is_empty(list))
        printf("List is empty\n");
    else
        printf("List not empty\n");

}
void list_find_action(LinkedList *list)
{
    int num;
    printf("Enter integer to find:");
    safe_int_input(&num);
    if(list_find(list, &num))
        printf("%d is found\n", num);
    else
        printf("%d not found\n", num);
}
void list_insert_after_action(LinkedList *list)
{
    int num, pos;
    printf("Enter integer to insert:");
    safe_int_input(&num);
    printf("Enter position to insert after:");
    safe_int_input(&pos);
    if (list_insert_after(list, pos, &num, sizeof(int)))
        printf("%d is inserted after  pos:%d\n", num , pos);
    else
        printf("Insertion error\n");
}

void list_delete_after_action(LinkedList *list)
{
    int pos;
    printf("Enter position to delete after:");
    safe_int_input(&pos);
    if(list_delete_after(list, pos))
        printf("Element after pos %d is deleted\n", pos);
    else
        printf("Element after pos %d is not deleted\n", pos);
    

}
void list_deleteval_action(LinkedList *list)
{
    int num;
    printf("Enter integer to delete:");
    safe_int_input(&num);
    if(list_delete_value(list, &num))
        printf("%d is deleted\n", num);
    else
        printf("%d not on the list\n", num);
}

void list_print_action(LinkedList *list)
{
    if(!list_print(list, print_int))
        printf("List is empty\n");
}