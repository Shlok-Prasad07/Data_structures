/* Introduction to dynamic memory allocation and use of DMA functions malloc(), calloc(), free(), etc. 
[Construct a structure for students having roll number, name, and marks; ask the user for the number 
of students, allocate memory run time, get all data and print given data in table format.] */

//1. DMA using malloc()

#include <stdio.h>      // Used for printf() and scanf()
#include <stdlib.h>     // Used for malloc() and free()

// Structure to store student details
struct stud
{
    int num, marks;     // Student number and marks
    char name[30];      // Student name
};

void main()
{
    int i, n;           // i for loop, n for number of students
    struct stud *p;     // Pointer to structure

    // Ask user for number of students
    printf("How many number of students:");
    scanf("%d", &n);

    // Dynamically allocate memory for n students
    p = (struct stud*) malloc(n * sizeof(struct stud));

    // Check whether memory is allocated or not
    if(p == NULL)
    {
        printf("\nMemory not available..");
    }

    // Input student details
    printf("Enter Student Details:");

    // Loop to enter details of all students
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Number:");
        scanf("%d", &p[i].num);       // Store student number

        printf("Enter Name:");
        scanf("%s", p[i].name);       // Store student name

        printf("Enter Marks:");
        scanf("%d", &p[i].marks);     // Store student marks
    }

    // Display student details
    printf("\nStudent Details\n Number\t Name\t Marks");

    // Loop to display details of all students
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t%s\t%d",
               p[i].num,              // Display student number
               p[i].name,             // Display student name
               p[i].marks);           // Display student marks
    }

    // Release dynamically allocated memory
    free(p);
}
