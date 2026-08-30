/* Introduction to dynamic memory allocation and use of DMA functions malloc(), calloc(), free(), etc. 
[Construct a structure for students having roll number, name, and marks; ask the user for the number 
of students, allocate memory run time, get all data and print given data in table format.] */

//2. DMA using calloc()

#include <stdio.h>      // For printf() and scanf()
#include <stdlib.h>     // For malloc(), calloc() and free()

// Structure to store student information
struct stud
{
    int num, marks;     // Student number and marks
    char name[30];      // Student name
};

void main()
{
    int i, n;           // i = loop variable, n = number of students
    struct stud *p;     // Pointer to structure

    // Ask user for number of students
    printf("How many number of students:");
    scanf("%d", &n);

    // Allocate memory dynamically using malloc()
    // Memory is allocated for n students
    p = (struct stud*) malloc(n * sizeof(struct stud));

    // Alternative: Allocate memory using calloc()
    // calloc() initializes allocated memory to zero
    // p = (struct stud*) calloc(n, sizeof(struct stud));

    // Check whether memory allocation was successful
    if(p == NULL)
    {
        printf("\nMemory not available..");
    }

    // Ask user to enter student details
    printf("Enter Student Details:");

    // Loop to enter details of all students
    for(i = 0; i < n; i++)
    {
        // Enter student number
        printf("\nEnter Number:");
        scanf("%d", &p[i].num);

        // Enter student name
        printf("Enter Name:");
        scanf("%s", p[i].name);

        // Enter student marks
        printf("Enter Marks:");
        scanf("%d", &p[i].marks);
    }

    // Display heading
    printf("\nStudent Details\n Number\t Name\t Marks");

    // Loop to display details of all students
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t%s\t%d",
               p[i].num,       // Display student number
               p[i].name,      // Display student name
               p[i].marks);    // Display student marks
    }

    // Release dynamically allocated memory
    free(p);
}
