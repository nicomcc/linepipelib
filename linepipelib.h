#ifndef _LINEPIPELIB_H_
#define _LINEPIPELIB_H_

typedef struct node
{
    char *line;
    struct node *next;
} Node;

Node *head;

void increaseBuffer(char **str, int c);

Node CreateList(int lineSize, char *text);

void PrintList(Node *head);

void DeleteList(Node *head);

int NumberOfNodes(int text_size, int line_size);

void BubbleSort(Node *start) ;

void Swap(Node *a, Node*b);

void PrintReverseList(Node *head);

#endif