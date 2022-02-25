#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct stuendt_st
{
    int id;
    int score;
} student;

void print(const void *data)
{
    const student *stu = data;
    printf("%d %d\n", stu->id, stu->score);
}

int compare(const void *key, const void *record)
{
    const int *k = key;
    const student *stu = record;

    return *k - stu->id;
}

int main()
{
    LIST *list = list_create(sizeof(student));
    student arr[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i].id = i;
        arr[i].score = rand() % 100;
    }

    for (int i = 0; i < 3; i++)
    {
        list_insert(list, &arr[i], TAIL);
    }
    
    list_print(list, print);

    int key = 1;

    printf("********\n");
    list_delete(list, &key, compare);

    list_print(list, print);

    list_destroy(list);
    return 0;
}
