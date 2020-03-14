#include <stdio.h>
#include<stdlib.h>

//declaring structure
struct stack
{
   int data;
   struct stack *ptr; //pointer type of stack
};

typedef struct stack Stack;
typedef Stack *stackPtr;

//function prototypes of different functions
void push(stackPtr *top, int x); //for pushing value in stack
int pop(stackPtr *top); //for popping value out of stack
int checkEmpty(stackPtr top); //checking whether stack is empty
void printValue(stackPtr showPtr); //for printing value that are pushed and popped

int main()
{
   stackPtr stackNewPtr = NULL; //declared pointer that points to the top of stack
   int option; //variable for choosing different options
   int value; //variable for storing entered by the user

   while (1)
   {
         //different options for the user
   printf("\nPlease choose following options:\n");
   printf("1. Insert an element in stack\n");
   printf("2. Delete an element in stack\n");
   printf("3. Display stack content\n");
   printf("4. Exit\n");

   printf("\nPlease enter your choise :");
   scanf("%d", &option);
      switch (option)
      {
      case 1:
         printf("\nEnter value: ");
         scanf("%d", &value);
         push(&stackNewPtr, value);
         break;

      case 2:
         if (!checkEmpty(stackNewPtr))
         {
            printf("\nPopped Value: %d\n", pop(&stackNewPtr));
         }
         break;

      case 3:
          printValue(stackNewPtr);
          break;

      case 4:
      printf("Exit, Thank You.");
         exit(0);
    
      default:
         puts("\n**Invalid choice**");
         break;
      }
   }
}

//function for pushing value into the top of stack
void push( stackPtr *top, int x )
{
    stackPtr nodePtr;

    //allocating memory
    nodePtr = malloc(sizeof(Stack));

    //pushing value at the top of stack only if there is space
    if(nodePtr != NULL)
    {
       nodePtr -> data = x;
       nodePtr -> ptr = *top;
       *top = nodePtr;
    }

    else
       printf("\nERROR !!! (Not enough space)");
   }

//popping value out of the stack
int pop(stackPtr *top)
{
   int pValue; //variable for value at the top
   stackPtr tempPtr;

   tempPtr = *top;
   pValue = (*top) -> data;
   *top = (*top) -> ptr;
   free(tempPtr); //free temporary pointer value
}

//function for printing value stored in the stack
void printValue(stackPtr showPtr)
{
   if(showPtr == NULL)
   {
       printf("\nNull.");
   }
   else
   {
      printf("\nData stored in stack:\n");

      while(showPtr != NULL)
     {
         printf("%d --> ", showPtr -> data);
         showPtr = showPtr -> ptr;
     }
     printf("NULL\n");
   }
}

int checkEmpty(stackPtr top)
{
   return top == NULL;
}