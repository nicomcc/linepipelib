#include "linepipelib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//dynamically reallocates buffer memory until all data is read
void increaseBuffer(char **str, int c)
{
    size_t len = 0;
    char *buffer;

    if (*str)
        len = strlen(*str);

    buffer = (char *)realloc(*str, len + 2);
    if (!buffer)
    {
        printf("\nMemory allocation error\n");
    }
    else
    {
        *str = buffer;
        buffer[len] = c;
        buffer[len + 1] = 0;
        printf("Buffer Size: %ld\n", len);
    }
}

Node CreateList(int nodesNumber)
{
    Node *cur, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->line = "asd";
    tmp->next = NULL;
    head = tmp;
    cur = head;

    for (int i = 2; i < nodesNumber; i++)
    {
        tmp = (Node *)malloc(sizeof(Node));
        tmp->line = "asd";
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
    }
}

void PrintList(Node *head)
{
    Node *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL)
    {
        printf("%s", ptr->line);
        ptr = ptr->next;
    }

    printf(" ]");
}

void DeleteList(Node *head)
{
    Node *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
        tmp = NULL;
    }
}