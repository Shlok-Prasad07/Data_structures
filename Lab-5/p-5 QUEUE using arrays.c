// Write a program to implement QUEUE using arrays
// Operations: INSERT, DELETE, PEEK, CHANGE, DISPLAY, isEmpty, isFull

#include <stdio.h>      // Used for printf() and scanf()
#include <stdlib.h>     // Used for exit()

#define MAX 5            // Maximum size of Queue is 5

int Que[MAX],            // Array used to store Queue elements
    front = -1,          // front points to first element
    rear = -1;           // rear points to last element

int value;               // Variable used to store input value


// Function to check whether Queue is full
int isFull()
{
    // Queue is full when rear reaches last index
    if(rear == MAX - 1)
        return 1;        // Return 1 means Queue is Full
    else
        return 0;        // Return 0 means Queue is Not Full
}


// Function to insert an element into Queue
void insert()
{
    // Check whether Queue is full
    if(isFull() == 1)
        printf("Queue is Overflow.");

    else
    {
        // Take value from user
        printf("Enter a Value:");
        scanf("%d", &value);

        // If Queue is initially empty,
        // set front to first position
        if(front == -1)
            front++;

        // Increase rear to next position
        rear++;

        // Store value at rear position
        Que[rear] = value;

        printf("Insertion Done.");
    }
}


// Function to check whether Queue is empty
int isEmpty()
{
    // If front is -1, Queue is empty
    if(front == -1)
        return 1;        // Return 1 means Queue is Empty
    else
        return 0;        // Return 0 means Queue is Not Empty
}


// Function to delete an element from Queue
void del()
{
    // Check whether Queue is empty
    if(isEmpty() == 1)
        printf("Queue is underflow.");

    else
    {
        // Delete the element at front
        printf("%d is deleted.", Que[front]);

        // If only one element is present,
        // reset both front and rear to -1
        if(front == rear)
            front = rear = -1;

        else
            // Move front to next element
            front++;
    }
}


// Function to display the last inserted element
void peek()
{
    // Check whether Queue is empty
    if(isEmpty() == 1)
        printf("Queue is Empty.");

    else
        // Display element at rear
        printf("Last inserted Value is %d.", Que[rear]);
}


// Function to change an element in Queue
void change()
{
    int index, newvalue;     // index = position, newvalue = new value

    // Check whether Queue is empty
    if(isEmpty() == 1)
        printf("Queue is Empty.");

    else
    {
        // Ask user for index
        printf("Enter an index:");
        scanf("%d", &index);

        // Check whether index is valid
        // Queue has (rear-front+1) elements
        if(index > (rear-front+1) || index <= 0)
            printf("Invalid Index..");

        else
        {
            // Take new value from user
            printf("Enter a new value:");
            scanf("%d", &newvalue);

            // Change value at given index
            // index+front-1 gives actual array position
            Que[index + front - 1] = newvalue;

            printf("value updated.");
        }
    }
}


// Function to display all Queue elements
void display()
{
    int i;                   // Loop variable

    // Check whether Queue is empty
    if(isEmpty() == 1)
        printf("Queue is Empty.");

    else
    {
        printf("\nQueue is:");

        // Display elements from front to rear
        for(i = front; i <= rear; i++)
            printf("%d ", Que[i]);
    }
}


// Main function
void main()
{
    int ch;                  // Variable to store user's choice

    // Infinite loop to continuously show Queue menu
    while(1)
    {
        // Display Queue operations
        printf("\n\nQueue Operation:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Peek");
        printf("\n4. Change");
        printf("\n5. Display");
        printf("\n6. isEmpty");
        printf("\n7. isFull");
        printf("\n8. Exit");

        // Ask user to select an operation
        printf("\nEnter Your Choice:");
        scanf("%d", &ch);

        // Execute operation according to user's choice
        switch(ch)
        {
            case 1:
                insert();       // Call insert function
                break;

            case 2:
                del();          // Call delete function
                break;

            case 3:
                peek();         // Call peek function
                break;

            case 4:
                change();       // Call change function
                break;

            case 5:
                display();      // Call display function
                break;

            case 6:
                // Check whether Queue is empty
                if(isEmpty() == 1)
                    printf("Yes, Queue is Empty.");
                else
                    printf("No, Queue is not Empty.");
                break;

            case 7:
                // Check whether Queue is full
                if(isFull() == 1)
                    printf("Yes, Queue is Full.");
                else
                    printf("No, Queue is Not Full.");
                break;

            case 8:
                // Exit the program
                exit(0);

            default:
                // Execute when user enters invalid choice
                printf("Invalid Choice; Try Again!");
        }
    }
}

// Easy points to remember

/* front = -1;       // Queue is initially empty
rear = -1;        // Queue is initially empty

rear++;           // INSERT ? move rear forward
Que[rear] = value;// Store new value

front++;          // DELETE ? move front forward

Que[rear];        // PEEK ? last inserted element

front == -1;      // Queue is EMPTY

rear == MAX-1;    // Queue is FULL

Que[index+front-1] // CHANGE ? change selected element */



//Queue follows FIFO:

/* FIFO = First In First Out

INSERT:  10 ? 20 ? 30
         ?         ?
       front      rear

DELETE ? 10 first */

