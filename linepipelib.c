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
    char *line;

    //nodes for list construction
    Node *cur, *tmp;

    tmp = (Node *)malloc(sizeof(Node));
    if (!tmp)
    {
        printf("\nMemory allocation error\n");
    }

    //head node
    else
    {
        line = strtok(text, "\n");
        tmp->line = (char *)malloc(strlen(line) + 1);
        if (!tmp->line)
        {
            printf("\nMemory allocation error\n");
        }
        //gets first line
        else
        {
            strcpy(tmp->line, line);
            line = strtok(NULL, "\n");
        }

        tmp->next = NULL;
        head = tmp;
        cur = head;

        //create list nodes from text line split
        while (line != NULL)
        {
            tmp = (Node *)malloc(sizeof(Node));
            if (!tmp)
            {
                printf("\nMemory allocation error\n");
            }

            else
            {
                tmp->line = (char *)malloc(strlen(line));

                strcpy(tmp->line, line);
                line = strtok(NULL, "\n");

                tmp->next = NULL;
                cur->next = tmp;
                cur = cur->next;
            }
        }
    }

    //free line heap memory
    free(line);
    line = NULL;
}

void PrintList(Node *head)
{
    Node *ptr = head;
    //start from the beginning
    while (ptr != NULL)
    {
        printf("%s\n", ptr->line);
        ptr = ptr->next;
    }
}

/* Function to reverse linked list */
void PrintReverseList(Node *head)
{

    if (head == NULL)
        return;

    // print the list after head node
    PrintReverseList(head->next);

    // After everything else is printed, print head
    printf("%s\n", head->line);
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


// Bubble sort the given linked list 
void BubbleSort(Node *start)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;

    // Checking for empty list 
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (strcmp(ptr1->line, ptr1->next->line) > 0)
            {
                Swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// function to swap data of two nodes a and b
void Swap(Node *a, Node *b)
{
    char *temp = a->line;
    a->line = b->line;
    b->line = temp;
}
