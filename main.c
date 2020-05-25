#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linepipelib.h"

int main(int argc, char *argv[])
{
    char *pipeData = NULL;
    int input;
    int lineSize;
    int lineCount = 0;

    if (argc > 1)
    {
        lineSize = atoi(argv[1]);

        //send each byte individually from pipe
        while ((input = getchar()) != EOF)
        {
            //prevents from jumping line
            if(input == '\n' || input == '\r') {
                lineCount++;
            }
            increaseBuffer(&pipeData, input);
        }

        //printf("Line Count is: %d\n", lineCount);
        //Creates linked list based on data read from pipe and desired line size from input
        CreateList(lineSize, pipeData);

        
        printf("\n***********Original lines***********\n");
        PrintList(head);
        
        BubbleSort(head);
        printf("\n***********Sorted List***********\n");
        PrintList(head);

        printf("\n***********Reverse Sorted List***********\n");
        PrintReverseList(head);

        //free memory
        DeleteList(head);
        free(pipeData);
        pipeData = NULL;
    }

    else if (argc <= 1)
    {
        printf("insufficient parameters");
    }
}
