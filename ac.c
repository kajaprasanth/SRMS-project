#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

struct node* createNode(int data) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(int ele) {
    struct node *newnode = createNode(ele);
    newnode->next = top;
    top = newnode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct node *dnode = top;
    printf("Popped element: %d\n", dnode->data);
    top = top->next;
    free(dnode);
}

void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void printStack() {
    struct node *temp = top;

    if (temp == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                printStack();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }

    } while (1);

    return 0;
}
