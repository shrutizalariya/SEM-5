#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

// Push operation
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

//Peep Operation
void peep(int pos) {
    int index = top - pos + 1;
    if (index < 0 || index > top) {
        printf("Invalid position\n");
    } else {
        printf("Element at position %d is: %d\n", pos, stack[index]);
    }
}

// Change operation (position from top)
void change(int pos, int new_val) {
    int index = top - pos + 1;
    if (index < 0 || index > top) {
        printf("Invalid position\n");
    } else {
        printf("Changed value at position %d from %d to %d\n", pos, stack[index], new_val);
        stack[index] = new_val;
    }
}

// Display operation
void display() {
	int i;
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main menu
int main() {
    int choice, value, pos , x=1;
    while (x==1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Peep\n");
        printf("5. Change\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                peek();
                display();
                break;
            case 4:
            	printf("Enter pos: ");
                scanf("%d", &pos);
                peep(pos);
                display();
                break;
            case 5:
                printf("Enter position from top to change: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &value);
                change(pos, value);
                display();
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting program.\n");
                x=0;
                break; 
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}


