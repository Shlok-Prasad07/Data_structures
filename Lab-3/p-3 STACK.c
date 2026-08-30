//Write a program to implement STACK using an array that performs the following operations: 
//(a) PUSH (b) POP (c) PEEP (d) CHANGE (e) DISPLAY

#include <stdio.h>      // Used for printf() and scanf()
#include <stdlib.h>     // Used for exit()

#define MAX 5            // Maximum size of stack is 5

int S[MAX], top = -1;    // S is stack array and top stores top position
                         // top = -1 means stack is empty


// Function to check whether stack is full
int isFull()
{
    if(top == MAX - 1)   // If top reaches last index (4)
        return 1;        // Return 1 means stack is full
    else
        return 0;        // Return 0 means stack is not full
}


// Function to insert an element into stack
void push()
{
    int x;               // Variable to store value

    // Check whether stack is full
    if(isFull())
        printf("Stack is OverFlow.");   // Cannot insert if stack is full

    else
    {
        printf("Enter a Value:");
        scanf("%d",&x);                  // Take value from user

        top++;                           // Increase top by 1
        S[top] = x;                      // Store value at top position

        printf("Value inserted.");
    }
}


// Function to check whether stack is empty
int isEmpty()
{
    if(top == -1)        // If top is -1, stack has no elements
        return 1;        // Return 1 means stack is empty
    else
        return 0;        // Return 0 means stack is not empty
}


// Function to delete an element from stack
void pop()
{
    // Check whether stack is empty
    if(isEmpty())
        printf("\nStack is Underflow."); // Cannot delete from empty stack

    else
    {
        // Display the top element before deleting
        printf("%d is deleted.", S[top]);

        top--;             // Decrease top by 1
    }
}


// Function to display all stack elements
void display()
{
    int i;                 // Loop variable

    // Check whether stack is empty
    if(isEmpty())
        printf("Stack is Empty.");

    else
    {
        printf("Stack is: ");

        // Print elements from first position to top
        for(i=0; i<=top; i++)
            printf("%d ", S[i]);
    }
}


// Function to display the topmost element
void peep()
{
    // Check whether stack is empty
    if(isEmpty())
        printf("Stack is Empty.");

    else
        // Display topmost element without deleting it
        printf("Topmost element is %d.", S[top]);
}


// Function to change an element of stack
void change()
{
    int index, value;      // index = position from top, value = new value

    // Check whether stack is empty
    if(isEmpty())
        printf("Stack is Empty.");

    else
    {
        // Ask user for index from top
        printf("Enter an Index:");
        scanf("%d",&index);

        // Check whether entered index is valid
        if(top-index+1 < 0)
            printf("Invalid Index.");

        else
        {
            // Ask user for new value
            printf("Enter a value:");
            scanf("%d",&value);

            // Change the value at given position
            // top-index+1 converts top-based index to array index
            S[top-index+1] = value;

            printf("Value changed Successfully.");
        }
    }
}


// Main function
void main()
{
    int choice, v;         // choice stores user's menu choice

    // Infinite loop to continuously show stack menu
    while(1)
    {
        // Display stack operations menu
        printf("\n\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peep");
        printf("\n4. Change");
        printf("\n5. Display");
        printf("\n6. isEmpty");
        printf("\n7. isFull");
        printf("\n8. Exit");

        // Ask user to select an operation
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        // Execute operation according to user's choice
        switch(choice)
        {
            case 1:
                push();          // Call push function
                break;

            case 2:
                pop();           // Call pop function
                break;

            case 3:
                peep();          // Call peep function
                break;

            case 4:
                change();        // Call change function
                break;

            case 5:
                display();       // Call display function
                break;

            case 6:
                // Check whether stack is empty
                if(isEmpty())
                    printf("Yes, Stack is Empty.");
                else
                    printf("No, Stack is Not Empty.");
                break;

            case 7:
                // Check whether stack is full
                if(isFull())
                    printf("Yes, Stack is Full.");
                else
                    printf("No, Stack is Not Full.");
                break;

            case 8:
                exit(0);          // Stop the program

            default:
                printf("\nInvalid Choice!"); // For wrong menu choice
        }
    }
}
