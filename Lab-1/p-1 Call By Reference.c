//Demonstrate call by value and call by reference using the UDF concept.
//[ Swap two values with a function. Demonstrate Call by Value and Call by Reference]

//2. Call By Reference

#include<stdio.h>              // Include standard input/output library

void swap(int *a, int *b);     // Function declaration
                               // * means pointer

void main()
{
    int x, y;                  // Declare two integer variables

    printf("Enter two values:"); // Ask user to enter two values
    scanf("%d%d",&x,&y);       // Read values of x and y

    swap(&x,&y);               // Call swap function by passing addresses
                               // &x gives address of x
                               // &y gives address of y

    printf("\nAfter Swapping: x=%d y=%d",x,y);
                               // Print the swapped original values
}

void swap(int *a,int *b)
{
    int temp;                  // Temporary variable for swapping

    temp = *a;                 // Store value at address a in temp
    *a = *b;                   // Put value of b into a
    *b = temp;                 // Put original value of a into b

    // Original x and y are changed because their addresses were passed
}
