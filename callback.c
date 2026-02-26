#include "callback.h"
#include <stdio.h>

void print_int(void *data)
{
    printf("%d\n", *(int*)data);
}
void print_double(void *data)
{
    printf("%f\n", *(double*)data);
}
void print_float(void *data)
{
    printf("%f\n", *(float*)data);
}
void print_string(void *data)
{
    printf("%s\n", (char*)data);
}
