#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head, *second, *third;

    // Create three nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Store data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Connect the nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Display the linked list
    printf("Linked List: ");

    printf("%d -> ", head->data);
    printf("%d -> ", second->data);
    printf("%d -> NULL", third->data);

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
