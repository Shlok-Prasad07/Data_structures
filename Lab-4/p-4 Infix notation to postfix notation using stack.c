// Implement a program to convert infix notation to postfix notation using stack

#include <stdio.h>      // Used for printf(), puts(), gets()
#include <string.h>     // Used for strcat()
#include <ctype.h>      // Used for isalnum()
#include <stdlib.h>     // Used for exit()

#define MAX 20           // Maximum size of stack

char infix[50],          // Array to store infix expression
     postfix[50],        // Array to store postfix expression
     st[MAX];            // Stack array

int top = -1,            // top = -1 means stack is empty
    i = 0,               // i is used to read infix expression
    j = 0;               // j is used to store postfix expression


// Function to push a character into stack
void push(char ch)
{
    int k;               // Loop variable for displaying stack

    // Check whether stack is full
    if(top == MAX - 1)
    {
        printf("Stack Overflow.");
        exit(0);         // Stop the program
    }

    top++;               // Increase top position
    st[top] = ch;        // Store character at top of stack

    // Display current stack
    printf("\nStack is: ");

    for(k = 0; k <= top; k++)
        printf("%c ", st[k]);
}


// Function to remove and return top character from stack
char pop()
{
    // Check whether stack is empty
    if(top == -1)
    {
        printf("Stack underflow");
        exit(0);
    }

    top--;               // Decrease top

    // Return the previously topmost element
    return(st[top + 1]);
}


// Function to find priority of operators
int priority(char ch)
{
    switch(ch)
    {
        case '(':
            return 0;    // Lowest priority

        case '+':
        case '-':
            return 1;    // + and - have priority 1

        case '*':
        case '/':
        case '%':
            return 2;    // *, / and % have priority 2

        case '$':
        case '^':
            return 3;    // $ and ^ have highest priority
    }

    return -1;           // If character is not an operator
}


// Function to convert infix expression to postfix
void infix_to_postfix()
{
    char temp;           // Temporary variable

    // Add ')' at the end of infix expression
    // This helps to pop all remaining operators
    strcat(infix, ")");

    printf("\nStep1:");
    puts(infix);         // Display modified infix expression

    // Push '(' into stack initially
    push('(');


    // Process infix expression character by character
    while(infix[i] != '\0')
    {
        // If character is an operand (letter or number)
        if(isalnum(infix[i]))
        {
            // Directly add operand to postfix expression
            postfix[j] = infix[i];

            i++;          // Move to next infix character
            j++;          // Move to next postfix position
        }


        // If character is opening bracket or exponent operator
        else if(infix[i] == '(' ||
                infix[i] == '$' ||
                infix[i] == '^')
        {
            // Push the character into stack
            push(infix[i]);

            i++;          // Move to next character
        }


        // If closing bracket is found
        else if(infix[i] == ')')
        {
            // Pop operators until opening bracket is found
            while(top != -1 && st[top] != '(')
                postfix[j++] = pop();

            // If opening bracket is not found,
            // expression is invalid
            if(top == -1)
            {
                printf("Invalid Expression.");
                exit(0);
            }

            // Remove '(' from stack
            temp = pop();

            i++;          // Move to next character
        }


        // If +, -, *, / or % operator is found
        else if(infix[i] == '+' ||
                infix[i] == '-' ||
                infix[i] == '*' ||
                infix[i] == '/' ||
                infix[i] == '%')
        {
            // Pop operators having greater or equal priority
            while(top != -1 &&
                  priority(st[top]) >= priority(infix[i]))
            {
                postfix[j++] = pop();
            }

            // If stack becomes empty unexpectedly,
            // expression is invalid
            if(top == -1)
            {
                printf("Invalid Expression.");
                exit(0);
            }

            // Push current operator into stack
            push(infix[i]);

            i++;          // Move to next character
        }


        // Ignore spaces in the expression
        else if(infix[i] == ' ')
        {
            i++;
        }


        // If any invalid character is found
        else
        {
            printf("Invalid Expression.");
            exit(0);
        }
    }

    // Add NULL character at the end of postfix string
    postfix[j] = '\0';
}


// Main function
void main()
{
    // Ask user to enter infix expression
    printf("Enter an infix Expression:");

    // Read the infix expression
    gets(infix);

    // Call function to convert infix to postfix
    infix_to_postfix();

    // Display final postfix expression
    printf("\nPostfix Expression is: ");
    puts(postfix);
}


//Main logic to remember

/* Operand ? Directly add to postfix

'('     ? Push into stack

')'     ? Pop until '(' is found

Operator ? Pop higher/equal priority operators
           Then push current operator

End     ? Postfix expression is ready */


// OUTPUT

/*Infix:   A+B*C

Postfix: ABC*+  */

