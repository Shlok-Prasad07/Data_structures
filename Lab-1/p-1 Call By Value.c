//Demonstrate call by value and call by reference using the UDF concept. 
//[ Swap two values with a function. Demonstrate Call by Value and Call by Reference]

//1. Call By Value

#include<stdio.h>              // Include standard input/output library

void swap(int a, int b);       // Function declaration

void main()
{
    int x, y, a, b;            // Declare integer variables

    printf("Enter two values:"); // Ask user to enter two values
    scanf("%d %d",&x,&y);       // Read values of x and y

    swap(x,y);                  // Call swap function by passing values
                                // Only copies of x and y are passed

    // Original x and y will not change in Call By Value
}

void swap(int a, int b)
{
    int temp;                   // Temporary variable for swapping

    temp = a;                   // Store value of a in temp
    a = b;                      // Copy value of b into a
    b = temp;                   // Copy original value of a into b

    // Values of a and b are swapped only inside this function
    printf("\nAfter Swapping: x=%d y=%d",a,b);
}
