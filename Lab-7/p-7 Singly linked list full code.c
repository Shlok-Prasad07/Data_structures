/*Write a menu-driven program to implement the 
following operations on the singly linked list: 
(a) Insert a node at the front of the linked list. (b) Insert 
a node at the end of the linked list. 
(c) Insert a node such that the linked list is in ascending 
order. (According to info. Field) 
(d) Delete the first node of the linked list. 
(e) Delete the last node of the linked list. 
(f) Delete a node before the specified position.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *head = NULL;

/* (a) Insert at front */
void insertFront() {
    struct node *newnode;
    
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->next = head;
    head = newnode;

    printf("Node inserted at front.\n");
}

/* (b) Insert at end */
void insertEnd() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("Node inserted at end.\n");
}

/* (c) Insert in ascending order */
void insertAscending() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->info);

    newnode->next = NULL;

    /* Insert at front */
    if (head == NULL || newnode->info < head->info) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL &&
               temp->next->info < newnode->info) {
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("Node inserted in ascending order.\n");
}

/* (d) Delete first node */
void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}

/* (e) Delete last node */
void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    /* Only one node */
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

/* (f) Delete node before specified position */
void deleteBeforePosition() {
    struct node *temp, *del;
    int pos, i;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    /* No node exists before position 1 or 2 */
    if (pos <= 2) {
        printf("No node exists before this position.\n");
        return;
    }

    temp = head;

    /* Move to node just before the node to delete */
    for (i = 1; i < pos - 2; i++) {
        if (temp->next == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL || temp->next->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node before position %d deleted.\n", pos);
}

/* Display linked list */
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Main function */
int main() {
    int choice;

    while (1) {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Ascending Order\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Node Before Specified Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertAscending();
                break;

            case 4:
                deleteFirst();
                break;

            case 5:
                deleteLast();
                break;

            case 6:
                deleteBeforePosition();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
