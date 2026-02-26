#include "Start.h"
#include <stdio.h>
#include "Safe_input.h"


void start()
{
    int ans = 1;
    while(1)
    {
        printf("Type 1: Stack\n");
        printf("Type 2: Queue\n");
        printf("Type 3: Singly linked list\n");
        printf("Type 0 to exit\n");
        printf("Your choice:");
        safe_int_input(&ans);
        switch(ans)
        {
            case 1 : stacks(); break;
            case 2 : queue(); break;
            case 3 : s_llist(); break;
            default: break;
        }
        if (ans == 0)
            break;
    }

}


void queue()
{
    
}
