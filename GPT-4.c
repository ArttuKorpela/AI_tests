#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the node structure for the linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit program if memory allocation fails
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new integer to the linked list
void addNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode; // Set new node as head if list is empty
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Link the new node at the end
    }
}

// Function to find the smallest number in the linked list
int findSmallest(Node* head) {
    int min = INT_MAX;
    while (head != NULL) {
        if (head->value < min) {
            min = head->value;
        }
        head = head->next;
    }
    return min;
}

// Function to find the largest number in the linked list
int findLargest(Node* head) {
    int max = INT_MIN;
    while (head != NULL) {
        if (head->value > max) {
            max = head->value;
        }
        head = head->next;
    }
    return max;
}

// Function to free the memory allocated for the linked list
void freeList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int input;

    printf("Enter integers (enter -1 to finish): \n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break; // Exit the input loop
        }
        addNode(&head, input);
    }

    printf("Smallest number: %d\n", findSmallest(head));
    printf("Largest number: %d\n", findLargest(head));

    // Free the allocated memory
    freeList(&head);

    return 0;
}