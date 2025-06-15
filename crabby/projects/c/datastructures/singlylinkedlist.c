// linkedlist.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    // declare struct Node pointer newNode, allocate memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // assign data element with provided data from function parameter
    // assign next element with NULL, this is the current last node
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    // Initialize an empty singly linked list
    struct Node* head = NULL;

    // Insert elements into the singly linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);

    // Print the singly linked list
    printf("Singly Linked List: ");
    printList(head);

    return 0;
}
