#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *temp;

struct node* createNode(int);
void createStack();
void push(int);
void pop();
void peek();
void search(int);
void printStack();
int readData();

int main() {
    int data, choice, ch;

    createStack();

    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: data = readData();
                    push(data);
                    break;

            case 2: pop();
                    break;

            case 3: peek();
                    break;

            case 4: data = readData();
                    search(data);
                    break;

            default: printf("Invalid choice\n");
        }

        printStack();
        printf("Do you want to continue (0 to exit): ");
        scanf("%d", &ch);

        if (ch == 0)
            break;

    } while (1);

    return 0;
}

int readData() {
    int data;
    printf("Enter element: ");
    scanf("%d", &data);
    return data;
}

struct node* createNode(int data) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void createStack() {
    int choice, data;
    struct node *newnode;

    printf("Do you want to create initial stack? (1-Yes / 0-No): ");
    scanf("%d", &choice);

    while (choice == 1) {
        printf("Enter an element: ");
        scanf("%d", &data);

        newnode = createNode(data);
        newnode->next = top;
        top = newnode;

        printStack();
        printf("Enter your choice (1 to continue & 0 to exit): ");
        scanf("%d", &choice);
    }
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
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", top->data);
}

void search(int x) {
    struct node *temp = top;
    int flag = 0;

    while (temp != NULL) {
        if (temp->data == x) {
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if (flag == 1)
        printf("Search successful\n");
    else
        printf("Search not successful\n");
}

void printStack() {
    printf("The stack is: ");

    struct node *temp = top;

    if (temp == NULL) {
        printf("EMPTY\n");
        return;
    }

    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
