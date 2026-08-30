// Write a program to implement Circular QUEUE using arrays
// Operations: INSERT, DELETE, DISPLAY

#include <stdio.h>      // Used for printf() and scanf()
#include <stdlib.h>     // Used for exit()

#define MAX 5            // Maximum size of Circular Queue

int CQ[MAX],             // Array used to store Circular Queue elements
    front = -1,          // front points to first element
    rear = -1,           // rear points to last element
    value;               // Variable used to store input value


// Function to check whether Circular Queue is full
int isFull()
{
    // If next position of rear is front, Queue is full
    if((rear + 1) % MAX == front)
        return 1;        // Return 1 means Queue is Full
    else
        return 0;        // Return 0 means Queue is Not Full
}


// Function to insert an element into Circular Queue
void insert()
{
    // Check whether Circular Queue is full
    if(isFull())
        printf("Circular Queue is Overflow.");

    else
    {
        // Take value from user
        printf("Enter a value:");
        scanf("%d", &value);

        // Move rear circularly
        // % MAX makes rear return to 0 after reaching MAX-1
        rear = (rear + 1) % MAX;

        // Store value at rear position
        CQ[rear] = value;

        // If Queue is initially empty,
        // set front to first position
        if(front == -1)
            front++;

        printf("Insertion Done.");
    }
}


// Function to check whether Circular Queue is empty
int isEmpty()
{
    // front = -1 means Queue is empty
    if(front == -1)
        return 1;        // Return 1 means Empty
    else
        return 0;        // Return 0 means Not Empty
}


// Function to delete an element from Circular Queue
void del()
{
    // Check whether Queue is empty
    if(isEmpty())
        printf("Circular Queue is Underflow.");

    else
    {
        // Delete and display front element
        printf("%d is Deleted.", CQ[front]);

        // If only one element is present
        if(front == rear)
            front = rear = -1;   // Make Queue empty

        else
            // Move front circularly to next position
            front = (front + 1) % MAX;
    }
}


// Function to display last inserted element
void peek()
{
    // Check whether Queue is empty
    if(isEmpty())
        printf("Circular Queue is Empty.");

    else
        // rear points to the last inserted element
        printf("Last inserted value is %d", CQ[rear]);
}


// Function to display all elements of Circular Queue
void display()
{
    int i;                         // Loop variable

    // Check whether Queue is empty
    if(isEmpty())
        printf("Circular Queue is Empty.");

    else
    {
        printf("Circular Queue is: ");

        // Start from front and move circularly
        // until rear is reached
        for(i = front; i != rear; i = (i + 1) % MAX)
            printf("%d ", CQ[i]);

        // Finally print the rear element
        printf("%d", CQ[rear]);
    }
}


// Function to change an element in Circular Queue
void change()
{
    int index, newvalue;           // index = position, newvalue = new value

    // Ask user for index
    printf("Enter an index:");
    scanf("%d", &index);


    // Case 1: front is before or equal to rear
    // Example: front = 1, rear = 4
    if(front <= rear)
    {
        // Check whether index is valid
        if(index > rear - front + 1 || index <= 0)
            printf("Invalid Index");

        else
        {
            // Take new value
            printf("Enter a new value");
            scanf("%d", &newvalue);

            // Change value at given index
            CQ[index + front - 1] = newvalue;

            printf("New Value Updated.");
        }
    }


    // Case 2: rear has crossed front
    // Example: front = 3, rear = 1
    else
    {
        // Calculate number of elements when Queue is wrapped
        if(index > (MAX + rear - front + 1) || index <= 0)
            printf("Invalid Index");

        else
        {
            // Take new value
            printf("Enter new value");
            scanf("%d", &newvalue);

            // % MAX is used to handle circular position
            CQ[(index + front - 1) % MAX] = newvalue;

            printf("New Value Updated.");
        }
    }
}


// Main function
void main()
{
    int ch;                        // Variable to store user's choice

    // Infinite loop to continuously show menu
    while(1)
    {
        // Display Circular Queue operations
        printf("\n\nCircular Queue Operations:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Peek");
        printf("\n4. Change");
        printf("\n5. Display");
        printf("\n6. isFull");
        printf("\n7. isEmpty");
        printf("\n8. Exit");

        // Ask user to select operation
        printf("\nEnter Your Choice:");
        scanf("%d", &ch);


        // Execute operation according to user's choice
        switch(ch)
        {
            case 1:
                insert();          // Call insert function
                break;

            case 2:
                del();             // Call delete function
                break;

            case 3:
                peek();            // Display last inserted element
                break;

            case 4:
                change();          // Change an element
                break;

            case 5:
                display();         // Display all elements
                break;

            case 6:
                // Check whether Circular Queue is full
                if(isFull())
                    printf("Yes, Circular Queue is Full.");
                else
                    printf("No, Circular Queue is not Full.");
                break;

            case 7:
                // Check whether Circular Queue is empty
                if(isEmpty())
                    printf("Yes, Circular Queue is Empty.");
                else
                    printf("No, Circular Queue is not Empty.");
                break;

            case 8:
                // Exit the program
                exit(0);

            default:
                // If user enters an invalid choice
                printf("Invalid Choice..");
        }
    }
}
