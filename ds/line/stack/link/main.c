#include "link_stack.h"

#include <stdio.h>

typedef struct student
{
    int id;
    int score;
    char *name;
} student;


void print(void *d)
{
    student *stu = d;
    printf("%d %d %s\n", stu->id, stu->score, stu->name);
}

int main()
{   
    link_stack stack = ls_create(sizeof(student));
    if (stack == NULL)
    {
        printf("error\n");
        exit(1);
    }

    student arr[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i].id = i;
        arr[i].score = rand() % 100;
        arr[i].name = "aaa";
        ls_push(stack, &arr[i]);
    }

    ls_print(stack, print);
    printf("********\n");

    student s;
    ls_top(stack, &s);
    ls_print(stack, print);

    printf("********\n");
    print(&s);

    printf("%ld %ld\n", *(size_t *)stack->data, sizeof(student));

    ls_destroy(stack);
    return 0;
}
