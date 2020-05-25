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

Node CreateList(int nodesNumber, char *text)
{
    printf("text: %s\n", text);
    char *newLine = (char *) malloc(nodesNumber);
    //char newLine[3] = "";
    

    strncpy(newLine, text, nodesNumber);
    printf("Data Size: %ld\n", strlen(newLine));
    printf("substring: %s\n", newLine);
    Node *cur, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    tmp->line = (char *)malloc(strlen(newLine) + 1);
    strcpy(tmp->line, newLine);
    tmp->next = NULL;
    head = tmp;
    cur = head;

    for (int i = 1; i < 5; i++)
    {
        // subString(text, i*2, nodesNumber, newLine);
        strncpy(newLine, text + (i * nodesNumber), nodesNumber);
        printf("substring: %s\n", newLine);
        tmp = (Node *)malloc(sizeof(Node));
        tmp->line = (char *)malloc(strlen(newLine) + 1);
        strcpy(tmp->line, newLine);
        tmp->next = NULL;
        cur->next = tmp;
        cur = cur->next;
    }
    free(newLine);
    newLine=NULL;
}

void PrintList(Node *head)
{
    Node *ptr = head;
    printf("\n[ ");

    //start from the beginning
    while (ptr != NULL)
    {
        printf("list value: %s\n", ptr->line);
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
        free(tmp->line);
        tmp->line = NULL;
        free(tmp);
        tmp = NULL;
    }
}

