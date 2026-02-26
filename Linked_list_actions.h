#include "Linked_list.h"

typedef void (*ActionFunc_list)(LinkedList *);

typedef struct MenuOption_list
{
    const char *text;
    ActionFunc_list func;
}MenuOption_list;

void list_menu_loop(const char *title, MenuOption_list*, int, LinkedList *);
void list_pushf_action(LinkedList *);
void list_pushb_action(LinkedList *);
void list_popb_action(LinkedList *);
void list_popf_action(LinkedList *);
void list_empty_action(LinkedList *);
void list_find_action(LinkedList *);
void list_insert_after_action(LinkedList *);
void list_delete_after_action(LinkedList *);
void list_deleteval_action(LinkedList *);
void list_print_action(LinkedList *);
void s_llist();

