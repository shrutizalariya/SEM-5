#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
} *head = NULL;

// Insert at first
void insertAtFirst(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->info = data;

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->link = head;
    head = newNode;
}

// Insert at last
void insertAtLast(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->info = data;

    struct Node* temp = head;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

// Delete at first
int deleteAtFirst() {
    struct Node* First = head;

    if (head == NULL) {
        printf("Linked List is empty!\n");
        return 0;
    }

    int data = First->info;
    head = head->link;
    free(First);
    return data;
}

// Delete at last
int deleteAtLast() {
    if (head == NULL) {
        printf("Linked List is empty!\n");
        return 0;
    }

    struct Node* save = head->link;
    struct Node* First = head;

    // Only one node
    if (head->link == NULL) {
        int data = head->info;
        free(head);
        return data;
    }

    // Traverse to second last node
    while (save->link != NULL) {
        First = save;
        save = save->link;
    }

    int data = save->info;
    First->link = NULL;
    free(save);
    return data;
}

// Display the list
void display() {
    struct Node* ptr = head;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d-> ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

// Main menu
void main() {
    int choice, data;
    while (1) {
        printf("\n1.Insert at first\n2.Insert at last\n3.Delete at first\n4.Delete at last\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtFirst(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtLast(data);
            break;
        case 3:
            data = deleteAtFirst();
            if (data != 0)
                printf("Deleted data is: %d\n", data);
            break;
        case 4:
            data = deleteAtLast();
            if (data != 0)
                printf("Deleted data is: %d\n", data);
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting from program..........!\n");
            exit(0);
        default:
            printf("Invalid choice.please try again!!!!!!!!!!\n");
        }
    }
}
