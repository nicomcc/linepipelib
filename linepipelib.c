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
    }
}

Node CreateList(int lineSize, char *text)
{

    int nodes = NumberOfNodes(strlen(text), lineSize);
    printf("Number of lines: %d\n", nodes);

    //line memory size based on user input
    char *newLine = (char *)malloc(lineSize);
    if (!newLine)
    {
        printf("\nMemory allocation error\n");
    }
    else
    {
        strncpy(newLine, text, lineSize);
        printf("substring: %s\n", newLine);
    }
    //nodes for list creation
    Node *cur, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    if (!tmp)
    {
        printf("\nMemory allocation error\n");
    }

    else
    {
        tmp->line = (char *)malloc(strlen(newLine) + 1);
        if (!tmp->line)
        {
            printf("\nMemory allocation error\n");
        }
        else
        {
            strcpy(tmp->line, newLine);
        }
        tmp->next = NULL;
        head = tmp;
        cur = head;

        for (int i = 1; i < nodes; i++)
        {
            strncpy(newLine, text + (i * lineSize), lineSize);
            tmp = (Node *)malloc(sizeof(Node));
            tmp->line = (char *)malloc(strlen(newLine) + 1);
            strcpy(tmp->line, newLine);
            tmp->next = NULL;
            cur->next = tmp;
            cur = cur->next;
        }
    }

    //free newline heap memory
    free(newLine);
    newLine = NULL;
}

void PrintList(Node *head)
{
    int line = 1;
    Node *ptr = head;
    printf("\nList Nodes: \n");

    //start from the beginning
    while (ptr != NULL)
    {
        printf("Line[%d]: %s\n", line, ptr->line);
        ptr = ptr->next;
        line++;
    }
}

//free dinamically alocated memory from list nodes
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

//check if text size is divisible by line_size
int NumberOfNodes(int text_size, int line_size)
{
    printf("text size: %d\n", text_size);
    printf("line size: %d\n", line_size);
    return (text_size % line_size) == 0 ? (text_size / line_size) : ((text_size / line_size) + 1);
}
